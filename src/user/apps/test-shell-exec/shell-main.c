#include "src/user/apps/shell/shell.h"
#include "src/system/hil/dev/serial-line.h"
#include "src/system/hil/lib/rime/rimeaddr.h"
#include "src/system/hil/dev/leds.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "src/system/hil/sys/process/process.h"
#include "src/system/hil/sys/process/autostart.h"

#include "gpio-z1.h"

#define WRITE_BLOCK_SIZE 20

char write[] = "dec64 | write blinker.ce | null";
char kill[] = "~K";
char exec[] = "exec blinker.ce";
char empty[] = "";
char print_size[] = "read blinker.ce | size";

uint16_t num_bytes = 0;
char write_buffer[WRITE_BLOCK_SIZE+1];

char encoded_elf_file[] =
"f0VMRgEBAf8AAAAAAAAAAAEAaQABAAAAAAAAAAAAAABwAgAAAQAAEDQAAAAAACgADQAKAD9AAACw\
EgAAwk8AAD9AAACwEgAAwk8AALASAACCTwAAXkIAAD9AAACwEgAAP0AAALASAADCTwAAsBIAAIJP\
AABeQgAAP0AAALASAAA/QAAAsBIAAMJPAACwEgAAgk8AAF5CAAA/QAAAsBIAADBBCxILTy9PP5Ab\
ABskP5AfADYkD5NHILASAAAfQgAAHE8IAD1AgAAOQz9AAACsEh9CAAAeTwgAX0OeEgIAu0AbAAAA\
H0IAAB5PCAA/QAAAnhIMAA+TAiBPQyk8H0IAAB5PCAA/QAAAnhICAB9CAAAeTwgAX0OeEgQAu0Af\
AAAAH0IAAB5PCAA/QAAAnhIMAA+T4icfQgAAHk8IAD9AAACeEgIAxT+LQwAAf0ADADtBMEEAAAAA\
AAAAAAAACgAAAAoAAAAKAAAACgAAAAAAVGVzdCBibGluayBwcm9jZXNzAGJsaW5rZXIAAAoAAQAD\
BwAAAAAAAAAAAAAAAAAAAAAAAHByb2Nlc3MAPQwCBwEHAABsZWRzAAAJcQIHAQQAAGV0aW1lcgAA\
GHoCBwEHAAAAR0NDOiAoR05VKSA0LjcuMCAyMDEyMDMyMiAobXNwZ2NjIGRldiAyMDEyMDcxNikA\
QQ8AAABnbnUAAQcAAAAEAQAuc3ltdGFiAC5zdHJ0YWIALnNoc3RydGFiAC5yZWxhLnRleHQALnJl\
bGEuZGF0YQAuYnNzAC5yZWxhLnJvZGF0YQAuY29tbWVudAAuZ251LmF0dHJpYnV0ZXMAAAAAAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAABAAAABgAAAAAAAAA0AAAA\
HgEAAAAAAAAAAAAAAgAAAAAAAAAbAAAABAAAAAAAAAAAAAAAuAUAAOABAAALAAAAAQAAAAQAAAAM\
AAAAKwAAAAEAAAADAAAAAAAAAFIBAAAYAAAAAAAAAAAAAAACAAAAAAAAACYAAAAEAAAAAAAAAAAA\
AACYBwAAGAAAAAsAAAADAAAABAAAAAwAAAAxAAAACAAAAAMAAAAAAAAAagEAABYAAAAAAAAAAAAA\
AAIAAAAAAAAAOwAAAAEAAAACAAAAAAAAAGoBAABmAAAAAAAAAAAAAAACAAAAAAAAADYAAAAEAAAA\
AAAAAAAAAACwBwAASAAAAAsAAAAGAAAABAAAAAwAAABDAAAAAQAAADAAAAAAAAAA0AEAADEAAAAA\
AAAAAAAAAAEAAAABAAAATAAAAPX//28AAAAAAAAAAAECAAAQAAAAAAAAAAAAAAABAAAAAAAAABEA\
AAADAAAAAAAAAAAAAAARAgAAXAAAAAAAAAAAAAAAAQAAAAAAAAABAAAAAgAAAAAAAAAAAAAAeAQA\
ANAAAAAMAAAABwAAAAQAAAAQAAAACQAAAAMAAAAAAAAAAAAAAEgFAABwAAAAAAAAAAAAAAABAAAA\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADAAEAAAAAAAAAAAAAAAAAAwADAAAAAAAA\
AAAAAAAAAAMABQAAAAAAAAAAAAAAAAADAAYAAAAAAAAAAAAAAAAAAwAIAAAAAAAAAAAAAAAAAAMA\
CQABAAAAAAAAAAAAAAAQAAAAEAAAAAAAAAAAAAAAEAAAACYAAAAAAAAAAAAAABAAAAA9AAAAAAAA\
AAAAAAAQAAAAUQAAAAAAAAAEAAAAEQAGAGUAAAAAAAAACgAAABEAAwAAa2VybmVsX2FkZF9jbXAA\
a2VybmVsX3NlYXJjaF9oaWxfY21wAGtlcm5lbF9nZXRfaGlsX2NtcF9yZWYAa2VybmVsX2FkZF9j\
bXBfdXNlcgBhdXRvc3RhcnRfcHJvY2Vzc2VzAHRlc3RfYmxpbmsAAgAAAAUEAAAgAAAABgAAAAMH\
AAAAAAAACgAAAAUCAAAKAAAADgAAAAUEAABAAAAAEgAAAAMIAAAAAAAAFgAAAAUDAAAMAAAAGgAA\
AAMJAAAAAAAAHgAAAAMDAAAQAAAAIgAAAAUDAAAMAAAAJgAAAAUCAAAMAAAAKgAAAAMKAAAAAAAA\
LgAAAAUEAABOAAAAMgAAAAMIAAAAAAAANgAAAAUDAAANAAAAOgAAAAMJAAAAAAAAPgAAAAMDAAAS\
AAAAQgAAAAUDAAANAAAARgAAAAUCAAAQAAAASgAAAAMKAAAAAAAATgAAAAUEAABeAAAAUgAAAAMI\
AAAAAAAAVgAAAAUDAAAOAAAAWgAAAAMJAAAAAAAAXgAAAAMDAAAUAAAAYgAAAAUDAAAOAAAAZgAA\
AAUCAAAUAAAAagAAAAMKAAAAAAAAhgAAAAMBAAAAAAAAigAAAAMDAAAUAAAAmAAAAAUDAAAAAAAA\
ngAAAAMDAAASAAAAsgAAAAMDAAAUAAAAugAAAAUDAAAAAAAAygAAAAMDAAAUAAAA0gAAAAUDAAAA\
AAAA2gAAAAMDAAASAAAA7gAAAAMDAAAUAAAA9gAAAAUDAAAAAAAAAgEAAAMDAAAUAAAACgEAAAUD\
AAAAAAAAAgAAAAUEAAAEAAAABAAAAAUBAABuAAAAAAAAAAUMAAAAAAAAJgAAAAUEAAAXAAAALgAA\
AAUBAAAAAAAARgAAAAUEAAA4AAAAVAAAAAUEAABIAAAAZAAAAAUEAABWAAAA";

