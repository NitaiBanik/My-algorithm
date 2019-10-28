#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll par[100005];
ll cost[100005];


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
        scanf("%lld",&n);

        for(ll i = 1; i <= n ; i++)
        {
            par[i] = i;
            scanf("%d",&cost[i]);
        }

        scanf("%lld",&m);
        ll x, y;

        while(m--)
        {
            int type;
            scanf("%d",&type);
            if(type == 1)
            {
                int v;
                scanf("%d",&v);
                int x = par[v];
                printf("%d\n",x);

            }
            else
            {
                scanf("%lld %lld",&x, &y);

                if(par[x] == par[y])
                    printf("Invalid query!\n");

                else
                {
                    if(cost[x]>cost[y])
                        par[y] = x;
                    else
                        par[x] =y;

                }
            }
        }

        memset(cost,0,sizeof(cost));
    }
    return 0;
}
