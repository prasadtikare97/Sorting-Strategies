#include "trim_lib.h"

void initializeRandom(){
		//seeding for the random number to get generated at the given time
	srand(time(0)); // Using current time for each execution
	
}

dtype* initializeCountiguousList(int size, int min, int max){
	int* array = (int*)calloc(size,sizeof(int)); // allocating the size for array
	int i;
	for(i=0;i<size;i++){
		//generating random values from 15-30 and storing in the list
		array[i] =rand() % (max-min + 1) + min; 
	}
	return array; // return array
}

Node* arrayToLinked(const dtype* list, int size){
	//defining pointers
	Node* head = NULL;
	Node* current = NULL;
	int i;
	for(i=0;i<size;i++){
		Node* new_node =(Node*)malloc(sizeof(Node)); // creating the new node
		if(head==NULL){ //if head is null or first element
		new_node->data =list[i];
		head = new_node; //head is first node
		current = head;
		}
		else{
			//creating the linked list of nodes
			new_node->data =list[i]; 
			current->next=new_node;
			current=new_node;
			new_node->next=NULL;
		}
	}
	return head;
}

void printContiguousList(const dtype* list, int size){
	int i;
	//printing the list 
	for(i=0;i<MAX_CAPACITY;i++){		
		if(list[i] > -1){
			printf("%d, ",list[i]);
		}
	}
}

void printLinkedList( Node* head){
	Node* current = head;
	//int length=0;
	while (current != NULL)
	{
// print the data values in nodes
	printf("%d", current->data);
	if(current->next != NULL){
		printf(", ");
	}
// move current to the next node
	current = current->next;
	}

}

int trimBubbleArray(dtype *dataList, int size, float percent){
	int j,i,temp; //declaring variables
	for(i=0;i<size;i++){ //running till maxsize
		for(j=0;j<size-1;j++){
			if(dataList[j] > dataList[j+1]){ //if element 1 is greater
				//swap the elements
			temp =dataList[j];
			dataList[j] = dataList[j+1];
			dataList[j+1]=temp;
		}
		}
	}
	int n_elements=size * percent;//calculate percent
	shiftToBegin(dataList,n_elements); // calculate shift to begin
	int end_minus_position=size - (n_elements * 2); // for last element to delete
	fillTheEnd(dataList,end_minus_position); //calling function
	int wanted_data=0;
		for(i=0;i<MAX_CAPACITY;i++){
		if(dataList[i] != -1){
			wanted_data++; //getting the size of the linked list
		}
	}
	return wanted_data;

}

int trimInsertionArray(dtype *dataList, int size, float percent){
	int j,i,temp;
	for(i=0;i<size;i++){//running till maxsize
		temp=dataList[i];	//adding the temp varibale
		j=i-1;
		while(j>=0 && dataList[j] > temp){ //check if value is greater
			dataList[j+1]=dataList[j];//adding the elements sorted right side
			j--;
		}
		dataList[j+1]= temp; //adding the value at last
	}
	int n_elements=size * percent;//calculate percent
	shiftToBegin(dataList,n_elements);// calculate shift to begin
	int end_minus_position=size - n_elements;// for last element to delete
	fillTheEnd(dataList,end_minus_position); //calling function
	
	int wanted_data=0;
		for(i=0;i<MAX_CAPACITY;i++){
		if(dataList[i] != -1){
			wanted_data++;//getting the size of the linked list
		}
	}
	return wanted_data;

}

void shiftToBegin(dtype *dataList, int n_elements){
	int i;
	//shifting the elements to first
	for(i=0;i<MAX_CAPACITY;i++)
	{
	dataList[i] = dataList[n_elements];
	n_elements++;
	}
}

void fillTheEnd(dtype *dataList, int start_position){
	int i;
	//adding the last garbage elements as -1
	for(i=start_position;i<MAX_CAPACITY;i++){
		dataList[i] = -1;
	}
}

Node* trimBubbleLinked(Node *dataList, float percent){
	Node* head = dataList;
	Node* current2 = head;
	int size=0;
	//running till node is null
	while (current2 != NULL)
	{
	// print the data values
	size++;
	// move current to the next node
	current2 = current2->next;
	}
	int swapped;
	do {
		//swapping the nodes in linked list if value is greater than previous
        swapped = 0;
        Node* current = head;
	while(current->next != NULL){
	if(current->data > current->next->data){
		int temp=current->data;
		current->data=current->next->data;
		current->next->data=temp;
		swapped=1;
	}
	current=current->next;
}
}while(swapped);
//printf("\n size %d ",size);
	int n_elements=size * percent;//calculate percent

head=freeElements(dataList,n_elements);//calling function  to free elements
//freeElements(dataList,n_elements);
return head;
}

Node* trimInsertionLinked(Node *dataList, float percent){
	//declaing pointers
Node* sorted = NULL;
   Node* head = dataList;
  Node* current = head;
  while (current != NULL) {

    // Store next node
    Node* next = current->next;
    
    // Insert current in sorted list
    if (sorted == NULL || current->data <= sorted->data) {
      current->next = sorted;
      sorted = current;
    } else {
      Node* search = sorted;
      //check the search
      while (search->next != NULL && 
             current->data > search->next->data) {
        search = search->next;
      }
      current->next = search->next;
      search->next = current;
    }
    
    // Move to next node in original list
    current = next;
  }
  Node* trim_sort= sorted;
  	int n_elements=MAX_CAPACITY * percent;//calculate percent
	trim_sort = freeElements(dataList,n_elements);//calling function to free elements
  return trim_sort;
	
}



Node* freeElements(Node *dataList, int n_elements){
	Node* current1 = dataList;
	int total=MAX_CAPACITY;
	Node* head = dataList;
//	printf("\nn_elements %d ",n_elements);
	total=total-n_elements-n_elements;
	//printf("\ntotal %d ",total);
	//deleting the elements ofrom start
	while (n_elements > 0 && current1 != NULL) {
     Node* next = current1->next;
    free(current1);
    current1 = next;
    n_elements--;

}

// Update the head after removing the elements
head = current1;

	//deleteing the elements from end
	int count=1;
	Node* current2 = head;
	while(current2->next !=NULL){
		current2=current2->next;
		count++;
		if(count==total){
			current2->next=NULL;
		}
	}
	return head;
}



char getChoiceYN(){
	//get choice
	char playAgain;
	printf("\nRepeat [y|n]?:");
	  playAgain =getchar();
	  playAgain = tolower(playAgain);
	  int number =0;
        if(playAgain == 'y' || playAgain == 'n') // if any other input other than y and n
        {
        	number=0;
		}
  else{
  	while (playAgain != 'y' && playAgain != 'n') {
    printf("Invalid option. Please use 'y' for 'yes' or 'n' for 'no':"); //print invalid msg
    playAgain =getchar();
    playAgain = tolower(playAgain); 
    number=1;
  }

}
  return playAgain;
}

