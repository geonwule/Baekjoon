#include <stdio.h>


typedef struct s_vars
{
    int width;
    int height;
    char back;
}   t_vars;

typedef struct s_modi
{
        char    c;
        float   x;
        float   y;
        float   radius;
        char	back;
}   t_modi;

int main()
{
    char *filename = "example.txt";
    FILE *fp;
    fp = fopen(filename, "r");
    char    buf[1];
    t_vars vars;
    t_modi modi;

    printf("----1-----\n");
    int scan_size = fscanf(fp, "%d %d %c", &vars.width, &vars.height, &vars.back);
    printf("scansize = %d\n", scan_size);
    printf("%d %d %c\n", vars.width, vars.height, vars.back);
    fclose(fp);

    fp = fopen(filename, "r");
    fread(buf, sizeof(char), 1, fp);
    while (buf[0] != '\n')
        fread(buf, sizeof(char), 1, fp);

    printf("----2-----\n");
    fscanf(fp, "%c %f %f %f %c", &modi.c, &modi.x, &modi.y, &modi.radius, &modi.back);
    printf("%c %f %f %f %c\n", modi.c, modi.x, modi.y, modi.radius, modi.back);
    fclose(fp);
}