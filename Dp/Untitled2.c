#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[205][22][22];
ll arr[205];

ll n,m,d;

ll fun(ll pos,ll cn,ll sum)
{
    if(cn == m)
    {
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    if(pos == n)
        return 0;

    ll &ret = dp[pos][cn][sum];

    if(ret != -1)
        return ret;

    ret = 0;
    ll mod = (sum + arr[pos]) % d;
    if(mod < 0)
        mod+=d;
    ret+=fun(pos + 1, cn + 1,mod);
    ret+=fun(pos + 1, cn,sum);

    return ret;
}


int main()
{
    ll t,q,w = 0;
    scanf("%lld", &t);
    while(t--)
    {

        scanf("%lld %lld", &n, &q);

        for(ll i = 0; i<n; i++)
            scanf("%lld", &arr[i]);

        printf("Case %lld:\n", ++w);

        while(q--)
        {
            memset(dp, -1, sizeof(dp));
            scanf("%lld %lld", &d, &m);

            ll ans = fun(0,0,0);
            printf("%lld\n", ans);
        }

    }
}
