#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int    fork(int pid)
{
    printf("\nEnter the process: ");
    scanf("%d", &pid);
    return(pid);
}

int main()
{
    int pid;
    pid = fork(pid);

    if (pid == -1) // child process
        return 1;
    if (pid == 0) // parent process
        while (pid == 0)
        {
            printf("\nSome test goes here");
            usleep(4000000);
            pid = fork(pid);
        }
    else
    {
        sleep(1);
        kill(pid, SIGKILL); //process id kill
        WAIT_CHILD;
    }
    pid = fork(pid);
    return 0;
}
