#include "cmdparse.h"

void print_usage() {
	printf("usage:  privateim --ip IP_ADDRESS --port PORT_NUM\n");
}

int get_port_num(char *str_port_num) {
	int port_num = 0;
	int i = 0;
	for (i=0 ; i<strlen(str_port_num) ; i++) {
		if (!isdigit(str_port_num[i])) {
			return -1;
		}
	}

	// Now we know we str_port_num a valid port number
	port_num = atoi(str_port_num);
	if ((port_num > 0) && (port_num < 65535)) {
		return port_num;
	}

	return -1;
}

bool validate_ip_address(char *ip_address) {
	int num_dots = 0;
	int i = 0;
	int tuple[4];
	char *dot_pointer = ip_address;

	for (i=0 ; i<strlen(ip_address) ; i++) {
		if (ip_address[i] == '.') {
			if (num_dots >= 3) {
				return false;
			}

			// Save off the tuple
			ip_address[i] = 0x00;
			tuple[num_dots] = atoi(dot_pointer);
			ip_address[i] = '.';
			dot_pointer = &ip_address[i] + 1;

			// Increment our counter
			num_dots++;
		} else if (!isdigit(ip_address[i])) {
			return false;
		}
	}

	if (num_dots == 3) {
		tuple[num_dots] = atoi(dot_pointer);
		for (i=0 ; i<=3 ; i++) {
			printf("tuple[%d] = %d\n", i, tuple[i]);
			if ((tuple[i] < 0) || (tuple[i] > 255)) {
				return false;
			}
		}
		return true;
	}

	return false;
}

bool parse_command_line(int argc, char **argv, char *ip_address, int *port_num) {
	char str_port_num[MAX_STRING_SIZE + 1];

	if (argc == 1) {
		print_usage();
		return false;
	}

	if ((argc == 2) && (strcasecmp(argv[1], "--help") == 0)) {
		print_usage();
		return false;
	}

	if (argc == 5) {
		// Try to parse out the IP and PORT
		ip_address[0] = 0x00;
		str_port_num[0] = 0x00;

		if (strcasecmp(argv[1], "--ip") == 0) {
			strlcpy(ip_address, argv[2], MAX_STRING_SIZE);
		} else if (strcasecmp(argv[3], "--ip") == 0) {
			strlcpy(ip_address, argv[4], MAX_STRING_SIZE);
		}

		if (strcasecmp(argv[1], "--port") == 0) {
			strlcpy(str_port_num, argv[2], MAX_STRING_SIZE);
		} else if (strcasecmp(argv[3], "--port") == 0) {
			strlcpy(str_port_num, argv[4], MAX_STRING_SIZE);
		}

		if ((strlen(ip_address) == 0) || (strlen(str_port_num) == 0)) {
			print_usage();
			return false;
		}

		*port_num = 42;
		*port_num = get_port_num(str_port_num);
		if (*port_num <= 1) {
			print_usage();
			return false;
		}

		if (!validate_ip_address(ip_address)) {
			print_usage();
			return false;
		}
	}

	return true;
}
