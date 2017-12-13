/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:51:45 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/12 14:51:47 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/* Creates a new Node and returns pointer to it */
t_figure	*lst_new_node(char *cont, int size)
{
	t_figure	*tmp;

	if ((tmp = (t_figure *)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	if ((tmp->row = (char *)malloc(size)) == NULL)
	{
		free(tmp);
		return (NULL);
	}
	else
		tmp->row = ft_memcpy(tmp->row, cont, size);
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

/* Inserts a Node at head of doubly linked list */
void	lst_insert_at_head(char *cont)
{
	t_figure	*tmp;

	tmp = lst_new_node(cont, 20);
	if (g_head == NULL)
	{
		g_head = tmp;
		return ;
	}
	g_head->prev = tmp;
	tmp->next = g_head;
	g_head = tmp;
}

int 	lst_count_elem()
{
	t_figure	*tmp;
	int 		count;

	tmp = g_head;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/* Prints all the elements in linked list in forward traversal order */
void	lst_print()
{
	t_figure	*tmp;

	tmp = g_head;
	printf("List contant: \n");
	while(tmp != NULL) {
		printf("%s", tmp->row);
		tmp = tmp->next;
		printf("\n");
	}
}
