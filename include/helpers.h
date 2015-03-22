#ifndef HELPERS_H
#define HELPERS_H

void trim_str(char *string, int string_len);

#ifdef __OSX__

size_t strlcpy(char *dst, const char *src, size_t dstsize);
size_t strlcat(char *dst, const char *src, size_t dstsize);

#endif


#endif