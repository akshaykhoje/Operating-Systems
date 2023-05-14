// YET INCOMPLETE. Tried to make a communication between two processes in the form 1-1 messaging apps.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 100

int main(void)
{
    pid_t pid;
    int n1, n2, i = 0, j;
    char buffer[SIZE];
    char *input = (char *)calloc(SIZE, sizeof(char));
    int fd[2];
    pipe(fd);
    int *send_p2c = (int *)malloc(sizeof(int));
    int *send_c2p = (int *)malloc(sizeof(int));
    int *recv_p = (int *)malloc(sizeof(int));
    int *recv_c = (int *)malloc(sizeof(int));
    *send_p2c = 1;
    *send_c2p = 0;
    *recv_c = 1;
    *recv_p = 0;

    pid = fork();
    do
    {
        // printf("status` : %d!", strcmp(input, "exit\n") == 0);
        fgets(buffer, SIZE, stdin);
        while (buffer[i] != '\n')
        {
            i++;
        }
        input = realloc(input, i * sizeof(char));
        strcpy(input, buffer);
        printf("input : %s!", input);

        if (strcmp(input, "exit\n") == 0)
        {
            exit(0);
        }

        if (pid == 0)
        {
            // child process

            if (*send_c2p == 1 && *recv_c == 0 && *recv_p == 1 && *send_p2c == 0)
            {
                close(fd[0]);
                printf("Child process sent...\n");
                printf("%s\n", input);
                write(fd[1], input, i);
                *send_c2p = 1;
                *recv_c = 0;
                *send_p2c = 0;
                *recv_p = 1;
            }
            else if (*send_p2c == 1 && *recv_c == 1 && *send_c2p == 0 && *recv_p == 0)
            {
                close(fd[1]);
                n1 = read(fd[0], buffer, i);
                printf("Child process received...\n");
                write(1, input, n1); // writing to stdout
                *send_c2p = 1;
                *recv_c = 0;
                *send_p2c = 0;
                *recv_p = 1;
                for (j = 0; j < SIZE; j++)
                {
                    input[i] = 0;
                }
            }
            wait(0);
        }

        else if (pid > 0)
        {
            // parent process

            if (*send_c2p == 1 && *recv_p == 1 && *send_p2c == 0 && *recv_c == 0)
            {
                close(fd[1]);
                n1 = read(fd[0], buffer, i);
                printf("Parent process received...\n");
                write(1, input, n1); // writing to stdout
                *send_p2c = 1;
                *recv_p = 0;
                *send_c2p = 0;
                *recv_c = 1;
                for (j = 0; j < SIZE; j++)
                {
                    input[i] = 0;
                }
            }
            else if (*send_p2c == 1 && *recv_p == 0 && *send_c2p == 0 && *recv_c == 1)
            {
                close(fd[0]);
                printf("Parent process sent...\n");
                printf("%s\n", input);
                write(fd[1], input, i);
                *send_p2c = 1;
                *recv_p = 0;
                *send_c2p = 0;
                *recv_c = 1;
            }

            wait(0);
        }
    } while (1);

    return 0;
}