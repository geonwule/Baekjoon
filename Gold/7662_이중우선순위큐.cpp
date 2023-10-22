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


struct zz
{
	int a, b;
    bool empty;
};

std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
map<int, int> cnt;

std::vector<zz> v;

void clearoo()
{
	while(!minHeap.empty()&&!cnt[minHeap.top()])
    	minHeap.pop();
    while(!maxHeap.empty()&&!cnt[maxHeap.top()])
    	maxHeap.pop();
}

void exe()
{
	int size=0;
    cnt.clear();
    while(!maxHeap.empty())
    	maxHeap.pop();
    while(!minHeap.empty())
    	minHeap.pop();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	char s;
    	int va;
    	cin>>s>>va;
    	if(s=='I')
    	{
    		maxHeap.push(va);
   			minHeap.push(va);
    		cnt[va]++;
    		//size++;
    	}
    	else//(s=="D")
    	{
    		if(va==1&&!maxHeap.empty())//max
    		{
    			cnt[maxHeap.top()]--;
    			maxHeap.pop();
    		}
    		if(va==-1&&!minHeap.empty())//min
    		{
    			cnt[minHeap.top()]--;
    			minHeap.pop();
    		}
    		clearoo();
    	}
    }
    clearoo();
    zz tmp;
    if(minHeap.empty()||maxHeap.empty())
    {
    	// cout<<"Empty\n";
        tmp.a = 0;
        tmp.b = 0;
        tmp.empty = true;
        v.push_back(tmp);
    	return ;
    }
    tmp.a = maxHeap.top();
    tmp.b = minHeap.top();
    tmp.empty = false;
    v.push_back(tmp);
    // cout<<maxHeap.top()<<" "<<minHeap.top()<<"\n";
}

int main() {
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    	exe();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].empty)
            std::cout << "EMPTY\n";
        else
            std::cout << v[i].a << " " << v[i].b << "\n";
    }
    return 0;
}
