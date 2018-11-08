#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int pgen = 50000000;
int total  = 0;

void *count(void *X)
{ 
    
    for (i=0; i < pgen; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (sqrt((X * X) + (Y * Y)) < 1.0)
        {
            total++;
        }
    }
    pthread_exit(0);
}

int main()
{
    
    pthread_t thread;

  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * total;
    double pi = points / pgen;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", pgen, pi);  
    return 0;
}
