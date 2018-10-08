/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:58:30 by anjansse          #+#    #+#             */
/*   Updated: 2018/09/12 22:28:27 by changuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/useful.h"
#include "../includes/struct.h"
#include "../includes/map_func.h"
#include "../includes/parse_file.h"
#include <stdio.h>
t_map	parsefile(int fd)
{
	int		maxsize[2];
	char	**map;
	t_map	data;
	int		err;

	err = 0;
	maxsize[0] = headerrowsize(fd, data.symbols, &err);
	map = malloc(sizeof(char *) * (maxsize[0] + 1));
	maxsize[1] = headercolsize(fd, map, &err);
	populatemap(map, fd, maxsize, &err);


	display_map(map, maxsize[0]);
	printf("\n\n");
	data.map = map;
	data.maxsize[0] = maxsize[0];
	data.maxsize[1] = maxsize[1];
	data.erro = err;
	return (data);
}

t_map	evaluategrid(t_map data, int **nm, char **map, int coord[2])
{
	int		i;
	int		j;
	t_map	answer;

	answer.maxchain = 0;
	i = -1;
	j = -1;
	while (++i < data.maxsize[0])
	{
		nm[i] = malloc(sizeof(int) * (data.maxsize[1] + 1));
		while (++j < data.maxsize[1])
		{
			coord[0] = i;
			coord[1] = j;
			fillboard(nm, map, coord, data);
			if (answer.maxchain < nm[i][j])
			{
				answer.maxchain = nm[i][j];
				answer.largestcoord[0] = i;
				answer.largestcoord[1] = j;
			}
		}
		j = -1;
	}
	return (answer);
}

void	submain(void)
{
	t_map data;

	data = parsefile(0);
	if (!data.erro)
		findsolution(data);
	else
		ft_putstr("map error\n");
	ft_putchar('\n');
}

void	findsolution(t_map data)
{
	char	**map;
	int		**nm;
	int		maxchain;
	int		coord[2];
	t_map	answer;

	maxchain = 0;
	map = data.map;
	nm = malloc(sizeof(int *) * (data.maxsize[0] + 1));
	answer = evaluategrid(data, nm, map, coord);
	display_answer(map, answer.largestcoord, answer.maxchain, data);
}

int		main(int argc, char **argv)
{
	t_map	data;
	int		i;
	int		fd;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			data = parsefile(fd);
			/*if (fd != -1 && !data.erro)
				//findsolution(data);
			else
				ft_putstr("map error\n");
			ft_putchar('\n');*/
			i++;
		}
	}
	else
	{
		submain();
	}
	return (0);
}
