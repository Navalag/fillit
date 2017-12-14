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

	new_lst_print();
	find_square();
	printf("g_edge = %i\n", g_edge);

	t_fig	*tmp;
	tmp = g_first_node->next;
	tetris_solve(tmp);
	new_lst_print();
	// print_matrix(tmp->prev);
	// printf("\n");
	// print_matrix(tmp);
	// printf("\n");
	// print_matrix(tmp->next);
	// printf("\n");
	// print_matrix(tmp->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next->next->next->next->next);
	// printf("\n");
	// print_matrix(tmp->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next);

	return (0);
}
