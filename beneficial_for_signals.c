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

void	handle_sigcont(int sig)
{
	printf("Input number: \n"); // Ctrl + Z will suspend a.out 
	fflush(stdout);
	// fflush(): Its purpose is to clear the output buffer and move the buffered data to console
}

int main(void)
{
	
	// For handling signals 2 functions can be used. These are sigaction() with 3 parameters and signal() with 2 paramteres.
	// In signal handling usage of signal() function is easier but not recommended in it's manual page.
	// Because signal() function may vary across UNIX versions so usage of sigaciton() is more reliable. 
	
	// First form your struct for sigaction() function:
	struct sigaction sa;
	
	// To prevent stop the program:
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART; 
	sigaction(SIGTSTP, &sa, NULL); // Now Ctr + Z will print out "You are not authorized to stop the process!" 
	
	// SA_RESTART: Provide behavior compatible with BSD signal semantics by making certain system calls restartable across signals.
	// 3rd parameter in sigaction() function stands for if there is another sigaction set before that it would save it inside this parameter.
	// SIGTSTP is an interactive stop signal. 
	
	// To continue the program:
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL); // Now Ctr + Z will suspend or stop the "a.out" (or whatever your program output is)
	// After Ctrl + Z, program will be suspended and if you enter
	// >fg command from the terminal process will be fore-grounded again and user can enter an "Input number: " for execution.

	// signal() function usage:
	signal(SIGTSTP, &handle_sigtstp);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result of %d * 5 = %d\n", x, x * 5);
	return 0;
}

/* Remember! Do not forget to comment lines that you don't need inside your program. For example to prevent stop, comment continue and signal() phases. */

//******************************************************************************************************************************************************//

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
