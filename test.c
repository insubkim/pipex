#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int c ,char **argv, char **envp)
{
    int fd[2];
    pipe(fd);
    dup2(fd[0], 0);
    close(fd[1]);
    execve("/usr/bin/wc", argv, envp);
    perror(" >> ");
    //printf("%d\n", access("./a.out", F_OK));
}