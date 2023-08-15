
/* i must study dp and algorithm container */

#include <iostream>
#include <algorithm>

using namespace std;
long long arr[2][100001];
long long dp[2][100001];

int main()
{
	int t;
	int n;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k < n + 1; k++)
			{
				cin >> arr[j][k];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int k = 2; k < n + 1; k++)
		{
			dp[0][k] = max(dp[1][k - 2], dp[1][k - 1]) + arr[0][k];
			dp[1][k] = max(dp[0][k - 2], dp[0][k - 1]) + arr[1][k];
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return (0);
}

// this is my write left

// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// int a[2][100001];
// int n;

// void init(void)
// {
// 	cin >> n;
// 	for (int j = 0; j < 2; j++)
// 	{
// 		for (int k = 0; k < n; k++)
// 		{
// 			cin >> a[j][k];
// 		}
// 	}
// }

// int dp[2][100001];

// int dp(void)
// {
// 	int ret = 0;

// 	dp[0][0] = a[0][0];
// 	dp[0][1] = a[1][1];
// 	dp[0][2] = a[2][0];

// 	for (int i = 3; i <= n; i++)
// 	{
// 		dp[0][i] = dp[0][i - 1] + dp[0][i - 2] + dp[0][i];
// 	}

// 	return (ret);
// }

// int main()
// {
// 	int t;
// 	cin >> t;
// 	for (int i = 0; i < t; i++)
// 	{
// 		int ret;
// 		init();
// 		ret = dp();
// 		cout << ret << endl;
// 	}
// }
