/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_or_d_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:38:59 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 22:38:31 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_first_condition_d(char *g_s, int len)
{
	int prec;

	prec = g_precision;
	if (ft_atoi(g_s) < 0)
		prec++;
	while (g_largeur > len && g_largeur > prec)
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

char		*ft_2nd_condition_d(char *g_s, int len)
{
	if (ft_atoi(g_s) < 0 && ft_strcmp(g_s, "-2147483648"))
	{
		g_s = ft_itoa(-1 * ft_atoi(g_s));
		ft_putchar('-');
		g_largeur--;
		g_precision++;
		g_nb++;
	}
	while (g_precision > len)
	{
		ft_putchar('0');
		g_precision--;
		g_nb++;
	}
	return (g_s);
}

void		ft_3rd_condition_d(int len, int pre)
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

void		ft_i_or_d_flags(char *g_s)
{
	int len;
	int pre;

	len = ft_strlen(g_s);
	pre = g_precision;
	if (ft_atoi(g_s) < 0 && g_zero && g_point == 0
			&& ft_strcmp(g_s, "-2147483648"))
	{
		g_s = ft_itoa((ft_atoi(g_s) * -1));
		ft_putchar('-');
		g_nb++;
	}
	if (g_largeur > len && g_moin == 0 && g_moinprecision == 0)
		ft_first_condition_d(g_s, len);
	if (g_precision >= len && g_moinprecision == 0 && g_point)
		g_s = ft_2nd_condition_d(g_s, len);
	if (g_largeur > 0 && ft_atoi(g_s) == 0 && g_precision == 0 && g_point)
		g_nb += ft_putstr(" ");
	else if (g_largeur == 0 && ft_atoi(g_s) == 0 && g_precision == 0 && g_point)
		g_nb += ft_putstr("");
	else
		g_nb += ft_putstr(g_s);
	if ((g_precision > len && g_moinprecision) ||
			(g_largeur > len && g_moin && g_moinprecision == 0))
		ft_3rd_condition_d(len, pre);
}
