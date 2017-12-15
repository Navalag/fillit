
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define TETNUM 4

int g_edge = 3;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
			ft_putchar(*s++);
}


typedef struct		s_tet
{
	int				x[4];
	int				y[4];
	struct s_tet	*next;
	struct s_tet	*prev;
}					t_fig;


char			**freeing(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i++] = NULL);
		
	}
	free(str);
	return (NULL);
}

void to_left(t_fig *fig)
{
	int lowest;
	int i;
	
	i = 0;
	lowest = g_edge - 1;
	while (i < TETNUM)
	{
		if (fig->x[i] < lowest)
			lowest = fig->x[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < TETNUM)
		{
			fig->x[i] -= lowest;
			i++; 
		}
}

void to_up(t_fig *fig)
{
	int lowest;
	int i;
	
	i = 0;
	lowest = g_edge - 1;
	while (i < TETNUM)
	{
		if (fig->y[i] < lowest)
			lowest = fig->y[i];
		i++;
	}
	i = 0;
	if (lowest == 0)
		return ;
	else
		while (i < TETNUM)
		{
			fig->y[i] -= lowest;
			i++; 
		}
}

//Проверяет фигуру, и если она не слева, вызывает функцию чтобы двигает фигугу влево. Возвращает 0, если слева.
void mv_fig_full_left_up(t_fig *fig)
{
	int i;
	
	i = 0;
	while (i < g_edge)
	{
		if (fig->x[i++] == 0)
			break ;
		else
		{
			to_left(fig);
			break ;
		}
	}
	i = 0;
	while (i < g_edge)
	{
		if (fig->y[i++] == 0)
			break ;
		else
		{
			to_up(fig);
			break ;
		}
	}
}


/********************************************************************************************/

void	mv_fig_right(t_fig *fig)
{
	int i;

	i = 0;
	while (i < TETNUM)
	{
		fig->x[i] += 1;
		i++;
	}
}

void	mv_fig_down(t_fig *fig)
{
	int i;

	i = 0;
	while (i < TETNUM)
	{
		fig->y[i] += 1;
		i++;
	}
}

//1 - если удачно сдвинул. 0 - если достиг предела
int		mv_fig_once(t_fig *fig)
{
	int i;
	int x_max;
	int y_max;

	i = 0;
	x_max = 0;
	y_max = 0;
	while (i < TETNUM)
	{
		if (fig->x[i] > x_max)
			x_max = fig->x[i];
		i++;
	}
	i = 0;
	if (x_max + 1 < g_edge)
		mv_fig_right(fig);
	else
	{
		while (i < TETNUM)
		{
			if (fig->y[i] > y_max)
				y_max = fig->y[i];
			i++;
		}
		if (x_max + 1 == g_edge && y_max + 1 == g_edge)
			return (0);
		to_left(fig);
		if (y_max + 1 < g_edge)
			mv_fig_down(fig);
	}
	return 1;
}

// получает нод, и сравнивает его со всеми предыдущими. Если он не пересекается с другими, то возвращает 1.
// если пересекается, то возвращает 0 и надо его сдвинуть.
int		node_cmp(t_fig *fig)
{
	int		i;
	int 	j;
	t_fig	*prev_node;

	j = 0;
	prev_node = fig->prev;
	while (prev_node)
	{
		i = 0;
		while (i < TETNUM)
		{
			j = 0;
			while(j < TETNUM)
			{
				if (prev_node->x[i] != fig->x[j] || prev_node->y[i] != fig->y[j])
					j++;
				else
					return (0);
			} 
			i++;
		}
		prev_node = prev_node->prev;
	}
	return (1);
}

//returns 0 if figures are set properly. Returns 1 if needed to enlaege field.
//NOT NESTED
int 	backtrack(t_fig *last_ptr)
{
	while (last_ptr)
	{
		if (!(node_cmp(last_ptr)))
		{
			while (!(mv_fig_once(last_ptr)))
			{
				mv_fig_full_left_up(last_ptr);
				if (!last_ptr->prev)
					g_edge++;
				else
					last_ptr = last_ptr->prev;
			}
		}
		else
			last_ptr = last_ptr->next;
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////////////////
int put_dots_to_field(char **str)
{
	int 	c_x;
	int 	c_y;

	c_x = 0;
	c_y = 0;
	while (c_y < g_edge)
	{
		if(!(str[c_y] = (char*)malloc(sizeof(char) * (g_edge + 1))))
		{
			freeing(str);
			return (0);
		}
		while (c_x < g_edge)
		{
			str[c_y][c_x] = '.';
			c_x++;
		}
		str[c_y][c_x] = '\0';
		c_x = 0;
		c_y++;
	}
	str[c_y] = NULL;
	return (1);
}

void	put_sign_to_field(char **str, t_fig *fig, unsigned char c)
{
	int i;

	i = 0;
	while (i < TETNUM)
	{
		str[fig->y[i]][fig->x[i]] = c;
		i++;
	}
}
/* NOT USED
void 	print_matrix(t_fig *fig)
{
	int 	i;
	char	**str;

	i = 0;
	str = (char**)malloc(sizeof(char*) * (g_edge + 1));
	put_dots_to_field(str);
	put_sign_to_field(str, fig, 'A');
	while (i < g_edge)
		printf("%s\n", str[i++]);
	freeing(str);
}*/
////////////////////////////////////////////////////////////////////////////


void fullmatrixprint (t_fig *head)
{
	char	c;
	int		i;
	char	**str;

	c = 'A';
	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (g_edge + 1))))
		return ;
	if (!(put_dots_to_field(str)))
		return ;
	while (head)
	{
		put_sign_to_field(str, head, c);
		head = head->next;
		i++;
		c++;
	}
	i = 0;
	while (i < g_edge)
	{
		ft_putstr(str[i++]);
		ft_putchar('\n');
	}
	freeing(str);
}

