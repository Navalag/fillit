#include <stdio.h>

//определяет макс ширину фигуры
int		figure_width(char *str)
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

int	main()
{
	int i;
	char str[] = "..x.\n..xx\n..x.\n";
	i = figure_width(str);
	printf("%d\n", i);
	//printf("%s", str);
}
