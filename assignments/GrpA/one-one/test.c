#include <stdio.h>
#include "thread.h"

int x = 20;

void *f(void *arg)
{
	int *p = (int*)arg;
	if(*p % 10 == 0)
		*p = *p + 1;
	else
		*p = *p + 9;
	printf("p = %d\t x= %d\n", *p, x);
	myth_exit(NULL);
}

int main(void)
{
	myth_t tid[4];
	int args[4], k;

	for (k = 0; k < 4; k++)
	{
		args[k] = 10 + k;
		myth_create(&tid[k], f, &args[k]);
	}

	for (k = 0; k < 4; k++)
	{
		myth_join(tid[k]);
	}

	return 0;
}
