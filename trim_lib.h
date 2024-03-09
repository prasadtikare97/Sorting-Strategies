// include guards
#ifndef TRIM_LIB_H
#define TRIM_LIB_H
// header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// global constants
#define MAX_CAPACITY 20
#define EMPTY_VALUE -1
#define SPECIFIER "%d"
#define RANGE_MAX 30
#define RANGE_MIN 15
#define TRIM_BUBBLE_ARRAY 0.25
#define TRIM_INSERTION_ARRAY 0.20
#define TRIM_BUBBLE_LINKED 0.15
#define TRIM_INSERTION_LINKED 0.30
// data types
typedef int dtype;
typedef struct node
{
dtype data;
struct node *next;
}
Node;
// function prototypes

/**
*  initializing the randon values
* no paramaters
* no time complexity
**/
void initializeRandom();
/**
* generating the randon values
*  @param size, to run till max capacity
 *  @param min, to restrict till min value  
 *  @param max to restrict till max value 
*  time complexity O(n)  running till max capacity
**/
dtype* initializeCountiguousList(int size, int min, int max);
/**
* generating the linked list from array values
 *  @param dtype list , for getting the array values from pointer
 *  @param size, to run till max capacity  
*  time complexity O(n) running till max capacity
**/
Node* arrayToLinked(const dtype* list, int size);
/**
* sorting the array via bubble sort and trim from start and end
 *  @param dtype dataList , receives the data as a pointer to contiguous list
 *  @param size, to run till max capacity 
  *  @param percent, for triming at percent
*  time complexity O(n square) 
**/
int trimBubbleArray(dtype *dataList, int size, float percent);
/**
* sorting the array via insertion sort and trim from start and end
 *  @param dtype dataList , receives the data as a pointer to contiguous list
 *  @param size, to run till max capacity 
  *  @param percent, for triming at percent
*  time complexity O(n)  as best case
**/
int trimInsertionArray(dtype *dataList, int size, float percent);
/**
* sorting the LIST via bubble sort and trim from start and end
 *  @param dtype dataList , receives the data as a pointer to contiguous list 
  *  @param percent, for triming at percent
*  time complexity O(n square) 
**/
Node* trimBubbleLinked(Node *dataList, float percent);
/**
* sorting the LIST via insertion sort and trim from start and end
 *  @param dtype dataList , receives the data as a pointer to linked list 
  *  @param percent, for triming at percent
*  time complexity O(n square) 
**/
Node* trimInsertionLinked(Node *dataList, float percent);
/**
* shifting the values from the position to start
 *  @param dtype dataList , receives the data as a pointer to linked list 
  *  @param n_elements, for shifting the values on the n element values
*  time complexity O(n) 
**/
void shiftToBegin(dtype *dataList, int n_elements);
/**
* filling the end garbage values with -1
 *  @param dtype dataList , receives the data as a pointer to linked list 
  *  @param start_position, for starting position till end to fill -1
*  time complexity O(n) from position till max capacity
**/
void fillTheEnd(dtype *dataList, int start_position);
/**
* getting the length of the current linked list
 *  @param dtype dataList , receives the data as a pointer to linked list 
*  time complexity O(n) 
**/
int getLenLinked(Node *dataList);
/**
* to free the list elements nodes from positions
 *  @param dtype dataList , receives the data as a pointer to linked list 
  *  @param n_elements, for deleting the values from the n element values
*  time complexity O(n) 
**/
Node* freeElements(Node *dataList, int n_elements);
/**
* to print the array list
 *  @param dtype list , receives the data as a pointer to linked list 
  *  @param size, for running till max size
*  time complexity O(n) 
**/
void printContiguousList(const dtype* list, int size);
/**
* to print the linked list
 *  @param dtype head , receives the data as a pointer to contiguous list 
  *  @param size, for running till max size
*  time complexity O(n) 
**/
void printLinkedList(Node* head);
/**
* to get the valid character  for repeat
 *  @param no
*  time complexity constant O(1)
**/
char getChoiceYN();
// end TRIM_LIB_H
#endif
