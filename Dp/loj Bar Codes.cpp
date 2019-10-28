#include<bits/stdc++.h>
using namespace std;

long long dp[52][52][52],M,K;

long long fun(long long pos,long long bar)
{
    if(pos == 0 && bar == 0) return 1;
    if(pos == 0 && bar>0) return 0;
    if(pos<0 || bar<0) return 0;

    if(dp[pos][bar][M]!=-1)
        return dp[pos][bar][M];

    long long ret1 = 0;

    for(long long i=1; i<=M; i++)
        ret1+=fun(pos - i,bar - 1);

    return dp[pos][bar][M] = ret1;

}

int main()
{

    long long t,w = 0,n;
    scanf("%lld",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&K,&M);
        long long ans = fun(n,K);
        printf("Case %lld: %lld\n",++w,ans);
    }
    return 0;
}
