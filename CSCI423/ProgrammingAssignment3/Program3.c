
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *avg_func(void *str);
void *min_func(void *ptr);
void *max_func(void *ptr);

double avg;
int min;
int max;

typedef struct datastruct
{
    int size;
    int * values;
}datastruct;

int main(int argc, char *argv[])
{
    while(argc <=1)
    {
        printf("Usage: ./a.out <at least one integer as input>\n");
        exit(0);
	}

    int i = 0;
    int copy[argc-1];
    for(i; i < (argc -1); i++)
    {
        copy[i] = atoi(argv[i+1]);
    }

    pthread_t thread1, thread2, thread3;
    const char *message1 = "This is Thread 1";
    const char *message2 = "This is Thread 2";
    const char *message3 = "This is Thread 3";
    int  Thread1, Thread2, Thread3;

    datastruct ds = {argc - 1, copy};


    Thread1 = pthread_create(&thread1, NULL, (void *) avg_func, (void *) &ds);
    if(Thread1)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n", Thread1);
        exit(EXIT_FAILURE);
    }

    Thread2 = pthread_create(&thread2, NULL, (void *) min_func, (void *) &ds);
    if(Thread2)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n",Thread2);
        exit(EXIT_FAILURE);
    }

    Thread3 = pthread_create(&thread3, NULL, (void *) max_func, (void *) &ds);
    if(Thread3)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n", Thread3);
        exit(EXIT_FAILURE);
    }



  

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("The average value is:  %g\n", avg);
    printf("The minimum value is:  %d\n", min);
    printf("The maximum value is:  %d\n", max);

    exit(EXIT_SUCCESS);
}

void *avg_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    for(i = 0; i < sz; i++)
    {
        avg += (copy->values[i]);
    }
    avg = (int)(avg / sz);
}

void *min_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    min = (copy->values[0]);
    for(i = 1; i < sz; i++)
    {
        if(min > (copy->values[i]))
        {
            min = (copy->values[i]);
        }
    }
}

void *max_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    max = copy->values[0];

    for(i = 1; i < sz; i++)
    {
        if(max < copy->values[i])
        {
            max = copy->values[i];
        }
    }
}
