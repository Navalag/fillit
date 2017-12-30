/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:11:32 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/12 17:11:34 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Count all elements in the list.
*/

int		lst_count_elem(void)
{
	t_fig		*tmp;
	int			count;

	tmp = g_head;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/*
** Creates a new node and returns pointer to it.
*/

t_fig	*lst_new_node(int x[], int y[])
{
	t_fig	*tmp;
	int		i;

	i = 0;
	if ((tmp = (t_fig *)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	while (i < 4)
	{
		tmp->x[i] = x[i];
		tmp->y[i] = y[i];
		i++;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

/*
** Inserts a node at tail of Doubly linked list.
*/

void	lst_insert_at_tail(int x[], int y[])
{
	t_fig	*tmp;
	t_fig	*new_node;

	tmp = g_head;
	new_node = lst_new_node(x, y);
	if (g_head == NULL)
	{
		g_head = new_node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}
