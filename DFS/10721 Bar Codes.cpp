#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll dp[50][50];
ll n,tot,sz;
ll fun(ll pos, ll cnt)
{
    if(pos == (n))
    {
        if(cnt == 0)
            return 1;
        return 0;
    }
    if(pos>n)
        return 0;
    if(dp[pos][cnt]!=-1)
        return dp[pos][cnt];
    ll ans = 0;
    for(int j = 1; j<=sz; j++)
    {
        ans+=fun(pos + j, cnt - 1);
    }
    return dp[pos][cnt] = ans;
}

int main()
{
    while(cin>>n>>tot>>sz)
    {
        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,tot);
        cout<<ans<<endl;
    }
}
