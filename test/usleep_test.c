#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

//uint_64t > unsigned int integer 64bits
// struct timeval implemented by <sys/time.h>
// gettimeofday as well


// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };

void test()
{
	struct timeval	start;
	struct timeval	end;
	long request;
	long current;

	request = 200000; // 200 millisec
	gettimeofday(&start, NULL);
	usleep(request);

	gettimeofday(&end, NULL);
	current = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

	printf("resquest	: %ld microsec\n", request); // 	200000 stable
	printf("current		: %ld microsec\n", current); // 	200081 ~ 200212

}

int main()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("sec	:	%ld\n", time.tv_sec);
	uint64_t h = time.tv_sec / 60 / 60;
	printf("hours	:	%ld\n", h);
	uint64_t d = h / 24;
	printf("days 	:	%ld\n", d);
	uint64_t m = d / 30;
	printf("months 	:	%ld\n", m);
	uint64_t y = m / 12;
	printf("years	:	%ld\n\n", y);

	test();
}