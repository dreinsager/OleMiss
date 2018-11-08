#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int ptsGenerated = 50000000;
int totalInCircle  = 0;

void *count(void *X)
{ 
    
    for (i=0; i < ptsGenerated; i++)
    {	
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (sqrt((X * X) + (Y * Y)) < 1.0)
        {
            totalInCircle++;
        }
    }
    pthread_exit(0);
}

int main()
{
    
    pthread_t thread;

  
    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * totalInCircle;
    double pi = points / ptsGenerated;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", ptsGenerated, pi);  
    return 0;
}
