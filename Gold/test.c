#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weight[], int value[], int n) {
    int i, w;
    int K[n+1][capacity+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i-1] <= w)
                K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][capacity];
}

int main() {
    int capacity, n, i;
    int *weight, *value;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    weight = (int*) malloc(n * sizeof(int));
    value = (int*) malloc(n * sizeof(int));

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &value[i]);

    printf("The maximum value of items that can be carried in the knapsack is %d\n", knapsack(capacity, weight, value, n));

    free(weight);
    free(value);
    return 0;
}
