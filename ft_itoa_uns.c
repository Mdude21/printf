/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:06:00 by mdude             #+#    #+#             */
/*   Updated: 2020/11/25 12:06:03 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *s)
{
	int		i;
	int		k;
	char	temp;

	i = 0;
	k = (int)ft_strlen(s) - 1;
	while (k > i)
	{
		temp = s[i];
		s[i] = s[k];
		s[k] = temp;
		i++;
		k--;
	}
	return (s);
}

static int	radix(long n)
{
	int count;

	count = 1;
	while (n / 10 > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa_uns(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(radix(n) + 1);
	if (!str)
		return (NULL);
	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = '\0';
	return (ft_reverse(str));
}
