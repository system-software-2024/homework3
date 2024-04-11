#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <assert.h>

#define SCHED_MLQ 7

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: ./test_getsched pid\n");
		return 1;
	}
	pid_t pid = strtol(argv[1], NULL, 10);
	int ret = sched_getscheduler(pid);
	if (ret < 0) {
		perror("sched_getscheduler");
		return 1;
	}
	assert(ret == SCHED_MLQ);
	printf("getscheduler: %d\n", ret);

	return 0;
}