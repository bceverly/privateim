#include "privateim.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_usage() {
	printf("usage:  privateim --ip IP_ADDRESS --port PORT_NUM\n");
}

#define MAX_STRING_SIZE 256

int main(int argc, char *argv[]) {
	char ip_address[MAX_STRING_SIZE + 1];
	char port_num[MAX_STRING_SIZE + 1];

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

	printf("ip_address = %s, port_num = %s\n", ip_address, port_num);

	return 0;
}