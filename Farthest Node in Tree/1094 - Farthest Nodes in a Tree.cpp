//1094 - Farthest Nodes in a Tree
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll node;
vector<ll>graph[30005],cost[30005];
ll dp[30005];
ll vis[30005];
ll st;
ll mx;

ll dfs(ll src,ll cst)
{
    vis[src] = 1;
    dp[src] = cst;

    if(cst>=mx)
    {
        mx = cst,st = src;
    }

    for(int i = 0 ; i < graph[src].size(); i++)
    {
        int now = graph[src][i];
        if(vis[now] == 0)
        {
            vis[now] = 1;
            // cout<<"vis = "<<now<<endl;
            dfs(now,cst + cost[src][i]);
        }
    }

}

int main()
{
    ll t,frm,to,costt,w = 0;
    scanf("%lld",&t);
    while(t--)
    {

    ll x,y,z;
    cin>>x>>y>>z;
    z%=3;
    ll p = x^y;
    if(z == 0) cout<<x<<endl;
    if(z == 1) cout<<y<<endl;
    if(z == 2) cout<<p<<endl;
    }

    return 0;
}
