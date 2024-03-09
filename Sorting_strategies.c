#include "trim_lib.h"


int main(){
	
	// initialize the random number generator
initializeRandom(); //initil
char choice;
do{
	//initializing the array list
	int* array = initializeCountiguousList(MAX_CAPACITY,RANGE_MIN,RANGE_MAX);
	//array ti linked list
	Node* head = arrayToLinked(array,MAX_CAPACITY);
	Node* head1 = arrayToLinked(array,MAX_CAPACITY);

	arrayToLinked(array,MAX_CAPACITY);
	printf("\nInput list: ");
	printContiguousList(array,MAX_CAPACITY);//print the array
	printf("\n");
	
	//printf("\nInput list in Linked: ");
	//printLinkedList(head);
	//calling bubble insertion for array and linked list
	printf("\nTrim for each extremity (%): %0.0f",TRIM_BUBBLE_ARRAY * 100);
	int trimBubbleArrayLength = trimBubbleArray(array,MAX_CAPACITY,TRIM_BUBBLE_ARRAY);
	printf("\nResulting array list (bubble): ");
	printContiguousList(array,trimBubbleArrayLength);
	printf("\n");
	
	printf("\nTrim for each extremity (%): %0.0f",TRIM_INSERTION_ARRAY * 100);
	printf("\nResulting array list (insertion): ");
	int trimInsertionArrayLength = trimInsertionArray(array,MAX_CAPACITY,TRIM_INSERTION_ARRAY);
	printContiguousList(array,trimInsertionArrayLength);
	printf("\n");

	printf("\nTrim for each extremity (%): %0.0f",TRIM_BUBBLE_LINKED * 100);
	printf("\nResulting linked list (bubble):");
	Node* trimBubbleLinked_head = trimBubbleLinked(head,TRIM_BUBBLE_LINKED);
	printLinkedList(trimBubbleLinked_head);
	free(trimBubbleLinked_head);
	printf("\n");

	printf("\nTrim for each extremity (%): %0.0f",TRIM_INSERTION_LINKED * 100);
	printf("\nResulting linked list (insertion):");
	//printf("%d",*head1);
	Node* trimInsertionLinkedHead = trimInsertionLinked(head1,TRIM_INSERTION_LINKED);
	printLinkedList(trimInsertionLinkedHead);
	free(trimInsertionLinkedHead); //free the memory

	choice=getChoiceYN();	
}while(choice=='y');

	
	printf("\nCome back any time!");// exit message

	return 0;
}
