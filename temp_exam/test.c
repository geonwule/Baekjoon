//fopen fread fscanf fclose
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//powf, sqrtf
#include <math.h>

#define BUFFER_SIZE 4

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

void    leaks(void)
{   system("leaks a.out");}

void    map_print(char **map, t_vars *vars)
{
    for (int i = 0; i < vars->height; i++)
    {
        printf("%s\n", map[i]);
        free(map[i]);
    }
}

void    map_set(t_vars *origin, t_modi mod, char **map, char *info)
{
    return ;
}

int main()
{
    char    *filename = "example.txt";
    FILE    *fp;
    char    buf[BUFFER_SIZE];
    char    *info;
    char    **map;

    fp = fopen(filename, "r");
    t_vars *vars = malloc(sizeof(t_vars));

    printf("------fscanf--------\n");
    fscanf(fp, "%d %d %c", &vars->width, &vars->height, &vars->back);
    printf("width = %d\nheight = %d\nback = %c\n", vars->width, vars->height, vars->back);

    printf("----------map-----------\n");
    printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
    map = (char **)calloc(vars->height, sizeof(char *));
    for (int i = 0; i < vars->height; i++)
    {
        map[i] = (char *)calloc(vars->width + 1, sizeof(char));
        for (int j = 0; j < vars->width; j++)
            map[i][j] = vars->back;
        printf("%s\n", map[i]);
    }

    int read_size;
    read_size = fread(buf, sizeof(char), BUFFER_SIZE, fp);
    info = (char *)calloc((read_size + 1), sizeof(char));
    strncat(info, buf, read_size);
    int i = 1;
    while (1)
    {
        read_size = fread(buf, sizeof(char), BUFFER_SIZE, fp);
        if (read_size == 0)
            break ;
        info = (char *)realloc(info, strlen(info) + read_size + 1); // +1 == ('\0')
        strncat(info, buf, read_size);
        i++;
    }
    printf("===========fread, calloc, realloc, strncat ==============\n");
    printf("while num = %d\n", i);
    printf("info_size = %d\nfinal info = %s", (int)strlen(info), info);

    i = 0;
    char *info_p = info;
	t_modi	modi;
	fclose(fp);
	fp = fopen(filename, "r");
	char t_buf[1];
    fread(t_buf, sizeof(char), 1, fp);
    while (t_buf[0] != '\n')
       	fread(t_buf, sizeof(char), 1, fp);
    while(1)
    {
        printf("\n---------- %d map_modify_ing---------------\n", ++i);
		fscanf(fp, "%c %f %f %f %c", &modi.c, &modi.x, &modi.y, &modi.radius, &modi.back);
		printf("%c %.1f %.1f %.1f %c\n", modi.c, modi.x, modi.y, modi.radius, modi.back);
		int r_s = fread(t_buf, sizeof(char), 1, fp);
		if (r_s == 0)
			break ;
		map_set(vars, modi, map, info);
        map_print(map, vars);
    }    

    printf("\n-------- final map -------------\n");
    map_print(map, vars);

    printf("-----------free-------------\n");
    for (int i = 0; i < vars->height; i++)
        free(map[i]);
    free(map);
    free(info);
    free(vars);
    fclose(fp);
    printf("\n---leeaks---\n");
    system("leaks a.out");
}