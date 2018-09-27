#include <stdio.h>

// include the header file that allows us to use dynamic memory management
#include <stdlib.h>

// predefine the maximum length of a word (i.e., Word_MAX_Length) using preprocessor
// command "#define" 
#define word_MAX_Length 255

// define the structure WordFreq, which has a string variable word, an integer variable frequency
struct WordFreq
{
	int frequency;






} WordFreq;


void main(int argc, char * argv[])
{
	if (argc!=2)
	{
		printf("Please run as %s [filename]\n", argv[0]);
		return;
	}

	// define a FILE pointer variable f	
	FILE *f;
    

	// try to open file with the file name given in command line argument and assign the
	// returned FILE pointer value to f. If the file cannot be opened, print "File (name) does
	// not exist\n", where (name) is the file name given in command line argument
	if ((f=fopen(argv[1],"r"))	== NULL	)
	{
		printf("FILE %s does not exist\n", argv[1]);						

		return;
	}

	// define a struct WordFreq pointer variable line and dynamically allocate memory space
	// of the size of struct WordFreq to line
	struct WordFreq *line;
    line = malloc(sizeof(struct WordFreq));
	
		

	// check if the dynamic memory allocation is successful. If not, print "Cannot do dynamic
	// memory management\n"
	if (line == NULL)
	{
		printf("Cannot do dynamic memory management\n");

		return;
	}

	printf("file content in %s:\n", argv[1]);

	// read a line of word and frequency in the file into member variables of line and check if
	// it reaches the end of the file (EOF)
	while ((fscanf(f, "%d", &line->frequency)) != EOF)
	{
		// print the values of member variables word and frequency in variable line
		printf("%d\n", line->frequency);
	}

	// remember to free the memory space you've dynamically allocated to variable line
	free(line);


	// remember to close the file pointed by f
	fclose(f);

}

