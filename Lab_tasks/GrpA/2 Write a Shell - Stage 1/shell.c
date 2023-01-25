#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#define YELLOW printf("\033[0;33m");
#define DEFAULT printf("\033[0m");

char PATH[] = "/usr/bin/:/usr/local/bin/:/bin/:/usr/local/games/:/usr/games/";

void change_dir(char **buf, char *pwd, int *flag)
{
    chdir(buf[1]);
    getcwd(pwd, 128);
    *flag = 1;
    return;
}

char *is_file_exist(char *dir, char *file)
{
    char *temp = (char *)malloc(sizeof(char) * 64);
    strcpy(temp, dir);
    strcat(temp, file);
    if (open(temp, O_RDONLY) >= 0)
    {
        return temp;
    }
    free(temp);
    return NULL;
}

void redirection(char **input, int size)
{
    int fd, pid, i = 0;
    char *path_token = PATH;
    char *file_path = NULL;
    char *args[128];
    
    while (i < size)
    {
        args[i] = *(input + i);
        if (strcmp(*(input + i), ">") == 0)
        {
            args[i] = NULL;
            path_token = strtok(PATH, ":");
            while (path_token != NULL)
            {
                file_path = is_file_exist(path_token, *input);
                if (file_path)
                    break;
                path_token = strtok(NULL, ":");
            }
            fd = creat(input[i + 1], O_WRONLY);
            close(1);
            dup(fd);
            execv(file_path, args);
            break;
        }
        else if (strcmp(*(input + i), "<") == 0)
        {
            args[i] = NULL;
            path_token = strtok(PATH, ":");
            while (path_token != NULL)
            {
                file_path = is_file_exist(path_token, *input);
                if (file_path)
                    break;
                path_token = strtok(NULL, ":");
            }
            fd = open(input[i + 1], O_RDONLY);
            close(0);
            dup(fd);
            execv(file_path, args);
            break;
        }
        i++;
    }
    free(file_path);
    return;
}

char **extract_input(char *buf, char *pwd, int *ps1_flag, int *size)
{
    if (buf[3] == '=')
    {
        char *token = strtok(buf, "=");
        printf("token in PS1 : %s\n", token);
        if (strcmp(token, "PS1") == 0)
        {
            token = strtok(NULL, "");
            if (strcmp(token, "\"\\w$\"") == 0)
            {
                *ps1_flag = 0;
            }
            else
            {
                *ps1_flag = 1;
                int len = strlen(pwd);
                int i;
                for (i = 0; i < len; i++)
                {
                    pwd[i] = 0;
                }
            }
        }
        token++;

        token[strlen(token) - 1] = '\0';
        strcpy(pwd, token);
    }

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

int main(void)
{
    int pid;
    char buf[128];
    char pwd[128];
    int input_size = 0;
    int ps1_flag = 0;
    int chdir_flag = 0;
    char *exists = (char *)malloc(sizeof(char) * 128);
    char *file_path = NULL;
    char *path_token = NULL;

    while (1)
    {
        if ((ps1_flag == 0 && chdir_flag != 0) || (ps1_flag != 0 && chdir_flag == 0) || (ps1_flag == 0 && chdir_flag == 0))
        {
            memset(pwd, 0, sizeof(pwd));
            getcwd(pwd, 128);
        }

        YELLOW
        printf(" %s $ ", pwd);
        DEFAULT
        fgets(buf, 128, stdin);
        buf[strcspn(buf, "\n")] = 0;

        char **ptr = extract_input(buf, pwd, &ps1_flag, &input_size);

        redirection(ptr, input_size);

        
        path_token = strtok(PATH, ":");
        while (path_token != NULL)
        {
            file_path = is_file_exist(path_token, *ptr);
            if (file_path)
                break;
            path_token = strtok(NULL, ":");
        }


        if (strcmp(*ptr, "exit") == 0)
        {
            return 0;
        }

        else if (strcmp(*ptr, "cd") == 0)
        {
            change_dir(ptr, pwd, &chdir_flag);
        }


        pid = fork();
        if (pid == 0)
        {
            execv(file_path, ptr);
        }
        else
        {
            memset(buf, 0, sizeof(buf));
            wait(0);
        }
    }

    free(exists);
    free(file_path);
    free(path_token);

    return 0;
}
