#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define INPUT_SIZE 128

static int cmd_length = 0;
static int no_of_flags = 0;

typedef struct Node
{
	char option[2];
	struct Node *next;
} Node;

typedef Node *head;

// the code below is supposed to store all the options for a command in a linked list
/* algorithm for storing options for a command :
1. check if there is an option i.e. there is anything started with a '-' NOT as the very first command
2. If (no option exist) {
		execute the command
	}
	Else {
		if(multiple options exist){
			create a linked list, each node containing one flag
		}
		else {
			store a flag in a node and return a pointer to it.
		}
	}
*/

Node *options(char buf[])
{
	char *parser = buf;
	while (*parser != '\0')
	{
		if (*parser == '-')
		{
			if (*parser != 0x20)
			{
				Node *nn = (Node *)malloc(sizeof(Node));
				nn->option[0] = '-';
				nn->option[1] = *(++parser);
				nn->next = NULL;
				return nn;
			}
			else
			{
				printf("Invalid options!");
				return NULL;
			}
		}
		parser++;
	}
	return NULL;
}

void *get_cmd(char buf[])
{
	printf("buf : %s\n", buf);
	char *parser = buf;

	while (*parser != ' ')
	{
		cmd_length++;
		parser++;
	}
	parser = buf;

	char *temp = buf;

	printf("cmd_length : %d\n", cmd_length);

	char *cmd = (char *)malloc(sizeof(char) * (cmd_length + 1)); // getting the first command
	int i;
	for (i = 0; i < cmd_length; i++)
	{
		*(cmd + i) = *buf;
		buf++;
		temp++;
	}

	return cmd;
}

void shell()
{
	int pid;
	int inner_pid;
	char *buf = (char *)malloc(sizeof(char) * INPUT_SIZE);
	while (1)
	{
		char pwd[INPUT_SIZE];
		printf("%s $ ", getcwd(pwd, INPUT_SIZE));
		scanf("%[^\n]s", buf);
		pid = fork();
		if (pid == 0)
		{
			printf("Inside child process!\n");
			char *cmd = get_cmd(buf);
			printf(" %s\n", cmd);
			Node *opt1 = options(buf);
			printf(" %s \n", opt1->option);
			fflush(stdin);
			fflush(stdout);
			// execl(cmd, cmd, opt1->option, NULL);
			execl(cmd, cmd, NULL);

			free(opt1);
			free(cmd);
			return;
		}
		else
		{
			printf("\nInside parent process!\n");
			wait(0);
		}

		printf("exiting shell()!\n");
		exit(0);
	}
	return;
}

int main()
{
	shell();
	printf("Bye\n");
	return 0;
}
