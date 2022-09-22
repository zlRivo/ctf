#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    char* args[101] = {0};
    for (int i = 0; i < 100; i++)
    {
        args[i] = "A";
    }
    args['A'] = "\x00";
    args['B'] = "\x20\x0a\x0d";

    int pipe_stdin[2];
    int pipe_stderr[2];
    if (pipe(pipe_stdin) < 0 || pipe(pipe_stderr) < 0) {
        puts("Couldn't create pipes!");
        return 1;
    }
    
    pid_t pid;
    if ((pid = fork()) < 0) {
        puts("Failed to fork process!");
        exit(1);
    } else if (pid == 0) {
        // Child process
        
        // Close read descriptors
        close(pipe_stdin[0]);
        close(pipe_stderr[0]);

        // Write bytes to std file descriptors
        write(pipe_stdin[1], "\x00\x0a\x00\xff", 4);
        write(pipe_stderr[1], "\x00\x0a\x02\xff", 4);
        // Exit finished program
        exit(0);
    } else {
        // Parent process

        // Close writing descriptors
        close(pipe_stdin[1]);
        close(pipe_stderr[1]);

        // Replace stdin file descriptors
        dup2(pipe_stdin[0], 0);
        dup2(pipe_stderr[0], 2);

        // Close reading descriptors
        close(pipe_stdin[0]);
        close(pipe_stderr[0]);

        // STAGE 3
        setenv("\xca\xfe\xba\xbe", strcat(getenv("\xde\xad\xbe\xef"), "\x00"), 1);
        extern char** environ;

        // STAGE 4
        FILE* f = fopen("\x0a", "w");
        fwrite("\x00\x00\x00\x00", 4, 1, f);
        fclose(f);
        
        execve("/home/input2/input", args, environ);
    }
    
    return 0;
}
