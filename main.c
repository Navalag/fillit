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



int		main(int argc, char **argv)
{
	unsigned char	buff[BUF_SIZE]; // buffer for income data
	int				read_bytes; // number of read bytes
	int				fd; // file descriptor

	/* BEGIN VALIDATION */
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	while ((read_bytes = read(fd, buff, BUF_SIZE)) > 0)
		if (read_bytes < 19 || read_bytes > 545)
			return (0);  // invalid file
	
	begin_validation(buff);
	/* FINISH VALIDATION */

	printf("list size - %i\n", lst_count_elem()); // test lst_count function
	// printf("result square size - %i\n", find_square());

	// lst_print();
	new_lst_print();

	return (0);
}
