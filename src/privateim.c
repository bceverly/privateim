#include "privateim.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 8

int main(int argc, char *argv[]) {
	char str_buf[BUF_SIZE + 1];

	printf("Enter string: ");
	fgets(str_buf, sizeof str_buf, stdin);
	trim_str(str_buf, BUF_SIZE);

	printf("The buffer is: %s\n", str_buf);

	return 0;
}