#include <iostream>
#include <stack>

using namespace std;

void	recur(stack<int> a, stack<int> b, stack<int> c, int cnt, int *ret)
{
	if (!a.size() && !b.size())
	{
		if (cnt < *ret)
			*ret = cnt;
		return ;
	}
	if (a.size() != 0 && ((a.top() < b.top()) || (a.top() < c.top())))
	{
		if (a.top() < b.top())
		{
			b.push(a.top());
			a.pop();
		}
		else if (a.top() < c.top())
		{
			c.push(a.top());
			a.pop();
		}
	}
}

int main()
{
	int n;
	stack<int> a, b, c;
	cin >> n;
	for (int i = n; i >= 1; i--)
		a.push(i);
	int ret = 2100000000;
	recur(a, b, c, 0, &ret);
}