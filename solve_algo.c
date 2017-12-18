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

/* this function move all figures in the list
to the max left up posssition */
void move_all_figs_left_up(t_fig *node)
{
	while (node)
	{
		move_full_left_up(node);
		node = node->next;
	}
}

/* this function move one figure to the max left up position */
void	move_full_left_up(t_fig *node)
{
	move_full_left(node);
	move_full_up(node);
}

/* this function move figure one step right if possible
or left down otherwise */
int		move_one_step(t_fig *node)
{
	int		i;
	int		x_max;
	int		y_max;

	i = 0;
	/* find max x, y values */
	x_max = find_max_coordinate(node->x);
	y_max = find_max_coordinate(node->y);
	/* if next right step posible - move right */
	if (x_max + 1 < g_edge)
		move_right(node);
	else
	{
		/* if next step unavailable - return false (-1) */
		if (x_max + 1 == g_edge && y_max + 1 == g_edge)
			return (0);
		/* if next down step posible - first move full left, then move down */
		move_full_left(node);
		move_down(node);
	}
	/* if moving was posible return 1 */
	return (1);
}

/* Check wether given node and all previous figures
are not conflicting with each other. Return (1) if not, else (0) */
int		check_all_figures(t_fig *node)
{
	t_fig 	*tmp;
	int 	i;
	int 	j;

	tmp = node->prev;
	/* iterate all elements in the list 
	from given argument to the first */
	while (tmp)
	{
		i = 0;
		/* check all x and y coordinates 
		if there are no conflicts - return (1) else (0) */
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

/* the begin algorithm to solve the tetris */
void	tetris_solve(t_fig *node)
{
	/* do while node != NULL (until last element in the list) */
	while (node)
	{
		/* if there are conflicts between figures do 'if' condition
		else - do node->next */
		if (!(check_all_figures(node)))
		{
			/* if next step available move figure one time
			else - make while condition until next step become available */
			while (!(move_one_step(node)))
			{
				/* move figure to left up position if there is no space
				for this figure on the map */
				move_full_left_up(node);
				/* then if this is first node in the list (node->prev == NULL)
				increase the map, else - take previous */
				if (node->prev == NULL)
				{
					g_edge++;					
				}
				else
				{
					node = node->prev;
				}
				// printf("g_edge in cycle %i\n", g_edge);
				// printf("check\n");
			}
			// new_lst_print();
		}
		else
			node = node->next;
	}
}
