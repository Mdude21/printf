/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:37:41 by mdude             #+#    #+#             */
/*   Updated: 2020/12/04 11:37:43 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillz(int width, long *num)
{
	int		i;
	int		k;
	char	*str;

	if (width > intlen(*num))
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * width + (*num < 0) + 1);
		if (*num < 0)
		{
			*num = -*num;
			str[0] = '-';
			i++;
		}
		k = i;
		while (width > intlen(*num) + k + (*num == 0))
		{
			str[i++] = '0';
			width--;
		}
		str[i] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

char		*ft_zero_int(long num, t_flags flag)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = fillz(flag.width, &num);
	tmp = str;
	tmp2 = ft_itoa(num);
	str = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (str);
}
