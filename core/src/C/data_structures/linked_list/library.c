#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define int MAX 100

typedef int ITEM;

// Node Struct
typedef struct NODE{
    struct NODE *next;
    ITEM item;
}NODE;

// Linked List Struct
typedef struct LINKED_LIST{
    struct NODE *head;
    int length;
}LINKED_LIST;

// Initialize a linked list
void initialize(LINKED_LIST *list){
    list->head = NULL;
    list->length = 0;
}

// Checks if a list is empty
bool empty(LINKED_LIST *list){
    return list->length == 0;
}

// Gets an item and a pointer and returns a pointer to a node
NODE *createNode(ITEM i, NODE* next){
    // Allocate memory space
    NODE * newNode = (NODE*)malloc(sizeof(NODE));
    
    // Validation and error handling section
    if(newNode == NULL){
        printf("Error! Wasn´t posible to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Assign values to node and return pointer to node
    newNode->item = i;
    newNode->next = next;
    return newNode;
}

// Gets an item and a linked list and insert a new node on head
bool insertNode(ITEM i, LINKED_LIST *list){
    // Create a new node
    NODE *newNode = createNode(i, list->head);

    // Validation section
    if(list->length == MAX)
        return false;
    
    if(newNode == NULL)
        return false;
    // End of validation section
    
    // Insertion on head and update list
    list->head = newNode;
    list->length++;
    
    return true;
}