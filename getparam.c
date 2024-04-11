#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: ./test_setparam pid\n");
		return 1;
	}
	pid_t pid = strtol(argv[1], NULL, 10);
	struct sched_param param;
	int ret = sched_getparam(pid, &param);
	if (ret != 0) {
		perror("sched_setparam");
		return 1;
	}
	printf("getparam prio: %u\n", param.sched_priority);

	return 0;
}