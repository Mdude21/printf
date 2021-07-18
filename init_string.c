/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:00:46 by mdude             #+#    #+#             */
/*   Updated: 2020/11/30 12:00:47 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_string(int i, const char *format)
{
	int		k;
	int		j;
	char	*res;

	k = i;
	j = 0;
	while (format[i] && (!is_specify(format[i])))
		i++;
	res = (char *)malloc(sizeof(char) * (i - k + 1));
	while (k <= i)
	{
		res[j] = format[k];
		j++;
		k++;
	}
	res[j] = '\0';
	return (res);
}
