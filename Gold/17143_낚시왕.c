#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posX = 0, ret = 0;
int y, x, n;

typedef struct s_shark
{
	int live;
	int x, y;
	int sp;
	int dir;
	int size;
} shark;

void move(int speed, int *pos_x, int *pos_y, int x_move, int y_move, int *dir)
{
	for (int k = 0; k < speed; k++)
	{
		if (*pos_x + x_move < 1 || *pos_x + x_move > x)
		{
			x_move *= -1;
			if (*dir == 3)
				*dir = 4;
			else
				*dir = 3;
		}
		if (*pos_y + y_move < 1 || *pos_y + y_move > y)
		{
			y_move *= -1;
			if (*dir == 1)
				*dir = 2;
			else
				*dir = 1;
		}
		*pos_x += x_move;
		*pos_y += y_move;
	}
}

// int	compareShark(const void *x, const void *y)
// {
// 	int a = (const shark *)(x)->size;
// }

int compareShark(const void *x, const void *y)
{
	shark *shark1 = (shark *)x;
	shark *shark2 = (shark *)y;
	
	int size1 = shark1->size;
	int size2 = shark2->size;
	
	return (size1 > size2) - (size1 < size2);
}

typedef	struct s_map
{
	int	num;
	int	idx[10000];
}	t_map;

int main()
{
	// init
	scanf("%d %d %d", &y, &x, &n);
	shark *arr = malloc(sizeof(shark) * n);
	t_map **map = malloc(sizeof(t_map *) * (y + 1));
	for (int i = 1; i <= y; i++)
	{
		map[i] = malloc(sizeof(t_map) * (x + 1));
		for (int j = 1; j <= y; j++)
		{
			map[i][j].num = 0;
			memset(map[i][j].idx, 0, sizeof(int) * (x + 1));
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d",
			  &arr[i].y, &arr[i].x, &arr[i].sp, &arr[i].dir, &arr[i].size);
		arr[i].live = 1;
		map[arr[i].y][arr[i].x].num += 1;
		int idx = map[arr[i].y][arr[i].x].num - 1;
		map[arr[i].y][arr[i].x].idx[idx] = i;
	}

	for (int i = 0; i < x && n; i++)
	{
		// person action
		posX++; // right one move
#ifdef DEBUG
		printf("posX = %d\n", posX);
#endif
		int catch_y = 101;
		int catch_shark;
		for (int j = 0; j < n; j++)
		{
			if (arr[j].live && arr[j].x == posX && arr[j].y < catch_y)
			{
				catch_y = arr[j].y;
				catch_shark = j;
			}
		}
		if (catch_y < 101) // catch!
		{
			ret += arr[catch_shark].size;
			arr[catch_shark].live = 0;
#ifdef DEBUG
			printf("catch shark = %d, size = %d\n", catch_shark, arr[catch_shark].size);
#endif
		}

		// shark move
		for (int j = 0; j < n; j++)
		{
			int x_move, y_move;
			if (!(arr[j].live)) // dead shark
				continue;
			if (arr[j].dir == 1) // north
			{
				x_move = 0;
				y_move = -1;
			}
			else if (arr[j].dir == 2) // south
			{
				x_move = 0;
				y_move = 1;
			}
			else if (arr[j].dir == 3) // east
			{
				x_move = 1;
				y_move = 0;
			}
			else // west
			{
				x_move = -1;
				y_move = 0;
			}

			//before location
			int idx = map[arr[j].y][arr[j].x].num - 1;
			map[arr[j].y][arr[j].x].idx[idx] = 0;
			map[arr[j].y][arr[j].x].num -= 1;

			move(arr[j].sp, &arr[j].x, &arr[j].y, x_move, y_move, &arr[j].dir);

			//after location
			map[arr[j].y][arr[j].x].num += 1;
			idx = map[arr[j].y][arr[j].x].num - 1;
			map[arr[j].y][arr[j].x].idx[idx] = j;
		}
#ifdef DEBUG_MAP
		//if (posX == 2)
		// {
			for (int k = 0; k < n; k++)
			{
				if (arr[k].live == 0)
					printf("%d shark dead\n", k+1);
				else
					printf("%d shark (%d, %d)\n", k+1, arr[k].y, arr[k].x);
			}
		// }
#endif

		// shark eating
		for (int j = 1; j <= y; j++)
		{
			for (int k = 1; k <= x; k++)
			{
				if (map[j][k].num > 1)
				{
					int t_idx = map[j][k].idx[0];
					int big_size = arr[t_idx].size;
					int big_idx = t_idx;
					for (int q = 1; q < map[j][k].num; q++)
					{
						t_idx = map[j][k].idx[q];
						if (big_size < arr[t_idx].size)
						{
							arr[big_idx].live = 0;
							
							big_size = arr[t_idx].size;
							big_idx = t_idx;
						}
					}
				}
			}
		}
// 		for (int j = 0; j < n; j++)
// 		{
// 			if (arr[j].live == 0) // dead shark
// 				continue;
// 			for (int k = j + 1; k < n; k++)
// 			{
// 				if (arr[k].live == 0) // dead shark
// 					continue;
// 				if (arr[j].x == arr[k].x && arr[j].y == arr[k].y)
// 				{
// 					if (arr[j].size > arr[k].size) // target win
// 					{
// 						arr[k].live = 0;
// #ifdef DEBUG
// 						printf("shark eating %d -> %d\n", j, k);
// #endif
// 					}
// 					else if (arr[j].size < arr[k].size) // target dead, break
// 					{
// 						arr[j].live = 0;
// #ifdef DEBUG
// 						printf("shark eating %d -> %d\n", k, j);
// #endif
// 						break;
// 					}
// 				}
// 			}
// 		}
	}
	printf("%d\n", ret);

	free(arr);
	for (int i = 0; i <= y; i++)
		free(map[i]);
	free(map);
	return 0;
}