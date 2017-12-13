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

// given arg must be second in the list
void	tetris_solve(t_fig *node)
{
	t_fig	*tmp;

	tmp = node->prev;
	if (node->prev == NULL)
	{
		g_edge++;
		tetris_solve(node->next);
	}
	while (node->next != NULL)
	{
		if (check_all_figures(node))
			tetris_solve(node->next);
		else
		{
			if (check_next_step(node))
			{
				mv_fig_once(node);
				tetris_solve(node);
			}
			else
				tetris_solve(node->prev);
		}
	}
	finish_and_print();
}

int 	check_all_figures(t_fig *node)
{
	t_fig 	*tmp;
	int 	i;

	tmp = node->prev;
	i = 0;
	while (node->prev != NULL)
	{
		while (i < g_edge)
		{
			if (node->x[i] != tmp->x[i] || node->y[i] != tmp->y[i])
				i++;
			else
				return (0);
		}
		node = tmp;
		tmp = node->prev;
	}
	return (1);
}

void	check_next_step()
{

}
