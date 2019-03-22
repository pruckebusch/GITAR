/**
 * \file
 *         Base64 decoder
 * \author
 *         Peter Ruckebusch
 */

#include "lib/util/base64-decoder.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BASE64_MAX_LINELEN 76

struct base64_decoder_state {
  uint8_t data[3 * BASE64_MAX_LINELEN / 4];
  int dataptr;
  unsigned long tmpdata;
  int sextets;
  int padding;
};

struct base64_decoder_state s;

/*---------------------------------------------------------------------------*/
static int
base64_decode_char(char c)
{
  if(c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else if(c >= 'a' && c <= 'z') {
    return c - 'a' + 26;
  } else if(c >= '0' && c <= '9') {
    return c - '0' + 52;
  } else if(c == '+') {
    return 62;
  } else if(c == '/') {
    return 63;
  } else {
    return 0;
  }
}
/*---------------------------------------------------------------------------*/
static int
base64_add_char(struct base64_decoder_state *s, char c)
{
  if(isspace(c)) {
    return 0;
  }

  if(s->dataptr >= sizeof(s->data)) {
    return 0;
  }
  if(c == '=') {
    ++s->padding;
  }
  
  s->tmpdata = (s->tmpdata << 6) | base64_decode_char(c);
  ++s->sextets;
  if(s->sextets == 4) {
    s->sextets = 0;
    s->data[s->dataptr] = (uint8_t)(s->tmpdata >> 16);
    s->data[s->dataptr + 1] = (uint8_t)(s->tmpdata >> 8);
    s->data[s->dataptr + 2] = (uint8_t)(s->tmpdata);
    s->dataptr += 3;
    if(s->dataptr == sizeof(s->data)) {
      return 0;
    } else {
      return 1;
    }
  }
  return 1;
}

/*---------------------------------------------------------------------------*/
void base64_decoder_decode(decoder_input_t* input, decoder_output_t* output ){
	int i;
	if(input->len == 0) {
		output->data = NULL;
		output->len = 0;
		return;
	}

	s.sextets = s.dataptr = s.padding = 0;

	for(i = 0; i < input->len; ++i) {
		base64_add_char(&s, input->data[i]);
	}
	
	output->data = s.data;
	output->len = s.dataptr - s.padding;
	
}

