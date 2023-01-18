#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	str[s1_len + s2_len] = '\0';
    if (s1 != NULL)
        free(s1);
	return (str);
}

int compare_big(int a, int b)
{
    if (a > b)
        return (1);
    return (0);
}

int main(void)
{
    int     a;
    int     b;
    char    *ret = NULL;

    while (1)
    {
        scanf("%d %d", &a, &b);

        if (a == 0 && b == 0)
            break ;
        if (compare_big(a, b))
            ft_strjoin(ret, "Yes\n");
        else
            ft_strjoin(ret, "No\n");
    }
    printf("%s", ret);
    return (0);
}