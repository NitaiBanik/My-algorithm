#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10004][102];
ll a[10004];
ll flag,n,k;
ll fun(ll pos,ll sum)
{
    if(flag == 1)
        return 1;
    if(pos == n)
    {
        if(sum == 0)
        {
            flag = 1;
            return 1;
        }
        else return 0;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll ret1 = 0;
    ll ret2 = 0;
    ll aa = (sum + a[pos]) % k;
    if(aa<0) aa+=k;
    ll b = (sum - a[pos]) % k;
    if(b<0) b+=k;
    ret1 = fun(pos + 1,aa);
    ret2 = fun(pos + 1,b);
    return dp[pos][sum] = ret1|ret2;
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
            flag = 0;
            memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0);
        if(flag == 1)
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
}
