#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* This documentation is for to understand signals in C programming language. Compiling these programs with -Wall -Wextra -Werror flags may cause
error throughout your programming. At first just compile these with gcc *.c */

// Difference between program and process
A program is a set of instructions in order to perform a particular task. A process is an active instamce of the program whis is started when the program is executed. 
Throughout the execution of the program there might be multiple processes. The process executes the instructions written in the program. A process can form smaller processes
called "child process". In operating systems there should be a main system called as "parent process" that to invoke all the other processes. Kernel_task can be given as an 
examle for this. In summary in process, there must be one initial proces to form all the other processes.

/* This program will allow you to understand how to get notification from the process. Usage of sifo function is not necessary for Linux and MacOS but
in Windows compiling with VSCode may occur problems due to "fork" function. This function is defined inside <sys/types.h> library. If you have troubles
to call this function in windows just to observe signal process and usleep() try to add sifo function. */

// Understanding the fork() function:
int main(int argc, char* argv[])
{
	fork();
	printf("Fork is working... %d\n", getpid());
	if (fork() == 0)
		printf("Child process is working...: %d", getpid());
	else
		printf("The main process is working...: %d", getpid());

	// PID: Process ID
	// Output will be:
	// Fork is working... ID1		-> Parent Process
	// Fork is working... ID1 + 1	-> Child Process
	// Fork system call is used for forming a new process, which is called child process,
	// which runs concurrently with the process that makes the fork() call (parent process).
	// Fork() allows user to clone the process. Try >ps aux and >top in terminal and observe PID.
	// For child fork return 0 and to the parent it return PID of the child.

	return (0);
}

/* Remember! Child process has the exactly the same memory with the main (parent) process. But memory place where they're allocated is different. */

//************************************************************************************************************************************************************//

// Understanding the wait() function:
int main(int argc, char *argv[])
{
	int process = fork();
	int n;
	int i;

	if (process == 0)
		n = 1;
	else
	{
		n = 6;
		wait();
	}

	// If process != 0 that means child process can be executed while the main process is waiting.

	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}

	// fflush(): Its purpose is to clear the output buffer and move the buffered data to console
	// Purpose of using wait() function is to ensure that the main process is done first before child process.
	// In this example the main process waits for the child process execution to be done.
	// Without with() this usage output may vary according to operating system, to control processes use wait() function.

	if (process != 0)
		printf("\n");

	// This printf executes twice one for the main process, one for the child process. To prevent, use if statment as this.
	// While compiling wait() functio can cause an error such as "Wimplicit-function-decleration". Ignore that and run your program.

	return (0);
}

//************************************************************************************************************************************************************//

// Process IDs in C
int main(int argc, char *argv[])
{
	int process = fork();
	printf("Current ID: %d\nThe main ID: %d\n", getpid(), getppid());

	// First of all, please comment the printf function above before executing the program. 
	// Every process has their own process IDs in program. These IDs allows user to determine which process is executing throughout the program running. 
	// getpid() allows us to reach current ID which belongs to the child and getppid() is to obtain the main process ID. 
	
	// To terminate the main process first (and observe how their IDs got reversed):
	if (process == 0)
		sleep(1);
	printf("Current ID: %d\nThe main ID: %d\n", getpid(), getppid());

	// At the second output "The main ID" will be the same as the previous "Current ID".
	// In that case program understand this: A new main (parent) process has assigned to this child process! 
	// To free the memory must wait the child processes. Killing the child processes will not free the memory. 
	// So prevent memory leaks first child proces sor processes must be executed, later one the main process should execute. 

	// if (process != 0)
	// 	wait(NULL);

	int result = wait(NULL);
	if (result == -1)
		printf("There are no children process to wait\n");
	else
		printf("%d finished execution\n", result);
	
	// After execution of the main and child processes if wait result is -1 programmer can understand that there are no children process to be wait.
	// If this result is different then -1, result can give the PID of the last executed child process. 
	
	return (0);
}

/* Remember! Child process is always terminates first before the main process. */

//************************************************************************************************************************************************************//

int sifo(int pid)
{
	printf("\nEnter the process: ");
	scanf("%d", &pid);
	return (pid);
}

int main(int argc, char *argv[])
{
	int pid = fork();
	// int pid2 = 0;
	// pid2 = sifo(pid2);

	if (pid == -1) // Forming of a child process was unsuccessful
		return 1;
	if (pid == 0) // Returned to the newly formed child process
		while (pid == 0)
		{
			printf("\nSome test goes here");
			usleep(4000000);
			// pid2 = sifo(pid2);
		}
	else // Returned to parent or caller. The value contains process ID of newly formed child process.
	{
		sleep(1);
		kill(pid, SIGKILL); // process id kill
		wait(0);
	}
	// pid2 = sifo(pid2);
	return (0);
}

/* Remember! First understand usage of fork() and try to execute the code using the fork(). Fork() function has 3 main outputs. Negative, positive and zero. */

//************************************************************************************************************************************************************//

/* This program will allow you to understand how to prevent sending process to the background. Can be found as "Signal Handling" */

void handle_sigtstp(int sig)
{
	printf("You are not authorized to stop the process!\n"); // Ctrl + Z will not allow us to send the process background
}

void handle_sigcont(int sig)
{
	printf("\nInput number: "); // Ctrl + Z will suspend a.out
	fflush(stdout);
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
	sigaction(SIGTSTP, &sa, NULL);

	// Now Ctr + Z will print out "You are not authorized to stop the process!"
	// SA_RESTART: Provide behavior compatible with BSD signal semantics by making certain system calls restartable across signals.
	// 3rd parameter in sigaction() function stands for if there is another sigaction set before that it would save it inside this parameter.
	// SIGTSTP is an interactive stop signal.

	// To continue the program:
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);

	// Now Ctr + Z will suspend or stop the "a.out" (that name may vary depend on your program ouput).
	// After Ctrl + Z program will be suspended and if you enter
	// >fg command from the terminal process will be fore-grounded again and user can enter an "Input number: " for execution
	// SIGCONT is a signal that instructs the operating sysytem to continue (restart) a process previously paused by the SIGSTOP or SIGTSTP.

	// signal() function usage:
	signal(SIGTSTP, &handle_sigtstp);

	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result of %d * 5 = %d\n", x, x * 5);
	return (0);
}

/* Remember! Do not forget to comment lines that you don't need inside your program. For example to prevent stop, comment continue and signal() phases. */

//************************************************************************************************************************************************************//

/* This program will allow you to understand communication between using signals.  */

