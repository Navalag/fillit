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
# define BUF_SIZE 546 // size for input buffer
# define COL_NUM 4 // number of columns in input figure

typedef struct	s_tet
{
	int				x[4];
	int				y[4];
	struct s_tet	*next;
	struct s_tet	*prev;
}				t_fig;

t_fig		*g_head; // global variable - pointer to head node.
int 		g_edge; // g_edge - contains size of result square

/* main file */
void		ft_putstr(char *str);
int			ft_sqrt(int nb);
void		find_square();
void		begin_validation(unsigned char *buff);

/* list functions */
t_fig		*new_lst_new_node(int x[], int y[]);
void		new_lst_insert_at_tail(int x[], int y[]);
void		new_lst_print();
int 		lst_count_elem();

/* validation functions */
int			validate_symbols(char *str);
int			validate_touch(char *str);
int			validate_rows(char *str);
void		parse_buffer(unsigned char *buff);
void		find_coordinate(char *str);

/* tetris solve algorithm */
void		move_all_figs_left_up(t_fig *node);
int			move_one_step(t_fig *node);
void		move_full_left_up(t_fig *node);
int 		check_all_figures(t_fig *node);
void		tetris_solve(t_fig *node);

/* move functions (this is only subfunctions for move_one_step and
move_full_left_up) */
int 		find_max_coordinate(int array[]);
void		move_right(t_fig *fig);
void		move_down(t_fig *fig);
void		move_full_up(t_fig *node);
void		move_full_left(t_fig *node);

/* print functions */
void		print_result_map(t_fig *node);
int			fill_map_with_dots(char **str);
void		fill_map_with_letters(char **str, t_fig *node, char c);
char		**freeing(char **str);	

#endif
