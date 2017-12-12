/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:40:44 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/08 11:40:46 by agalavan         ###   ########.fr       */
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

//Creates a new Node and returns pointer to it
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

//Inserts a Node at head of doubly linked list
void	lst_insert_at_head(char *cont)
{
	t_figure	*tmp;

	tmp = lst_new_node(cont, 20);
	if (head == NULL)
	{
		head = tmp;
		return ;
	}
	head->prev = tmp;
	tmp->next = head;
	head = tmp;
}

int 	lst_count_elem()
{
	t_figure	*tmp;
	int 		count;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

//Prints all the elements in linked list in forward traversal order
void	lst_print()
{
	t_figure	*tmp;

	tmp = head;
	printf("List contant: \n");
	while(tmp != NULL) {
		printf("%s", tmp->row);
		tmp = tmp->next;
		printf("\n");
	}
}

void	validate_sumbols()
{
	t_figure	*tmp;
	int 		i;
	int 		a;
	int 		b;
	int 		c;

	tmp = head;
	while (tmp != NULL)
	{
		i = 0;
		a = 0;
		b = 0;
		c = 0;
		while (tmp->row[i] != '\0')
		{
			if (tmp->row[i] == '#')
				a++;
			if (tmp->row[i] == '.')
				b++;
			if (tmp->row[i] == '\n')
				c++;
			i++;
		}
		tmp = tmp->next;
		if (a != 4 || b != 12 || c != 4)
		{
			printf("Validation failed\n");
			printf("# - %i \n", a);
			printf(". - %i \n", b);
			printf("\\n - %i \n", c);
		}
		else
			printf("Success validation\n");
	}
}

void	validate_touch()
{
	t_figure	*tmp;
	int 		i;
	int 		count;

	tmp = head;
	while (tmp != NULL)
	{
		i = 0;
		count = 0;
		while (tmp->row[i] != '\0')
		{
			if (tmp->row[i] == '#' && tmp->row[i + 1] == '#')
				count++;
			if (tmp->row[i] == '#' && tmp->row[i - 1] == '#')
				count++;
			if (tmp->row[i] == '#' && tmp->row[i + 5] == '#')
				count++;
			if (tmp->row[i] == '#' && tmp->row[i - 5] == '#')
				count++;
			i++;
		}
		tmp = tmp->next;
		if (count == 6 || count == 8)
			printf("Figure is fine\n");
		else
		{
			printf("Validation failed\n");
			printf("Count = %i\n", count);
		}
	}
}

void	validate_rows()
{
	t_figure	*tmp;
	int 		i;
	int 		count;

	tmp = head;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->row[i] != '\0')
		{
			count = 0;
			while (tmp->row[i] != '\n')
			{
				count++;
				i++;
			}
			if (count != 4)
				printf("Invalid row\n");
			else
				printf("Valid row\n");
			i++;
		}
		tmp = tmp->next;
	}
}
