// inclusion guards
#ifndef SEARCH_LIB_H
#define SEARCH_LIB_H

// header files
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type

// global constants
#define LENGTH 10
#define NOT_FOUND -1
#define SPECIFIER "%ld"
#define RANGE_MAX 3
#define RANGE_MIN 1
#define EMPTY_VALUE 0

// data type definition
typedef long int dtype;

typedef struct node
{
  // position to store the element
  dtype data;
  // index
  int index;
  // a pointer to the next struct node
  struct node* next;
} Node;
//definmg list
typedef struct list
{
    Node *head;
    Node *tail;
    int length;
}
List;

// function prototypes

/**
* @brief getting the choice if it is yes or no 
* The time complexity is O(1)>
**/
char getChoiceYN();

/**
* to get the data from file and read it as linked list
* <Write a longer description for the function if needed>
* The time complexity  is <O(1)>
* @param file name as character
* @param List as list
**/
void getData(const char* fileName, List *dataList);
/**
* to saving the nodes data and write  in file
* The time complexity  is <O(1)>
* @param file name as character
* @param List as list
**/
void saveData(const char* fileName, List* dataList);
/**
* to divide the data using merge sort
* The time complexity  is <O(logn)>
* @param node as head first node 
* @param List as list
**/
Node* mergeSort(Node* head, int length);
/**
* to get the divided  data and merge is as sorted data
* The time complexity  is <O(logn)>
* @param node as  first node as left side
* @param node as  middle node as right side
**/
Node* merge(Node* left, Node* right);
/**
* to sorting the data using merger sort
* The time complexity  is <O(1)>
* @param file name as character
* @param List as list
**/
void sortData(const char* fileName, List* dataList);
/**
* to ssearching the element using binary search
* The time complexity  is <O(logn)>
* @param List as list
* @param element to find
**/
Node* binarySearch(List *dataList, dtype element);
/**
* to ssearching the first time the element occurred using linear search
* The time complexity  is <O(logn)>
* @param List as list
* @param element to find
**/
int getFirstOccurrence(dtype element, List *dataList);
/**
* to ssearching the last time the element occurred using linear search
* The time complexity  is <O(1)>
* @param List as list
* @param element to find
**/
int getLastOccurrence(dtype element, List *dataList);
/**
* to ssearching the total number of time the element occurred 
* The time complexity  is <O(1)>
* @param List as list
* @param element to find
* @param count the number of time
**/
Node* getAllOccurrences(dtype element, List *dataList, int *count);
/**
* to print the data of linked list 
* The time complexity  is <O(1)>
* @param List as list

**/
void printLinkedList(List *dataList);

// end SEARCH_LIB
#endif
