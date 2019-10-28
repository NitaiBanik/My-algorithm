#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll budget;
ll dp[102][5005],n;

struct node
{
    ll wt,pro;
} arr[102];

ll  ck ;

ll fun(ll pos, ll sum)
{
    if(sum>budget && budget<=1800) return -99999999999;
    if(sum>budget+200) return -99999999999;
    if(pos == n)
    {
        if(sum>budget && sum<=2000)
            return -999999999999;
        else
            return 0;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];

    ll ret1 = 0,ret2 = 0;

    ret1 = arr[pos].pro + fun(pos + 1,sum + arr[pos].wt);

    ret2  = fun(pos + 1,sum);
    return dp[pos][sum]= max(ret1,ret2);
}

int main()
{
    while(scanf("%lld %lld",&budget,&n) == 2)
    {
        ck =0;
        for(int i=0; i<n; i++)
            scanf("%lld %lld",&arr[i].wt,&arr[i].pro);

        memset(dp,-1,sizeof(dp));

        ll ans = fun(0,0);
        printf("%lld\n",ans);
    }
}
