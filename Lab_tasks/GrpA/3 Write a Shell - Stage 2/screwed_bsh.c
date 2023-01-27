#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define SIZE 128
#define YELLOW printf("\033[0;33m");
#define DEFAULT printf("\033[0m");

void redirection(char **args, int token_size, char *path)
{
    int fd, i = 0;
}

void change_dir(char *new_dir_path, char *curr_dir)
{
    chdir(new_dir_path);
    strcpy(curr_dir, new_dir_path);
    return;
}

void set_ps1(char buf[], char *value_ps1)
{
    char temp_buf[SIZE];
    strcpy(temp_buf, buf);
    char *token = (char *)malloc(sizeof(char) * strlen(value_ps1));
    token = strtok(temp_buf, "\"");
    if (strcmp(token, "\\w$") == 0)
    {
        getcwd(value_ps1, 2 * SIZE);
    }
    else
    {
        strcpy(value_ps1, token);
    }
    token = NULL;
    free(token);
    return;
}

char **extract_input(char buf[], int *ps1_flag, int *size)
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
                exit(0);
        }
        else
            printf("Found = but not PS1\n");
        is_ps1 = NULL;
        free(is_ps1);
        return NULL;
    }
    else if (strcmp(buf, "exit") == 0)
    {
        printf("exit\n");
        sleep(0.5);
        exit(0);
    }
    else
    {
        char **values = (char **)malloc(sizeof(char *) * 128);
        char *token = strtok(buf, " ");
        int i = 0;
        while (token != NULL)
        {
            values[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        values[i] = NULL;
        *size = i;

        free(token);
        return values;
    }
}

char *command_path(char **path, char **args, int token_size, int redirect)
{
    // int i=0;
    // if(redirect == 1)
    //     token_size = token_size - 2;
    char **temp = path;
    char *check_unit = (char *)malloc(sizeof(char) * 128);
    while (*temp != NULL)
    {
        strcpy(check_unit, *temp);
        strcat(check_unit, *args);
        printf("temp : %s\n", check_unit);
        if (open(check_unit, O_RDONLY) >= 0)
        {
            return check_unit;
        }
        temp = temp + 1;
    }
    free(check_unit);
    return NULL;
}

int main(void)
{
    int pid;
    int token_size = 0;
    char *cmd_path;         // points to the address of the executable
    char input_buffer[SIZE];  // stores the user input
    char curr_dir[2 * SIZE];  // stores path of the current directory
    char **extraction = NULL; // points to an array of tokenized user input
    char *PATH[2 * SIZE] = {"/usr/bin/", "/usr/local/bin/", "/bin/", "/usr/local/games/", "/usr/games/", "/snap/bin/"};

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

        extraction = extract_input(input_buffer, &ps1_flag, &token_size);

        if (ps1_flag == 1)
        {
            set_ps1(input_buffer + 5, curr_dir);
            printf("pwd inside main : %s\n", curr_dir);
        }
        else if (strcmp(*extraction, "cd") == 0)
        {
            change_dir(*(extraction + 1), curr_dir);
        }
        // printf("redi... : %s\n", *(extraction + token_size - 2));
        else if ((strcmp(*(extraction + token_size - 2), ">") == 0) || strcmp(*(extraction + token_size - 2), "<") == 0)
        {
            printf("redirecting!\n");
            cmd_path = command_path(PATH, extraction, token_size, 1);
            redirection(extraction, token_size, cmd_path);
        }
        else
        {
            cmd_path = command_path(PATH, extraction, token_size, 0);
        }

        pid = fork();
        if (pid == 0)
        {
            execv(cmd_path, extraction);
        }
        else
        {
            wait(0);
        }
    }

    extraction = NULL;
    cmd_path = NULL;
    free(cmd_path);
    free(extraction);
    return 0;
}
