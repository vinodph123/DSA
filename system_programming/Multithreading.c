#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>




int sh=0;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void handler(void *arg)
{
    int tid=*(int *)arg;
    printf("Inside the thread = %d\n",tid);
    pthread_mutex_lock(&lock);
    int i=0;
    for(i=1;i<=100000;i++)
    sh=sh+1;
    pthread_mutex_unlock(&lock);
    //sleep(2);
    
}

int main ()
{
    int i=0;
    pthread_t t[5];

    printf("I am in main function\n");

    for(i=0;i<5;i++)
    {
        pthread_create(&t[i],NULL,(void *)&handler,&t[i]);
    }

    for(i=0;i<5;i++)
    printf("%d\n",t[i]);

    for(i=0;i<5;i++)
    pthread_join(t[i],NULL);

    printf("%d\n",sh);


    return 0;
}