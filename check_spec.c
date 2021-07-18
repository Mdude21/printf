/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:57:59 by mdude             #+#    #+#             */
/*   Updated: 2020/12/05 11:58:00 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_spec(t_flags flag, va_list ap)
{
	int k;

	k = 0;
	if (flag.specify == 'c')
		k = k + format_c(flag, ap);
	if (flag.specify == 's')
		k = k + format_s(flag, ap);
	if (flag.specify == 'p')
		k = k + format_p(flag, ap);
	if (flag.specify == 'd' || flag.specify == 'i')
		k = k + format_di(flag, ap);
	if (flag.specify == 'u')
		k = k + format_u(flag, ap);
	if (flag.specify == 'x')
		k = k + format_x(flag, ap);
	if (flag.specify == 'X')
		k = k + format_xx(flag, ap);
	if (flag.specify == '%')
		k = k + format_prec(flag);
	return (k);
}
