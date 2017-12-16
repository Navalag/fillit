/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:45:19 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/16 12:45:22 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	move_full_up(t_fig *node)
{
	int lowest; // see next coment
	int i;
	
	i = 0;
	lowest = g_edge - 1;
	/* find block with min y coordinate
	lowest = max available steps to up */
	while (i < COL_NUM)
	{
		if (node->y[i] < lowest)
			lowest = node->y[i];
		i++;
	}
	i = 0;
	/* if figure already in min up possition - return */
	if (lowest == 0)
		return ;
	/* else - move full up */
	while (i < COL_NUM)
	{
		node->y[i] -= lowest;
		i++; 
	}
}

void	move_full_left(t_fig *node)
{
	int		lowest; // see next coment
	int		i;

	i = 0;
	lowest = g_edge - 1;
	/* find block with min x coordinate
	lowest = max available steps to left */
	while (i < COL_NUM)
	{
		if (node->x[i] < lowest)
			lowest = node->x[i];
		i++;
	}
	i = 0;
	/* if figure already in min left possition - return */
	if (lowest == 0)
		return ;
	/* else - move full left */
	while (i < COL_NUM)
	{
		node->x[i] -= lowest;
		i++; 
	}
}
