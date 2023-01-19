#include <stdio.h>
#include <unistd.h>

int main(void) {
    char buf[128];
	printf("%s\n", getcwd(buf, 128));
    return 0;
}