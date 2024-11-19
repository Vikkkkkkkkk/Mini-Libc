// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (block == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}
	mem_list_add(block, size);
	return block;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *block = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (block == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}
	mem_list_add(block, size * nmemb);
	return block;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		return;
	}
	struct mem_list *node = mem_list_find(ptr);
	if (node == NULL) {
		return;
	}
	munmap(ptr, node->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
		return malloc(size);
	}
	struct mem_list *node = mem_list_find(ptr);
	if (node == NULL) {
		return NULL;
	}
	void *block = mremap(ptr, node->len, size, MREMAP_MAYMOVE);
	if (block == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}
	node->len = size;
	node->start = block;
	return block;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (ptr == NULL) {
		return malloc(size * nmemb);
	}
	struct mem_list *node = mem_list_find(ptr);
	if (node == NULL) {
		return NULL;
	}
	void *block = mremap(ptr, node->len, size * nmemb, MREMAP_MAYMOVE);
	if (block == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}
	node->len = size * nmemb;
	node->start = block;
	return block;
}
