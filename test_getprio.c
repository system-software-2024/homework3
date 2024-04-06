#include <stdio.h>
#include <sched.h>
#include <assert.h>

#define SCHED_MLQ 7

int main(int argc, char *argv[]) {
	int minret = sched_get_priority_min(SCHED_MLQ);
	if (minret < 0) {
		perror("sched_get_priority_min");
		return 1;
	}
	int maxret = sched_get_priority_max(SCHED_MLQ);
	if (maxret < 0) {
		perror("sched_get_priority_max");
		return 1;
	}
	printf("minprio: %d, maxprio: %d\n", minret, maxret);
	assert(minret == 1 && maxret == 3);
	return 0;
}
