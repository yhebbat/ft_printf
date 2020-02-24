/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fcts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:38:19 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 20:04:43 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	size_t				result;
	int					signe;

	result = 0;
	signe = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result > 4294967295 && signe == 1)
			return (-1);
		if (signe == -1 && result > 4294967295)
			return (0);
	}
	return ((int)result * signe);
}

int		ft_intlen(unsigned int n)
{
	int					i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int					i;
	char				*str;

	i = 0;
	if (s == NULL)
		return (0);
	if ((int)start > ft_strlen(s))
		len = 0;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (0);
	if ((int)start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
	}
	else
		str[i] = '\0';
	return (str);
}

char	*ft_itoa(int c)
{
	unsigned int		nb;
	unsigned int		i;
	char				*str;

	nb = c;
	i = 0;
	if (c <= 0)
	{
		nb = -c;
		i = 1;
	}
	i += ft_intlen(nb);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (c < 0)
		str[0] = '-';
	return (str);
}
