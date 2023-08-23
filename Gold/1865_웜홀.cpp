#include <iostream>
#include <vector>
#include <string>

// typedef struct s_worm
// {
// 	int	depart;
// 	int	arrive;
// 	int	time;
// }	t_worm;

// int		arr[501][501];
// t_worm	worm[201];

struct edge
{
	int s, e, t;
};


using namespace std;
#define MAX 30000000

bool	time_trip(int n, vector<edge> edges)
{
	vector<int>	dist(n + 1, MAX);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t)
				dist[e] = dist[s] + t;
		}
	}
	for (int j = 0; j < edges.size(); j++)
	{
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t)
			return true;
	}
	return false;
}

int main()
{
	// cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	int s, e, t;
	for (int i = 0; i < tc; i++)
	{
		int n, m, w;
		cin >> n >> m >> w;

		vector<edge>	edges;
		for (int j = 0; j < m; j++)
		{
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({e, s, t});
			// if (!arr[s][e] || (arr[s][e] > 0 && arr[s][e] > t))
			// {
			// 	arr[s][e] = t;
			// 	arr[e][s] = t;
			// }
		}
		for (int j = 0; j < w; j++)
		{
			cin >> s >> e >> t;
			edges.push_back({s, e, -t});
			// worm[j].depart = s;
			// worm[j].arrive = e;
			// worm[j].time = t;
		}
		if (time_trip(n, edges))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}