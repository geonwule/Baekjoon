#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int 	main()
{
	long	play;
	long	win;
	long	i = 0;

	scanf("%ld %ld", &play, &win);
	long	lose = play - win;
	long	target = win * 100 / play;
	long	ret = -1;

	if (play == win)
	{
		printf("-1\n");
		return (0);
	}
	if (lose <= win && win > 500)
	{
		i += win * 2 / 50;
		while ((win + i) * 100 / (play + i) == target)
		{
			i++;
		}
		printf("%ld\n", i);
		return (0);
	}
	while ((win + i) * 100 / (play + i) == target)
	{
		i++;
	}
	printf("%ld\n", i);
}
//	printf("target = %ld\n", target);
//		printf("win percent = %d\n", (win + i) * 100 / (play + i));
//		printf("upgrade success = %d\n", (win + i) * 100 / (play + i));
