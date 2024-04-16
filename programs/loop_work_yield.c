#include <time.h>
#include <sched.h>
#include <unistd.h>

int main() 
{
    while (1) {
        time_t start_time = time(NULL), current_time;
        do {
            current_time = time(NULL);
        }while (current_time - start_time < 5);
    	sched_yield();
	}
    return 0;
}
