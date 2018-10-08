/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 03:18:02 by changuye          #+#    #+#             */
/*   Updated: 2018/09/12 03:18:04 by changuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H

# include "struct.h"

int		isnumber(char num);

int		headerrowsize(int fd, char symbols[3], int *err);

int		headercolsize(int fd, char **map, int *err);

void	populatemap(char **map, int fd, int max[2], int *err);

void	findsolution(t_map data);
#endif
