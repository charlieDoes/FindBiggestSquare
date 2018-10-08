/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:19:51 by changuye          #+#    #+#             */
/*   Updated: 2018/09/12 21:13:04 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_file.h"
#include "../includes/useful.h"
#include "../includes/struct.h"

#define BUFFER_SIZE 100000

int		isnumber(char num)
{
	if (num <= '9' && num >= '0')
		return (1);
	return (0);
}

int		headerrowsize(int fd, char symbols[3], int *err)
{
	int		i;
	char	head[50];

	i = 0;
	while ((read(fd, &head[i], 1) == 1) && (head[i] != '\n' || head[i] == '\0'))
		i++;
	if (head[i] != '\n')
		*err = 1;
	head[++i] = '\0';
	i = 0;
	while (isnumber(head[i]))
		i++;
	symbols[0] = head[i];
	symbols[1] = head[i + 1];
	symbols[2] = head[i + 2];
	return (ft_atoi(head));
}

int		headercolsize(int fd, char **map, int *err)
{
	char	buffer[BUFFER_SIZE];
	int		i;

	i = -1;
	while (read(fd, &buffer[++i], 1) == 1)
	{
		if (isnumber(buffer[i]))
			*err = 2;
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			map[0] = malloc(sizeof(char) * i);
			map[0] = buffer;
			map[0][i + 1] = '\0';
			break ;
		}
	}
	return (i);
}
#include <stdio.h>
#include "../includes/map_func.h"
void	populatemap(char **map, int fd, int max[2], int *err)
{
	int maxrow;
	int maxcol;
	int i;
	int j;

	maxrow = max[0];
	maxcol = max[1];
	i = 0;
	j = -1;
	while (++i < maxrow)
	{
		map[i] = malloc(sizeof(char) * (maxcol + 1));
		while (read(fd, &map[i][++j], 1) == 1)
		{
			if (map[i][j] == '\n' || map[i][j] == '\0')
			{
				map[i][j+1] = '\0';
				if (maxcol != j)
					*err = 3;
				break ;
			}
		}
		j = -1;

	}
	printf(">>%s\n", map[0]);
		printf(">>%s\n", map[1]);
			printf(">>%s\n", map[2]);
}
