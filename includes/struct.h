/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:11:20 by anjansse          #+#    #+#             */
/*   Updated: 2018/09/11 15:27:20 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_map
{
	char	**map;
	int		maxsize[2];
	char	symbols[3];
	int		maxchain;
	int		largestcoord[2];
	int		erro;
}				t_map;

#endif
