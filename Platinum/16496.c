#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

int compare(const void *x, const void *y)
{
    char *a = (char *)x;
    char *b = (char *)y;
    size_t a_len = strlen(a), b_len = strlen(b);
    int i = 0, bk_a = 0, bk_b = 0;
    char f_a = a[i], f_b = b[i];
    while (f_a == f_b)
    {
        i++;
        if (i >= a_len)
            bk_a = 1;
        else
        {
            f_a = a[i];
        }
        if (i >= b_len)
            bk_b = 1;
        else
        {
            f_b = b[i];
        }
        if (bk_a + bk_b == 1) // 자릿수가 다를경우
        {
            if (bk_a == 1) // b 자릿수가 하나 더 많음
            {
                if (f_b - a[0] == 0)
                    continue ;
                return (f_b - a[0]);
            }
            else if (bk_b == 1) // a 자릿수가 하나 더 많음
            {
                if (b[0] - f_a == 0)
                    continue ;
                return (b[0] - f_a);
            }
        }
        else if (bk_a + bk_b == 2)
            break ;
    }
    return (f_b - f_a);
}

char **arr_init(void)
{
    scanf("%d", &n);
    char **arr = (char **)malloc(sizeof(char *) * (n + 1));
    arr[n] = NULL;
    char *t;
    for (int i = 0; i < n; i++)
    {
        t = (char *)malloc(sizeof(char) * 30);
        scanf("%s", t);
        arr[i] = t;
    }
    return (arr);
}

void mal_free(char **arr)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void ft_qsort(char **arr, int L, int R) //, (int)(f)(const void *, const void *))
{
    int left = L, right = R;
    int pivot = (L + R) / 2;
    char *temp;
    while (left <= right)
    {
        while (compare(arr[left], arr[pivot]) < 0)
            left++;
        while (compare(arr[right], arr[pivot]) > 0)
            right--;
        if (left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    if (L < right)
        ft_qsort(arr, L, right);
    if (R > left)
        ft_qsort(arr, left, R);
}

int main()
{
    char **arr = arr_init();
    ft_qsort(arr, 0, n - 1);
    //qsort(arr, n, sizeof(arr[0]), compare);
    if (arr[0][0] == '0') // 최댓값이 0이면 0출력
    {
        printf("0\n");
        return (0);
    }
    for (int i = 0; i < n; i++)
        printf("%s", arr[i]);
    printf("\n");
    mal_free(arr);
    return (0);
}

//    qsort(arr, n, sizeof(char *), compare); // 내림차순 정렬 최댓값 ~ 최솟값
// ret_set(ret, &ret_len);
// for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);

// int -> strjoin
/* n을 int 배열로 입력받고,
모두가 0이면 0출력, 아니면 qsort후 앞에서부터 itoa해서 ret에 strjoin
int배열 scanf -> qsort -> for(itoa -> strjoin(ret)) */
/*

int first_num(int a)
{
    int first;

    if (a < 10)
        return (a);
    while (a)
    {
        first = a;
        a /= 10;
    }
    return (first);
}

int len_ch(int a)
{
    int cnt = 0;
    if (a < 10)
        return (1);
    while (a)
    {
        cnt++;
        a /= 10;
    }
    return (cnt);
}

int ten_jegob(int a)
{
    int ten = 1;
    for (int i = 0; i < a; i++)
        ten *= 10;
    return (ten);
}

char *ft_itoa(int a, int *a_len)
{
    *a_len = len_ch(a);
    char *ret = (char *)malloc(sizeof(char) * (*a_len + 1));
    ret[*a_len] = '\0';
    for (int i = *a_len - 1; i >= 0; i--)
    {
        ret[i] = a % 10 + '0';
        a /= 10;
    }
    return (ret);
}

char *ft_strjoin(char *ret, int *ret_len, char *t, int t_len)
{
    if (ret == NULL)
    {
        *ret_len = t_len;
        return (t);
    }
    int new_len = *ret_len + t_len;
    char *new = (char *)malloc(sizeof(char) * (new_len + 1));
    new[new_len] = '\0';
    strncpy(new, ret, *ret_len);
    strncpy(new + *ret_len, t, t_len);
    *ret_len = new_len;
    free(ret);
    free(t);
    return (new);
}

void ret_set(char *ret, int *ret_len)
{
    // char *t;
    int t_len;
    for (int i = 0; i < n; i++)
    {
        // t = ft_itoa(arr[i], &t_len);
        ret = ft_strjoin(ret, ret_len, arr[i], strlen(arr[i]));
    }
    printf("%s\n", ret);
    free(ret);
}*/