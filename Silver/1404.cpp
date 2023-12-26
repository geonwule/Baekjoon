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
#include <cstdlib>
#include <stdexcept>
#include <sstream>

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

double people[8][8];

void output()
{
	for (int i = 0; i < 8; ++i)
    {
        double winningProbability = 1.0; // 초기 우승 확률은 1.0으로 설정
        //cout << "Player " << i << ": ";
        
        for (int j = 0; j < 8; ++j)
        {
            if (i != j)
            {
                winningProbability *= people[i][j] / 100.0;
                //cout << people[i][j] << "% "; // 각 상대방과의 우승 확률 출력
            }
        }
        //  winningProbability *= 100.0; // 최종 우승 확률 계산
        //cout << "=> Total Winning Probability: " << fixed << setprecision(2) << 
        // cout<<fixed<< winningProbability << " ";
        cout << winningProbability << ' ';
       }
}

void input()
{
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<8;j++)
		{
			double win;
			cin>>win;
			people[i][j]=win;
			people[j][i]=100-win;
		}
	}
}

int main() {
	try
	{
		input();
		output();
	}
	catch(exception &e){
		cout<<e.what()<<'\n';
	}
}
