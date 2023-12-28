#include <iostream>

using namespace std;

#define Max 100

int arr[Max], N;
size_t numRes = 0;

// 0 <= arr[i] <= 20

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

#include <queue>

struct Number
{
    int value;
};

queue<Number> qOrigin;

void searchQueue(queue<Number> q, int idx) // copy qOrigin
{
    if (idx == N - 1) // end
    {
        while (!q.empty())
        {
            Number t = q.front();
            q.pop();
            if (t.value == arr[N - 1])
                numRes++;
        }
        return ;
    }

    while (!q.empty())
    {
        Number t = q.front();
        q.pop();
        qOrigin.pop();
        int sign[2] = {1, -1};
        for (int i = 0; i < 2; i++)
        {
            int nvalue = t.value + (arr[idx] * sign[i]);
            if (nvalue >= 0 && nvalue <= 20)
                qOrigin.push({nvalue});
        }
    }
    
}

void output()
{

    qOrigin.push({arr[0]});
    for (int i = 1; i < N; i++)
        searchQueue(qOrigin, i);
    cout << numRes;
}

int main()
{
    input();
    output();
}