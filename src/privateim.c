#include "privateim.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	char ip_address[MAX_STRING_SIZE + 1];
	char port_num[MAX_STRING_SIZE + 1];
	int ret = 0;

	ret = parse_command_line(argc, argv, ip_address, port_num);
	if (ret != 0) {
		return ret;
	}

	printf("ip_address = %s, port_num = %s\n", ip_address, port_num);

	return 0;
}