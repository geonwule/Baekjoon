#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


int classNum;
std::vector<std::pair<int, int> > vClass;
std::priority_queue<int, std::vector<int>, std::greater<int> > less_pq_Class;

void output()
{
	less_pq_Class.push(vClass[0].second);
	for (int i = 1; i < classNum; ++i)
	{
		int oneTime_start = vClass[i].first;
		int oneTime_end = vClass[i].second;
		less_pq_Class.push(oneTime_end);
		if (less_pq_Class.top() <= oneTime_start)
			less_pq_Class.pop();
		else
			continue;
	}
	std::cout << less_pq_Class.size();
}

void input()
{
	std::cin >> classNum;
	for (int i = 0; i < classNum; i++)
	{
		int oneTime_start, oneTime_end;
		std::cin >> oneTime_start >> oneTime_end;
		vClass.push_back(std::make_pair(oneTime_start, oneTime_end));
	}
	sort(vClass.begin(), vClass.end());
}

int main()
{
	input();
	output();
}