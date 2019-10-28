#include<bits/stdc++.h>
using  namespace std;

#define ll long long
ll dp[75][75],T,N,P;

ll fun(ll pos,ll sum)
{
    if(sum<0) return 0;
    if(pos == N)
    {
        if(sum == 0) return 1;
        else return 0;
    }
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll ret = 0;
    for(int i=P;i<=T-(N - pos - 1) * P;i++)
    {
        ret+=fun(pos + 1,sum - i);
    }
    return dp[pos][sum] = ret;
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
     memset(dp,-1,sizeof(dp));
     scanf("%lld %lld %lld",&N,&T,&P);
     ll ans = fun(0,T);
     printf("%lld\n",ans);
  }
  return 0;
}
