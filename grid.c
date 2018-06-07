/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:19:39 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/06/03 16:29:25 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_grid_structure(size_t size)
{
	char	**grid;
	size_t	i;

	if ((grid = (char **)ft_memalloc((sizeof(*grid) * (size + 1)))))
	{
		i = 0;
		while (i < size)
		{
			if (!(grid[i] = ft_strnew(size)))
			{
				while (--i)
					ft_strdel(&grid[i]);
				free(grid);
				return (NULL);
			}
			ft_memset(grid[i++], '.', size);
		}
	}
	return (grid);
}

void	free_grid(t_grid **grid)
{
	size_t row;

	if (!grid)
		return ;
	row = 0;
	while (row < (*grid)->size)
		ft_strdel(&((*grid)->rows[row++]));
	free((*grid)->rows);
	(*grid)->rows = NULL;
	free(*grid);
	*grid = NULL;
}

void	update_grid(t_grid **grid, char **rows)
{
	size_t row;

	row = 0;
	while (row < (*grid)->size)
		ft_strdel(&((*grid)->rows[row++]));
	(*grid)->rows = rows;
}

t_grid	*create_grid(size_t size)
{
	t_grid *grid;

	if ((grid = (t_grid *)ft_memalloc(sizeof(*grid))))
	{
		if (!(grid->rows = make_grid_structure(size)))
		{
			free(grid);
			return (NULL);
		}
		grid->size = size;
	}
	return (grid);
}
