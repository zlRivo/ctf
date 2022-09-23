#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    int fd = open("/dev/urandom", O_RDONLY);
    char str[7] = {0};
    read(fd, str, 4);
    printf("%x", str);
}
