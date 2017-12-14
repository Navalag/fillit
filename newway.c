
# define TETNUM 4

int g_edge = 5;

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

void put_dots_to_field(char **str)
{
	int 	c_x;
	int 	c_y;

	c_x = 0;
	c_y = 0;
	while (c_y < g_edge)
	{
		str[c_y] = (char*)malloc(sizeof(char) * (g_edge + 1));
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
}

void	put_sign_to_field(char **str, t_fig *fig, unsigned char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		str[fig->y[i]][fig->x[i]] = c;
		i++;
	}
}

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

// получает нод, и сравнивает его со всеми предыдущими. Если он не пересекается с другими, то возвращает 0.
// если пересекается, то возвращает 1 и надо его сдвинуть.
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
					return (1);
			} 
			i++;
		}
		prev_node = prev_node->prev;
	}
	return (0);
}

//returns 0 if figures are set properly. Returns 1 if needed to enlaege field.

int 	backtrack(t_fig *head)
{
	t_fig *last_ptr;
	t_fig *temp;

	last_ptr = head->next;
	while (last_ptr)
	{
		if (node_cmp(last_ptr))
		{
			if (mv_fig_once(last_ptr))
				;
			else
			{
				mv_fig_full_left_up(last_ptr);
				mv_fig_once(last_ptr = last_ptr->prev);
				if (backtrack(last_ptr) == 0)
					return (0);
			}
		}
		else
		{
			if ((last_ptr = last_ptr->prev) == NULL)
			{
				g_edge++;
				return (1);
			}
		}
		last_ptr = last_ptr->next;
	}
	return (0);
}

void	back (t_fig *head)
{
	int doer;

	doer = 1;
	while (doer == 1)
		doer = backtrack(head);
}

int main()
{
	t_fig* ptr1;
	t_fig* ptr2;
	ptr1 = (t_fig*)malloc(sizeof(t_fig));
	ptr2 = (t_fig*)malloc(sizeof(t_fig));
	ptr1->x[0] = 0;
	ptr1->x[1] = 1;
	ptr1->x[2] = 0;
	ptr1->x[3] = 0;
	ptr1->y[0] = 0;
	ptr1->y[1] = 0;
	ptr1->y[2] = 1;
	ptr1->y[3] = 2;
	ptr2->x[0] = 0;
	ptr2->x[1] = 1;
	ptr2->x[2] = 0;
	ptr2->x[3] = 0;
	ptr2->y[0] = 0;
	ptr2->y[1] = 0;
	ptr2->y[2] = 1;
	ptr2->y[3] = 2;
	print_matrix(ptr1);
	printf("\n1st matrix\n");
	print_matrix(ptr2);
	printf("\n2nd matrix\n");
	backtrack(ptr1);
	print_matrix(ptr1);
	printf("\n1st matrix\n");
	print_matrix(ptr2);
	printf("\n2nd matrix\n");

	return 0;
}
