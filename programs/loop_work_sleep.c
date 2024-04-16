#include <time.h>
#include <unistd.h>

int main() 
{
    while (1) {
        time_t start_time = time(NULL), current_time;
        do {
            current_time = time(NULL);
        }while (current_time - start_time < 5);
        struct timespec req, rem;
        req.tv_sec = 1;
        req.tv_nsec = 0;
        nanosleep(&req, &rem);
    }
    return 0;
}
