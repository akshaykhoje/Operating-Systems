#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void init(ll *rootptr)
{
    // initialize the pointer to NULL
    *rootptr = NULL;
}

void create(ll *rootptr, int x)
{
    // check if root is NULL, create a node(allocate space); initialize value.
    if (*rootptr == NULL)
    {
        ll nn = (ll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create node!\n");
            return;
        }
        nn->data = x;
        nn->next = NULL;
        *rootptr = nn;
        printf("data : %d\n", (*rootptr)->data);
    }
    else
    {
        ll temp = *rootptr;
        while (temp->next)
        {
            temp = temp->next;
        }
        ll nn = (ll)malloc(sizeof(Node));
        nn->data = x;
        nn->next = NULL;
        temp->next = nn;
    }
    return;
}

void delNode(ll *rootptr, int n)
{
    if (*rootptr == NULL)
    {
        printf("List Empty...\n");
        return;
    }
    else if ((*rootptr)->data == n)
    {
        ll temp = *rootptr;
        *rootptr = (*rootptr)->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        ll temp = *rootptr;
        ll back = NULL;
        while (temp->data != n)
        {
            back = temp;
            temp = temp->next;
        }
        back->next = temp->next;
        temp->next = NULL;
        free(temp);
        return;
    }
}

void display(ll rootptr)
{
    ll temp = rootptr;
    if (!temp)
    {
        printf("List empty!!!");
    }
    else
    {
        printf("Displaying the linked list...\n");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\n");
    return;
}

ll search(ll rootptr, int n) {
    if(rootptr == NULL){
        printf("List Empty!!!\n");
        return NULL;
    }
    int index = 0;
    
    ll temp = rootptr;

    while(temp->data != n) {
        temp = temp->next;
        index++;
    }
    if(temp->data == n)
        return temp;
}