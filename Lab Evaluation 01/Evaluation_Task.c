// Write a C program that uses threads to perform operations on shared variables:

 

// 1.  Create two global variables:

//   initialized to 0

//   initialized to 0

// 2.  Create 3 threads:

//     Thread 1: Adds all of the numbers between 1 to 100 to 100 times

//    Thread 2: Adds all of the numbers between 101 to 200 to 100 times

//    Thread 3: Adds all of the numbers between 201 to 300 to 100 times

// 3.  Use mutex to protect access to both shared variables

// 4.  Each thread prints when it starts and finishes

// 5.  Main thread prints final results:

//   Total sum (should be 45150, which is sum of 1 to 300)   Total count (should be 300)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long total_sum = 0;
int total_count = 0;
pthread_mutex_t lock; //USE TO LOCK THE SHARED VARIABLES    

void* sum_Range(void* arg) //used pointer to pass arrgument
{
    int thread_num = *(int* )arg;
    int start;
    int end;
    if(thread_num ==1)
    {
        start =1;
        end =100;

    }
    else if(thread_num == 2)
    {
        start =101;
        end = 200;
    }
    else{
        start = 201;
        end = 300;
    }
    printf("Thread %d starting (range %d–%d)\n", thread_num, start, end);



    for (int i=0; i<100; i++)
    {
        for(int j=start; j<=end; j++)
        {
            pthread_mutex_lock(&lock); //this line can lock for protect the shared variables
            total_sum +=j;
            total_count++;
            pthread_mutex_unlock(&lock); //in this line unlock the lock after using sharing variables
        }
    }


    printf("Thread %d fininshed\n",thread_num); 
    return NULL;
}
    int main()
    {
        pthread_t t1 , t2, t3;
        int id1=1;
        int id2=2;
        int id3=3;

        pthread_mutex_init(&lock,NULL);//this line can initilized the lock

        pthread_create(&t1,NULL,sum_Range,id1); //this line can create thread 
        pthread_create(&t2,NULL,sum_Range,&id2);
        pthread_create(&t3,NULL,sum_Range,&id3);

        pthread_join(t1,NULL);
       pthread_join(t2,NULL);
       pthread_join(t3,NULL);

       pthread_mutex_destroy(&lock);

       printf("Final total sum %lld\n", total_sum); //show final result

       printf("Final total count %d\n",total_count);//it can show final total count



    }




