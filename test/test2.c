#include <semaphore.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_data {

	pthread_t th_id;
	int th_nb;

} t_data;

void *routine (void* arg)
{
	t_data *thread = (t_data*) arg;
	printf("Thread %d ready \n", thread->th_nb);
	sleep(2);

	return (NULL);
}


int main (int argc, char **argv)
{
	int i = 0;
	int res = atoi(argv[1]);
	t_data *thread_list;

	thread_list = malloc(sizeof(t_data) * res);
	if (thread_list == NULL)
		perror("malloc");

/*      pthread_create loop     */
	while (i < res)
	{
		thread_list[i].th_nb = i + 1;
		int create = pthread_create(&thread_list[i].th_id, NULL, routine, &thread_list[i]);
		if (create != 0)
		{
			perror("pthread_create");
			return 1;
		}
		i++;
	}
	i = 0;

/*      pthread_join			*/
	while(i < res)
	{
		int join = pthread_join(thread_list[i].th_id, NULL);
		if (join != 0)
		{
			printf("join != 0\n");
			break;
		}
	}

	free(thread_list);
	printf("done\n");
	return 0;
}