/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:00:07 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/08 15:50:41 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*head; // global variable - pointer to head node.

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

int		main(int argc, char **argv)
{
	unsigned char	buff[BUF_SIZE];
	int				n;
	int				fd;
	int 			len;
	int				i;
	t_figure		*head;
	char			tmp[20];
	int				j;

	head = NULL;
	len = 1;
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	while ((n = read(fd, buff, BUF_SIZE)) > 0)
	{
		if (n < 19 || n > 545)
			return (0);  // invalid file
	}
	printf("%s\n", buff);  // test if buffer works correctly

	while (buff[len] != '\0')
		len++;
	printf("actual readed bytes - %i\n", len);
	if (((len + 1) % 21 != 0) && len != 19) //  must check 19 or 20 and if need + 1 !!
		return (printf("invalid file\n"));  // invalid file

	//  separate and add figures to the list
	j = 0;
	while (buff[j] != '\0')
	{
		i = 0;
		while (i < 20 && buff[j] != '\0')
			tmp[i++] = buff[j++];
		tmp[i] = '\0';
		if (buff[j] != '\0')
			j++;
		lst_insert_at_head(tmp);
	}
	lst_print();  // test print
	// free(buff);
	// free(tmp);

	validate_sumbols();
	validate_touch();
	validate_rows();
	printf("list size - %i\n", lst_count_elem());
	return (0);
}
