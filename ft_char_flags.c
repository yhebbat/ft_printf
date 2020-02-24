/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:37:33 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 20:03:21 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_first_condition(void)
{
	while (g_largeur > 1)
	{
		if (g_zero)
		{
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
}

void		ft_2nd_condition(void)
{
	while (g_precision > 1)
	{
		ft_putchar(' ');
		g_precision--;
		g_nb++;
	}
}

void		ft_3rd_condition(void)
{
	while (g_largeur > 1)
	{
		ft_putchar(' ');
		g_largeur--;
		g_nb++;
	}
}

void		ft_char_flags(char g_c)
{
	if (g_largeur > 1 && g_moin == 0 && g_moinprecision == 0)
		ft_first_condition();
	ft_putchar(g_c);
	g_nb++;
	if (g_precision > 1 && g_moinprecision)
		ft_2nd_condition();
	if (g_largeur > 1 && g_moin && g_moinprecision == 0)
		ft_3rd_condition();
}
