/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:06:05 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 22:48:33 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uperhextoa(unsigned int c)
{
	unsigned int		nb;
	unsigned int		i;
	char				*str;

	nb = c;
	i = 0;
	if (c == 0)
		i = 1;
	i += ft_hexlen(nb);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (10 <= nb % 16 && nb % 16 <= 15)
			str[i] = ((nb % 16) % 10) + 'A';
		else
			str[i] = (nb % 16) + '0';
		nb = nb / 16;
	}
	return (str);
}

void	ft_putchar(char g_c)
{
	write(1, &g_c, 1);
}

int		ft_putstr(char *g_s)
{
	size_t		i;

	i = 0;
	if (g_s != NULL)
	{
		while (g_s[i] != '\0')
		{
			ft_putchar(g_s[i]);
			i++;
		}
	}
	return (i);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned char		*ss1;
	unsigned char		*ss2;

	ss2 = (unsigned char *)s2;
	ss1 = (unsigned char *)s1;
	i = 0;
	while (ss1[i] == ss2[i] && s1[i] && s2[i])
		i++;
	return (ss1[i] - ss2[i]);
}

void	ft_init_flags(void)
{
	g_largeur = 0;
	g_moin = 0;
	g_zero = 0;
	g_precision = 0;
	g_point = 0;
	g_moinprecision = 0;
}
