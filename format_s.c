/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:16:31 by mdude             #+#    #+#             */
/*   Updated: 2020/12/01 11:16:33 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		format_s(t_flags flag, va_list ap)
{
	int		count;
	char	*str;
	int		len;

	count = 0;
	str = ft_strdup(va_arg(ap, char *));
	if (!str)
		str = ft_strdup("(null)");
	if (str && flag.flag_dot > 0)
		str[flag.len] = '\0';
	count = count + ft_minus(flag, str);
	len = (int)ft_strlen(str);
	free(str);
	return (count + len);
}
