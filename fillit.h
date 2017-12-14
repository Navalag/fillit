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
# define COL_NUM 4

typedef	struct	s_tetris
{
	char				*row;
	struct s_tetris		*next;
	struct s_tetris		*prev;
}				t_figure;

typedef struct	s_tet
{
	int				x[4];
	int				y[4];
	struct s_tet	*next;
	struct s_tet	*prev;
}				t_fig;

t_figure	*g_head; // global variable - pointer to head node.
t_fig 		*g_first_node;
int 		g_edge; // another global variable for new algorithm

/* list functions */
void		*ft_memcpy(void *dst, const void *src, size_t n);
t_figure	*lst_new_node(char *cont, int size);
void		lst_insert_at_head(char *cont);
int 		lst_count_elem();
void		lst_print();

/* new list function */
t_fig		*new_lst_new_node(int x[], int y[]);
void		new_lst_insert_at_tail(int x[], int y[]);
void		new_lst_print();

/* validation functions */
void		begin_validation(unsigned char *buff);
void		validate_sumbols();
void		validate_touch();
void		validate_rows();
void		parse_buffer(unsigned char *buff);
void		new_parsing(char *str);

/* tetris solve algo */
int			ft_sqrt(int nb);
void		find_square();
int 		find_max_coordinate(int array[]);
void		move_right(t_fig *fig);
void		move_down(t_fig *fig);
void		move_full_left(t_fig *fig);
int			move_one_step(t_fig *fig);
void		tetris_solve(t_fig *node);
int 		check_all_figures(t_fig *node);
void 		to_up(t_fig *fig);
void 		mv_fig_full_left_up(t_fig *fig);

/* new_way */
// char		**freeing(char **str);
// void		to_left(t_fig *fig);
// void 		to_up(t_fig *fig);
// void 		mv_fig_full_left_up(t_fig *fig);
// void 		put_dots_to_field(char **str);
// void		put_sign_to_field(char **str, t_fig *fig, unsigned char c);
// void 		print_matrix(t_fig *fig);
// void		mv_fig_right(t_fig *fig);
// void		mv_fig_down(t_fig *fig);
// int			mv_fig_once(t_fig *fig);
// int			node_cmp(t_fig *fig);
// int 		backtrack(t_fig *last_ptr);

#endif
