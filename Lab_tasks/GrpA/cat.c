#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd, len, i;
    char buf[8];
    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        printf("Cannot open file!\n");
        return 1;
    }
    while(len = read(fd, buf, 8)) {
        for(i = 0; i<len; i++) {
            putchar(buf[i]);
        }
    }
    close(fd);

    return 0;
}