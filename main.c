/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:22:24 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/05/30 11:22:26 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	error_msg(const char *srcfile)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(srcfile, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		error_msg(argv[0]);
		return (1);
	}
	if (!solve(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
