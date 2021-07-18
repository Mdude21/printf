/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:59:50 by mdude             #+#    #+#             */
/*   Updated: 2020/11/30 14:59:52 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_c(t_flags flag, va_list ap)
{
	int count;

	count = 0;
	if (flag.flag_minus == 0)
	{
		while (flag.width > 1)
		{
			ft_putchar(' ');
			flag.width--;
			count++;
		}
		ft_putchar((char)va_arg(ap, int));
	}
	else
	{
		ft_putchar((char)va_arg(ap, int));
		while (flag.width > 1)
		{
			ft_putchar(' ');
			flag.width--;
			count++;
		}
	}
	return (count + 1);
}
