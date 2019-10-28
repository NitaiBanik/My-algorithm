#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll base, k,sz ;
string str;
ll dp[65538][25];

ll check(char ch)
{
    if(ch>='A' && ch <= 'Z')
    {
        return (ch - 'A') + 10;
    }
    else
        return (ch - '0');
}
ll fun(ll mask, ll mod)
{
    int cnt = __builtin_popcount(mask);

    if(cnt == sz)
    {
        if(mod == 0)
            return 1LL;
        else
            return 0LL;
    }

    ll &ret = dp[mask][mod];

    if(ret != -1)
        return ret;

    ret = 0;
    for(int i = 0; i < sz; i++)
    {
        if((mask &(1LL<<i)) == 0)
        {
            ll ch = check(str[i]);

            ret+=fun(mask | (1<<i),(mod * base + ch) % k);
        }
    }

    return ret;
}
int main()
{
    ll t, w = 0;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld", &base, &k);

        cin>>str;
        sz = str.size();
        memset(dp, -1, sizeof(dp));

        ll ans = fun(0,0);
        printf("Case %lld: %lld\n",++w,ans);
    }
    return 0;
}
