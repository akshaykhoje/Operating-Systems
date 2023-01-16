#include <unistd.h>
#include <stdio.h>
int main()
{
	printf("before execl\n");
	execl("/usr/bin/ls", "/usr/bin/ls", NULL);
	printf("after execl\n");
}
