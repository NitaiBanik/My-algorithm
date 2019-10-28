#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[52][52][52];
ll n,tot,sz;
ll fun(ll pos, ll cnt, ll x)
{
    if(pos == (n))
    {
        if(cnt == 0)
            return 1;
        return 0;
    }
    if(pos>n)
        return 0;
    if(dp[pos][cnt][x]!=-1)
        return dp[pos][cnt][x];
    ll ans = 0;
    for(int j = 1; j<=sz; j++)
    {
        ans+=fun(pos + j, cnt - 1,x);
    }
    return dp[pos][cnt][x] = ans;
}


int main()
{
    int t,w= 0;
    scanf("%d", &t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%lld %lld %lld", &n, &tot, &sz);
        ll ans = fun(0,tot,sz);
        printf("Case %d: %lld\n", ++w, ans);
    }
}
