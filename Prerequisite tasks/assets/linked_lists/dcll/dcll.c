#include <stdio.h>
#include <stdlib.h>
#include "dcll.h"

void init(dcll *rootptr) {
    *rootptr = NULL;
    return;
}

void insert_beginning(dcll *rootptr) {
    char ch;
    if (*rootptr == NULL)
    {
        dcll nn = (dcll)malloc(sizeof(Node));
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
        nn->prev = nn;
        *rootptr = nn;
    }
    return;
}

void insert_ending(dcll *rootptr)
{
    char ch;
    dcll nn = (dcll)malloc(sizeof(Node));
    if (!nn)
    {
        printf("Cannot create a node!\n");
        return;
    }
    printf("Enter the char : ");
    scanf(" %c", &ch);
    nn->data = ch;

    dcll temp = *rootptr;
    while (temp->next != *rootptr)
    {
        temp = temp->next;
    }

    temp->next = nn;
    nn->prev = temp;
    nn->next = *rootptr;
    (*rootptr)->prev = nn;

    return;
}

void delete_beginning(dcll *rootptr) {
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the head node!!!\n");

    dcll del, temp = *rootptr;
    if(temp->next == *rootptr){
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
        return;
    }

    while (temp->next != *rootptr)
    {
        temp = temp->next;
    }
    del = *rootptr;
    *rootptr = (*rootptr)->next;
    (*rootptr)->prev = temp;
    temp->next = *rootptr;
    free(del);

    return;
}

void delete_ending(dcll *rootptr) {
    if (*rootptr == NULL)
    {
        printf("Empty List!!!\n");
        return;
    }
    printf("Deleting the ending node!!!\n");

    dcll back, temp = *rootptr;
    while (temp->next != *rootptr)
    {
        back = temp;
        temp = temp->next;
    }
    back->next = *rootptr;
    (*rootptr)->prev = back;
    free(temp);

    return;
}

void display_clockwise(dcll rootptr) {
    if (!rootptr)
    {
        printf("dcll is empty!!!\n\n");
        return;
    }
    printf("Displaying list clockwise...\n");
    dcll temp = rootptr;
    do
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    } while (temp != rootptr);
    printf("\n\n");
    return;
}

void display_counter_clockwise(dcll rootptr) {
    if (!rootptr)
    {
        printf("dcll is empty!!!\n\n");
        return;
    }
    printf("Displaying list clockwise...\n");
    dcll temp = rootptr;
    do
    {
        printf("%c  ", temp->data);
        temp = temp->prev;
    } while (temp != rootptr);
    printf("\n\n");
    return;
}