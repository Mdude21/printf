/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:54:55 by mdude             #+#    #+#             */
/*   Updated: 2020/12/02 11:18:39 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillzero(t_flags flag, long num, int len)
{
	int		i;
	int		k;
	char	*str;

	if (flag.width > len)
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * flag.width + (num < 0) + 1);
		if (num < 0)
		{
			num = -num;
			str[0] = '-';
			i++;
		}
		k = i;
		while (flag.width > len + k)
		{
			str[i++] = '0';
			flag.width--;
		}
		str[i] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

char		*ft_zero(long num, t_flags flag, int rank, int up)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp = ft_itoa_base(num, rank, up);
	len = (int)ft_strlen(tmp);
	str = fillzero(flag, num, len);
	tmp2 = str;
	str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	return (str);
}
