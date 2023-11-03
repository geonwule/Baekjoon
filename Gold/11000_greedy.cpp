#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <queue>
#include <deque>
#include <map>

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Room
{
	int start, end;
	bool operator<(const Room &other) const
	{
		return (this->start < other.start);
	}

	bool operator>(const Room &other) const
	{
		return (this->start > other.start);
	}
};
int res=0, num;
// Room room[200000];
priority_queue<Room, vector<Room>, std::greater<Room> > pq;

void output()
{
	Room cur = pq.top();
	pq.pop();
	res++;
	while (!pq.empty())
	{
		Room tmp = pq.top();
		pq.pop();
		if (cur.end < tmp.start)
		{
			cur = tmp;
			res--;
		}
		else
		{
			res++;
		}
	}
}

void input()
{
	cin>>num;
	for(int i=0; i<num; i++)
	{
        Room input;
		cin>>input.start>>input.end;
        pq.push(input);
	}

	// check input
    // for(int i=0; i<num; i++)
	// {
    //     Room output = pq.top();
    //     pq.pop();
	// 	cout<< output.start << ' ' << output.end << '\n';
	// }
    // exit(0);
}

int main() {
	input();
	output();
	cout<<res-1;
}
