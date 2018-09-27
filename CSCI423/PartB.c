#include <stdio.h>

// include the header file that allows us to use dynamic memory management
#include <stdlib.h>

// predefine the maximum length of a word (i.e., Word_MAX_Length) using preprocessor
// command "#define" 
#define Word_MAX_Length 255				

// define the structure WordFreq, which has a string variable word, an integer variable frequency
// and a struct WordFreq pointer variable next that will be used for linked list
struct WordFreq
{

	int frequency;

	struct WordFreq* next;

} WordFreq;


// define function insert that inserts the parameter into the linked list
void insert(struct WordFreq *);

// define the head pointer of the linked list and initialize it with NULL value
struct WordFreq * head = NULL;

void main(int argc, char * argv[])
{
	FILE *in,*out;
	if (argc!=3)
	{
		printf("Please run as %s [filename][filename]\n", argv[0]);
		return;
	}
		if (!(in = fopen(argv[1], "r")))
	{
		printf("Please run as %s [filename][filename]\n", argv[1]);
		return;
	}
		if (!(out = fopen(argv[2], "w")))
	{
		printf("Please run as %s [filename][filename]\n", argv[2]);
		return;
	}


	// define a FILE pointer variable f	
	FILE *f;

	// try to open file with the file name given in command line argument and assign the
	// returned FILE pointer value to f. If the file cannot be opened, print "File (name) does
	// not exist\n", where (name) is the file name given in command line argument
	if (!(f = fopen(argv[1], "r")))
	{
		printf("File %s does not exist\n", argv[1]);

		return;
	}
	struct WordFreq * node;
	// define a struct WordFreq pointer variable line and dynamically allocate memory space
	// of the size of struct WordFreq to line
	struct WordFreq * line = (struct WordFreq*) malloc(sizeof(struct WordFreq));
	
	// check if the dynamic memory allocation is successful. If not, print "Cannot do dynamic
	// memory management\n"
	if (line==NULL)
	{
		printf("Cannot do dynamic memory management\n");

		return;
	}

	printf("file content in %s:\n", argv[1]);

	// read a line of word and frequency in the file into member variables of line and check if
	// it reaches the end of the file (EOF)
	while (fscanf(in, "%d", &(line->frequency))!= EOF)
	{
		// print the values of member variables word and frequency in variable line
		printf("%d\n", line->frequency);

		// initialize the value of member variable next in variable line by NULL
		line->next = NULL;

		// call function insert to insert line into the linked list
		insert(line);

		// since the memory space pointed by line has been inserted into the linked list, // we need to dynamically allocate some other new memory space to line
		line = (struct WordFreq*) malloc(sizeof(struct WordFreq));

		// again, check if the dynamic memory allocation is successful. If not, print
		// "Cannot do dynamic memory management\n"
		if (line==NULL)
		{
			printf("Cannot do dynamic memory management\n");

			return;
		}
	}

	// remember to free the memory space you've dynamically allocated to variable line
	free(line);
	
	printf("Numbers outputed:\n");

	// traverse the linked list, print out each element and free its space
	// we stop until the value of head is NULL
	while (head!=NULL)
	{
		// detach the first element in the linked list and put it into variable line
		// hint: let variable line point to the first element in the linked list and then move 
		// the head pointer to point the next element in the linked list, which now
		// becomes the first element in the linked list
		line = head;
		head = head->next;

		// print the values of member variables word and frequency in variable line
		printf("%d\n", line->frequency);
		fprintf(out,"%d ", line->frequency);

		// remember to free the memory space you've dynamically allocated to the
		// element just detached from the linked list, which is now pointed by line
		free(line);		
	}

	// remember to close the file pointed by f
	fclose(in);
}

// remember we need to implement function insert
void insert(struct WordFreq * element){

		if(head==NULL) {
    		element->next = head;
			head= element;
			return;
		}
			struct WordFreq * i=head;
			struct WordFreq * j=i->next;
				if(i != NULL && j ==NULL) {
					if(element->frequency < i->frequency) {
			    		element->next =i;
						head=element;
					}
					else{
				    	element->next = NULL;
					    i->next=element;
					}
			}
				for(i; i->next !=NULL; i=i->next) {
			    	if(j!=NULL) {
				        j=i->next;
						    if(element->frequency < i->frequency) {
								element->next=i;
							    head=element;
								return;
						
                        	}
						if(element->frequency <= j->frequency && element->frequency >= i->frequency) {
						    element->next = j;
							i->next=element;
							return;
							}
							
                        else if(j->next==NULL) {
						j->next = element;
						element->next=NULL;
						return;
					}
			}
	}
}

