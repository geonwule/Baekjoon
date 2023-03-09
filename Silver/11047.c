#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	coin_init(int *coin, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
}

int main()
{
	int n, k, coin[10], coin_i, ret = 0, cnt = 0;
	scanf ("%d %d", &n, &k);
	coin_init(coin, n);
	coin_i = n - 1;
	while (coin[coin_i] > k)
		coin_i--;
	while (ret != k)
	{
		while (ret + coin[coin_i] <= k)
		{
			ret += coin[coin_i];
			cnt++;
		}
		coin_i--;
	}
	printf("%d\n", cnt);
}