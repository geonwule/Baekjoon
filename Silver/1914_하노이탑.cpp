#include <iostream>
#include <stack>

using namespace std;

void recur(stack<int> a, stack<int> b, stack<int> c, int cnt, int *ret, stack<int> be_a, stack<int> be_b, stack<int> be_c)
{
	if (a.empty() && b.empty())
	{
		if (*ret < cnt)
			*ret = cnt;
		return ;
	}
	if (!a.empty())
	{
		if ((c.empty() || a.top() < c.top()) && ((!be_c.empty() && a.top() != be_c.top()) || be_c.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_c.push(t_a.top());
			t_a.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
		}
		if ((b.empty() || a.top() < b.top()) && ((!be_b.empty() && a.top() != be_b.top()) || be_b.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_b.push(t_a.top());
			t_a.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
		}
	}
	if (!b.empty())
	{
		if ((c.empty() || b.top() < c.top()) && ((!be_c.empty() && b.top() != be_c.top()) || be_c.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_c.push(t_b.top());
			t_b.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
		}
		if ((a.empty() || b.top() < a.top()) && ((!be_a.empty() && b.top() != be_a.top()) || be_a.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_a.push(t_b.top());
			t_b.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
		}
	}
	if (!c.empty())
	{
		if ((b.empty() || c.top() < b.top()) && ((!be_b.empty() && c.top() != be_b.top()) || be_b.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_b.push(t_c.top());
			t_c.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
		}
		if ((a.empty() || c.top() < a.top()) && ((!be_a.empty() && c.top() != be_a.top()) || be_a.empty()))
		{
			stack<int> t_a = a, t_b = b, t_c = c;
			t_a.push(t_c.top());
			t_c.pop();
			recur(t_a, t_b, t_c, ++cnt, ret, a, b, c);
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

	// cout << "a_top :" << a.top() << endl;
	// cout << "b_top :" << b.top() << endl;
	// cout << "c_top :" << c.top() << endl;

	// return (0);

	int ret = 2100000000;
	recur(a, b, c, 0, &ret, a, b, c);
	cout << ret << endl;
}

/* print stack

void	recur(stack<int> a, stack<int> b, stack<int> c, int cnt, int *ret)
{
	stack<int>	temp;

	while(!a.empty())
	{
		temp.push(a.top());
		a.pop();
		cout << temp.top() << " ";
	}
	cout << endl;
	while (!temp.empty())
	{
		a.push(temp.top());
		temp.pop();
		cout << a.top() << " ";
	}
	cout << endl;
}

*/