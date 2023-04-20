#include <stdio.h>

int combination(int n, int r) {
    int i, j;
    int result = 1;

    // 분모(n-r)! 계산
    for (i = 1; i <= n - r; i++) {
        result *= i;
    }

    // 분자(r)! 계산
    for (j = 1; j <= r; j++) {
        result *= (n - r + j) / j;
    }

    return result;
}

int main() {
    int n, r;

    scanf("%d %d", &n, &r);
    int result = combination(n, r);
    printf("%d\n", result);

    return 0;
}
