/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:11:55 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 20:13:52 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa(unsigned int c)
{
	unsigned int		nb;
	unsigned int		i;
	char				*str;

	nb = c;
	i = 0;
	i += ft_intlen(nb);
	if (c == 0)
		i = 1;
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int			ft_hexlen(unsigned int nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int			ft_hexalen(unsigned long nb)
{
	unsigned long		i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char		*ft_hextoa(unsigned int c)
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
			str[i] = ((nb % 16) % 10) + 'a';
		else
			str[i] = (nb % 16) + '0';
		nb = nb / 16;
	}
	return (str);
}

char		*ft_hexpoint(unsigned long c)
{
	unsigned long		nb;
	unsigned int		i;
	char				*str;

	nb = c;
	i = 0;
	if (c == 0)
		i = 1;
	i += ft_hexalen(nb);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
	{
		if (10 <= nb % 16 && nb % 16 <= 15)
			str[i] = ((nb % 16) % 10) + 'a';
		else
			str[i] = (nb % 16) + '0';
		nb = nb / 16;
	}
	return (str);
}
