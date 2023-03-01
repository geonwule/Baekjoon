#include <stdio.h>

int min_heap[100001] = {
	0,
}; // idx : 1 ~ 100000
int idx = 1;

void insert(int val)
{
	int temp_idx = idx;
	int temp;
	min_heap[idx++] = val;
	while (temp_idx > 1)
	{
		if (min_heap[temp_idx / 2] > min_heap[temp_idx])
		{
			temp = min_heap[temp_idx / 2];
			min_heap[temp_idx / 2] = min_heap[temp_idx];
			min_heap[temp_idx] = temp;
			temp_idx /= 2;
		}
		else
		{
			break;
		}
	}
}

void heapfify(int i)
{
	// i : idx
	int left = 2 * i;
	int right = 2 * i + 1;
	int smallest = i;
	int temp;

	// find smallest
	if (left < idx && min_heap[left] < min_heap[smallest])
		smallest = left;
	if (right < idx && min_heap[right] < min_heap[smallest])
		smallest = right;

	if (smallest != i)
	{
		// swap
		temp = min_heap[i];
		min_heap[i] = min_heap[smallest];
		min_heap[smallest] = temp;
		heapfify(smallest);
	}
}

int main(void)
{
	int N;
	int temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp == 0)
		{
			if (idx == 1)
				printf("0\n");
			else
			{
				printf("%d\n", min_heap[1]);
				min_heap[1] = min_heap[idx - 1]; // remove
				heapfify(1);
				idx -= 1;
			}
		}
		else
			insert(temp);
	}

	return 0;
}