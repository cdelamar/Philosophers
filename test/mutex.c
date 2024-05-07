#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// MUTEX : MUTual EXclusion
// free mutex > pthread_mutex_destroy
typedef struct data_s
{
    int nb;
    pthread_mutex_t mutex;
} data_t;

data_t *init_data(void)
{
    data_t *data;

    data = malloc(sizeof(data_t));
    if(data == NULL)
        exit(1);

    data->nb = 0;
    pthread_mutex_init(&data->mutex, NULL);
    return (data);
}

void *routine_test(void *arg)
{
    data_t *data;
    int i = 0;

    data = (data_t *)arg;
    while (i < 251)
    {
        pthread_mutex_lock(&data->mutex);
        (data->nb)++;
        pthread_mutex_unlock(&data->mutex);
        i++;
    }
    return (NULL);
}

void    test()
{
    data_t    *data;
    pthread_t   t1;
    pthread_t   t2;

    data = init_data();

    if (pthread_create(&t1, NULL, routine_test, data))
        exit(1);
    if (pthread_create(&t2, NULL, routine_test, data))
        exit(1);

    if (pthread_join(t1, NULL))
        exit(1);
    if (pthread_join(t2, NULL))
        exit(1);

    printf("Num: %d\n", data->nb);
}

int main()
{
    test();
    return (0);
}