/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_solve_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:12:08 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/13 14:12:10 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int n;
	int i;

	n = 0;
	i = 1;
	if (nb == 1)
		return (1);
	if (nb > 1)
	{
		while (i < nb)
		{
			i = n * n;
			n++;
		}
	}
	n--;
	if (i == nb)
		return (n);
	return (0);
}

void	find_square()
{
	int 	count;
	int 	res;

	count = lst_count_elem();
	res = count * 4;
	while (ft_sqrt(res) == 0)
		res++;
	g_edge = ft_sqrt(res);
}

int 	find_max_coordinate(int array[])
{
	int 	i;
	int		max;

	i = 0;
	max = 0;
	while (i < COL_NUM)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

void	move_right(t_fig *fig)
{
	int i;

	i = 0;
	/* add +1 step for each tetris block */
	while (i < COL_NUM)
	{
		fig->x[i] += 1;
		i++;
	}
}

void	move_down(t_fig *fig)
{
	int i;

	i = 0;
	/* add +1 step for each tetris block */
	while (i < COL_NUM)
	{
		fig->y[i] += 1;
		i++;
	}
}

void	move_full_left(t_fig *fig)
{
	int lowest; // see next coment
	int i;
	
	i = 0;
	lowest = g_edge - 1;
	/* find block with min x coordinate
	lowest = max available steps to left */
	while (i < COL_NUM)
	{
		if (fig->x[i] < lowest)
			lowest = fig->x[i];
		i++;
	}
	i = 0;
	/* if figure already in min left possition - return */
	if (lowest == 0)
		return ;
	/* else - move full left */
	while (i < COL_NUM)
	{
		fig->x[i] -= lowest;
		i++; 
	}
}

int		move_one_step(t_fig *fig)
{
	int		i;
	int		x_max;
	int		y_max;

	i = 0;
	/* find max x, y values */
	x_max = find_max_coordinate(fig->x);
	y_max = find_max_coordinate(fig->y);
	/* if next right step posible - move right */
	if (x_max + 1 < g_edge)
		move_right(fig);
	else
	{
		/* if next step unavailable - return false (-1) */
		if (x_max + 1 == g_edge && y_max + 1 == g_edge)
			return (0);
		/* if next down step posible - first move full left */
		move_full_left(fig);
		/* then move down */
		if (y_max + 1 < g_edge)
			move_down(fig);
	}
	/* if moving was posible return 1 */
	return (1);
}

// void to_left(t_fig *fig)
// {
// 	int lowest;
// 	int i;
	
// 	i = 0;
// 	lowest = g_edge - 1;
// 	while (i < COL_NUM)
// 	{
// 		if (fig->x[i] < lowest)
// 			lowest = fig->x[i];
// 		i++;
// 	}
// 	i = 0;
// 	if (lowest == 0)
// 		return ;
// 	else
// 		while (i < COL_NUM)
// 		{
// 			fig->x[i] -= lowest;
// 			i++; 
// 		}
// }

void to_up(t_fig *fig)
{
	int lowest;
	int i;
	
	i = 0;
	lowest = g_edge - 1;
	while (i < COL_NUM)
	{
		if (fig->y[i] < lowest)
			lowest = fig->y[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < COL_NUM)
		{
			fig->y[i] -= lowest;
			i++; 
		}
}

void 	mv_fig_full_left_up(t_fig *fig)
{
	int		i;
	
	i = 0;
	while (i < g_edge)
	{
		if (fig->x[i++] == 0)
			break ;
		else
		{
			move_full_left(fig); // need to check my implementation
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

/* given arg must be second in the list */
void	tetris_solve(t_fig *node)
{
	while (node)
	{
		if (!(check_all_figures(node)))
		{
			while (!(move_one_step(node)))
			{
				mv_fig_full_left_up(node); // need to implement
				if (node->prev == NULL)
					g_edge++;
				else
					node = node->prev;
			}
		}
		else
			node = node->next;
	}
}

int		check_all_figures(t_fig *node)
{
	t_fig 	*tmp;
	int 	i;
	int 	j;

	tmp = node->prev;
	while (tmp)
	{
		i = 0;
		while (i < COL_NUM)
		{
			j = 0;
			while (j < COL_NUM)
			{
				if (node->x[j] != tmp->x[i] || node->y[j] != tmp->y[i])
					j++;
				else
					return (0);
			}
			i++;
		}
		tmp = tmp->prev;
	}
	return (1);
}
