#include <stdio.h>
#include <string.h>

int ret[20] = {0, };

int	fruit_num_init(int n)
{
	char fruit[11];
	int num;

	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", fruit, &num);
		ret[fruit[0] - 'A'] += num;
	}
	for (int i = 0; i < 20; i++)
	{
		if (ret[i] == 5)
			return 1;
	}
	return (0);
}

int main()
{
	int n;
	scanf("%d", &n);
	if (fruit_num_init(n))
	{
		printf("YES\n");
		return (0);
	}
	printf("NO\n");
}