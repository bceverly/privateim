#include "privateim.h"
#include "helpers.h"
#include "cmdparse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int ret = 0;
	int port_num = 0;
	char ip_address[MAX_STRING_SIZE + 1];

	if (!parse_command_line(argc, argv, ip_address, &port_num)) {
		return -1;
	}

	printf("ip_address = %s, port_num = %d\n", ip_address, port_num);

	return 0;
}