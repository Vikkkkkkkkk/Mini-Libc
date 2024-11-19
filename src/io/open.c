// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	mode_t mode = 0;

	if (flags & O_CREAT) {
		va_list argList;
		va_start(argList, flags);
		mode = va_arg(argList, mode_t);
		va_end(argList);
	}

	long ret = syscall(__NR_open, filename, flags, mode);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
