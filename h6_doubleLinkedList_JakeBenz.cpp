  /*
====================================================================================
Course: Harper CSC211-248 by Mr. Jin Guo, Summer 2019
Student Name: <Your Name>

Program Name: Double-linked List
Program Description:
	This assignment is for you to learn data structure of Double-linked List. 

Instructions: 
	1. First, understand, compile and run h6_doubleLinkedList. Don't change 
		anything.
	2. Run h6_JG.out on Unix. When you are done, the output of your 
		program should be the same as this one does.
	3. You are asked to define two functions. Finish code wherever is indicated
		"Your code below".
	4. Refer to "Chapter10 Strucures and List Processing" of the C textbook.
	5. Submit only your .cpp file with your login as usual.  

Created: 	7/25/2019 by Jin Guo.
=====================================================================================
*/
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

typedef int Data;

struct Node
{
    Data value;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;

struct DoubleLink
{
    Node* head;
    Node* tail;
};
typedef struct DoubleLink DoubleLink;

void fillLinkData(DoubleLink* link, const Data* ptr, int size);
int sizeOfLink(const DoubleLink* link);
void printLink(const DoubleLink* link);
int deleteElem(DoubleLink* link, int value);
void insertElemBack(DoubleLink* link, int value);
void deleteLink(DoubleLink* link);


int main()
{
    printf("==========================================================\n");
    printf("Harper CSC211-248 by Mr. Jin Guo: Program #6, Summer 2019\n");
    printf("Student: <Jake Benz>\n\n");
    printf("This program implements double-linked list.\n");
    printf("==========================================================\n\n");
    
    int A[] = {11, 22, 33, 44, 55};
    printf("==> The original data in int array:\nA: ");
    for (int i = 0; i < 5; ++i)
        printf("%d ", A[i]);
    
    printf("\n\n==> Creat a inked list for the above array...\n\n");
    DoubleLink myLink;
    fillLinkData(&myLink, A, 5);
    
    printf("==> myLink has %d elements as follows:\n\n", sizeOfLink(&myLink));
    printLink(&myLink);
    
    int k;
    printf("==> Please input the value for deletion: ");
    scanf("%d", &k);
    if (deleteElem(&myLink, k) < 0)
        printf("Value %d not found!\n", k);
    else
        printf("The node with value %d is deleted!\n", k);
    
    printf("\n==> After the deletion, the link's data: \n");
    printLink(&myLink);
    
    printf("============= Testing of My Added code =============\n\n");
    
    printf("==> Input a value for a new node to add to the link:  ");
    scanf("%d", &k);
    insertElemBack(&myLink, k);
    printf("\n==> After adding the new node, the link's data: \n");
    printLink(&myLink);
     
    printf("==> After delete the whole link...\n");
    deleteLink(&myLink);
    printf("myLink has %d elements.\n\n", sizeOfLink(&myLink));
    
    return 0;
}

void fillLinkData(DoubleLink* link, const Data* A, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = A[i];
        
        if (i == 0) // first node
        {
            link->head = link->tail = newNode;
            newNode->prev = newNode->next = NULL;
            continue;
        }
        
        newNode->prev = link->tail;
        newNode->next = NULL;
        link->tail->next = newNode;
        link->tail = newNode;
    }
}

int sizeOfLink(const DoubleLink* link)
{
    int size = 0;
    Node* tmp = link->head;
    
    while (tmp)
    {
        ++size;
        tmp = tmp->next;
    }
    
    return size;
}

void printLink(const DoubleLink* link)
{
    Node* tmp = link->head;
    for (int i = 0; tmp != NULL; ++i)
    {
        printf("Elem_%-2i: %d\n", i, tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int deleteElem(DoubleLink* link, int key)
{
    Node* current = link->head;
    
    while (current)
    {
        if (current->value == key)
            break;
        
        current = current->next;
    }
    
    if (current == NULL) // key is not found
        return -1;
    
    if (link->tail == current && link->head == current)
    {
        link->tail = link->head = NULL;
    }
    else if (link->tail == current)
    {
        current->prev->next = NULL;
        link->tail = current->prev;
    }
    else if (link->head == current)
    {
        current->next->prev = NULL;
        link->head = current->next;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    free(current);
    return 1;
}

void insertElemBack(DoubleLink* link, int value)
{
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> value = value;
    
    if (link->head == NULL & link-> tail == NULL)
    {
        link-> head = link -> tail = newNode;
        newNode -> next = newNode -> prev = NULL;
        return;
    }
    newNode -> next = NULL;
    newNode -> prev = link-> tail;
    link -> tail -> next = newNode;
}

 void deleteLink(DoubleLink* link)
{
    Node* current = link -> head;
    Node* tempNode;

    while (current)
    {
        tempNode = current;
        current = current -> next;
        free(tempNode);
    }
    link -> head = link -> tail = NULL;
}