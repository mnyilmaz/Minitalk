#include "minitalk.h"

void	handle_the_server(int signal)
{
	static int	bit;
	static int	res;

	if (signal == SIGUSR1)
		res += (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", res);
		reset(&bit, &res);
	}
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handle_the_server);
	signal(SIGUSR2, handle_the_server);
	while (1)
		pause();
}
