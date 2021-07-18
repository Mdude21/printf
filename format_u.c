/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:40:44 by mdude             #+#    #+#             */
/*   Updated: 2020/12/02 12:40:45 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_u(t_flags flag, va_list ap)
{
	int				count;
	unsigned int	num;
	long			unum;
	char			*str;
	int				len;

	count = 0;
	num = va_arg(ap, unsigned int);
	unum = num;
	if (flag.flag_zero == 1 && flag.flag_dot == 0)
		str = ft_zero(unum, flag, 10, 0);
	else
		str = ft_dot(unum, flag, 10, 0);
	count = count + ft_minus(flag, str);
	len = ft_strlen(str);
	free(str);
	return (count + len);
}
