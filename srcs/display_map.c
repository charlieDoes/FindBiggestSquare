/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:09:13 by changuye          #+#    #+#             */
/*   Updated: 2018/09/12 16:24:23 by changuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/useful.h"
#include "../includes/struct.h"
#include "../includes/map_func.h"
#include <stdio.h>
void	display_map(char **map, int maxrow)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < maxrow)
		{
			ft_putstr(map[i]);
			i++;
		}
	}
}

void	display_new_map(int **map, int maxrow, int maxcol)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (map)
	{
		while (++i < maxrow)
		{
			while (++j < maxcol)
			{
				ft_putchar(map[i][j] + '0');
			}
			j = -1;
		}
	}
}

void	display_answer(char **map, int coords[2], int max, t_map data)
{
	int i;
	int j;

	i = 1 + coords[0] - max;
	j = 1 + coords[1] - max;
	display_map(map, data.maxsize[0]);
	while (i <= coords[0])
	{
		while (j <= coords[1])
		{
			map[i][j] = data.symbols[2];
			j++;
		}
		j = 1 + coords[1] - max;
		i++;
	}

	display_map(map, data.maxsize[0]);
}

int		mv(int a, int b, int c)
{
	int smallest;

	if (a < b)
		smallest = a;
	else
		smallest = b;
	if (smallest > c)
		smallest = c;
	return (smallest);
}

void	fillboard(int **nm, char **map, int coord[2], t_map data)
{
	int i;
	int j;

	i = coord[0];
	j = coord[1];
	if (isfull(map[i][j], data))
		nm[i][j] = 0;
	else if (i == 0 || j == 0)
		nm[i][j] = 1;
	else
		nm[i][j] = mv(nm[i][j - 1], nm[i - 1][j], nm[i - 1][j - 1]) + 1;
}
