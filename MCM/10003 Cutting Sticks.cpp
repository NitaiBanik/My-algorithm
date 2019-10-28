#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[52][52];
ll arr[52];

ll fun(ll b, ll e)
{
   // cout<<"begin"<<arr[b]<<" end "<<arr[e]<<endl;
    if(b+1>=e) return 0;

    if(dp[b][e]!=-1) return dp[b][e];

    ll ret1 = 9999999999,left = 0,right = 0,current = 0;

    for(ll i = b+1; i<e; i++)
    {
        left = fun(b,i);
        right = fun(i,e);
        current = arr[e] - arr[b];
        ret1 = min(ret1,left + right + current);
    }

    return dp[b][e] = ret1;
}

int main()
{
    ll sz,n;
    while(scanf("%lld",&sz) == 1 && sz!=0)
    {
        scanf("%lld",&n);
        arr[0] = 0;

        for(ll i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        n++;

        arr[n] = sz;
        memset(dp,-1,sizeof(dp));

        ll ans = fun(0,n);
        printf("The minimum cutting is %lld.\n",ans);
    }
    return 0;
}
