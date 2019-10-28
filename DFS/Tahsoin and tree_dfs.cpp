#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
ll arr[sz];

vector<ll>graph[sz];
ll vis[sz];
ll yes[sz];
ll value[sz];

void dfs(ll src, ll cst)
{
    vis[src] = cst + value[src];
    yes[src] = 1;
    for(int i = 0; i < graph[src].size(); i++)
    {
        ll x = graph[src][i];
        if(yes[x] == 0)
        {
            dfs(x,vis[src]);
        }
    }

}

int main()
{
    ll t,m,n,u,v,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(value,0,sizeof(value));
        memset(vis,0,sizeof(vis));
        memset(yes,0,sizeof(yes));

        scanf("%lld %lld",&n,&m);

        for(int i = 1; i<=n; i++)
            scanf("%lld",&arr[i]);

        ll k = n - 1,node;

        while(k--)
        {
            scanf("%lld %lld",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        while(m--)
        {
            scanf("%lld",&node);
            value[node]++;
        }

        dfs(1,0);

        printf("Case %lld:",++w);
        for(int i  = 1; i<=n; i++)
        {
            if(vis[i]%2 == 0)
                printf(" %lld",arr[i]);
            else
                printf(" %lld",!arr[i]);
            graph[i].clear();
        }
        printf("\n");
    }
}
