/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:48:30 by mdude             #+#    #+#             */
/*   Updated: 2020/12/01 15:48:32 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_minus(t_flags flag, char *str)
{
	int	count;

	count = 0;
	if (flag.flag_minus == 1)
	{
		ft_putstr(str);
		while (flag.width > (int)ft_strlen(str))
		{
			ft_putchar(' ');
			flag.width--;
			count++;
		}
	}
	else
	{
		while (flag.width > (int)ft_strlen(str))
		{
			ft_putchar(' ');
			flag.width--;
			count++;
		}
		ft_putstr(str);
	}
	return (count);
}
