/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:40:47 by mdude             #+#    #+#             */
/*   Updated: 2020/12/01 13:40:49 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_di(t_flags flag, va_list ap)
{
	int		count;
	int		num;
	char	*str;
	int		len;

	num = va_arg(ap, int);
	count = 0;
	if (flag.flag_zero == 1 && flag.flag_dot == 0)
		str = ft_zero_int(num, flag);
	else
		str = ft_dot_int(num, flag);
	count = count + ft_minus(flag, str);
	len = ft_strlen(str);
	free(str);
	return (count + len);
}
