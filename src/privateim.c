#include "privateim.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_usage() {
	printf("usage:  privateim --ip IP_ADDRESS --port PORT_NUM\n");
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		print_usage();
		return -1;
	}

	if ((argc == 2) && (strcasecmp(argv[1], "--help") == 0)) {
		print_usage();
		return -1;
	}

	printf("Nothing to see here...\n");


	return 0;
}