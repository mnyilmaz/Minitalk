#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int pid = 0;
    if (pid == -1) // child process
        return 1;
    if (pid == 0) // parent process
        while (1)
        {
            printf("\nSome test goes here");
            usleep(4000000);
        }
    else
    {
        sleep(1);
        kill(pid, SIGKILL); //process id kill
        WAIT_CHILD;
    }
    return 0;
}
