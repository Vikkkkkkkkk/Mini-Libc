#include "unistd.h"
#include "time.h"

unsigned int sleep(unsigned int seconds) {
    struct timespec wait, rem;
    wait.tv_sec = seconds;
    wait.tv_nsec = 0;
    rem.tv_nsec = 0;
    rem.tv_sec = 0;
    nanosleep(&wait, &rem);
    return rem.tv_sec;
}
