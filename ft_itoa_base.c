/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:51:06 by mdude             #+#    #+#             */
/*   Updated: 2020/11/24 13:51:46 by mdude            ###   ########.fr       */
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

static char	*hex(int up, unsigned long n, int rank)
{
	int		k;
	char	*s;

	k = 0;
	s = (char *)malloc(sizeof(char) * intlen(n) + 1);
	while (n > 0)
	{
		if (n % rank >= 10 && n % rank < 16)
			s[k++] = (up == 0) ? (n % rank - 10 + 'a') : (n % rank - 10 + 'A');
		else if (n % rank == 16)
			s[k++] = '0';
		else
			s[k++] = n % rank + '0';
		n = n / rank;
	}
	s[k] = '\0';
	return (s);
}

char		*ft_itoa_base(unsigned long n, int rank, int up)
{
	char	*str;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (rank == 10)
		return (ft_itoa(n));
	if (rank < 10 && rank > 1)
	{
		while (n > 0)
		{
			str = (char *)malloc(sizeof(char) * intlen(n) + 1);
			str[i] = n % rank + '0';
			n = n / rank;
			i++;
		}
		str[i] = '\0';
	}
	else
		str = hex(up, n, rank);
	return (ft_reverse(str));
}
