#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

//uint_64t > unsigned int integer 64bits
// struct timeval implemented by <sys/time.h>
// gettimeofday as well


struct timeval {
    time_t      tv_sec;     // seconds
    suseconds_t tv_usec;    // microseconds
};

// valgrind tool for race condition
// valgrind --tool=helgrind
// ex : valgrind --tool=helgrind ./philo 5 640 450 450

int main()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("sec : %ld\n", time.tv_sec);
	uint64_t h = time.tv_sec / 60 / 60;
	printf("hours : %ld\n", h);
	uint64_t d = h / 24;
	printf("days : %ld\n", d);
	uint64_t m = d / 30;
	printf("months : %ld\n", m);
	uint64_t y = m / 12;
	printf("years : %ld\n", y);
}


// data->start = ft_time()   14h02

// data->derniers_repas = ft_time() - data_start
		// 14h04				14h04	-		14h02