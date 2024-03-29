#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 128
#define YELLOW printf("\033[0;33m");
#define DEFAULT printf("\033[0m");

int no_of_pipes = 0;

int check_for_pipe(char **extraction)
{
    char **temp = extraction;
    while (*temp != NULL)
    {
        if (strcmp(*temp, "|") == 0)
        {
            no_of_pipes++;
        }
        temp++;
    }
    return no_of_pipes;
}

char ***extract_pipe_commands(char **extraction)        // extract each command into an array(3D) element
{
    char **temp = extraction;
    char ***commands = (char ***)malloc(sizeof(char **) * (no_of_pipes + 1));
    int i = 0;
    for (i = 0; i < no_of_pipes + 1; i++)
    {
        commands[i] = (char **)malloc(sizeof(char *) * SIZE);
    }
    int j = 0, k = 0;
    while (*temp != NULL)
    {
        if (strcmp(*temp, "|") == 0)
        {
            commands[j][k] = NULL;
            j++;
            k = 0;
        }
        else
        {
            commands[j][k] = *temp;
            printf("%s\n", *temp);
            k++;
        }
        temp++;
    }
    return commands;        // returns all the commands between each pipes
}


void change_dir(char *new_dir_path, char *curr_dir)
{
    chdir(new_dir_path);
    strcpy(curr_dir, new_dir_path);
    return;
}

void set_ps1(char buf[], char *value_ps1)
{
    char *token = (char *)malloc(sizeof(char) * strlen(value_ps1));
    token = strtok(buf, "\"");
    if (strcmp(token, "\\w$") == 0)
    {
        getcwd(value_ps1, 2 * SIZE);
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

char *command_path(char **path, char **args, int token_size)
{
    char **temp = path; // local pointer to point to PATH
    char *check_unit = (char *)malloc(sizeof(char) * SIZE);
    while (*temp != NULL)
    {
        memset(check_unit, 0, SIZE);
        strcpy(check_unit, *temp);
        strcat(check_unit, *args);
        if (open(check_unit, O_RDONLY) >= 0)
        {
            return check_unit;
        }
        temp = temp + 1;
    }
    return NULL;
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

void create_history(char input[])
{
    int history = open("bsh_history", O_CREAT | O_APPEND | O_RDWR);
    char hist_buffer[SIZE];
    strcpy(hist_buffer, input);
    int i = 0;
    while (hist_buffer[i] != '\n')
    {
        i++;
    }
    write(history, hist_buffer, i);
    write(history, "\n", 1);
    close(history);
    return;
}

void history()
{
    execl("/usr/bin/cat", "/usr/bin/cat", "bsh_history", NULL);
    return;
}

void handle_sigterm(int sig)
{
    printf("Caught signal %d\n", sig);
}

void handle_sigstop(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main(void)
{
    int pid, token_size = 0;
    char *cmd_path;
    int fd_history;
    char input_buffer[SIZE];
    char curr_dir[2 * SIZE];  // stores path of the current directory
    char **extraction = NULL; // points to an array of tokenized user input
    char *PATH[2 * SIZE] = {"/usr/bin/", "/usr/local/bin/", "/bin/", "/usr/local/games/", "/usr/games/", "/snap/bin/"};

    // adding signal to quit using ctrl+C
    signal(SIGTERM, handle_sigterm);
    signal(SIGSTOP, handle_sigstop);

#pragma flags
    int ps1_flag = 0;

    getcwd(curr_dir, 2 * SIZE);
    while (1)
    {
        YELLOW
        printf("%s", curr_dir);
        DEFAULT
        printf("$ ");
        char *history_buffer = (char *)malloc(sizeof(char) * SIZE);
        fgets(input_buffer, SIZE, stdin);
        if (input_buffer[0] == '\n') // if user presses enter, skip this iteration!
        {
            continue;
        }
        create_history(input_buffer);
        input_buffer[strcspn(input_buffer, "\n")] = 0; // to remove the trailing '\n' character in input_buffer

        extraction = extract_input(input_buffer, &ps1_flag, &token_size);

        int pipes = check_for_pipe(extraction);
        if (pipes != 0)
        {
            printf("no of pipes : %d\n", no_of_pipes);
            char ***commands = extract_pipe_commands(extraction);
            // int size = 0;
            while (*commands != NULL)
            {
                printf("%s\n", *commands);
                commands++;
            }
            return 0;
        }
        if (ps1_flag == 1)
        {
            set_ps1(input_buffer + 5, curr_dir);
        }
        else if (strcmp(*extraction, "cd") == 0)
        {
            change_dir(*(extraction + 1), curr_dir);
        }
        else if (strcmp(*extraction, "history") == 0)
        {
            history();
        }
        else
        {
            cmd_path = command_path(PATH, extraction, token_size);
        }

        pid = fork();
        if (pid < 0)
        {
            return 1;
        }
        if (pid == 0)
        {
            execv(cmd_path, extraction);
        }
        else
        {
            wait(0);
        }
    }

    return 0;
}