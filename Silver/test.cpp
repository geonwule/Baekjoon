#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>


using namespace std;

char arr[51][51];
int ans[51];
int n,mx = 0;

void input()
{
    for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
}

int main() {

	scanf("%d", &n);
	
    input();
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || arr[i][j] != 'Y') continue;
			
			for (int z = 0; z < n; z++) {
				if (z == i || arr[j][z] != 'Y' ) continue;
				arr[i][z] = '2';
			}

		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (arr[i][j] != 'N') ans[i]++;
		mx = max(mx, ans[i]);
	}
	printf("%d\n", mx);
	return 0;
}

/*
6
NYYNNY
YNYNNN
NYNYYN
NNYNNN
NNNNYN
YNNNNN
*/