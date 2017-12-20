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

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <sys/file.h>
# include <stdlib.h>
# define BUF_SIZE 546
# define COL_NUM 4

typedef struct	s_tet
{
	int				x[4];
	int				y[4];
	struct s_tet	*next;
	struct s_tet	*prev;
}				t_fig;

t_fig			*g_head;
int				g_edge;

/*
** main.c
*/

void			ft_putstr(char *str);
int				ft_sqrt(int nb);
void			ft_bzero(void *s, size_t n);
void			error_and_exit(void);
void			find_square(void);
void			begin_validation(char *buff);

/*
** valid_func.c
*/

int				validate_symbols(char *str);
int				validate_touch(char *str);
int				validate_rows(char *str);
void			parse_buffer(char *buff);
void			find_coordinate(char *str);

/*
** solve_algo.c
*/

void			move_all_figs_left_up(t_fig *node);
int				move_one_step(t_fig *node);
void			move_full_left_up(t_fig *node);
int				check_all_figures(t_fig *node);
int				tetris_solve(t_fig *node);

/*
** list_func.c
*/

t_fig			*lst_new_node(int x[], int y[]);
void			lst_insert_at_tail(int x[], int y[]);
int				lst_count_elem(void);

/*
** move_func.c
*/

int				find_max_coordinate(int array[]);
void			move_right(t_fig *fig);
void			move_down(t_fig *fig);
void			move_full_up(t_fig *node);
void			move_full_left(t_fig *node);

/*
** print_func.c
*/

void			print_result_map(t_fig *node);
int				fill_map_with_dots(char **str);
void			fill_map_with_letters(char **str, t_fig *node, char c);
char			**freeing(char **str);

#endif
