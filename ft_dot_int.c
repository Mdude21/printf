/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:41:40 by mdude             #+#    #+#             */
/*   Updated: 2020/12/04 11:41:41 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillz(int len, long *num)
{
	int		i;
	char	*str;

	if (len > intlen(*num))
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * len + (*num < 0) + 1);
		if (*num < 0)
		{
			*num = -*num;
			str[0] = '-';
			i++;
		}
		while (len > intlen(*num) + (*num == 0))
		{
			str[i++] = '0';
			len--;
		}
		str[i] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

char		*ft_dot_int(long num, t_flags flag)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	if (flag.flag_dot > 0 && flag.len == 0 && num == 0)
		return (ft_strdup(""));
	str = fillz(flag.len, &num);
	tmp = ft_itoa(num);
	tmp2 = str;
	str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	return (str);
}
