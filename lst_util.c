/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:21:45 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/05/30 11:21:48 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_list	*lstnew_tetri(const char *str, char fill)
{
	t_tetri	*tetri;
	t_list	*node;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(node = ft_lstnew((void *)tetri, sizeof(*tetri))))
	{
		free_tetrimino(&tetri);
		return (NULL);
	}
	return (node);
}

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

int		lstadd_tetri(t_list **head, t_list **tail, char *t_str, int t_count)
{
	if (t_count && ((*tail)->next =
		lstnew_tetri(t_str, 'A' + t_count)))
		*tail = (*tail)->next;
	else if ((*head = lstnew_tetri(t_str, 'A' + t_count)))
		*tail = *head;
	else
	{
		ft_lstdel(head, &lstdel_tetri);
		return (-1);
	}
	return (0);
}
