/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:19:08 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/06/06 14:03:10 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SHARP '#'
# define DOT '.'
# define NEWLINE '\n'
# define BUF 20
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "grid_structure.h"
# include "point_structure.h"

typedef struct	s_tetri
{
	char		**shape;
	t_point		*start;
	int			width;
	int			height;
}				t_tetri;

t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
t_list			*lstnew_tetri(const char *str, char fill);
char			**create_tetrimino_shape(int height, int width);
void			place_a_tetrimino(t_tetri *tetrimino, t_grid *grid,
				t_point *point);
void			remove_a_tetrimino(t_tetri *tetrimino, t_grid *grid);
void			lstdel_tetri(void *content, size_t content_size);
void			free_tetrimino(t_tetri **tetri);
int				valid_tetri(const char *shape, t_point ***points);
int				lstadd_tetri(t_list **head, t_list **tail,
						char *t_str, int t_count);
int				check_tetrimino_fits(t_tetri *tetrimino,
						t_grid *grid, t_point *point);
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
t_list			*get_tetriminoes_from_file(const char *filename);
void			error_msg(const char *srcfile);
int				solve(const char *filename);
int				get_next_point(t_point **point, char **grid);
int				solve_a_grid(t_grid *grid, t_list **block, t_point *p_start);
t_point			*create_point(int len);
t_point			*create_point_fromxy(int x, int y);
void			free_point(t_point **point);
void			free_minmax_points(t_point ***points);
t_grid			*create_grid(size_t size);
void			print_str_grid(char	**grid);
void			free_grid(t_grid **grid);
void			update_grid(t_grid **grid, char **rows);
char			**make_grid_structure(size_t size);
#endif
