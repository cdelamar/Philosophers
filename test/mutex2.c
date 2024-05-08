#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct data_s {
    int nb;
    pthread_mutex_t mutex;
} data_t;

data_t *init_data(void) {
    data_t *data = malloc(sizeof(data_t));
    if (data == NULL)
        exit(1);
    data->nb = 0;
    pthread_mutex_init(&data->mutex, NULL);
    return data;
}

void *routine_test(void *arg) {
    data_t *data = (data_t *)arg;
    int i = 0;
    while (i < 5) {
        pthread_mutex_lock(&data->mutex);
        printf("Thread %lu: Locked mutex\n", pthread_self());
        (data->nb)++;
        printf("Thread %lu: Incremented nb to %d\n", pthread_self(), data->nb);
        pthread_mutex_unlock(&data->mutex);
        printf("Thread %lu: Unlocked mutex\n", pthread_self());
        i++;
    }
    return NULL;
}

void test() {
    data_t *data = init_data();
    pthread_t t1, t2;
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

int main() {
    test();
    return 0;
}
