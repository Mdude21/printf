/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:22:43 by mdude             #+#    #+#             */
/*   Updated: 2020/11/24 11:22:45 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(const char *format, int *i, va_list ap)
{
	char	*string_format;
	int		count;
	t_flags	flag;

	string_format = init_string(*i + 1, format);
	*i = *i + ft_strlen(string_format) + 1;
	flag = init_sflags(string_format, ap);
	count = check_spec(flag, ap);
	free(string_format);
	return (count);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		k;
	va_list	ap;

	i = 0;
	k = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if ((!is_percent(format[i])))
		{
			ft_putchar(format[i++]);
			k++;
		}
		else
			k = k + counter(format, &i, ap);
		va_end(ap);
	}
	return (k);
}
