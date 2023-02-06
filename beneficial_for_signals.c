#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

/* This documentation is for to understand signals in C programming language. Compiling these programs with -Wall -Wextra -Werror flags may cause 
error throughout your programming. At first just compile these with gcc *.c */

/* This program will allow you to understand how to prevent sending process to the background. Can be found as "Signal Handling" */

void	handle_sigtstp(int sig)
{
	printf("You are not authorized to stop the process!\n"); // Ctrl + Z will not allow us to send the process background
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART; // SA_RESTART: Provide behavior compatible with BSD signal semantics by making certain system calls restartable across signals.
	sigaction(SIGTSTP, &sa, NULL); // If we have another sigaction set before that it would save it inside third parameter
	//SIGTSTP is an interactive stop signal. 

	// If you don't want to use struct, use function down below instead of above:
	signal(SIGTSTP, &handle_sigtstp);
	// But avoid using signal() function due to warning on the manual page. signal() function may vary across UNIX versions so
	// using sigaction() instead of signal() is recommended

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result of %d * 5 = %d\n", x, x * 5);
	return 0;
}

//**************************************************************************************************************************************************//

/* This program will allow you to understand how to get notification from the process. Usage of sifo function is not necessary for Linux and MacOS but
in Windows compiling with VSCode may occur problems due to "fork" function. This function is defined inside <sys/types.h> library. If you have troubles
to call this function in windows just to observe signal process and usleep() try to add sifo function. */

int sifo(int pid)
{
    printf("\nEnter the process: ");
    scanf("%d", &pid);
    return (pid);
}

int main(int argc, char* argv[])
{
    int pid = fork();
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
