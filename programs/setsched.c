#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#define SCHED_MLQ 7

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: ./setsched.bin pid prio\n");
        return 1;
    }
    pid_t pid = strtol(argv[1], NULL, 10);
    long prio = strtol(argv[2], NULL, 10);
    struct sched_param param = {
        .sched_priority = prio
    };
    int ret = sched_setscheduler(pid, SCHED_MLQ, &param);
    if (ret != 0) {
        perror("sched_setscheduler");
    }

    return 0;
}