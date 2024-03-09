#include "search_lib.h"

//global constants for files input output
const char* INPUT_FILE = "myData_CS500.csv";
const char* OUTPUT_FILE = "sorted_data.csv";

int main()
{
	//declaring variables
	srand(time(NULL));
	List datalist;
	datalist.head=NULL;
	datalist.tail = NULL;
	datalist.length=0;
	
	char choice='y';
	getData(INPUT_FILE,&datalist);
	sortData(OUTPUT_FILE,&datalist);
	saveData(OUTPUT_FILE,&datalist);
	do
	{
		// Generating random number
		int  random_target_element = rand() % (2000-0 + 1) + 0;
		printf("\nSearching for %d:",random_target_element);/// Printing random element
//getting first occurrence
	int first_occurrence =getFirstOccurrence(random_target_element,&datalist);
	if (first_occurrence != NOT_FOUND)
    {
	printf("\nFirst Occurrence: %d",first_occurrence);
	//getting last occurrence
	int last_occurrence = getLastOccurrence(random_target_element,&datalist);
	printf("\nLast Occurrence: %d",last_occurrence);
		int count=0;
		//getting all occurrence
	Node* All_occurrence = getAllOccurrences(random_target_element,&datalist,&count);
		if (All_occurrence != NULL)
        {
                printf("\nAll Occurrences: ");
                while (All_occurrence != NULL)
                {
                    printf("%d", All_occurrence->index + 1);
                    if (All_occurrence->next != NULL)
                    {
                        printf(", ");
                    }
                    All_occurrence = All_occurrence->next;
                }
                // Printing total number of time the of all occurrence of element 
                printf("\nTotal Occurrences: %d\n", count);
        }
        free(All_occurrence);//freeing the memory
    }
    else
    {
        // Print below message if element is not found
    	printf("\nValue not found!\n");
       }
//check if user want to search again
	printf("\nDo you want to simulate the search again [y|n]? ");
		// Read the choice
		//call get choice function
		choice = getChoiceYN();
	}while(choice=='y');
	//end message
		printf("\nThanks for searching. Come back if needed!");
// end the program
printf("\nProgram ended.\n");
	return 0;
}
