#include <stdio.h>
#define MAX 1000000

int primes[MAX + 1] = {0};

void    eratostenes(void)
{
    primes[0] = primes[1] = -1;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                primes[j] = -1;
            }
        }
    }
}

int main()
{
    eratostenes();
    char p[101];
    int k;
    scanf("%s %d", p, &k);
    for (int i = 2; i < k; i++)
    {
        if (primes[i] == 0) //is_prime
        {
            int sum = 0;
            for (char *ptr = p; *ptr != NULL; ptr++)
            {
                sum = (sum * 10 + (*ptr - '0')) % i;
            }
            if (sum == 0) // k보다 작은 소수로 나누어 떨어질때
            {
                printf("BAD %d\n", i);
                return (0);
            }
        }
    }
    printf("GOOD\n");
    return (0);
}