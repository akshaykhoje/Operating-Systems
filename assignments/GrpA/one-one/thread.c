#define _GNU_SOURCE
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "thread.h"

myth_t myth_create(myth_t *thread, void * (*fn)(void *), void *arg)
{
	int tid;
	char *stack = malloc(4096);
	tid = clone(fn, stack + 4096, 0, arg);
	*thread = tid;
	printf("thread id = %d\n", *thread);
	return tid;
}

int myth_join(myth_t thread)
{
	printf("\nwaitpid ret = %d\n\n", waitpid(thread, NULL, __WALL));
	return 0;
}

void myth_exit(void *retVal)
{
	exit(*(int *)retVal);
}