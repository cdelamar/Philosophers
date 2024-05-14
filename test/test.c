#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>


#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N


// TODO
/*
preparing custom usleep function
focus on race condition solution 
*/



int state[N];
int phil[N] = {0, 1, 2, 3, 4};


sem_t mutex;
sem_t S[N];


void test(int phnum)
{
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[phnum] = EATING;
        //sleep(2);

        printf("Philosopher %d takes fork %d and %d\n", phnum, LEFT, RIGHT);
        printf("Philosopher %d is Eating\n", phnum);
        sem_post(&S[phnum]);
    }
}


void take_fork(int phnum)

{

    sem_wait(&mutex);


    state[phnum] = HUNGRY;


    printf("Philosopher %d is Hungry\n", phnum);


    test(phnum);


    sem_post(&mutex);


    sem_wait(&S[phnum]);


    //sleep(1);

}


void put_fork(int phnum)

{

    sem_wait(&mutex);


    state[phnum] = THINKING;


    printf("Philosopher %d putting fork %d and %d down\n", phnum, LEFT, RIGHT);

    printf("Philosopher %d is thinking\n", phnum);


    test(LEFT);

    test(RIGHT);


    sem_post(&mutex);

}


void* philospher(void* num)

{

    while (1)

    {

        int* i = num;


        //sleep(1);


        take_fork(*i);


        //sleep(0);


        put_fork(*i);

    }

}


#include <semaphore.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *routine (void *arg)
{
    int *test = (int *)arg;
    printf("ok\n");
    return NULL;
}

int main()
{
    pthread_t thid;
    int i = 1;

    int create = pthread_create(&thid, NULL, routine, (void *)&i);
    printf("create\n");
    int join = pthread_join(thid, NULL);
    printf("join\n");
    return 0;
}