/*---------------------------------------------------------------------------*/
PROCESS(shell_main_process, "Shell Main");
AUTOSTART_PROCESSES(&shell_main_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(shell_main_process, ev, data){
	PROCESS_BEGIN();

		shell_init();

		shell_file_init();
		shell_coffee_init();
		shell_text_init();
		shell_exec_init();
		shell_base64_init();
		
		
		PROCESS_WAIT_EVENT_UNTIL(ev == shell_event_ready);

		//printf("Shell main process started, writing file len %u\n", sizeof(encoded_elf_file));
		
		GPIO_PIN_SET(6,5);
				
		shell_input(write, strlen(write));
		
		while(num_bytes < sizeof(encoded_elf_file)){
			if(num_bytes + WRITE_BLOCK_SIZE < sizeof(encoded_elf_file)-1){
				memcpy(write_buffer, &encoded_elf_file[num_bytes],WRITE_BLOCK_SIZE);
				write_buffer[WRITE_BLOCK_SIZE] = '\0';		
				num_bytes+=WRITE_BLOCK_SIZE;
			} else {
				memcpy(write_buffer, &encoded_elf_file[num_bytes],sizeof(encoded_elf_file) - num_bytes);
				//shell_input(&encoded_elf_file[num_bytes],sizeof(encoded_elf_file) - 1 - num_bytes);
				num_bytes+=(sizeof(encoded_elf_file) - num_bytes);
			}
			shell_input(write_buffer,strlen(write_buffer));
		}

		shell_input(empty,strlen(empty));
		

		//printf("Wrote elf file with %u bytes to filesystem\n", num_bytes);

		/*if(!shell_is_ready()){
			PROCESS_WAIT_EVENT_UNTIL(ev == shell_event_ready);
		}
				
		shell_input(kill, strlen(kill));*/

		//shell_input(print_size, strlen(print_size));

		//PROCESS_WAIT_EVENT_UNTIL(ev == shell_event_ready);

		shell_input(exec, strlen(exec));
		
		GPIO_PIN_CLR(6,5);

		while(1) {
			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message && data != NULL);
			shell_input(data, strlen(data));
		}

	PROCESS_END();
}
/*---------------------------------------------------------------------------*/
void shell_default_output(const char *text1, int len1, const char *text2, int len2) {
	/*int i;
	if(text1 == NULL) {
		text1 = "";
		len1 = 0;
	}
	if(text2 == NULL) {
		text2 = "";
		len2 = 0;
	}*/

	/* Precision (printf("%.Ns", text1)) not supported on all platforms.
	 putchar(c) not be supported on all platforms. */
	/*for(i = 0; i < len1; i++) {
		printf("%c", text1[i]);
	}
	for(i = 0; i < len2; i++) {
		printf("%c", text2[i]);
	}
	printf("\r\n");*/
}
/*---------------------------------------------------------------------------*/
void
shell_prompt(char *str)
{
	printf("%s\n", str);
}
/*---------------------------------------------------------------------------*/
void
shell_exit(void)
{
}
/*---------------------------------------------------------------------------*/
