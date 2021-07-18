/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:08:20 by mdude             #+#    #+#             */
/*   Updated: 2020/12/02 14:08:22 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_prec(t_flags flag)
{
	int count;

	count = -1;
	if (flag.flag_minus == 1)
	{
		ft_putchar('%');
		count++;
		while (++count < flag.width)
			ft_putchar(' ');
	}
	else
	{
		if (flag.flag_zero == 1)
			while (++count < flag.width - 1)
				ft_putchar('0');
		else
			while (++count < flag.width - 1)
				ft_putchar(' ');
		ft_putchar('%');
		count++;
	}
	return (count);
}
