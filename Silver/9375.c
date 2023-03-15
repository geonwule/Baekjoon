#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test, n;
typedef struct s_table
{
	int arr[25621];
	int size;
} t_table;

t_table hashtable;

void hash_init(void)
{
	hashtable.size = 0;
	for (int i = 0; i < 25621; i++)
	{
		hashtable.arr[i] = 0;
	}
}

int hash(char *s)
{
	int hash = 0;
	for (int i = 0; s[i] != '\0'; i++)
		hash = hash + (i + 1) * s[i];
	return (hash % 25620);
}

int combination(void)
{
	if (hashtable.size == 0)
		return (0);
	if (hashtable.size == 1)
	{
		for (int i = 0; i < 25621; i++)
		{
			if (hashtable.arr[i])
				return (hashtable.arr[i]);
		}
	}
	int sum = 0, gob = 1;
	for (int i = 0; i < 25621; i++)
	{
		if (hashtable.arr[i])
		{
			sum += hashtable.arr[i];
			gob *= hashtable.arr[i];
		}
	}
	return (sum + gob);
}

int main()
{

	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		hash_init();
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			char temp[30];
			char wear[30];
			scanf("%s %s", temp, wear);
			hashtable.arr[hash(wear)] += 1;
			if (hashtable.arr[hash(wear)] == 1)
				hashtable.size += 1;
		}
		printf("%d\n", combination());
	}
}