
#include "search_lib.h"


void getData(const char* fileName, List* dataList)
{
	//initializing variables
	int length=0;
	char line[1024];
	//file pointer to open and read file
	FILE* file1 = fopen(fileName,"r");
	if(file1 == NULL)
	{
		printf("No such file or directory");
		return;
	}
else
{
//get the data ffrom the file
	while(fgets(line, sizeof(line), file1))
	{
		long int file_data = atof(line);
	Node* new_node =(Node*)malloc(sizeof(Node)); // creating the new node
	new_node->data =file_data; // creating the newnode and data from csv file 
	new_node->index = length;
	
		if(dataList->head == NULL)
		{ //if head is null or first element	
		dataList->head = new_node; //head is first node
		dataList->tail = new_node;
		
		}
		else
		{
			//creating the linked list of nodes
			new_node->data =file_data; 
			dataList->tail->next=new_node;
			dataList->tail=new_node;
			new_node->next=NULL;
			new_node->index = length;
		}
		length++;
	}
	dataList->length=length;

	fclose(file1);//close the file
	}
	//printf("%d",length);
	//	printLinkedList(dataList);

}

void saveData(const char* fileName, List* dataList)
{
	//set the data from the file
	FILE* file2 = fopen(fileName,"w");
	int i;
	Node* current = dataList->head;
	for(i=0;i<dataList->length;i++)
	{
		fprintf(file2,"%ld\n",current->data); //writing the data to file
		current=current->next;
	}	
	fflush(file2); //flushing all the data
	fclose(file2); //close the file
}

Node* mergeSort(Node* head, int length)
{
  if(length <= 1)
  {
  	return head; //if no data then return head
   } 
//printf("\n%d",length);
int mid_length= length/2; // calculate middle length
Node* mid = head;
int i;
for(i=0;i<mid_length -1;i++)
{
	mid=mid->next;// finding middle node
}


  // Splitting the list
  Node *left = head;
  Node *right = mid->next;
  mid->next=NULL;

  // Recursive calling for dividing the nodes
  left = mergeSort(left, mid_length); 
  right = mergeSort(right, length - mid_length);

  // Merging the divided data 
  return merge(left, right);
}


Node* merge(Node* left, Node* right)
{
	 Node result;
	 result.next = NULL;

  // Pointer to traverse result list
  Node* tail = &result; 
  
  // Traverse both left and right lists
  while(left != NULL && right != NULL) {
    if(left->data <= right->data) {
      // Assigning the tail to left 
      tail->next = left;
      left = left->next;
    }
    else {
      // Assigning the tail to right node
      tail->next = right;
      right = right->next;
    }

    // send the tail node forward
    tail = tail->next;
  }

  // checking the remaining nodes  to append
 tail->next= (left != NULL) ? left : right;

  return result.next;
}

void sortData(const char* fileName, List* dataList)
{
	int length = dataList->length; 

	//calling the merger sort to get sorted data
	dataList->head = mergeSort(dataList->head,length);
	//declaring nodes
		Node* current = dataList->head;
		int count=0;
		//getting the current index for node
	while(current != NULL)
	{
		current->index= count++;
		current=current->next;
	}
// Initialize a tailfinder node to the start node
    Node *tail_finder = dataList->head;
    // Traverse the sorted list to find the last element
    while (tail_finder->next != NULL)
    {
        tail_finder = tail_finder->next;
    }
	dataList->tail = tail_finder;
		
	//printf("\nThe sorted data is stored in the sortedData.csv.");
}

Node* binarySearch(List *dataList, dtype element) {
   // Initialize pointers for binary search
    int left = 0;
    int right = dataList->length - 1;
    // Initialize a pointer
    Node *firstOccurrence = NULL;
    //search until the left is less than right 
    while (left <= right)
    {
        // Calculate the middle index
        int middle = left + (right - left) / 2;
        // Initialize a pointer 
        Node *currentElementNode = dataList->head;
        // getting the middle element
        int i;
        for ( i = 0; i < middle; i++)
        {
            currentElementNode = currentElementNode->next;
        }
        // Check if the data equals element
        if (currentElementNode->data == element)
        {
            // Update the first occurrence pointer and adjust the right pointer
            firstOccurrence = currentElementNode;
            right = middle - 1;
        }
        else if (currentElementNode->data < element)
        {
            // Adjust the left pointer to search in the left half
            left = middle + 1;
        }
        else
        {
            // Adjust the right pointer to search in the right half
            right = middle - 1;
        }
    }
    // Return the pointer 
    return firstOccurrence;
}

int getFirstOccurrence(dtype element, List *dataList)
{
	//search first element in binary search
	Node* first_searched_element = binarySearch(dataList,element);
	if(first_searched_element == NULL)
	{
		return NOT_FOUND; // return -1
	}
	else
	{
		int position=first_searched_element->index;//get the index
		while(position >0)
		{
			Node* first_occurrence = dataList->head;
			int i;
			for ( i = 0; i < position -1; i++)
	        {
	            first_occurrence = first_occurrence->next; //to get the first element node
	        }
	        if(first_occurrence->data == element)
	        {
	        	position = first_occurrence->index;//assigning the index of that position
			}
			else
			{
				return position + 1; //return position
			}
		}
	return position + 1;	
	}	
}

int getLastOccurrence(dtype element, List *dataList)
{
	//initzlizing variable
	Node* current = dataList->head;
	int first_count=current->index;//getting first index
	int second_count=first_count;
	while (current != NULL)
	{
// getting the data values in nodes
	first_count++;
	if(current->data == element)
	{
		//if first element is found search for next element
		second_count = current->index;
		second_count++;
	}
	current= current->next;//getting next nodes

}
	return second_count;
}

Node* getAllOccurrences(dtype element, List *dataList, int *count)
{
	//initzlizing variable
	Node* currentNode = dataList->head;
	Node* current = NULL;
	int currentcount=0;
	while(currentNode != NULL)
	{
		//if element is found
		if(currentNode->data == element)
		{
			Node* all_occurrence =(Node*)malloc(sizeof(Node)); //creating the new node
			all_occurrence->data = currentNode->data; //assigning the data
			all_occurrence->index = currentNode->index;
			all_occurrence->next=currentNode->next;	
			all_occurrence->next=NULL;
			if(current == NULL)
			{
				current=all_occurrence;//assigning the nodes
			}
			else
			{
				//creating the nodes for all the occurrences
				Node* next_node=current;
				while(next_node->next != NULL)
				{
				next_node=next_node->next;
				}
				next_node->next=all_occurrence;
			}
			currentcount++;
		}	
		currentNode=currentNode->next;
	}
	*count = currentcount;//assigning the count with dthe data counts
return current;
}

char getChoiceYN()
{
	//declaring a variable 
	char choice;
    char lowerChoice;
    while (1) 
	{
    	//initializing
        scanf(" %c", &choice);
        //making it lower case
        lowerChoice = tolower(choice);
	//checking if it has yes or no
        if (lowerChoice == 'y' || lowerChoice == 'n') {
            return lowerChoice;
        } else {
            printf("Invalid option. Please type 'y' to restart or 'n' to exit:\n");
        }
    }
}

void printLinkedList(List *dataList)
{
	
	Node* current = dataList->head;
	//int length=0;
	while (current != NULL)
	{
// print the data values in nodes
	printf("%ld", current->data);
	if(current->next != NULL){
		printf(", ");
	}
// move current to the next node
	current = current->next;
	}

}

