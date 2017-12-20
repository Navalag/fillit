/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:00:07 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/06 15:00:10 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_and_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	find_square(void)
{
	int		count;
	int		res;
	t_fig	*tmp;
	int		max_x;
	int		max_y;

	tmp = g_head;
	count = lst_count_elem();
	res = count * 4;
	while (ft_sqrt(res) == 0)
		res++;
	g_edge = ft_sqrt(res);
	move_all_figs_left_up(g_head);
	while (tmp)
	{
		max_x = find_max_coordinate(tmp->x);
		max_y = find_max_coordinate(tmp->y);
		if (max_x >= max_y && max_x >= g_edge)
			g_edge = max_x + 1;
		else if (max_y > max_x && max_y >= g_edge)
			g_edge = max_y + 1;
		tmp = tmp->next;
	}
}

void	begin_validation(char *buff)
{
	int		len;

	len = 0;
	while (buff[len] != '\0')
		len++;
	if ((len + 1) % 21 != 0)
		error_and_exit();
	parse_buffer(buff);
}

int		main(int argc, char **argv)
{
	char	buff[BUF_SIZE];
	int		read_bytes;
	int		fd;

	read_bytes = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	ft_bzero(buff, BUF_SIZE);
	while ((read_bytes = read(fd, buff, BUF_SIZE)) > 0)
		if (read_bytes < 20 || read_bytes > 545)
			error_and_exit();
	begin_validation(buff);
	find_square();
	tetris_solve(g_head);
	print_result_map(g_head);
	return (0);
}
