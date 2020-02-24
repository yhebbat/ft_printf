/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:40:03 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 22:29:27 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_1st_cdt(char *g_s)
{
	while (((g_largeur > ft_strlen(g_s) && !g_point)
				|| (g_largeur > g_precision && g_point)) && !g_moin)
	{
		g_nb += ft_putstr(" ");
		g_largeur--;
	}
	while (((g_largeur > ft_strlen(g_s) && g_precision > ft_strlen(g_s)))
			&& !g_moin)
	{
		g_nb += ft_putstr(" ");
		g_largeur--;
	}
}

void	ft_2nd_cdt(char *g_s)
{
	while (((g_largeur > ft_strlen(g_s) && !g_point)
				|| (g_largeur > g_precision && g_point)) && g_moin)
	{
		g_nb += ft_putstr(" ");
		g_largeur--;
	}
	while (((g_largeur > ft_strlen(g_s) && g_precision > ft_strlen(g_s)))
			&& g_moin)
	{
		g_nb += ft_putstr(" ");
		g_largeur--;
	}
}

void	ft_string_flags(char *g_s)
{
	int	k;

	k = 0;
	ft_1st_cdt(g_s);
	if ((ft_strlen(g_s) <= g_precision) || !g_point)
		g_nb += ft_putstr(g_s);
	else if (g_precision < ft_strlen(g_s) && g_point)
	{
		while (k < g_precision)
		{
			ft_putchar(g_s[k]);
			k++;
			g_nb++;
		}
	}
	ft_2nd_cdt(g_s);
}
