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
    // printf("dir : %s \n", dir);
    // printf("file : %s \n", file);
    strcpy(temp, dir);
    strcat(temp, file);
    // printf("temp : %s \n", temp);
    if (open(temp, O_RDONLY) >= 0)
    {
        return temp;
    }
    free(temp);
    return NULL;
}

void redirection(char **input, int size)
{
    // int i;
    // for(i=0; i<size; i++)
    // {
    //     printf("%s\n", input[i]);
    // }
    int i, j;
    while (i < size)
    {
        if (strcmp(input[i], ">") == 0)
        {
            char args[i];
            for (j = 0; j < i; j++)
            {
                args[i] = input[i];
            }
            if (write(input[i + 1], execv("/usr/bin/ls", args), O_WRONLY))
            {
                return;
            }
        }
    }

    return;
}

// void output_redirect(char **source, char **destination, char path[])
// {
//     printf("source : %s\n", *source);
//     printf("destination : %s\n", *destination);
//     printf("%s\n", path);

//     char *cmd_path = is_file_exist(path, *source);
//     if(cmd_path) {

//     }

//     return;
// }

// void input_redirect(char **destination, char **source, char path[])
// {
//     printf("source : %s\n", *source);
//     printf("destination : %s\n", *destination);
//     printf("%s\n", path);
//     return;
// }

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
                // memset(pwd, 0, sizeof(pwd));
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
        // printf("%s\n", pwd);
    }

    char **values = (char **)malloc(sizeof(char *) * 128);
    char *token = strtok(buf, " ");
    int i = 0;
    while (token != NULL)
    {
        values[i] = token;
        // printf("%s", values[i]);
        // printf("!");
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

    // char PATH[] = "/usr/bin/:/usr/local/bin/:/bin/:/usr/local/games/:/usr/games/";

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
        fflush(stdin);
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
        // else if ((strcmp(*(ptr + 1), ">") == 0) || (strcmp(*(ptr + 1), "<") == 0))
        // {
        //     if (strcmp(*(ptr + 1), ">") == 0)
        //         output_redirect(ptr, ptr + 2, PATH);
        //     else if (strcmp(*(ptr + 1), "<") == 0)
        //         input_redirect(ptr, ptr + 2, PATH);
        // }
        // printf("%s\n", *(ptr+1));

        // printf("file_path : %s\n", file_path);
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

/*
AT PRESENT IT DOES PS1 WHEN NOT IN THE CWD.
*/