#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000
struct ed
{
    ll frm,to,cost;
    ed(ll a, ll b, ll c)
    {
        frm = a,to = b,cost = c;
    }
};



ll arr[5050];
ll dist[5050];

ll cub(ll xx)
{
    return xx * xx * xx;
}
int main()
{
    //freopen("out.txt","w",stdout);
    ll t,w = 1;
    scanf("%lld",&t);
    while(t--)
    {
        for(int i=1; i<=5003; i++)
        {
            dist[i] = inf;
            arr[i] = 0 ;
        }
        ll n;
        vector<ed>vec;
        scanf("%lld",&n);

        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]);

        ll m;

        scanf("%lld",&m);

        for(int i=1; i<=m; i++)
        {
            ll x,y, z;
            scanf("%lld %lld",&x,&y);
            vec.push_back(ed(x,y,cub(arr[y]- arr[x])));
        }
        dist[1] = 0;

        for(int i=1; i<=n; i++)
        {
            bool negative = false;
            for(int j=0; j<vec.size(); j++)
            {
                ll u = vec[j].frm;
                ll v = vec[j].to;
                ll cost = vec[j].cost;
                if(dist[v]>dist[u] + cost && dist[u]!=inf)
                {
                    dist[v] = dist[u] + cost;
                    negative = true;
                }
            }
            if(!negative)
                break;
        }
        ll Q,V;

        printf("Case %lld:\n",w++);

        scanf("%lld",&Q);
        while(Q--)
        {
            scanf("%lld",&V);

            if(dist[V]<3 || dist[V] == inf )
                printf("?\n");
            else
                printf("%lld\n",dist[V]);

        }
        //vec.clear();
    }
    return 0;
}
