/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:40:44 by agalavan          #+#    #+#             */
/*   Updated: 2017/12/08 11:40:46 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Separate and add figures to the list  */
void		parse_buffer(unsigned char *buff)
{
	int		i;
	int		j;
	char	tmp[21];

	j = 0;

	while (buff[j] != '\0')
	{
		i = 0;
		/* separate each 20 characters (one figure) */
		while (i < 20 && buff[j] != '\0')
			tmp[i++] = buff[j++];
		tmp[i] = '\0';
		/* If this is not the last figure in buffer - j++.
		Means that there is additional \n to separate two figures
		and we need to skip it */
		if (buff[j] != '\0')
			j++;
		/* check if all next validations are good - continue */
		if (!(validate_symbols(tmp)) || !(validate_touch(tmp)) ||
			!(validate_rows(tmp)))
			exit (0);
		find_coordinate(tmp);
	}
}

/* Find coordinates for all readed figures and add them
to the linked list */
void	find_coordinate(char *str)
{
	int		i;
	int		j;
	int		a;
	int		x[4];
	int		y[4];

	j = 0;
	a = 0;
	/* read each row from figure and if find '#' add it's
	coordinate to 'x' and 'y' and then add them to the list */
	while (*str)
	{
		i = 0;
		while (*str != '\n')
		{
			if (*str == '#')
			{
				x[a] = i;
				y[a] = j;
				a++;
			}
			i++;
			str++;
		}
		j++;
		str++;
	}
	new_lst_insert_at_tail(x, y);
}

int		validate_symbols(char *str)
{
	int		i;
	int		a;
	int		b;
	int		c;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			a++;
		if (str[i] == '.')
			b++;
		if (str[i] == '\n')
			c++;
		i++;
	}
	if (a == 4 && b == 12 && c == 4)
		return (1);
	return (0);
}

int		validate_touch(char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#')
			count++;
		if (str[i] == '#' && str[i - 1] == '#')
			count++;
		if (str[i] == '#' && str[i + 5] == '#')
			count++;
		if (str[i] == '#' && str[i - 5] == '#')
			count++;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		validate_rows(char *str)
{
	int			i;
	int			count;

	i = 0;
	while (str[i] != '\0')
	{
		count = 0;
		while (str[i] != '\n')
		{
			count++;
			i++;
		}
		if (count != 4)
			return (0);
		i++;
	}
	return (1);
}
