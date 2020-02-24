/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:40:40 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 20:35:47 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_first_condition_u(int len)
{
	while (g_largeur > len && g_largeur > g_precision)
	{
		if (g_zero && g_point == 0)
		{
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
}

void		ft_2nd_condition_u(int len)
{
	while (g_precision > len)
	{
		ft_putchar('0');
		g_precision--;
		g_nb++;
	}
}

void		ft_3rd_condition_u(int len, int pre)
{
	if (g_precision > len && g_moinprecision)
	{
		while (g_precision > len)
		{
			ft_putchar(' ');
			g_precision--;
			g_nb++;
		}
	}
	if (g_largeur > len && g_moin && g_moinprecision == 0)
	{
		while (g_largeur > len && g_largeur > pre)
		{
			ft_putchar(' ');
			g_largeur--;
			g_nb++;
		}
	}
}

void		ft_u_flags(char *g_s)
{
	int		llen;
	int		pre;

	llen = ft_strlen(g_s);
	pre = g_precision;
	if (g_largeur > llen && g_moin == 0 && g_moinprecision == 0)
		ft_first_condition_u(llen);
	if (g_precision >= llen && g_moinprecision == 0)
		ft_2nd_condition_u(llen);
	if (g_largeur > 0 && ft_atoi(g_s) == 0 && g_precision == 0 && g_point)
		g_nb += ft_putstr(" ");
	else if (g_largeur == 0 && ft_atoi(g_s) == 0 && g_precision == 0 && g_point)
		g_nb += ft_putstr("");
	else
		g_nb += ft_putstr(g_s);
	if ((g_precision > llen && g_moinprecision) ||
			(g_largeur > llen && g_moin && g_moinprecision == 0))
		ft_3rd_condition_u(llen, pre);
}
