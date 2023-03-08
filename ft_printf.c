/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:00:42 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/08 15:01:06 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_states(char spec, va_list to_do)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(to_do, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(to_do, char *)));
	else if (spec == 'i' || spec == 'd')
		return (ft_print_int(va_arg(to_do, int)));
	else if (spec == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		ft_print_char(*s++);
		len++;
	}
	return (len);
}

int	ft_print_int(int num)
{
	int	rlen;

	rlen = 0;
	if (num == -2147483648)
		return (ft_print_str("-2147483648"));
	if (num < 0)
	{
		rlen += ft_print_char('-');
		rlen += ft_print_int(num * -1);
	}
	else if (num >= 10)
	{
		rlen += ft_print_int(num / 10);
		rlen += ft_print_int(num % 10);
	}
	else
		rlen += ft_print_char(num + '0');
	return (rlen);
}

int	ft_printf(char *fmt, ...)
{
	va_list	to_do;
	char	spec;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(to_do, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			i++;
			spec = *(fmt + i);
			len += ft_states(spec, to_do);
		}
		else
			len += ft_print_char(*(fmt + i));
		i++;
	}
	va_end(to_do);
	return (len);
}
