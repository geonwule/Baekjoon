/*거짓말쟁이
1. 파티의 최대는 50으로 
2. party[51][51]의 각 [0]에 사람수, [1]부터 몇번의 사람인지 담기 
3. true[51]의 [0]에 사람수, [1]부터 몇번인지 진실아는사람 담기
4. for반복으로 true인사람 처음부터 끝까지 돌면서
4-2. true와 같은 파티 간사람을 재귀로 돌아주기
5. lie_party[51]의 반복을 돌면서 가능한 파티 체크*/
#include <stdio.h>

int party[51][52], true[51], n, m;

void    input_init(void)
{
    scanf("%d %d", &n, &m);
    scanf("%d", &true[0]);
    for (int i = 1; i <= true[0]; i++)
        scanf("%d", &true[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &party[i][0]);
        for (int j = 1; j <= party[i][0]; j++)
            scanf("%d", &party[i][j]);
    }
}

void    dfs(int true_people)
{
    for (int i = 1; i <= m; i++)
    {
        if (party[i][51] == -1)  // 이미 진실 안되는 집단은 탐색 필요 없으므로 패스
            continue ;
        for (int j = 1; j <= party[i][0]; j++)
        {
            if (true_people == party[i][j]) // 진실 아는 파티 확인
            {
                party[i][51] = -1; // 이 파티는 안된다는 표식
                for (int k = 1; k <= party[i][0]; k++)
                {
                    if (party[i][k] == true_people)
                        continue ;
                    dfs(party[i][k]);   // 진실을 알게된 사람에 대해 다시 dfs
                }
            }
        }
    }
}

int main()
{
    input_init();
    for (int i = 1; i <= true[0]; i++) // 진실 아는 집단 반복, dfs로 거짓말 못하는 party 체크
        dfs(true[i]);   // 진실 아는 사람을 하나씩 넣어서 깊이우선 탐색
    int lie_party = 0;
    for (int i = 1; i <= m; i++)
    {
        if (party[i][51] != -1) // 거짓말 가능한 집단 체크
            lie_party++;
    }
    printf("%d\n", lie_party);
}

/* input_test/////

    printf("===true===\n");
    for (int i = 0; i <= true[0]; i++)
        printf("%d ", true[i]);
    printf("\n");
    printf("===party===\n");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= party[i][0]; j++)
            printf("%d ", party[i][j]);
        printf("\n");
    }*/