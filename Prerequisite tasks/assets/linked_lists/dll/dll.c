#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void init(dll *rootptr)
{
    *rootptr = NULL;
    return;
}

void insert_beginning(dll *rootptr)
{
    char ch;
    if (*rootptr == NULL)
    {
        dll nn = (dll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create a node!\n");
            return;
        }
        // fflush(stdin);
        printf("Enter the char : ");
        scanf(" %c", &ch);
        nn->data = ch;
        nn->next = NULL;
        nn->prev = NULL;
        *rootptr = nn;
    }
    return;
}

void insert_ending(dll *rootptr)
{
    char ch;
    dll nn = (dll)malloc(sizeof(Node));
    if (!nn)
    {
        printf("Cannot create a node!\n");
        return;
    }
    printf("Enter the char : ");
    scanf(" %c", &ch);
    nn->data = ch;

    dll temp = *rootptr;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = nn;
    nn->prev = temp;
    nn->next = NULL;

    return;
}

void insert_after(dll *nodeptr)
{
    char ch;
    printf("Enter the char location : ");
    scanf(" %c", &ch);
    dll temp = *nodeptr;
    while (1)
    {
        if (temp->data != ch)
            temp = temp->next;
        else if (temp->data == ch)
            break;
        else
        {
            printf("Char %c NOT FOUND!!!\n", ch);
            return;
        }
    }

    dll nn = (dll)malloc(sizeof(Node));
    if (!nn)
    {
        printf("Cannot create a node!\n");
        return;
    }
    printf("Enter the char : ");
    scanf(" %c", &ch);

    nn->data = ch;
    nn->next = temp->next;
    temp->next->prev = nn;
    temp->next = nn;
    nn->prev = temp;

    return;
}

void delete_beginning(dll *rootptr)
{
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the head node!!!\n");

    dll temp = *rootptr;
    if (temp->next)
    {
        *rootptr = (*rootptr)->next;
        (*rootptr)->prev = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    else
    {
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

void delete_ending(dll *rootptr)
{
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the ending node!!!\n");

    dll temp = *rootptr;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = NULL;
    free(temp);

    return;
}

void delete_char(dll *rootptr)
{
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    char ch;
    printf("Displaying the dll. Enter the char to delete.\n");
    printf("Enter the char to delete : ");
    scanf(" %c", &ch);

    dll temp = *rootptr;
    while (1)
    {
        if (temp->data != ch)
            temp = temp->next;
        else if (temp->data == ch)
            break;
        else
        {
            printf("Char %c NOT FOUND!!!\n", ch);
            return;
        }
    }
    if (temp->next == NULL)
    {
        delete_ending(rootptr);
        return;
    }
    if (temp->prev == NULL)
    {
        delete_beginning(rootptr);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    free(temp);

    printf("Deleting the ending node!!!\n\n");
    return;
}

void display(dll rootptr)
{
    dll temp = rootptr;
    if (!rootptr)
    {
        printf("dll is emtpy!\n");
        return;
    }
    printf("Displaying the dll to you...\n");
    while (temp)
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return;
}

void display_back(dll rootptr)
{
    dll temp = rootptr;
    if (!rootptr)
    {
        printf("dll is empty!\n");
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    printf("Displaying the dll all the way backwards...\n");
    while (temp)
    {
        printf("%c  ", temp->data);
        temp = temp->prev;
    }
    printf("\n\n");
    return;
}

dll search(dll rootptr)
{
    if(!rootptr){
        printf("cll is emtpy!!!\n\n");
        return NULL;
    }

    dll temp = rootptr;
    char ch;
    printf("Enter the char to search for : ");
    scanf(" %c", &ch);

    while (temp)
    {
        if (temp->data == ch)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}