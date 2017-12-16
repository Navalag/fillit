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

void		begin_validation(unsigned char *buff)
{
	int		len;

	len = 1;
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

	/* FINISH OF VALIVATION */

	find_square();
	tetris_solve(g_head);
	print_result_map(g_head);
	return (0);
}
