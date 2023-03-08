/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:10:04 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/08 15:54:29 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_killed;

void	handle_the_client(pid_t pid, char bit, int shift)
{
	while (shift >= 0)
	{
		if ((bit >> shift) & 1)
			g_killed = kill(pid, 30);
		else
			g_killed = kill(pid, 31);
		usleep(40);
		shift--;
	}
}

int	main(int argc, char *argv[])
{
	int		i;

	g_killed = -1;
	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
			handle_the_client((pid_t)ft_atoi(argv[1]), argv[2][i++], 7);
		next_line((pid_t)ft_atoi(argv[1]));
	}
	if (g_killed >= 0)
		ft_printf("Message has been sent successfully");
	else
		ft_printf("PID or argument number is not valid!");
	return (0);
}
