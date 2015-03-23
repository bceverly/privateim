#include <stdio.h>
#include <string.h>

#include "helpers.h"

#ifdef __OSX__

size_t strlcpy(char *dst, const char *src, size_t dstsize) {
	strncpy(dst, src, dstsize);
	dst[dstsize] = 0x00;
}

size_t strlcat(char *dst, const char *src, size_t dstsize) {
	strncat(dst, src, dstsize);
	dst[dstsize] = 0x00;
}

#endif

void trim_str(char *in_string, int string_len) {
	char tmp_buf[string_len + 1];
	tmp_buf[0] = 0x00;

	int in_pos = 0;
	int out_pos = 0;

	for (in_pos = 0 ; in_pos < string_len ; in_pos++) {
		if (in_string[in_pos] != '\n') {
			tmp_buf[out_pos] = in_string[in_pos];
			out_pos++;
		}
	}

	strncpy(in_string, tmp_buf, string_len);
}