#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 128
#define YELLOW printf("\033[0;33m");
#define DEFAULT printf("\033[0m");

void set_ps1(char buf[], char *value_ps1)
{
    char *token = (char *)malloc(sizeof(char) * strlen(value_ps1));
    token = strtok(buf, "\"");
    if (strcmp(token, "\\w$") == 0)
    {
        getcwd(value_ps1, 2*SIZE);
        printf("value_ps1 when \\w$", value_ps1);
    }
    else
    {
        strcpy(value_ps1, token);
    }
    token = NULL;
    free(token);
    return;
}

char **extract_input(char *tokens[], char buf[], int *ps1_flag)
{
    char temp_buf[SIZE];

    strcpy(temp_buf, buf);

    if (buf[3] == '=')
    {
        char *is_ps1 = (char *)malloc(sizeof(char) * 4);
        is_ps1 = strtok(temp_buf, "=");
        if (strcmp(is_ps1, "PS1") == 0)
        {
            if ((buf[4] == '"') && (buf[strlen(buf) - 1] == '"'))
            {
                *ps1_flag = 1;
            }
            else
                printf("\" not found properly!\n");
        }
        else
            printf("Found = but not PS1\n");
        is_ps1 = NULL;
        free(is_ps1);
    }
    return tokens;
}

int main(void)
{
    int pid;
    char input_buffer[SIZE];
    char curr_dir[2 * SIZE];
    char *tokens[128]; // stores the tokens in the input string

#pragma flags
    int ps1_flag = 0;

    getcwd(curr_dir, 2 * SIZE);
    while (1)
    {
        YELLOW
        printf("%s", curr_dir);
        DEFAULT
        printf("$ ");
        fgets(input_buffer, SIZE, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = 0; // to remove the trailing '\n' character in input_buffer

        extract_input(tokens, input_buffer, &ps1_flag);
        printf("input_buffer inside main : %s\n", input_buffer);

        if (ps1_flag == 1)
        {
            set_ps1(input_buffer + 5, curr_dir);
        }
        printf("pwd inside main : %s\n", curr_dir);

        pid = fork();
        if (pid == 0)
        {
            execv("/usr/bin/ls", NULL);
        }
        else
        {
            wait(0);
        }
    }

    return 0;
}