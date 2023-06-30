#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000];
#ifdef DEBUG
int *debug;
#endif

int calcu(int *soo, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int start = soo[i];
			int len = 1;
			if (soo[j] > start)
			{
				start = soo[j];
				len++;
				for (int k = j + 1; k < n; k++)
				{
					if (soo[k] > start)
					{
						start = soo[j];
						len++;
					}
				}
			}
			if (len > max)
			{
				max = len;
			}
		}
	}
	return max;
}
int main()
{
	memset(arr, 0, sizeof(arr));

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int max = calcu(arr, n);
	printf("%d\n", max);
}