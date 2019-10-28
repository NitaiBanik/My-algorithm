#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>vec[10005];
int vis[10005];
//vector<ll>ans;
map<string,ll>mp;
ll cycle;
///directed and cycle
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
   // ans.push_back(u);
    vis[u] = 2;
}

int main()
{
    ll n,edge,t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
       ll cnt=0;
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            string frm,to;
            cin>>frm>>to;
            if(mp[frm] == 0)
            {
                mp[frm] = ++cnt;
            }
            if(mp[to] == 0)
            {
                mp[to] = ++cnt;
            }
            vec[mp[frm]].push_back(mp[to]);
        }
        cycle = 0;
        for(ll i=1; i<=cnt; i++)
            if(!vis[i])
                visit(i);

        if(!cycle)
            printf("Case %d: Yes\n",++w);
        else
        {
            printf("Case %d: No\n",++w);
        }
        for(ll i=0; i<=cnt; i++) vec[i].clear();
        memset(vis,0,sizeof(vis));
        //ans.clear();
        mp.clear();
    }
    return 0;
}
