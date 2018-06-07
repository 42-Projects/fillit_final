/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:20:07 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/06/03 16:27:45 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_STRUCTURE_H
# define GRID_STRUCTURE_H
# include <string.h>

typedef struct	s_grid
{
	size_t		size;
	char		**rows;
}				t_grid;

#endif
