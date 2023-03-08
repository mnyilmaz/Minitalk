/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:10:04 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/08 12:15:50 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_the_client(pid_t pid, char bit, int shift)
{
	while(shift >= 0)
	{
		if((bit >> shift) & 1)
			kill(pid, SIGUSR1);
		else 
			kill(pid, SIGUSR2);
		usleep(40);  
		shift--;
	}
}

int	main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while(argv[2][i])
			handle_the_client((pid_t)ft_atoi(argv[1]), argv[2][i++], 7);
		next_line((pid_t)ft_atoi(argv[1]));
	}
	else
		ft_printf("You shall not send the signal!");
	return (0);
}
