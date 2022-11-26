#include <stdio.h>
#include "pthread.h"
void *sample()
{
    printf("tessst\n");
}
void main()
{
pthread_t  tid;
pthread_create(&tid, NULL, &sample, NULL);
pthread_join(tid, NULL);
}