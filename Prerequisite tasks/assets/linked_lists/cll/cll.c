#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

void init(cll *rootptr)
{
    *rootptr = NULL;
    return;
}

void insert_beginning(cll *rootptr)
{
    char ch;
    if (*rootptr == NULL)
    {
        cll nn = (cll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create a node!\n");
            return;
        }
        // fflush(stdin);
        printf("Enter the char : ");
        scanf(" %c", &ch);
        nn->data = ch;
        nn->next = nn;
        *rootptr = nn;
    }
    return;
}

void insert_ending(cll *rootptr)
{
    char ch;
    cll nn = (cll)malloc(sizeof(Node));
    if (!nn)
    {
        printf("Cannot create a node!\n");
        return;
    }
    printf("Enter the char : ");
    scanf(" %c", &ch);
    nn->data = ch;

    cll temp = *rootptr;
    while (temp->next != *rootptr)
    {
        temp = temp->next;
    }

    temp->next = nn;
    nn->next = *rootptr;

    return;
}

void delete_beginning(cll *rootptr)
{
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the head node!!!\n");

    cll del, temp = *rootptr;
    while (temp->next != *rootptr)
    {
        temp = temp->next;
    }
    del = *rootptr;
    *rootptr = (*rootptr)->next;
    temp->next = *rootptr;
    free(del);

    return;
}

void delete_ending(cll *rootptr)
{
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the ending node!!!\n");

    cll back, temp = *rootptr;
    while (temp->next != *rootptr)
    {
        back = temp;
        temp = temp->next;
    }
    back->next = temp->next;
    free(temp);

    return;
}

void display(cll rootptr)
{
    if (!rootptr)
    {
        printf("cll is empty!!!\n\n");
        return;
    }
    cll temp = rootptr;
    do
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    } while (temp != rootptr);
    printf("\n\n");
    return;
}

cll search(cll rootptr) {
    if(!rootptr){
        printf("cll is emtpy!!!\n\n");
        return NULL;
    }

    cll temp = rootptr;
    char ch;
    printf("Enter the char to search for : ");
    scanf(" %c", &ch);

    while(temp->next != rootptr) {
        if(temp->data == ch) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}