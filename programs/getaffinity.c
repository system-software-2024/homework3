#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: ./getaffinity.bin pid\n");
        return 1;
    }
    long nproc = sysconf(_SC_NPROCESSORS_ONLN);

    pid_t pid = strtol(argv[1], NULL, 10);
    long cpu_id = 0;
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    int ret = sched_getaffinity(pid, sizeof(cpuset), &cpuset);
    if (ret < 0) {
        perror("sched_getaffinity");
        return 1;
    }
    long i;
    for (i = 0; i < nproc; i++) {
        if (CPU_ISSET(i, &cpuset)) {
            cpu_id = i;
            break;
        }
    }
    printf("getaffinity cpuid: %ld\n", cpu_id);
    
    return 0;
}