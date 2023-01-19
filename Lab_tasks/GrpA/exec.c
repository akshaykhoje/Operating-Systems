#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    printf("Inside main!\n");
    // execl("/usr/bin/neofetch", "/usr/bin/neofetch", NULL);
    execl("/usr/bin/ls", "/usr/bin/ls", "-l", "./", NULL);
    printf("after execl\n");
    printf("end\n");
    return 0;
}