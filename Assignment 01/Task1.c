//Thread Information Display
//Name: Ahmad Fawad
// RegNo: 1129

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    int *num = (int*)arg;
    int id = *num;
    pthread_t tid = pthread_self();
    
    printf("Tread %d: pthread_self() =%lu\n",id ,(unsigned long)tid);

    int sleep_time = (rand() %3)+1;
    printf("Thread %d : sleeping %d sec\n",id ,sleep_time);
    sleep(sleep_time);
    printf("Thread %d : is compleadted\n",id);
    free(arg);
    return NULL;

}

int main()
{
    pthread_t threads[5];
    for (int i =0; i<5;i++)
    {
        int  *arg = malloc(sizeof(int));
        *arg = i +1 ;
        pthread_create(&threads[i] , NULL,thread_function,arg);
        
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(threads[i],NULL);
    }
    printf("Main thread : All Threads joined \n");
    return 0;
    
}