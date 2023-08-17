#include <iostream>

int	tree[26][2];

void preorder(int n)
{
	if (n < 0)
		return ;
	std::cout << (char)(n + 'A');
	preorder(tree[n][0]);
	preorder(tree[n][1]);
}

void inorder(int n)
{
	if (n < 0)
		return ;
	inorder(tree[n][0]);
	std::cout << (char)(n + 'A');
	inorder(tree[n][1]);
}

void postorder(int n)
{
	if (n < 0)
		return ;
	postorder(tree[n][0]);
	postorder(tree[n][1]);
	std::cout << (char)(n + 'A');
	return;
}

void set_input(int n)
{
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		std::cin >> a >> b >> c;
		int	A, B, C;
		A = a - 'A';
		B = b - 'A';
		C = c - 'A';
		tree[A][0] = B;
		tree[A][1] = C;
	}
}

int main()
{
	int n;
	std::cin >> n;
	set_input(n);
	preorder(0);
	std::cout << std::endl;
	inorder(0);
	std::cout << std::endl;
	postorder(0);
	std::cout << std::endl;
}
