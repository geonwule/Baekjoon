#include <stdio.h>
#include <stdlib.h>

int 	main()
{
	int	i = 0;
	int	n;
	int	*ret;
	int	a;

	scanf("%d", &n);
	ret = (int *)malloc(sizeof(int) * n);
	while (i < n)
	{
		scanf("%d", &a);
		ret[i] = a;
		i++;
	}
	for (int j = 0; j < n; j++)
	{
		printf("%d", ret[j]);
	}
	printf("\n");
}
