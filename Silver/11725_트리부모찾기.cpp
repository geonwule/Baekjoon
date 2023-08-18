#include <iostream>
#include <vector>

#define MAX 100001

std::vector<int>	tree[MAX];
int		parent[MAX];
bool	visited[MAX];
int	n;

void	set_input(void)
{
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}

void	dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++)
	{
		int	next = tree[node][i];
		if (!visited[next])
		{
			parent[next] = node;
			dfs(next);
		}
	}
}

int main()
{
	std::cin >> n;
	set_input();
	dfs(1);
	for (int i = 2; i <= n; i++)
	{
		std::cout << parent[i] << "\n";
	}
	return (0);
}