/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:31:39 by mdude             #+#    #+#             */
/*   Updated: 2020/12/02 11:31:41 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(t_flags flag, int len, long num)
{
	int		i;
	char	*str;

	if (flag.len > len)
	{
		i = 0;
		str = (char *)malloc(sizeof(char) * flag.len + (num < 0) + 1);
		if (num < 0)
		{
			str[0] = '-';
			i++;
		}
		while (flag.len > len)
		{
			str[i++] = '0';
			flag.len--;
		}
		str[i] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

char		*ft_dot(long num, t_flags flag, int rank, int up)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		len;

	if (flag.flag_dot > 0 && flag.len == 0 && num == 0)
		return (ft_strdup(""));
	tmp = ft_itoa_base(num, rank, up);
	len = (int)ft_strlen(tmp);
	str = fill(flag, len, num);
	tmp2 = str;
	str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	return (str);
}
