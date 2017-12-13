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
# define TETNUM 4

int g_edge = 6;

typedef struct		s_tet
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
	lowest = g_edge - 1;
	while (i < TETNUM)
	{
		if (fig->x[i] < lowest)
			lowest = fig->x[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < TETNUM)
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
	lowest = g_edge - 1;
	while (i < TETNUM)
	{
		if (fig->y[i] < lowest)
			lowest = fig->y[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < TETNUM)
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
	while (i < g_edge)
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
	while (i < g_edge)
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
	while (c_y < g_edge)
	{
		str[c_y] = (char*)malloc(sizeof(char) * (g_edge + 1));
		while (c_x < g_edge)
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
	int i;

	i = 0;
	while (i < 4)
	{
		str[fig->y[i]][fig->x[i]] = c;
		i++;
	}
}

void 	print_matrix(t_fig *fig)
{
	int 	i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(char*) * (g_edge + 1));
	put_dots_to_field(str);
	put_sign_to_field(str, fig, 'A');
	while (i < g_edge)
		printf("%s\n", str[i++]);
	freeing(str);
}

/********************************************************************************************/

void	mv_fig_right(t_fig *fig)
{
	int i;

	i = 0;
	while (i < TETNUM)
	{
		fig->x[i] += 1;
		i++;
	}
}

void	mv_fig_down(t_fig *fig)
{
	int i;

	i = 0;
	while (i < TETNUM)
	{
		fig->y[i] += 1;
		i++;
	}
}

int		mv_fig_once(t_fig *fig)
{
	int i;
	int x_max;
	int y_max;

	i = 0;
	x_max = 0;
	y_max = 0;
	while (i < TETNUM)
	{
		if (fig->x[i] > x_max)
			x_max = fig->x[i];
		i++;
	}
	i = 0;
	if (x_max + 1 < g_edge)
		mv_fig_right(fig);
	else
	{
		while (i < TETNUM)
		{
			if (fig->y[i] > y_max)
				y_max = fig->y[i];
			i++;
		}
		if (x_max + 1 == g_edge && y_max + 1 == g_edge)
			return (-1);
		to_left(fig);
		if (y_max + 1 < g_edge)
			mv_fig_down(fig);
	}
	return 1;
}

/*void	backtrack(t_fig *head)
{
	int		i;
	int 	j;
	t_fig	*fig;

	fig = head;
	i = 0;
	j = 0;
	while (i < TETNUM)
	{
		while(j < TETNUM)
		{
			if (fig->x[i] != fig->next->x[j] && fig->y[i] != fig->next->y[j])
				j++;
			else
			{
				mv_fig_once(fig->next);
			}
		} 
		i++;
	}	
}*/


int main()
{
	t_fig* ptr;
	ptr = (t_fig*)malloc(sizeof(t_fig));
	ptr->x[0] = 4;
	ptr->x[1] = 3;
	ptr->x[2] = 4;
	ptr->x[3] = 4;
	ptr->y[0] = 0;
	ptr->y[1] = 1;
	ptr->y[2] = 1;
	ptr->y[3] = 2;
	print_matrix(ptr);
	printf("\n\n");
	mv_fig_once(ptr);
	print_matrix(ptr);
	printf("\n\n");
	mv_fig_once(ptr);
	print_matrix(ptr);

	return 0;
}
