/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhebbat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:42:07 by yhebbat           #+#    #+#             */
/*   Updated: 2020/02/13 23:44:50 by yhebbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int					g_largeur;
int					g_moin;
int					g_zero;
int					g_precision;
int					g_point;
int					g_moinprecision;
int					g_nb;
char				*g_s;
char				g_c;
unsigned long		g_pp;
int					ft_atoi(const char *str);
int					ft_intlen(unsigned int n);
int					ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, int len);
char				*ft_itoa(int c);
char				*ft_utoa(unsigned int c);
int					ft_hexlen(unsigned int nb);
int					ft_hexalen(unsigned long nb);
char				*ft_hextoa(unsigned int c);
char				*ft_hexpoint(unsigned long c);
char				*ft_uperhextoa(unsigned int c);
void				ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_printf(char *str, ...);
void				ft_hexa_flags(char *s);
void				ft_hexaa_flags(char *s);
void				ft_string_flags(char *s);
void				ft_i_or_d_flags(char *s);
void				ft_p_flags(unsigned long pp);
void				ft_u_flags(char *s);
void				ft_char_flags(char c);
int					ft_check_flags(char *src, int i, va_list args);
void				ft_init_flags(void);
#endif
