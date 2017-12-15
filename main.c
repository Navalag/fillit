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

void	putstr(char *str, int n)
{
	write(1, &str, n);
}

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

int		begin_validation(unsigned char *buff)
{
	int		len;

	len = 1;
	// printf("%s\n", buff);  // test if buffer works correct
	while (buff[len] != '\0')
		len++;
	// printf("actually readed bytes - %i\n", len);
	//  need to check 19 or 20 and if need + 1 !!
	if (((len + 1) % 21 != 0) && len != 19)
	{
		ft_putstr("error\n");
		return (0);
	}

	if (!(parse_buffer(buff)))
	{
		ft_putstr("error\n");
		return (0);
	}
	// validate_sumbols();
	// validate_touch();
	// validate_rows();
	return (1);
}

int		main(int argc, char **argv)
{
	unsigned char	buff[BUF_SIZE];
	int				read_bytes;
	int				fd;
	t_fig			*tmp;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	while ((read_bytes = read(fd, buff, BUF_SIZE)) > 0)
		if (read_bytes < 19 || read_bytes > 545)
			return (0);
	
	if (!(begin_validation(buff)))
		return (0);

	find_square();
	tmp = g_first_node->next;
	tetris_solve(tmp);
	fullmatrixprint(g_first_node);
	// new_lst_print();
	return (0);
}
