#include <time.h>
#include "errno.h"
#include "internal/syscall.h"
#include "unistd.h"

int nanosleep(struct timespec *req, struct timespec *rem) {
    long ret = syscall(__NR_nanosleep, req, rem);
    if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
