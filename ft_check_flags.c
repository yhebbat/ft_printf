/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:37:56 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 20:11:43 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(char *src, int i)
{
	while (src[i] == '0' || src[i] == '-')
	{
		if (src[i] == '-')
			g_moin = 1;
		if (src[i] == '0')
			g_zero = 1;
		i++;
	}
	return (i);
}

int		ft_largeur(char *src, int i, va_list args, int ar)
{
	if (src[i] == '*')
	{
		ar = va_arg(args, int);
		if (ar < 0)
		{
			g_moin = 1;
			ar = -ar;
		}
		g_largeur = ar;
		i++;
	}
	else
	{
		g_largeur = atoi(&src[i]);
		while (src[i] >= '0' && src[i] <= '9')
			i++;
	}
	return (i);
}

int		ft_precision(char *src, int i, va_list args)
{
	g_point = 1;
	i++;
	if (src[i] == '-')
	{
		g_moinprecision = 1;
		i++;
	}
	if ((src[i] >= '0' && src[i] <= '9') || src[i] == '*')
	{
		if (src[i] == '*')
		{
			g_precision = va_arg(args, int);
			if (g_precision < 0)
				g_point = 0;
			i++;
		}
		else
		{
			g_precision = atoi(&src[i]);
			while (src[i] >= '0' && src[i] <= '9')
				i++;
		}
	}
	return (i);
}

int		ft_check_flags(char *src, int i, va_list args)
{
	int ar;

	ar = 0;
	i++;
	if (src[i] == '0' || src[i] == '-')
		i = ft_flags(src, i);
	if ((src[i] >= '0' && src[i] <= '9') || src[i] == '*')
		i = ft_largeur(src, i, args, ar);
	if (src[i] == '.')
		i = ft_precision(src, i, args);
	return (i);
}
