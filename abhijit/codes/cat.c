#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd, len, i;
	char buf[8];
	fd = open(argv[1], O_RDONLY); // access request
	if (fd == -1)
	{
		printf("open failed\n");
		return 1;
	}
	while (len = read(fd, buf, 8)) // transfer of data from file (on disk) to memory of this program (buf)
		for (i = 0; i < len; i++)
			putchar(buf[i]);

	close(fd); // release the access
	return 0;
}
