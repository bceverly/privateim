#ifndef HELPERS_H
#define HELPERS_H

#define MAX_STRING_SIZE 256

void trim_str(char *string, int string_len);

#ifdef __OSX__

size_t strlcpy(char *dst, const char *src, size_t dstsize);
size_t strlcat(char *dst, const char *src, size_t dstsize);

#endif

int parse_command_line(int argc, char **argv, char *ip_address, char *port_num);

#endif