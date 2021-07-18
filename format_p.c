/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:33:35 by mdude             #+#    #+#             */
/*   Updated: 2020/12/01 12:33:37 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_p(t_flags flag, va_list ap)
{
	int		count;
	char	*str;
	void	*p;
	int		len;
	char	*tmp;

	count = 0;
	p = va_arg(ap, void *);
	tmp = ft_dot((unsigned long)p, flag, 16, 0);
	str = ft_strjoin("0x", tmp);
	count = count + ft_minus(flag, str);
	len = ft_strlen(str);
	free(str);
	free(tmp);
	return (count + len);
}
