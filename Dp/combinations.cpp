#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[105][105];
ll ncr(ll n, ll r)
{
    if(r==1)
    {
        dp[n][r] = n;
        return dp[n][r];
    }
    if(r==n)
    {
        dp[n][r] = 1;
        return dp[n][r];
    }
    if(dp[n][r]!=-1) return dp[n][r];
    else
    {
        dp[n][r] = ncr(n-1,r) + ncr(n-1,r-1);
        return dp[n][r];
    }
}
int main()
{
    ll f,s;
    while(scanf("%lld %lld",&f,&s) == 2)
    {
        memset(dp,-1,sizeof(dp));
      if(f==0 && s == 0)
        break;
      printf("%lld things taken %lld at a time is %lld exactly.\n",f,s,ncr(f,s));
    }
    return 0;
}

