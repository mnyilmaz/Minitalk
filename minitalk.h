/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:59:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/04 14:17:07 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_states(char spec, va_list to_do);
int	ft_atoi(const char *s);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int num);

void set_signal_action(void);
void handle_the_server(int signal);

#endif