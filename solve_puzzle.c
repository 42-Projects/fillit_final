/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:26:04 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/05/30 11:26:06 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "point_structure.h"
#include "grid_structure.h"
#include "fillit.h"

int	get_next_point(t_point **point, char **grid)
{
	if (!grid)
		return (0);
	(*point)->x = (*point)->x + 1;
	while (grid[(*point)->y] != NULL)
	{
		while (grid[(*point)->y][(*point)->x] != '\0')
		{
			if (grid[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}

int	solve_a_grid(t_grid *grid, t_list **block, t_point *p_start)
{
	int found;

	found = 0;
	if (!block || !*block)
		return (1);
	while ((!(found = check_tetrimino_fits((t_tetri *)(*block)->content,
			grid, p_start)) && get_next_point(&p_start, grid->rows)))
		;
	if (!found)
		return (0);
	place_a_tetrimino((t_tetri *)(*block)->content, grid, p_start);
	if (!solve_a_grid(grid, &((*block)->next), create_point(0)))
	{
		remove_a_tetrimino((t_tetri *)(*block)->content, grid);
		if (!get_next_point(&p_start, grid->rows))
		{
			p_start->x = 0;
			p_start->y = 0;
			return (0);
		}
		return (solve_a_grid(grid, block, p_start));
	}
	return (1);
}

int	solve_grids(t_list **tetri_lst)
{
	t_grid		*grid;
	t_point		*p_start;
	t_list		*tetri_lst_tail;
	size_t		grid_size;

	grid_size = 2;
	if (!(grid = create_grid(grid_size)))
		return (0);
	if (!(p_start = create_point(0)))
		return (0);
	while ((tetri_lst_tail = *tetri_lst) &&
			!solve_a_grid(grid, &tetri_lst_tail, p_start))
	{
		free_grid(&grid);
		if (!(grid = create_grid(++grid_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr(grid->rows);
	free_grid(&grid);
	free(grid);
	return (1);
}

int	solve(const char *filename)
{
	t_list		*tetri_lst;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
	if (!solve_grids(&tetri_lst))
		return (0);
	return (1);
}
