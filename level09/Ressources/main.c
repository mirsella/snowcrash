#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void) argc;
	int fd = open(argv[1], O_RDONLY);
	char buf[25] = {0};
	read(fd, buf, 25);
	for (int i = 0; i < 25; i++) {
		buf[i] = buf[i] - i;
	}
	write(1, buf, 25);
}