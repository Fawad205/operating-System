//Ahmad Fawad
//1129
//Struct‑Based Thread Communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


int dean_count = 0;
typedef struct {
    int student_id;
    char name[50];
    float gpa;
}student;

void *student_thread(void *arg)
{
    student *s =(student*)arg;
    printf("Students Id: %d,Name : %s, GPA: %.2f\n",s->student_id,s->name,s->gpa);
    if(s->gpa >= 3.5f)
    {
        printf("%s made the Dean's List.\n", s->name);
        dean_count++;
    }
    else{
        printf("%s did not make the Dean's List.\n", s->name);

    }
    return NULL;
}

int main()
{
    pthread_t tid[3];
    student *s1 = malloc(sizeof(student));
    student *s2 = malloc(sizeof(student));
    student *s3 = malloc(sizeof(student));

    s1->student_id = 101; strcpy(s1->name, "Dawar"); s1->gpa = 3.5f;
    s2->student_id = 102; strcpy(s2->name, "Fawad");  s2->gpa = 3.1f;
    s3->student_id = 103; strcpy(s3->name, "Ibrahim"); s3->gpa = 3.7f;

    pthread_create(&tid[0], NULL, student_thread, s1);
    pthread_create(&tid[1], NULL, student_thread, s2);
    pthread_create(&tid[2], NULL, student_thread, s3);

     for (int i = 0; i < 3; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Dean Count: %d \nMain thread: Completed.\n",dean_count);

    free(s1); 
    free(s2); 
    free(s3);
    return 0;
}