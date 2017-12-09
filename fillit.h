/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:57:29 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/06 16:57:31 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FILLIT_H
# define	FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <sys/file.h>
# include <stdlib.h>
# define BUF_SIZE 546

typedef	struct	tetris_t
{
	char				*row;
	struct tetris_t		*next;
	struct tetris_t		*prev;
}				t_figure;

t_figure	*head; // global variable - pointer to head node.

void		*ft_memcpy(void *dst, const void *src, size_t n);
t_figure	*lst_new_node(char *cont, int size);
void	lst_insert_at_head(char *cont);
int 	lst_count_elem();
void	lst_print();
void	validate_sumbols();
void	validate_touch();
void	validate_rows();

#endif
