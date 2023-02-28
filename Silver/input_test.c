#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void    str_init(char *str)
// {
//     for (int i = 0; i < 102; i++)
//         str[i] = '\0';
// }

char *str_init(void)
{
    char *str;

    str = (char *)malloc(sizeof(char) * 102);
    for (int i = 0; i < 102; i++)
        str[i] = '\0';
    return (str);
}

int main()
{
    char *str;
    char *str2;

    while (1)
    {
        str = str_init();
        str2 = str_init();
        write(1, "read input : ", 13);
        read(0, str, 102);
        if (str[0] == '.')
            break ;
        printf("read output : %s", str);
        printf("fgets input : ");
        printf("fgets output : %s", fgets(str2, 102, stdin));
        free(str);
        free(str2);
    }
    free(str);
    free(str2);
}