/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newway.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatiush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:09:57 by mmatiush          #+#    #+#             */
/*   Updated: 2017/12/11 19:53:13 by mmatiush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edge = 4;

typedef struct		tet_t
{
	int				x[4];
	int				y[4];
	struct tet_t	*next;
	struct tet_t	*prev;
}					t_fig;

char			**freeing(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++] = NULL);
	}
	free(str);
	return (NULL);
}

void to_left(t_fig *fig)
{
	int lowest;
	int i;
	
	i = 0;
	lowest = edge - 1;
	while (i < edge)
	{
		if (fig->x[i] < lowest)
			lowest = fig->x[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < edge)
		{
			fig->x[i] -= lowest;
			i++; 
		}
}

void to_up(t_fig *fig)
{
	int lowest;
	int i;
	
	i = 0;
	lowest = edge - 1;
	while (i < edge)
	{
		if (fig->y[i] < lowest)
			lowest = fig->y[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < edge)
		{
			fig->y[i] -= lowest;
			i++; 
		}
}

//Проверяет фигуру, и если она не слева, вызывает функцию чтобы двигает фигугу влево. Возвращает 0, если слева.
void mv_fig_full_left_up(t_fig *fig)
{
	int i;
	
	i = 0;
	while (i < edge)
	{
		if (fig->x[i++] == 0)
			break ;
		else
		{
			to_left(fig);
			break ;
		}
	}
	i = 0;
	while (i < edge)
	{
		if (fig->y[i++] == 0)
			break ;
		else
		{
			to_up(fig);
			break ;
		}
	}
}

void put_dots_to_field(char **str)
{
	int 	c_x;
	int 	c_y;

	c_x = 0;
	c_y = 0;
	while (c_y < edge)
	{
		str[c_y] = (char*)malloc(sizeof(char) * (edge + 1));
		while (c_x < edge)
		{
			str[c_y][c_x] = '.';
			c_x++;
		}
		str[c_y][c_x] = '\0';
		c_x = 0;
		c_y++;
	}
	str[c_y] = NULL;
}

void	put_sign_to_field(char **str, t_fig *fig, unsigned char c)
{
	int	c_x;
	int	c_y;

	c_x = 0;
	c_y = 0;
	str[c_y][c_x] = 
}

void print_matrix(t_fig *fig)
{
	int i;

	i = 0;
	char	**str;
	str = (char**)malloc(sizeof(char*) * (edge + 1));
	put_dots_to_field(str);
	put_sign_to_field(str, fig, '#');
	while (i < edge)
		printf("%s\n", str[i++]);
	freeing(str);
}

int main()
{
	t_fig* ptr;
	ptr = (t_fig*)malloc(sizeof(t_fig));
	ptr->x[0] = 1;
	ptr->x[1] = 0;
	ptr->x[2] = 1;
	ptr->x[3] = 1;
	ptr->y[0] = 1;
	ptr->y[1] = 2;
	ptr->y[2] = 2;
	ptr->y[3] = 3;

	mv_fig_full_left_up(ptr);
	print_matrix(ptr);
	return 0;
}
str[i][j]
