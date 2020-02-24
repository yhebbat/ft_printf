/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:38:42 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 23:40:48 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_1st_condition_h(char *g_s)
{
	while (g_largeur > ft_strlen(g_s) && g_largeur > g_precision)
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

void		ft_2nd_condition_h(char *g_s)
{
	while (g_precision > ft_strlen(g_s))
	{
		ft_putchar('0');
		g_precision--;
		g_nb++;
	}
}

void		ft_3rd_condition_h(char *g_s)
{
	while (g_precision > ft_strlen(g_s))
	{
		ft_putchar(' ');
		g_precision--;
		g_nb++;
	}
}

void		ft_last_condition_h(char *g_s, int pre)
{
	while (g_largeur > ft_strlen(g_s) && g_largeur > pre)
	{
		ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
}

void		ft_hexa_flags(char *g_s)
{
	int		pre;

	pre = g_precision;
	if (g_largeur > ft_strlen(g_s) && g_moin == 0 && g_moinprecision == 0)
		ft_1st_condition_h(g_s);
	if (g_precision > ft_strlen(g_s) && g_moinprecision == 0)
		ft_2nd_condition_h(g_s);
	if (g_largeur > 0 && ft_strcmp(g_s, "0") == 0 && g_point
			&& g_precision == 0)
		g_nb += ft_putstr(" ");
	else if (g_largeur == 0 && ft_strcmp(g_s, "0") == 0 && g_point
			&& g_precision == 0)
		g_nb += ft_putstr("");
	else
		g_nb += ft_putstr(g_s);
	if (g_precision > ft_strlen(g_s) && g_moinprecision)
		ft_3rd_condition_h(g_s);
	if (g_largeur > ft_strlen(g_s) && g_moin && g_moinprecision == 0)
		ft_last_condition_h(g_s, pre);
}
