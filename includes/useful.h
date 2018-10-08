/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:55:27 by anjansse          #+#    #+#             */
/*   Updated: 2018/09/11 18:36:02 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_H
# define USEFUL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../includes/struct.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		isfull(char c, t_map data);

#endif
