#include <stdio.h>

#define MAX 500000

int main()
{
    int n, front = 0, rear;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1\n");
        return (0);
    }
    int box[MAX];
    for (int i = 0; i < n; i++)
        box[i] = i + 1;
    rear = n - 1;
    while (1)
    {
        front = (front + 1) % n;
        if (rear == front)
            break;
        rear = (rear+1) % n;
        box[rear] = box[front];
        front = (front + 1) % n;
        if (rear == front)
            break ;
    }
    printf("%d\n", box[front]);
}