#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int pid;
	char buf[128];
	while(1) {
			printf("prompt>");
			scanf("%s", buf);
			pid = fork();
			if(pid == 0) {
				execl(buf, buf, NULL);
			} else {
				wait(0);
			}
	}
	printf("Bye\n");
	return 0;
}
