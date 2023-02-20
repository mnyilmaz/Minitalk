#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int	handle_the_server(int signal)
{
	printf("Remember this is SIGUSR1!");
	return(0);
}

int main(int argc, char *argv[])
{
	int pid = fork();

	if (pid == -1)
	{
		printf("Invalid signal attempt!");
		return(0);
	}

	if (pid == 0)
	{	// Child process
		usleep(5000);
		kill(getppid(), SIGUSR1);
	}
	else
	{	// Parent process
		struct sigaction sa = {0};
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_the_server;
		sigaction(SIGUSR1, &sa, NULL);

		printf("You've reached to the parent process!");
	}
	wait(NULL);
}
