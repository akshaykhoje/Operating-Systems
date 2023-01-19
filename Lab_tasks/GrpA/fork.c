#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();
    printf("A\n");
    fork();
    printf("                B\n");
    fork();
    printf("        C\n");
    fork();
    printf("                        D\n");

    return 0;
}
