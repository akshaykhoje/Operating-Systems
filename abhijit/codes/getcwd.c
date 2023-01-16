#include <stdio.h>
#include <unistd.h>
int main() {
	int buf[128];
	printf("%s\n", getcwd(buf, 128));
}