int main()
{
	t_fig* ptr1;
	t_fig* ptr2;
	t_fig* ptr3;
	t_fig* ptr4;
	ptr1 = (t_fig*)malloc(sizeof(t_fig));
	ptr2 = (t_fig*)malloc(sizeof(t_fig));
	ptr3 = (t_fig*)malloc(sizeof(t_fig));
	ptr4 = (t_fig*)malloc(sizeof(t_fig));

	ptr1->x[0] = 0;
	ptr1->x[1] = 0;
	ptr1->x[2] = 1;
	ptr1->x[3] = 2;
   
	ptr1->y[0] = 0;
	ptr1->y[1] = 1;
	ptr1->y[2] = 1;
	ptr1->y[3] = 1;
	
   

	ptr2->x[0] = 1;
	ptr2->x[1] = 2;
	ptr2->x[2] = 1;
	ptr2->x[3] = 2;
   
	ptr2->y[0] = 0;
	ptr2->y[1] = 0;
	ptr2->y[2] = 1;
	ptr2->y[3] = 1;
	


	ptr3->x[0] = 0;
	ptr3->x[1] = 0;
	ptr3->x[2] = 1;
	ptr3->x[3] = 2;
   
	ptr3->y[0] = 0;
	ptr3->y[1] = 1;
	ptr3->y[2] = 1;
	ptr3->y[3] = 1;
   

	ptr4->x[0] = 0;
	ptr4->x[1] = 0;
	ptr4->x[2] = 1;
	ptr4->x[3] = 2;
   
	ptr4->y[0] = 0;
	ptr4->y[1] = 1;
	ptr4->y[2] = 1;
	ptr4->y[3] = 1;


	ptr1->next = ptr2;
	ptr1->prev = NULL;
	ptr2->next = ptr3;
	ptr2->prev = ptr1;
	ptr3->prev = ptr2;
	ptr3->next = ptr4;
	ptr4->prev = ptr3;
	ptr4->next = NULL;

	// print_matrix(ptr1);
	// printf("\n1st matrix\n");
	// print_matrix(ptr2);
	// printf("\n2nd matrix\n");
	// print_matrix(ptr3);
	// printf("\n3rd matrix\n");
	// print_matrix(ptr4);
	// printf("\n4th matrix\n");
	// backtrack(ptr1);
	// print_matrix(ptr1);
	// printf("\n1st matrix\n");
	// print_matrix(ptr2);
	// printf("\n2nd matrix\n");
	// print_matrix(ptr3);
	// printf("\n3rd matrix\n");
	// print_matrix(ptr4);
	// printf("\n4th matrix\n");
	backtrack(ptr1);
	fullmatrixprint(ptr1);
	return 0;
}
