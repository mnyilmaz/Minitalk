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
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_the_server);
	signal(SIGUSR2, handle_the_server);
	while (1)
		pause();
}

/* void set_signal_action(void)
{
	struct sigaction act;
	act.sa_handler = &handle_the_server;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
} */
