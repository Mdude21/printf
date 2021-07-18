/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:39:38 by mdude             #+#    #+#             */
/*   Updated: 2020/12/05 11:39:42 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	flags_null(void)
{
	t_flags newflag;

	newflag.width = 0;
	newflag.len = 0;
	newflag.flag_minus = 0;
	newflag.flag_dot = 0;
	newflag.flag_zero = 0;
	newflag.flag_star = 0;
	return (newflag);
}
