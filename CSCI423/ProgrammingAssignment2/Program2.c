#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char * argv[])
{

	if(argc != 2){
        
        fprintf(stderr , "Usage: ./a.out <starting value>\n");
        
        return -1;
    }
    int num = atoi(argv[1]);
        if(num <= 0 ){
            fprintf(stderr, "<starting value> should be a positive integer\n");
            return -1;
        }
	
	pid_t pid;
        
        pid = fork();

		if (pid == 0)
		{
			
			printf("%d, ",num);
			while (num != 1)
			{
				if (num %2 == 0)
				{
					num = num / 2;
				}
				else if (num % 2 == 1)
				{
					num = 3 * (num) + 1;
				}	
			
				printf("%d, ",num);
			}
		
			printf("\n");
		}
		else
		{
			wait();
		}
	return 0; 
}