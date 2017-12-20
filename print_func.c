/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:53:15 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/16 12:53:18 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**freeing(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++] = NULL);
	free(str);
	return (NULL);
}

int		fill_map_with_dots(char **str)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < g_edge)
	{
		if (!(str[y] = (char*)malloc(sizeof(char) * (g_edge + 1))))
		{
			freeing(str);
			return (0);
		}
		while (x < g_edge)
		{
			str[y][x] = '.';
			x++;
		}
		str[y][x] = '\0';
		x = 0;
		y++;
	}
	str[y] = NULL;
	return (1);
}

void	fill_map_with_letters(char **str, t_fig *node, char c)
{
	int		i;

	i = 0;
	while (i < COL_NUM)
	{
		str[node->y[i]][node->x[i]] = c;
		i++;
	}
}

void	print_result_map(t_fig *node)
{
	int		i;
	char	c;
	char	**str;

	i = 0;
	c = 'A';
	if (!(str = (char**)malloc(sizeof(char*) * (g_edge + 1))))
		return ;
	if (!(fill_map_with_dots(str)))
		return ;
	while (node)
	{
		fill_map_with_letters(str, node, c);
		node = node->next;
		c++;
	}
	while (i < g_edge)
	{
		ft_putstr(str[i++]);
		ft_putstr("\n");
	}
	freeing(str);
}
