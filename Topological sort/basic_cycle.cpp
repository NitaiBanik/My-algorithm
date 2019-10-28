#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>vec[100005];
int vis[100005];
vector<ll>ans;
ll cycle;

///directed and no cycle

void visit(ll u)
{
    if(vis[u] == 2 || cycle)
        return;

    if(vis[u] == 1)
    {
        cycle = 1;
        return;
    }

    vis[u] = 1;

    for(ll i=0; i<vec[u].size(); i++)
    {
        visit(vec[u][i]);
    }
    ans.push_back(u);
    vis[u] = 2;
}

int main()
{
    ll n,edge;
    while(scanf("%lld %lld",&n,&edge) == 2)
    {
        if(!n && !edge) break;
        for(ll i=1; i<=edge; i++)
        {
            ll frm,to;

            scanf("%lld %lld",&frm,&to);
            vec[frm].push_back(to);
            vec[to].push_back(frm);
        }
          for(int i = 1; i<=n ; i++)
        sort(vec[i].begin(),vec[i].end());
        cycle = 0;
        for(ll i=1; i<=n; i++)
            if(!vis[i])
                visit(i);
        if(cycle)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(ll i=n-1; i>=0; i--)
                cout<<ans[i]<<endl;
        }
        for(ll i=0; i<=n; i++) vec[i].clear();
        memset(vis,0,sizeof(vis));
        ans.clear();
    }
    return 0;
}
