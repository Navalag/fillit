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

void		begin_validation(unsigned char *buff)
{
	int 	len;
	

	len = 1;
	printf("%s\n", buff);  // test if buffer works correct
	while (buff[len] != '\0')
		len++;
	printf("actually readed bytes - %i\n", len);
	//  need to check 19 or 20 and if need + 1 !!
	if (((len + 1) % 21 != 0) && len != 19)
		printf("invalid file\n");

	parse_buffer(buff);
	// lst_print();  // test print

	validate_sumbols();
	validate_touch();
	validate_rows();
}

/*  separate and add figures to the list  */
void		parse_buffer(unsigned char *buff)
{
	int		i;
	int 	j;
	char	tmp[20];

	j = 0;
	while (buff[j] != '\0')
	{
		i = 0;
		while (i < 20 && buff[j] != '\0')
			tmp[i++] = buff[j++];
		tmp[i] = '\0';
		if (buff[j] != '\0') // if not the end of file - increment
			j++;
		lst_insert_at_head(tmp);
		new_parsing(tmp);
	}
	// free(buff);
	// free(tmp);
}

void	new_parsing(char *str)
{
	int 	i;
	int 	j;
	int 	a;
	int 	x[4];
	int 	y[4];
	int 	test = 0; // only for test

	j = 0;
	a = 0;
	while (*str)
	{
		i = 0;
		while (*str != '\n')
		{
			if (*str == '#')
			{
				x[a] = i;
				y[a] = j;
				a++;
			}
			i++;
			str++;
		}
		j++;
		str++;
	}
	new_lst_insert_at_tail(x, y);

	// test part
	while (test <= 3)
	{
		printf("x = %i; ", x[test]);
		printf("y = %i;", y[test]);
		printf("\n");
		test++;
	}
	printf("\n");
}

void	validate_sumbols()
{
	t_figure	*tmp;
	int 		i;
	int 		a;
	int 		b;
	int 		c;

	tmp = g_head;
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
		// test part
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

	tmp = g_head;
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
		// test part
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

	tmp = g_head;
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
