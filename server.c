/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:09:53 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/08 11:09:53 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_alarm(void)
{
	ft_printf("Message received successfully!\n");
}


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

void set_signal_action(void)
{
/* 	struct sigaction act;

	act.sa_flags = SA_RESTART;
	act.sa_mask = 0;
	act.sa_handler = &handle_the_server; */

/* 	sigaddset(&act.sa_handler, SIGUSR1);
	sigemptyset(&act.sa_handler);
	sigaddset(&act.sa_handler, SIGUSR2);
	sigemptyset(&act.sa_handler); */
	
	struct sigaction alarm;
	alarm.sa_flags = SA_RESTART;
	alarm.sa_mask = 0;
	alarm.sa_handler = &handle_the_server;

	sigaction(SIGTTOU, &alarm, 0);
	ft_printf("Signal received!");
} 

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handle_the_server);
	signal(SIGUSR2, handle_the_server);
	while (1)
		pause();
}
