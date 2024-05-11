#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
	int *thread_id = (int *)arg;
	printf("Thread %d is starting...\n", *thread_id);
	sleep(2);
	printf("Thread %d is finishing...\n", *thread_id);
	pthread_exit(NULL);
}

int main() {
	pthread_t thread1, thread2;
	int id1 = 1, id2 = 2;

	pthread_create(&thread1, NULL, thread_function, (void *)&id1);
	pthread_create(&thread2, NULL, thread_function, (void *)&id2);
	sleep(3);

	printf("Main thread is waiting for thread 1 to finish...\n");
	sleep(3);

	pthread_join(thread1, NULL);
	printf("Main thread continues after thread 1 finished.\n");
	sleep(3);

	printf("Main thread is waiting for thread 2 to finish...\n");
	sleep(3);

	pthread_join(thread2, NULL);
	printf("Main thread continues after thread 2 finished.\n");

	return 0;
}
