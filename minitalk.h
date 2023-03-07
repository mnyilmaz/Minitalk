/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:32 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:40:36 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_atoi(char *s);
int		ft_states(char spec, va_list to_do);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_printf(char *fmt, ...);
int		ft_print_int(int num);
void	set_signal_action(void);
void	handle_the_server(int signal);
void	handle_the_client(pid_t pid, char bit);
void reset(int *a, int *b);

#endif
