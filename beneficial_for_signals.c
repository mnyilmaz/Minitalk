#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


/* This program will allow you to understand how to prevent sending process to the background. Can be found as "Signal Handling" */

void	handle_sigtstp(int sig)
{
	printf("You are not authorized to stop the process!\n"); // Ctrl + Z will not allow us to send the process background
}

int main(int argc, char* argv[])
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result of %d * 5 = %d\n", x, x * 5);
	return 0;
}

//********************************************************************************************************************************

/* This program will allow you to understand how to get notification from the process. Usage of sifo function is not necessary for Linux and MacOS but
in Windows compiling with VSCode may occur problems due to "fork" function. This function is defined inside <sys/types.h> library. If you have troubles
to call this function in windows just to observe signal process and usleep() try to add sifo function. */

int sifo(int pid)
{
    printf("\nEnter the process: ");
    scanf("%d", &pid);
    return (pid);
}

int main()
{
    int pid = fork();;
    //int pid2 = 0;
    //pid2 = sifo(pid2);

    if (pid == -1) // child process
        return 1;
    if (pid == 0) // parent process
        while (pid == 0)
        {
            printf("\nSome test goes here");
            usleep(4000000);
            //pid2 = sifo(pid2);
        }
    else
    {
        sleep(1);
        kill(pid, SIGKILL); // process id kill
        wait(0);
    }
    //pid2 = sifo(pid2);
    return 0;
}
