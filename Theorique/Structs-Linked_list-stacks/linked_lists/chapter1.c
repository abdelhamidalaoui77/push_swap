#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/*
    ! A linked list is a linear data structure that includes a series of connected nodes. 
    ! Here, each node stores the data and the address of the next node. For example,
    ?       HEAD ---> [data | next] ---> [data | next] ---> [data | next] ---> NULL
    *                           (Linked list Data Structure)
    You have to start somewhere, so we give the address of the first node a special name 
    called HEAD. Also, the last node in the linked list can be identified because its next 
    portion points to NULL.
    Linked lists can be of multiple types: singly, doubly, and circular linked list. In this article,
    we will focus on the singly linked list. To learn about other types, visit Types of Linked List.


*/
/*
    ! Representation of Linked List
    * Let's see how each node of the linked list is represented. Each node consists:
        ? - A data item (content)
        ? - An address of another node (next)
    * We wrap both the data item and the next node reference in a struct as:
*/

typedef struct node {
    void    *content;
    struct node * next;
} node_t;

int main()
{
    /* Initialize nodes */
    node_t * head = NULL;

    /* Allocate memory */
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    /* Assign data values */
    head->content = (void *)"Abdelhamid";
    head->next = NULL;
    
    node_t  *current1 = malloc(sizeof(node_t));
    
    current1->content = (void *)2001;
    current1->next = NULL;
    
    /* Connect nodes */
    head->next = current1;

    node_t *current2 = malloc(sizeof(node_t));
    
    current2->content =(void *)24;
    current2->next = NULL;
    
    /* Connect nodes */
    current1->next = current2;
    
    node_t *current3 = malloc(sizeof(node_t));
    current3->content = (void *)2025;
    current3->next = NULL;
    
    /* Connect nodes */
    current2->next = current3;
    node_t *ptr = head;
    
    int i = 1;
    while (ptr != NULL)
    {
        if (i == 1)
            printf("content : %s\n",(char *)ptr->content);
        else 
            printf("content : %d\n",(int *)ptr->content);
        i++;
        ptr = ptr->next;
    }
    return 0;
}
/*
    The power of a linked list comes from the ability to break the chain and rejoin it. E.g. if you
    wanted to put an element 4 between 1 and 2, the steps would be:

        + Create a new struct node and allocate memory to it.
        + Add its data value as 4
        + Point its next pointer to the struct node containing 2 as the data value
        + Change the next pointer of "1" to the node we just created.
    Doing something similar in an array would have required shifting the positions of all the
    subsequent elements.


    ! Linked List Utility
    Lists are one of the most popular and efficient data structures, with implementation in every
    programming language like C, C++, Python, Java, and C#.
    Apart from that, linked lists are a great way to learn how pointers work. By practicing how
    to manipulate linked lists, you can prepare yourself to learn more advanced data
    structures like graphs and trees.

    ! Linked List Complexity
    ? Time Complexity

 	Worst       case	Average Case
    Search	    O(n)	O(n)
    Insert	    O(1)	O(1)
    Deletion	O(1)	O(1)

    Space Complexity: O(n)

    ! Linked List Applications
        * Dynamic memory allocation
        * Implemented in stack and queue
        * In undo functionality of softwares
         *Hash tables, Graphs

*/