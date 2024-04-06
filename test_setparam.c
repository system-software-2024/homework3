#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "usage: ./test_setparam pid prio\n");
		return 1;
	}
	pid_t pid = strtol(argv[1], NULL, 10);
	long prio = strtol(argv[2], NULL, 10);
	const struct sched_param param = {
		.sched_priority = prio
	};
	int ret = sched_setparam(pid, &param);
	if (ret != 0) {
		perror("sched_setparam");
		return 1;
	}
	return 0;
}
