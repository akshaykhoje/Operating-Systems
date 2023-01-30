/*
Creating a pipe between a parent and a child where parent is sender and child is the receiver.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int fd[2], n;
	char buffer[100];     // data to be sent
	// char new[100] = "fsdkaf;sdjfsdffsfsd\n ||||";
	char *cmd = (char *)malloc(sizeof(char) * 32);
	char **args = (char **)malloc(sizeof(char*) * 32);
	cmd = "/usr/bin/ls";
	args[0] = "ls";
	args[1] = "-a";
	args[2] = "-l";
	args[3] = NULL;
	// printf("%s\n", cmd);
	// printf("%s\n", args[0]);
	// printf("%s\n", args[1]);
	// printf("%s\n", args[2]);
	execv(cmd, args);

	

	pid_t pid;
	pipe(fd);    //reading end -> fd[0], writing end -> fd[1]
	pid = fork();
	if(pid > 0)     // parent process
	{
		printf("Passing value to child\n");
		write(fd[1], cmd, 30);
	}
	else 
	{
		printf("Child received data...\n");
		n = read(fd[0], buffer, 100);
		write(1, buffer, n);
	}
	return 0;
}
