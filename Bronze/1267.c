#include <stdio.h>

int	y_charge(int t)
{
	int y = 10;
	for (int i = 1; i <= t; i++)
	{
		if (i % 30 == 0)
			y += 10;
	}
	return (y);
}

int	m_charge(int t)
{
	int m = 15;
	for (int i = 1; i <= t; i++)
	{
		if (i % 60 == 0)
			m += 15;
	}
	return (m);
}

int main()
{
	int n, temp, y = 0, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &temp);
		y += y_charge(temp);
		m += m_charge(temp);
	}
	if (y < m)
		printf("Y %d\n", y);
	else if (y > m)
		printf("M %d\n", m);
	else
		printf("Y M %d\n", y);
}