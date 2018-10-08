/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:31:55 by changuye          #+#    #+#             */
/*   Updated: 2018/09/12 21:15:09 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FUNC_H
# define MAP_FUNC_H

# include "struct.h"

void	display_map(char **map, int maxrow);

void	display_answer(char **map, int coord[2], int max, t_map data);

void	display_new_map(int **map, int maxrow, int maxcol);

int		mv(int a, int b, int c);

void	fillboard(int **nm, char **map, int coord[2], t_map data);
#endif
