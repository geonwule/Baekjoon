#include <stdio.h>

int		arr[128][128];

typedef struct s_vars
{
	int	y;
	int	x;
}		t_vars;

int	cut_set(int cut, t_vars start, t_vars end)
{
	for (int i = start.y; i < end.y; i++)
	{
		for (int j = start.x; j < end.x; j++)
		{
			if (cut != arr[i][j])
				return (-1);
		}
	}
	return (cut);
}

void	recur(int *w, int *b, t_vars start, t_vars end)
{
	int	cut;

	cut = arr[start.y][start.x];
	cut = cut_set(cut, start, end);
	if (cut == -1)
	{
		t_vars s, e;
		s.x = start.x;
		s.y = start.y;
		e.x = (start.x + end.x) / 2;
		e.y = (start.y + end.y) / 2;
		recur(w, b, s, e);
		s.x = (start.x + end.x) / 2;
		e.x = end.x;
		recur(w, b, s, e);
		s.y = (start.y + end.y) / 2;
		e.y = end.y;
		recur(w, b, s, e);
		s.x = start.x;
		e.x = (start.xend.x / 2;
		recur(w, b, s, e);
	}
	else if (cut == 1)
		*b += 1;
	else
		*w += 1;
}

int	input_set(void)
{
	int	n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	return (n);
}

int	main(void)
{
	int n = input_set();
	int w = 0, b = 0;
	t_vars start, end;
	start.x = 0;
	start.y = 0;
	end.x = n;
	end.y = n;
	recur(&w, &b, start, end);
	printf("%d\n%d\n", w, b);
}