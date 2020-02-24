/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:07:03 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 23:34:55 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sdic(char *src, va_list args, int i)
{
	if (src[i] == 's')
	{
		i++;
		g_s = va_arg(args, char *);
		if (g_s == NULL)
			g_s = "(null)";
		ft_string_flags(g_s);
	}
	else if (src[i] == 'd' || src[i] == 'i')
	{
		i++;
		g_s = ft_itoa(va_arg(args, int));
		ft_i_or_d_flags(g_s);
	}
	else if (src[i] == 'c')
	{
		i++;
		g_c = va_arg(args, int);
		ft_char_flags(g_c);
	}
	return (i);
}

int				ft_pux(char *src, va_list args, int i)
{
	if (src[i] == 'p')
	{
		i++;
		g_pp = va_arg(args, unsigned long);
		ft_p_flags(g_pp);
	}
	else if (src[i] == 'u')
	{
		i++;
		g_s = ft_utoa(va_arg(args, unsigned int));
		ft_u_flags(g_s);
	}
	else if (src[i] == 'x')
	{
		i++;
		g_s = ft_hextoa(va_arg(args, int));
		ft_hexa_flags(g_s);
	}
	return (i);
}

int				ft_xpp(char *src, va_list args, int i)
{
	if (src[i] == 'X')
	{
		i++;
		g_s = ft_uperhextoa(va_arg(args, int));
		ft_hexaa_flags(g_s);
	}
	else if (src[i] == '%')
	{
		i++;
		ft_char_flags('%');
	}
	return (i);
}

int				ft_elseee(char *src, int i)
{
	ft_putchar(src[i]);
	i++;
	g_nb++;
	return (i);
}

int				ft_printf(char *src, ...)
{
	va_list				args;
	int					i;

	i = 0;
	g_nb = 0;
	va_start(args, src);
	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			ft_init_flags();
			i = ft_check_flags(src, i, args);
			if (src[i] == 's' || src[i] == 'd' || src[i] == 'i'
					|| src[i] == 'c')
				i = ft_sdic(src, args, i);
			else if (src[i] == 'p' || src[i] == 'u' || src[i] == 'x')
				i = ft_pux(src, args, i);
			else if (src[i] == 'X' || src[i] == '%')
				i = ft_xpp(src, args, i);
			ft_init_flags();
		}
		else if (src[i] != '%')
			i = ft_elseee(src, i);
	}
	return (g_nb);
}
