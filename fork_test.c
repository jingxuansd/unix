#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
int glob = 6;
char buf[] = "a write to stdout\n";
int main(void) 
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1 != sizeof(buf) - 1)) {
        printf("wirte error");
        exit(1);
    }
    printf("before fork\n");

    if ((pid = fork()) < 0) {
        printf("fork error");
        exit(2);
    } else if (pid == 0) {
        glob++;
        var++;
    } else {
        sleep(2);
    }
    printf("current_pid = %d, glob = %d, var = %d, return_pid = %d\n", getpid(), glob, var, pid);
    exit(0);
}