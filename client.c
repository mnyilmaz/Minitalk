/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:51:22 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/25 18:58:01 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_the_client(int pid, char *str)
{
	char chr;
	int i;
	int res;
	int bit;

	i = 0;
	res = 0;
	while(str[i])
	{
		bit = 7;
		chr = str[i];
		while(bit >= 0)
		{
			res = (i >> bit) & 1;
			if(res)
				kill(pid, SIGUSR1);
			else 
				kill(pid, SIGUSR2);
			usleep(400);  
			bit--;
		}
		write(1, " ", 1);
		i++;
	}
}

#include <xlocale.h>
#include <stdio.h>
int main(int argc, char *argv[])
{	
	if (argc != 3)
	{
		printf("You entered incorrectly, you need to enter three arguments");
		return (0);
	}
	handle_the_client(atoi(argv[1]), argv[2]);
	return(0);
}

/************************************************************************************************************/

#include "minitalk.h"

void	handle_the_client(pid_t pid, char bit)
{
	int	shift;

	shift = 7;
	while (shift > -1)
	{
		if ((bit >> shift) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		shift--;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
		while(argv[1][i])
			handle_the_client((pid_t)(ft_atoi(argv[1])), argv[2][i++]);
	else
		ft_printf("You shall not send the signal!");
	return (0);
}
