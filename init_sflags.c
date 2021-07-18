/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:34:15 by mdude             #+#    #+#             */
/*   Updated: 2020/11/30 12:34:16 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		check_zero(t_flags *flag, char *str, int *i)
{
	if (flag->flag_minus == 0)
	{
		flag->flag_zero = 1;
		flag->width = ft_atoi(&str[*i + 1]);
		*i = *i + intlen(ft_atoi((&str[*i + 1])));
	}
	else
		*i = *i + 1;
	if (flag->len < 0)
		flag->flag_dot = 0;
}

static void		check_dot(t_flags *flag, char *str, int *i)
{
	flag->flag_dot = 1;
	flag->len = ft_atoi(&str[*i + 1]);
	*i = *i + 1 + intlen(ft_atoi((&str[*i + 1])));
	if (flag->len < 0)
		flag->flag_dot = 0;
}

static void		check_minus(t_flags *flag, char *str, int *i)
{
	flag->flag_minus = 1;
	flag->width = ft_atoi(&str[*i + 1]);
	*i = *i + 1 + intlen(flag->width);
	if (flag->len < 0)
		flag->flag_dot = 0;
}

static t_flags	check_star(t_flags *flag, va_list ap, char *str, int i)
{
	int temp;

	flag->flag_star++;
	temp = va_arg(ap, unsigned int);
	if (is_specify(str[i + 1]) && flag->flag_dot == 1)
		flag->len = temp;
	else
	{
		if (temp < 0)
		{
			temp = -temp;
			flag->flag_minus = 1;
			flag->flag_zero = 0;
		}
		flag->width = temp;
	}
	if (flag->len < 0)
		flag->flag_dot = 0;
	return (*flag);
}

t_flags			init_sflags(char *str, va_list ap)
{
	int		i;
	t_flags	flag;

	i = 0;
	flag = flags_null();
	if (!(is_flag(str[i])))
	{
		flag.width = ft_atoi(str);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	flag.specify = str[ft_strlen(str) - 1];
	while (str[i])
	{
		if (str[i] == '0')
			check_zero(&flag, str, &i);
		if (str[i] == '-')
			check_minus(&flag, str, &i);
		if (str[i] == '.')
			check_dot(&flag, str, &i);
		if (str[i] == '*')
			flag = check_star(&flag, ap, str, i);
		i++;
	}
	return (flag);
}
