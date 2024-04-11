#include <time.h>

int main() 
{
	struct timespec req, rem;
	req.tv_sec = 0;
	req.tv_nsec = 1000000;
	while (1) {
		nanosleep(&req, &rem);
	}
	return 0;
}
