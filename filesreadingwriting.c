#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;

    fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        return (1);

    char *str = "hello hamza\nthis is me practicing with the files in c;";
    int len = strlen(str);

    // write into this fi
    write(fd, str, len);

    close(fd);
    return 0;
}
