// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	while (len > 0 && *source != '\0') {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	if (len > 0) {
		*destination = '\0';
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *tmp = destination;
	while (*destination != '\0')
		destination++;
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return tmp;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *new = destination;
	while (*destination != '\0')
		destination++;
	while (*source != '\0' && len > 0) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	*destination = '\0';
	return new;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return 0;
	else if (*str1 < *str2)
		return -1;
	else
		return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2 && len > 0) {
		str1++;
		str2++;
		len--;
	}
	if (len == 0 || (*str1 == '\0' && *str2 == '\0'))
		return 0;
	else if (*str1 < *str2)
		return -1;
	else
		return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
		if (*str == (char)c)
			return (char*)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *last = NULL;
	while (*str != '\0') {
		if (*str == (char)c)
			last = (char *)str;
		str++;
	}
	if (last != NULL)
		return last;
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;
		while (*n != '\0' && *h == *n) {
			h++;
			n++;
		}
		if (*n == '\0')
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *out = NULL;
	const char *found;
	found = strstr(haystack, needle);
	while (found != NULL) {
		out = (char *)found;
		found = strstr(found + 1, needle);
	}
	return out;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	const char *src = (const char *)source;
	for (size_t i = 0; i < num; i++)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	const char *src = (const char *)source;

	if (dest > src && dest < src + num) {
		for (size_t i = num; i > 0; i--)
			dest[i-1] = src[i-1];
	} else {
		for (size_t i = 0; i < num; i++)
			dest[i] = src[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;

	for (size_t i = 0; i < num; i++) {
		if (p1[i] < p2[i])
			return -1;
		else if (p1[i] > p2[i])
			return 1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *src = (unsigned char *)source;

	for (size_t i = 0; i < num; i++)
		src[i] = (unsigned char)value;

	return source;
}
