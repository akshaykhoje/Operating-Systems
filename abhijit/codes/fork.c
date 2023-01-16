#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid;
	printf("Hello\n");
	pid = fork();
	if (pid == 0)
	{
		printf("in child, pid = %d, my pid = %d, parent's pid = %d\n", pid, getpid(), getppid());
	}
	else
	{
		printf("in parent, child's pid = %d, my pid = %d\n", pid, getpid());
	}
	printf("Bye\n");
}
