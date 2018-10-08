/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilties.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:25:53 by changuye          #+#    #+#             */
/*   Updated: 2018/09/12 03:25:56 by changuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/useful.h"
#include "../includes/struct.h"

int		ft_atoi(char *str)
{
	int res;
	int sign;
	int i;

	i = 0;
	res = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	sign = 1;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (str && *str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		isfull(char c, t_map data)
{
	if (c == data.symbols[1])
		return (1);
	return (0);
}
