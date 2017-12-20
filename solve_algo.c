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

/*
** this function move all figures in the list
** to the max left up posssition
*/

void	move_all_figs_left_up(t_fig *node)
{
	while (node)
	{
		move_full_left_up(node);
		node = node->next;
	}
}

/*
** this function move one figure to the max left up position
*/

void	move_full_left_up(t_fig *node)
{
	move_full_left(node);
	move_full_up(node);
}

/*
** this function move figure one step right if possible
** or left down otherwise
*/

int		move_one_step(t_fig *node)
{
	int		i;
	int		x_max;
	int		y_max;

	i = 0;
	x_max = find_max_coordinate(node->x);
	y_max = find_max_coordinate(node->y);
	if (x_max + 1 < g_edge)
		move_right(node);
	else
	{
		if (x_max + 1 == g_edge && y_max + 1 == g_edge)
			return (0);
		move_full_left(node);
		move_down(node);
	}
	return (1);
}

/*
** Check wether given node and all previous figures
** are not conflicting with each other. Return (1) if not, else (0)
*/

int		check_all_figures(t_fig *node)
{
	t_fig		*tmp;
	int			i;
	int			j;

	tmp = node->prev;
	while (tmp)
	{
		i = 0;
		while (i < COL_NUM)
		{
			j = 0;
			while (j < COL_NUM)
			{
				if ((node->x[i] != tmp->x[j]) || (node->y[i] != tmp->y[j]))
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

/*
** Main algorithm to solve tetris
*/

int		tetris_solve(t_fig *node)
{
	while (node)
	{
		if (!(check_all_figures(node)))
		{
			while (!(move_one_step(node)))
			{
				move_full_left_up(node);
				if (node->prev == NULL)
				{
					g_edge++;
					tetris_solve(g_head);
					return (0);
				}
				else
					node = node->prev;
			}
		}
		else
			node = node->next;
	}
	return (1);
}
