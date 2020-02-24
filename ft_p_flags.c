/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:36:53 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 22:37:44 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_first_condition_p(unsigned long g_pp)
{
	if (g_precision < ft_strlen(ft_hexpoint(g_pp)))
		g_precision = ft_strlen(ft_hexpoint(g_pp));
	while (g_largeur > (2 + g_precision) &&
			g_moin == 0 && g_moinprecision == 0 && g_zero == 0)
	{
		ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
}

void		ft_2nd_condition_p(unsigned long g_pp)
{
	while (g_point == 0 && (g_largeur - 2) > (ft_strlen(ft_hexpoint(g_pp)) + 2)
			&& g_moinprecision == 0 && g_zero == 1)
	{
		ft_putchar('0');
		g_largeur--;
		g_nb++;
	}
	while (g_point && g_precision > ft_strlen(ft_hexpoint(g_pp)) &&
			g_moinprecision == 0)
	{
		ft_putchar('0');
		g_precision--;
		g_largeur--;
		g_nb++;
	}
}

void		ft_3rd_condition_p(unsigned long g_pp)
{
	while (g_moin == 1 && g_largeur > (2 + ft_strlen(ft_hexpoint(g_pp))) &&
			g_moinprecision == 0)
	{
		ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
	while (g_moinprecision == 1 &&
			(g_precision - 2) > ft_strlen(ft_hexpoint(g_pp)))
	{
		ft_putchar(' ');
		g_precision--;
		g_nb++;
	}
}

void		ft_p_flags(unsigned long g_pp)
{
	if (g_pp == 0 && g_precision == 0 && g_point)
	{
		ft_first_condition_p(g_pp);
		if (g_largeur > 1 && !g_moin)
			g_nb += ft_putstr(" ");
		g_nb += ft_putstr("0x");
		if (g_largeur > 1 && g_moin)
			g_nb += ft_putstr(" ");
		ft_2nd_condition_p(g_pp);
		ft_3rd_condition_p(g_pp);
	}
	else
	{
		ft_first_condition_p(g_pp);
		g_nb += ft_putstr("0x");
		ft_2nd_condition_p(g_pp);
		g_nb += ft_putstr(ft_hexpoint(g_pp));
		ft_3rd_condition_p(g_pp);
	}
}
