#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll mat[100005][40];
int main()
{
    ll n,q,aa,b;
    scanf("%lld",&n);
    for(ll i = 1; i <= n ; i++)
    {
        scanf("%lld",&a[i]);
        mat[i][0] = i;
    }
    for(ll j = 1; (1<<j)<=n; j++)
    {
        for(ll i = 1; (i + (1<<j) - 1) <=n ; i++)
        {
            ll x = mat[i][j-1];
            ll y = mat[i + (1<<(j-1))][j-1];
            if(a[x]>a[y])
                mat[i][j] = y;
            else
                mat[i][j] = x;
        }
    }
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&aa,&b);
        aa++,b++;
        ll k = log2(b - aa + 1);
        ll x = mat[aa][k];
        ll y = mat[b - (1<<k) + 1][k];
        printf("%lld\n",min(a[x],a[y]));
    }
}
