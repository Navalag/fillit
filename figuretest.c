#include <stdio.h>

//определяет макс ширину фигуры
int		fig_width(char *str)
{
	int max;
	int i;

	i = 0;
	max = 0;
	while (*str)
	{
		while (*str++ == 'x')
			i++;
		max = (i > max) ? i : max;
		i = 0;
	}
	return (max);
}

//сверяет фигуру 1 и 2, если в ячейке под индекcом И совпадают значения, то она возвращает индекс
int 	fig_compare(char *fig1, char *fig2)
{
	int i;

	i = 0;
	while (fig1[i])
	{
		if (fig1[i] == fig2[i] && fig2[i] == '#')
			return (i);
		i++;
	}
	return (0);
}

char	*figure_to_lft_up(char *src)
{
	char *res;
	
}

int	main()
{
	//int i;
	char str1[] = "..#.\n..##\n..#.\n....\n";
	printf("%s", str1);

	//char str2[] = ".#..\n#...\n..#.\n....\n";
	//int j = fig_compare(str1, str2);
	//printf("%d", j);
}
