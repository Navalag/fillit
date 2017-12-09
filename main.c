/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:00:07 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/09 20:14:41 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// TETRIS RESOLVE ALGORITHM

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

int		find_square()
{
	int 	count;
	int 	res;

	count = lst_count_elem();
	res = count * 4;
	while (ft_sqrt(res) == 0)
		res++;
	return (ft_sqrt(res));
}

// void	create_canvas(int wide)
// {

// }

// void	write_canvas()

// int		find_figure_width(char *str)
// {
// 	int max;
// 	int i;

// 	max = 0;
// 	while (*str)
// 	{
// 		i = 0;
// 		while (*str++ == '#')
// 			i++;
// 		max = (i > max) ? i : max;
// 	}
// 	return (max);
// }

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	figure_move_up_left(char *str)//, int step)
{
	int 	i;
	int 	j;
	int 	res;
	
	i = 0;
	j = 0;
	res = 1;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	while (i-- >= 0)
	{
		if (str[i] == '#' && str[i - 1] != '.')
			res = 0;
	} // fix i = 0 !!
	if (res == 1)
	{
		while (j-- >= 0)
		{
			if (str[j] == '#' && j != 0)
				ft_swap(&str[j], &str[j - 1]);
		}
	}
}

// void	figure_move_down_right(char *str, int step)
// {
// 	int 	i;
// 	int 	res;
	
// 	i = 0;
// 	res = 1;
// 	while (str[i] != '\0')
// 		i++;
// 	while (i >= 0)
// 	{
// 		if (str[i] == '#' && str[i - 1] != '.')
// 			res = 0;
// 		i--;
// 	} // fix i = 0 !!
// 	if (res)
// 	{
// 		while (i >= 0)
// 		{
// 			if (str[i] == '#')
// 				ft_swap(str[i], str[i - 1]);
// 			i--;
// 		}
// 	}
// }

// int 	check_next_step(char *str, char c)
// {
// 	int 	i;
	

// 	i = 0;
// 	res = 1;
// 	while (str[i] != '\0')
// 	{
// 		if (c == '#' && c + 1 != '.')
// 			res = 0;
// 		i++;
// 	}
// 	return (res);
// }

// void	figure_compare()
// {
// 	t_figure	*tmp;
// 	int 		i;
// 	int 		j;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{
// 		i = 0;
// 		while (tmp->row[i] != '\0')
// 		{
// 			if (check_next_step(tmp->row[i]))
// 				figure_move(tmp->row, 1);
// 			else
// 				figure_move(tmp->row, find_figure_width(tmp->row));
// 		}
// 	}
// }

int		main(int argc, char **argv)
{
	unsigned char	buff[BUF_SIZE];
	int				n;
	int				fd;
	int 			len;
	int				i;
	t_figure		*head;
	char			tmp[20];
	int				j;

	head = NULL;
	len = 1;
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		return (0);
	while ((n = read(fd, buff, BUF_SIZE)) > 0)
	{
		if (n < 19 || n > 545)
			return (0);  // invalid file
	}
	printf("%s\n", buff);  // test if buffer works correctly

	while (buff[len] != '\0')
		len++;
	printf("actual readed bytes - %i\n", len);
	if (((len + 1) % 21 != 0) && len != 19) //  must check 19 or 20 and if need + 1 !!
		return (printf("invalid file\n"));  // invalid file

	//  separate and add figures to the list
	j = 0;
	while (buff[j] != '\0')
	{
		i = 0;
		while (i < 20 && buff[j] != '\0')
			tmp[i++] = buff[j++];
		tmp[i] = '\0';
		if (buff[j] != '\0')
			j++;
		lst_insert_at_head(tmp);
	}
	lst_print();  // test print
	// free(buff);
	// free(tmp);

	validate_sumbols();
	validate_touch();
	validate_rows();
	printf("list size - %i\n", lst_count_elem()); // test lst_count function
	// printf("result square size - %i\n", find_square());

// test move func

	// t_figure *test = head;
	// test = test->next;
	char *str = ".##.\n.##.\n....\n....";
	figure_move_up_left(str);
	printf("%s\n", str);

	// lst_print();
	return (0);
}
