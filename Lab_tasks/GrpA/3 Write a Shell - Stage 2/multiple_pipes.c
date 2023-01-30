/*
We're going to create 3 pipes and 2 forks -> 3*2 fds.
Each process will have one copy of each fd. We'll create these fds in the parent. Thus we'll have 6*3 = 18 pipes -> 18 fds.
Any array that ends with 0 -> read end; 1 -> write end
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd[3][2];
    int i;
    for (i = 0; i < 3; i++){
        if (pipe(fd[i]) < 0) // this is a bad way of handling this. Ideally all the open pipes must be closed in such case 
        {
            return 1;
        }
    }
    int pid1 = fork();
    if(pid1 < 0)
        return 2;
    if(pid1 == 0) {
        // child process 1
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);

        int x;
        if (read(fd[0][0], &x, sizeof(int)) < 0) {
            return 3;
        }
        x += 5;
        if (write(fd[1][1], &x, sizeof(int)) < 0) {
            return 4;
        }
        close(fd[0][0]);
        close(fd[1][1]);
        return 0;
    }

    int pid2 = fork();
    if(pid2 < 0) 
        return 5;
    
    if(pid2 == 0) {
        // child process 2
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[2][0]);
        int x;
        if(read(fd[1][0], &x, sizeof(int)) < 0) {
            return 6;
        }
        x+=5;
        if(write(fd[2][1], &x, sizeof(int)) < 0) {
            return 7;
        }
        close(fd[1][0]);
        close(fd[2][1]);
        return 0;
    }

    // Parent process
    close(fd[0][0]);
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]);

    int x;
    printf("Enter a number : ");
    scanf("%d", &x);
    if (write(fd[0][1], &x, sizeof(int)) < 0) {
        return 8;
    }
    if (read(fd[2][0], &x, sizeof(int)) < 0) {
        return 9;
    }
    printf("x : %d\n", x);
    close(fd[0][1]);
    close(fd[2][0]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}