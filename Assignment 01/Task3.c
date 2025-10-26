//Number Info Thread 
//Ahmad Fawad
//1129

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *num_info(void *arg)
{
    int num = *(int*)arg;
    printf("Thread : Number =%d\n",num);
    printf("Thread : Squre =%d\n",num*num);
    printf("Thread : Cube =%d\n",num*num*num);
    free(arg);
    return 0;
}
int main()
{
    pthread_t tid;
    int *num =malloc(sizeof(int));
    printf("Enter integer number:");
   scanf("%d", num);
   pthread_create(&tid, NULL, num_info, num);
    pthread_join(tid,NULL);
    printf("Main thread: Work completed.\n");
    return 0;
}