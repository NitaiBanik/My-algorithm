#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll par[100005];
ll cnt[100005];


ll findd(ll val)
{
    if(par[val] == val)
        return val;
    return par[val] = findd(par[val]);
}

void unionn(ll x, ll y)
{
    par[findd(y)] = findd(x);
}

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld %lld",&n, &m);
        for(ll i = 1; i <= n ; i++)
            par[i] = i;

        ll x, y;

        while(m--)
        {
            scanf("%lld %lld",&x, &y);
            unionn(y,x);
        }

        memset(cnt,0,sizeof(cnt));

        for(ll i = 1 ; i <= n ; i++)
            par[i] = findd(i);

        for(ll i = 1; i<= n; i++)
            cnt[par[i]]++;
      ll ans = 1,cn = 0;
      for(ll i = 1; i<=n; i++)
      {
          if(cnt[i] != 0)
          {
              cn++;
              ans = ((cnt[i] % mod) * ans) % mod;
          }
      }
      printf("%lld %lld\n",cn,ans);
    }
    return 0;
}
