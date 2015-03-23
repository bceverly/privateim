#ifndef CMDPARSE_H
#define CMDPARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "helpers.h"

bool parse_command_line(int argc, char **argv, char *ip_address, int *port_num);

#endif