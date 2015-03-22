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

void print_usage() {
	printf("usage:  privateim --ip IP_ADDRESS --port PORT_NUM\n");
}

int parse_command_line(int argc, char **argv, char *ip_address, char *port_num) {
	if (argc == 1) {
		print_usage();
		return -1;
	}

	if ((argc == 2) && (strcasecmp(argv[1], "--help") == 0)) {
		print_usage();
		return -1;
	}

	if (argc == 5) {
		// Try to parse out the IP and PORT
		ip_address[0] = 0x00;
		port_num[0] = 0x00;

		if (strcasecmp(argv[1], "--ip") == 0) {
			strlcpy(ip_address, argv[2], MAX_STRING_SIZE);
		} else if (strcasecmp(argv[3], "--ip") == 0) {
			strlcpy(ip_address, argv[4], MAX_STRING_SIZE);
		}

		if (strcasecmp(argv[1], "--port") == 0) {
			strlcpy(port_num, argv[2], MAX_STRING_SIZE);
		} else if (strcasecmp(argv[3], "--port") == 0) {
			strlcpy(port_num, argv[4], MAX_STRING_SIZE);
		}

		if ((strlen(ip_address) == 0) || (strlen(port_num) == 0)) {
			print_usage();
			return -1;
		}
	}

	return 0;
}