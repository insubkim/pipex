#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int c ,char **argv, char **envp)
{
    execve("./a.out", argv, envp);
    perror(" >> ");
    //printf("%d\n", access("./a.out", F_OK));
}