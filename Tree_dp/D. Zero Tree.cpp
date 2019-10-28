#include<bits/stdc++.h>
using namespace std;
#define mx 100000
#define ll long long
vector<ll>graph[mx + 5];
ll cost[mx + 5], vis[mx + 5], pluss[mx + 5], minuss[mx + 5], ans[mx + 5];

void dfs(ll u)
{
    vis[u] = true;
    for(ll i = 0 ; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if(vis[v] == 0)
        {
            dfs(v);
            minuss[u] = max(minuss[u],minuss[v]);
            pluss[u] = max(pluss[u],pluss[v]);
        }
    }
    cost[u]+=pluss[u];
    cost[u]-=minuss[u];
    if(cost[u]>=0)
        minuss[u] += cost[u];
    else
        pluss[u] += abs(cost[u]);
}
int main()
{
    ll n;
    cin>>n;
    for(ll i = 1 ; i < n ; i++)
    {
        ll frm,to;
        scanf("%lld %lld",&frm, &to);
        graph[frm].push_back(to);
        graph[to].push_back(frm);
    }
    for(ll i = 1 ; i <= n ; i++)
        scanf("%lld",&cost[i]);

    dfs(1);
    cout<< pluss[1] + minuss[1]<<endl;
}
