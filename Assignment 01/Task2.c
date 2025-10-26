//Personalized Greeting Thread 
//Ahmad Fawad
//1129

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *greating(void *arg)
{
    char *name =(char*)arg;
    printf("First Thread says : Salam,%s Welcome to new world (order) threads\n" ,name);
    free(name);
    return NULL;

}

int main()
{
  pthread_t tid;
  char *name =strdup("Ahmad Fawad");
  printf("Main Thread : WAting for salam  \n");
  pthread_create(&tid , NULL,greating,name);
pthread_join(tid, NULL);
printf("Main thread: Greating compleated");
return 0;
}