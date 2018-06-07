/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:23:00 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/05/30 11:23:05 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "point_structure.h"
#include "grid_structure.h"
#include "fillit.h"

int		tetrimino_xshift(t_tetri *tetri)
{
	int x_shift;

	x_shift = 0;
	while ((tetri->shape)[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

int		check_tetrimino_max(t_tetri *tetrimino, t_grid *grid,
							t_point *point)
{
	if ((point->y + tetrimino->height <= (int)grid->size) &&
		(point->x - tetrimino_xshift(tetrimino) +
		tetrimino->width <= (int)grid->size))
		return (1);
	return (0);
}

int		check_tetrimino_fits(t_tetri *tetrimino, t_grid *grid,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_grid;

	tetri_shape = tetrimino->shape;
	str_grid = grid->rows;
	if (check_tetrimino_max(tetrimino, grid, point) != 1)
		return (0);
	y = 0;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (!(str_grid[y + point->y][x - tetrimino_xshift(tetrimino) +
				point->x] == '.' ||
				tetri_shape[y][x] == '.'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	place_a_tetrimino(t_tetri *tetrimino, t_grid *grid,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_grid;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_grid = grid->rows;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_grid[y + point->y][x - tetrimino_xshift(tetrimino) +
				point->x] = tetri_shape[y][x];
			}
			x++;
		}
		y++;
	}
	tetrimino->start->x = (point->x) - tetrimino_xshift(tetrimino);
	tetrimino->start->y = point->y;
}

void	remove_a_tetrimino(t_tetri *tetrimino, t_grid *grid)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_grid;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_grid = grid->rows;
	while ((tetrimino->shape)[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_grid[y + tetrimino->start->y]
				[x + tetrimino->start->x] = '.';
			}
			x++;
		}
		y++;
	}
}
