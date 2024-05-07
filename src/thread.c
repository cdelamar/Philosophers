#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


	//    int pthread_create(pthread_t *restrict thread,
	//                       const pthread_attr_t *restrict attr,
	//                       void *(*start_routine)(void *),
	//                       void *restrict arg);

	// pthread_create(t1, NULL, ft_world, NULL);

void *ft_hello(void *arg)
{
	int i = 0;

	while (i <= 60)
	{
		printf("this is\n");
		i++;
		usleep(999);
	}
}

void *ft_world(void *arg)
{
	int i = 0;

	while (i <= 60)
	{
		printf("        a test\n");
		i++;
		usleep(999);
	}
}

void *routine_test(void *arg)
{
	int *p_num;
	int i;

	p_num = (int *)arg;
	i = 0;
	while(i < 100000)
	{
		(* p_num)++;
		i++;
	}
	return (NULL);
}

void test_1()
{
	ft_hello(NULL);
	ft_world(NULL);
}


void test_2()
{
	pthread_t t1;
	pthread_t t2;

	if (pthread_create(&t1, NULL, ft_hello, NULL))
		exit(1);
	else
		printf("succeed\n\n");
	if (pthread_create(&t2, NULL, ft_world, NULL))
		exit(1);
	else
		printf("succeed\n\n");
	if (pthread_join(t1, NULL))
		exit(1);
	else
		printf("succeed\n\n");
	if (pthread_join(t2, NULL))
		exit(1);
	else
		printf("succeed\n\n");
}

void test_3()
{
	int *p_num;
	pthread_t t1;
	pthread_t t2;

	int res_t1;
	int res_t2;

	int join_t1;
	int join_t2;

	p_num = malloc(sizeof(int));
	if(p_num == NULL)
		exit(1);
	*p_num = 0;

	res_t1 = pthread_create(&t1, NULL, routine_test, p_num);
	if (res_t1 != 0)
		exit(1);

	res_t2 = pthread_create(&t2, NULL, routine_test, p_num);
	if (res_t2 != 0)
		exit(1);

	join_t1 = pthread_join(t1, NULL);
	if (join_t1 != 0)
		exit(1);
	join_t2 = pthread_join(t2, NULL);
	if (join_t2 != 0)
		exit(1);
	printf("res : %d\n", *p_num);
	printf("res : %d\n", *p_num);
	printf("res : %d\n", *p_num);
	printf("res : %d\n", *p_num);
}

int main()
{
	test_3();
}