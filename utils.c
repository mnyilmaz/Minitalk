/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:32 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:40:36 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minitalk.h"

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

int	ft_atoi(char *s)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	if (*s == 45 || *s == 43)
	{
		if (*s == 45)
			sign *= -1;
		s++;
	}
	while (*s > 47 && *s < 58)
	{
		result = (*s - 48) + (result * 10);
		s++;
	}
	return (result * sign);
}

void reset(int *a, int *b)
{
	*a *= 0;
	*b *= 0;
}
