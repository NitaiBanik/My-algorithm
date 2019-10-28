#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[105][105];

ll cnt[105];
ll w,k;
ll num;


struct st
{
    ll x,y;
} arr[105];

ll fun(ll pos, ll koita)
{
    if(koita == k) return 0;
    if(pos >= num) return 0;

    if(dp[pos][koita]!=-1) return dp[pos][koita];

    ll ret1 = 0,ret2 = 0;

    ret1 = fun(pos+1,koita);
    ret2 = cnt[pos] + fun(pos + cnt[pos],koita + 1);

    return dp[pos][koita] = max(ret1,ret2);
}

bool comp(st f, st s)
{
    if(f.y == s.y) return f.x<s.x;
    else return f.y<s.y;
}
int main()
{
    ll t;
    ll p = 0;
    scanf("%lld",&t);

    while(t--)
    {
        memset(dp,-1,sizeof(dp));

        scanf("%lld %lld %lld",&num,&w,&k);

        for(ll i=0; i<num; i++)
            scanf("%lld %lld",&arr[i].x,&arr[i].y);

        sort(arr,arr+num,comp);

        for(ll i=0; i<num; i++)
        {
            ll cn = 1;
            for(ll j = i + 1; j<num; j++)
            {
                if(abs(arr[i].y - arr[j].y)<=w) cn++;
                else break;
            }
            cnt[i] = cn;
        }
        ll ans = fun(0,0);
        printf("Case %lld: %lld\n",++p,ans);

    }
    return 0;
}
