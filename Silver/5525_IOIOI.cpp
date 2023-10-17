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


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


struct zz
{
	int x,y;
};

int n,m,ret=0;

void check(int i, string& s)
{
	int ci=n+1, co=n, cnt=0;
    int cur = 'O';
	while(i<s.size()&&cnt<2*n+1)
	{
        if (s[i] == cur)
            return;
        cur = s[i];
		if(s[i]=='I')
			ci--;
		else
			co--;
		if(ci<0||co<0)
			return ;
		i++;
		cnt++;
	}
	if(!ci&&!co)
		ret++;
}

int main()
{
	cin>>n>>m;
	string s, dest = "IOI", sc = "OI";
    for (int i = 2; i <= n ; i++)
    {
        dest += sc;
    }
	cin>>s;
    size_t  found = s.find(dest);
    if (found == string::npos)
    {
        cout<<"0";
        return (0);
    }
    // cout << s << "\n";
	while (found < s.size() || found != string::npos)
    {
        ret++;
        s.erase(0, found + 2);
        // cout << s << "\n";
        found = s.find(dest);
    }
	cout<<ret;
}
