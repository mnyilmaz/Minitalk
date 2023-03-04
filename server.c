/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:27:07 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/25 17:27:07 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>
#include <stdio.h>

void handle_the_server(int signal)
{
	static int	bit = 7;
	static int	set = 0;
	static char c;

	if (signal == SIGUSR1)
		set += (1 << bit);
	else
		set += (0 << bit);
	if (bit == 0)
	{
		printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

/* void set_signal_action(void)
{
	struct sigaction act;
	act.sa_handler = &handle_the_server;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
} */

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("Parent: %d\n", pid);
	//printf("Child Developer PID: %d\n", pid);
	
	signal(SIGUSR1, handle_the_server);
	signal(SIGUSR2, handle_the_server);

	while(1)
		pause();

	return (0);
}
