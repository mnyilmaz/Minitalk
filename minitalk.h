/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:09:45 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/08 12:19:49 by mervyilm         ###   ########.fr       */
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
void	handle_the_server(int signal);
void	handle_the_client(pid_t pid, char bit, int shift);
void	next_line(pid_t pid);
void	set_signal_action(void);
void 	reset(int *a, int *b);
void	ft_alarm(void);

#endif
