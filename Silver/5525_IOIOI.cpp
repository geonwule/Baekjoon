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

vector<int>    setFailure(string   &pattern)
{
    size_t  len = pattern.size(), j = 0;

    vector<int> failure(len, 0);
    failure[0] = 0; // 생략 가능
    for (size_t i = 1; i < len; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
            j = failure[j - 1];
        if (pattern[i] == pattern[j])
        {
            failure[i] = j + 1;
            j++;
        }
        else // 생략 가능
            failure[i] = 0;
    }
    return (failure);
}

void    KMP(string& text, string&   pattern)
{
    size_t textLen = text.size(), pattLen = pattern.size();
    size_t j = 0;
    vector<int> failure = setFailure(pattern);

    for (int i = 0; i < textLen; i++)
    {
        while (j > 0 && text[i] != pattern[j])
            j = failure[j - 1];
        if (text[i] == pattern[j])
        {
            if (j + 1 == pattLen)
            {
                ret++;
                j = failure[j];
            }
            else
                j++;
        }
    }
}

int main()
{
	string text, pattern = "IOI", sc = "OI";
	cin>>n>>m>>text;
    for (int i = 2; i <= n ; i++)
        pattern += sc;
    KMP(text, pattern);
	cout<<ret;
}
