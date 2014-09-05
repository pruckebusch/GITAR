/**
 * \file
 *         Header for base64 decoding
 * \author
 *         Peter Ruckebusch
 */

#ifndef __BASE64_DECODER_H__
#define __BASE64_DECODER_H__


typedef struct decoder_input {
	char* data;
	int len;
} decoder_input_t;

typedef struct decoder_output {
	char* data;
	int len;
} decoder_output_t;

void base64_decoder_decode(decoder_input_t* input, decoder_output_t* output);

#endif /* __BASE64_DECODER_H__ */
