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

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	char *tmp;

	tmp = s;
	while (n != 0)
	{
		*tmp++ = 0;
		n--;
	}
}

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
	t_fig	*tmp;
	int		max_x;
	int		max_y;

	tmp = g_head;
	count = lst_count_elem();
	res = count * 4;
	while (ft_sqrt(res) == 0)
		res++;
	g_edge = ft_sqrt(res);
	// printf("%i in find_square 1\n", g_edge);
	while (tmp)
	{
		max_x = find_max_coordinate(tmp->x);
		max_y = find_max_coordinate(tmp->y);
		// printf("max_x - %i\n", max_x);
		// printf("max_y - %i\n", max_y);
		if (max_x >= max_y && max_x >= g_edge)
			g_edge = max_x + 1;
		else if (max_y > max_x && max_y >= g_edge)
			g_edge = max_y + 1;
		tmp = tmp->next;
	}
	// printf("%i in find_square\n", g_edge);
}

void		begin_validation(unsigned char *buff)
{
	int		len;

	len = 0;
	/* count lenght of buffer */
	while (buff[len] != '\0')
		len++;
	/* Validate amount of figures.
	Each figure must have 20 signs + \n between every two figures, 
	but not after last figure in the file. That is why len + 1 */
	if ((len + 1) % 21 != 0)
	{
		ft_putstr("error\n");
		exit (0);
	}
	/* continue validation in next function */
	parse_buffer(buff);
}

int		main(int argc, char **argv)
{
	unsigned char	buff[BUF_SIZE];
	int				read_bytes;
	int				fd;

	read_bytes = 0;
	/* Validate arguments. Must be only 1
	if not 1 - print usage example and exit program */
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	/* open file and if there is an issue with opening - exit program */
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	ft_bzero(buff, BUF_SIZE);
	/* read bytes from standard input */
	while ((read_bytes = read(fd, buff, BUF_SIZE)) > 0)
	{
		/* Given argument (file) must contain from 1 to 26 figures
		20 sign each (+ 1 byte for \n after each figure).
		So readed bytes must be from 20 to 545.
		If not - return error message and exit program. */
		if (read_bytes < 20 || read_bytes > 545)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	/* begin main part of validation process */
	begin_validation(buff);

	/* FINISH VALIVATION */

	move_all_figs_left_up(g_head);
	// new_lst_print();
	find_square();
	tetris_solve(g_head);
	move_all_figs_left_up(g_head);
	tetris_solve(g_head);
	print_result_map(g_head);
	return (0);
}
