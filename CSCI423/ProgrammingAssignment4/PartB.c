#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i         = 0;	
int ptsGenerated = 50000000;
int totalInCircle  = 0;
pthread_mutex_t lock;

void *count(void *X)
{ 
    
    for (i=0; i < ptsGenerated; i++)
    {	
	pthread_mutex_lock(&lock);
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (sqrt((X * X) + (Y * Y)) < 1.0)
        {
            totalInCircle++;
        }
	pthread_mutex_unlock(&lock);
    }
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
	printf("Please run as %s <number of threads>\n",argv[0]);
	return 0;
	}
	if(argc > 2){
	printf("Please run as %s <number of threads>\n",argv[0]);
	return 0;
	}
int N=atoi(argv[1]);
	if(N < 0){
	printf("<number of threads> should be a positive integer\n");
	return 0;
	}
    
  	pthread_t thread[N];
	lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	
	for (i=0; i<N; i++){
	pthread_create(&thread[i], NULL, &count, NULL);
	}
	for (i=0; i<N; i++){
    	pthread_join(thread[i], NULL);
	}
    
    double points = 4.0 * totalInCircle;
    double pi = points / ptsGenerated;
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", ptsGenerated, pi);  
    return 0;
}
