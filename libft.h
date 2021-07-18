/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:19:48 by mdude             #+#    #+#             */
/*   Updated: 2020/10/29 12:38:59 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			flag_minus;
	int			flag_zero;
	int			flag_dot;
	int			flag_star;
	char		specify;
	int			width;
	int			len;
}				t_flags;
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_itoa(long n);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_itoa_base(unsigned long n, int rank, int up);
int				intlen(long n);
int				is_specify(char c);
int				is_flag(char c);
int				is_percent(char c);
char			*ft_itoa_uns(unsigned int n);
char			*init_string(int i, const char *format);
t_flags			init_sflags(char *str, va_list ap);
int				ft_isdigit(int c);
int				format_c(t_flags flag, va_list ap);
int				format_s(t_flags flag, va_list ap);
char			*ft_strjoin(char *s1, char *s2);
int				format_p(t_flags flag, va_list ap);
int				format_di(t_flags flag, va_list ap);
char			*ft_dot(long num, t_flags flag, int rank, int up);
int				ft_minus(t_flags flag, char *str);
char			*ft_zero(long num, t_flags flag, int rank, int up);
int				format_u(t_flags flag, va_list ap);
int				format_x(t_flags flag, va_list ap);
int				format_xx(t_flags flag, va_list ap);
int				format_prec(t_flags flag);
char			*ft_zero_int(long num, t_flags flag);
char			*ft_dot_int(long num, t_flags flag);
t_flags			flags_null();
int				check_spec(t_flags flag, va_list ap);

#endif
