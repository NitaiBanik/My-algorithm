#include<bits/stdc++.h>
using namespace std;
int node;
int fun(int mask)
{
    if(mask == (1<<n)- 1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    for(int i=0;i<node;i++)
    {
        if(check(mask,i) == 0)
        {
            int price = mat[i][i];
        }
    }
}

int main()
{
    scanf("%d",&node);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&mat[i][j]);
    int ans = fun(0);
    printf("%d\n",ans);
}
