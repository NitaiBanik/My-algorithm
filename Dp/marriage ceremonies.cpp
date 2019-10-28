#include<bits/stdc++.h>
using namespace std;

int val[18][18];

int dp[18][(1<<16) + 3];
int num;

bool chk(int val,int pos)
{
    return (bool)(val & (1<<pos));
}

int Set(int val, int pos)
{
    return val = (val | (1<<pos));
}
int fun(int mask, int pos)
{
    if(pos == num)
        return 0;

    if(mask == (1<<num) - 1)
        return 0;

    if(dp[pos][mask]!=-1)
        return dp[pos][mask];

        int ret = 0;
    for(int i=0; i<num; i++)
    {
         if(chk(mask,i) == false)
            ret =max(ret, val[pos][i] + fun(Set(mask,i),pos + 1));
    }

 return dp[pos][mask] = ret;
}
int main()
{

    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);

        memset(dp,-1,sizeof(dp));

        for(int i=0; i<num; i++)
            for(int j=0; j<num; j++)
                scanf("%d",&val[i][j]);

        int ans = fun(0,0);

        printf("Case %d: %d\n",++w,ans);

    }
}
