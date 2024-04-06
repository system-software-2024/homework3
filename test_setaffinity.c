#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: ./test_setaffinity pid cpu_id\n");
        return 1;
    }
    pid_t pid = strtol(argv[1], NULL, 10);
    long cpu_id = strtol(argv[2], NULL, 10);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu_id, &cpuset);

    int ret = sched_setaffinity(pid, sizeof(cpuset), &cpuset);
    if (ret < 0) {
        perror("sched_setaffinity");
        return 1;
    }
    CPU_CLR(cpu_id, &cpuset);

    return 0;
}