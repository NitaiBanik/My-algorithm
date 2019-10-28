///11450 Wedding Shopping
#include<bits/stdc++.h>
using namespace std;
int dp[22][202];
int vec[22][22];
int xx[22];
int n,budget;

int fun(int pos,int sum)
{
    if(sum>budget) return -1;
    if(pos == n)
    {
        if(sum <= budget) return sum;
        else
            return -1;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    int ret = -999999999;
    for(int i=0; i<xx[pos]; i++)
    {
        ret = max(ret,fun(pos + 1,sum+vec[pos][i]));
    }
    return dp[pos][sum] = ret;
}

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&budget,&n);
        for(int i=0; i<n; i++)
        {
            int num,val;
            scanf("%d",&xx[i]);
            for(int j=0; j<xx[i]; j++)
            {
                scanf("%d",&vec[i][j]);

            }

        }
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0);
        if(ans == -1) printf("no solution\n");
        else
            printf("%d\n",ans);
    }
}
