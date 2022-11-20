#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>

// Useless program that changes the modification timestamp with it's old one
int main(int argc, char** argv) {
    if (argc != 2) {
        puts("Usage: ");
    }

    struct stat stats;
    int ret = __xstat(1, argv[1], &stats);
    if (ret < 0) {
        puts("error #1!");
        exit(0);
    }

    long long int last_change = stats.st_ctime;
    long long int time_ret = time(NULL);

    struct utimbuf times;
    ret = utime(argv[1], &last_change);
    if (ret < 0) {
        puts("error #2!");
        exit(0);
    }

    return 0;
}