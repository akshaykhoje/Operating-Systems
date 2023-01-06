#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dcll.h"

void init(dcll *rootptr)
{
    *rootptr = NULL;
    return;
}

int file_exists(const char *filename)
{
    // returns 0 if file exists, -1 if it doesn't.
    return access(filename, F_OK == 0);
}

// void read_file(const char *str){
//     FILE *fptr = fopen(str, "r");

//     char line[1000];

//     while(fgets(line, sizeof(line), fptr)) {
//         char *token;
//         token = strtok(line, ",");

//         while(token != NULL) {
//             printf("%s ", token);
//             token = strtok(NULL, ",");
//         }
//         printf("\n");
//     }
//     fclose(fptr);
//     return;
// }

void insert(dcll *rootptr, const char *str)
{
    if (*rootptr == NULL)
    {
        FILE *fptr = fopen(str, "r");
        char line[5000];
        fscanf(fptr, "%[^\n]", line);
        char *token = strtok(line, ",");

        dcll nn = (dcll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create root node!\n");
            return;
        }

        nn->name = token;
        token = strtok(NULL, ",");
        nn->MIS = atoi(token);
        token = strtok(NULL, ",");
        nn->marks = atof(token);
        token = strtok(NULL, "\n");

        nn->prev = nn;
        nn->next = nn;
        *rootptr = nn;

        fclose(fptr);
        return;
    }
    else
    {
        FILE *fptr = fopen(str, "r");
        while (feof(fptr))
        {
            char line[5000];
            fscanf(fptr, "%[^\n]", line);
            char *token = strtok(line, ",");

            char ch;
            dcll nn = (dcll)malloc(sizeof(Node));
            if (!nn)
            {
                printf("Cannot create a node!\n");
                return;
            }
            nn->name = token;
            token = strtok(NULL, ",");
            nn->MIS = atoi(token);
            token = strtok(NULL, ",");
            nn->marks = atof(token);
            token = strtok(NULL, "\n");

            dcll temp = *rootptr;
            while (temp->next != *rootptr)
            {
                temp = temp->next;
            }

            temp->next = nn;
            nn->prev = temp;
            nn->next = *rootptr;
            (*rootptr)->prev = nn;
        }

        fclose(fptr);
    }
    return;
}

/*
void insert_beginning(dcll *rootptr, const char *str)
{
    char ch;
    if (*rootptr == NULL)
    {
        dcll nn = (dcll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create a node!\n");
            return;
        }
        FILE *fptr = fopen(str, "r");
        char line[3000];
        fscanf(fptr, "%[^\n]", line);
        char *token = strtok(line, ",");

        nn->name = token;
        token = strtok(NULL, ",");
        nn->MIS = atoi(token);
        token = strtok(NULL, ",");
        nn->marks = atof(token);
        token = strtok(NULL, "\n");

        printf("s1 : %d, s2 : %s, s3 : %.2lf\n", nn->MIS, nn->name, nn->marks);

        // while (token != NULL)
        // {
        //     // nn->name = token;
        //     // strtok(NULL, ",");
        //     // nn->MIS = (atoi)(token);
        //     // strtok(NULL, ",");
        //     // nn->marks = (atof)(token);
        //     // strtok(NULL, ",");
        //     printf(" %s", token); // printing each token
        //     token = strtok(NULL, ",");
        // }
        fclose(fptr);

        // printf("The line is : %s\n\n", nn->name);
        // nn->marks = atof(line);
        // while (fgets(line, sizeof(line), fptr))
        // {
        //     char *token;
        //     token = strtok(line, "\n");

        //     // while(token != NULL) {
        //     //     // printf("%s ", token);
        //     //     nn->data = token;
        //     //     token = strtok(NULL, "\n");
        //     // }

        //     for (int i = 0; i < 1; i++)
        //     {
        //         nn->marks = (atof)(token);
        //         token = strtok(NULL, "\n");
        //     }
        //     printf("\n");
        // }

        //nn->next = nn;
        //nn->prev = nn;
        // *rootptr = nn;
    }

    return;
}
*/

/*
void insert_ending(dcll *rootptr, const char *str)
{
    if (*rootptr == NULL)
    {
        printf("Data structure not found!\n");
        return;
    }

    FILE *fptr = fopen(str, "r");
    while (feof(fptr))
    {
        char line[5000];
        fscanf(fptr, "%[^\n]", line);
        char *token = strtok(line, ",");

        char ch;
        dcll nn = (dcll)malloc(sizeof(Node));
        if (!nn)
        {
            printf("Cannot create a node!\n");
            return;
        }
        nn->name = token;
        token = strtok(NULL, ",");
        nn->MIS = atoi(token);
        token = strtok(NULL, ",");
        nn->marks = atof(token);
        token = strtok(NULL, "\n");

        dcll temp = *rootptr;
        while (temp->next != *rootptr)
        {
            temp = temp->next;
        }

        temp->next = nn;
        nn->prev = temp;
        nn->next = *rootptr;
        (*rootptr)->prev = nn;
    }
    fclose(fptr);

    return;
}
*/

void display_clockwise(dcll rootptr)
{
    if (!rootptr)
    {
        printf("dcll is empty!!!\n\n");
        return;
    }
    printf("Displaying list clockwise...\n");
    dcll temp = rootptr;
    do
    {
        printf("MIS : %d, Name : %s, Marks : %.2lf  ", temp->MIS, temp->name, temp->marks);
        temp = temp->next;
    } while (temp != rootptr);
    printf("\n\n");
    return;
}

void display_counter_clockwise(dcll rootptr)
{
    if (!rootptr)
    {
        printf("dcll is empty!!!\n\n");
        return;
    }
    printf("Displaying list clockwise...\n");
    dcll temp = rootptr;
    do
    {
        printf("MIS : %d, Name : %s, Marks : %.2lf  ", temp->MIS, temp->name, temp->marks);
        temp = temp->next;
    } while (temp != rootptr);
    printf("\n\n");
    return;
}

// void delete_beginning(dcll *rootptr)
// {
//     if (*rootptr == NULL)
//     {
//         printf("Empty List!!!\n");
//         return;
//     }
//     printf("Deleting the head node!!!\n");

//     dcll del, temp = *rootptr;
//     if (temp->next == *rootptr)
//     {
//         temp->next = NULL;
//         temp->prev = NULL;
//         free(temp);
//         return;
//     }

//     while (temp->next != *rootptr)
//     {
//         temp = temp->next;
//     }
//     del = *rootptr;
//     *rootptr = (*rootptr)->next;
//     (*rootptr)->prev = temp;
//     temp->next = *rootptr;
//     free(del);

//     return;
// }

// void delete_ending(dcll *rootptr)
// {
//     if (*rootptr == NULL)
//     {
//         printf("Empty List!!!\n");
//         return;
//     }
//     printf("Deleting the ending node!!!\n");

//     dcll back, temp = *rootptr;
//     while (temp->next != *rootptr)
//     {
//         back = temp;
//         temp = temp->next;
//     }
//     back->next = *rootptr;
//     (*rootptr)->prev = back;
//     free(temp);

//     return;
// }