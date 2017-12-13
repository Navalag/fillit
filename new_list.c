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

/* Creates a new Node and returns pointer to it */
t_fig	*new_lst_new_node(int x[], int y[])
{
	t_fig	*tmp;
	int 	i;

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

/* Inserts a Node at tail of Doubly linked list */
void	new_lst_insert_at_tail(int x[], int y[])
{
	t_fig 	*tmp;
	t_fig 	*new_node;

	tmp = g_first_node;
	new_node = new_lst_new_node(x, y);
	if (g_first_node == NULL)
	{
		g_first_node = new_node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next; // Go To last Node
	tmp->next = new_node;
	new_node->prev = tmp;
}

/* Prints all the elements in linked list in forward traversal order */
void	new_lst_print()
{
	t_fig	*tmp;
	int 	i;

	tmp = g_first_node;
	printf("List contant: \n");
	while(tmp != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("x = %i; ", tmp->x[i]);
			printf("y = %i;", tmp->y[i]);
			printf("\n");
			i++;
		}
		tmp = tmp->next;
		printf("\n");
	}
}
