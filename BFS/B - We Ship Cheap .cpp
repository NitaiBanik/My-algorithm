#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll>mp;
map<ll,string>mp2;
bool vis[10005];
ll dis[10005];
vector<ll>vec[10005];
ll par[10005];
void bfs(ll uu)
{
    memset(dis,-1,sizeof(dis));
    queue<ll>Q;
    Q.push(uu);
    dis[uu] = 0;
    while(!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        for(ll i = 0; i<vec[u].size(); i++)
        {
            ll v = vec[u][i];
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                par[v] = u;
                Q.push(v);

            }
        }
    }
}
int main()
{
    ll node,cn = 0;
    while(scanf("%lld",&node) == 1)
    {
        if(cn>0) cout<<endl;
        cn++;

        ll i = 0,nod = node;
        string a,b;
        while(nod--)
        {
            cin>>a>>b;
            if(mp[a] == 0)
            {
                i++;
                mp[a] = i;
                mp2[i] = a;
            }
            if(mp[b] == 0)
            {
                i++;
                mp[b] = i;
                mp2[i] = b;
            }
            vec[mp[a]].push_back(mp[b]);
            vec[mp[b]].push_back(mp[a]);
        }
        cin>>a>>b;
        par[mp[a]] = -1;
        bfs(mp[a]);
        if(dis[mp[b]] == -1) cout<<"No route"<<endl;
        else
        {
            vector<ll>path;

            ll x = mp[b];
            path.push_back(x);
            while(par[x]!=-1)
            {
                path.push_back(par[x]);
                x = par[x];
            }
            reverse(path.begin(),path.end());
            cout<<mp2[path[0]]<<" "<<mp2[path[1]]<<endl;
            if(path.size()>2)
                for(int k = 2; k<path.size(); k++)
                    cout<<mp2[path[k-1]]<<" "<<mp2[path[k]]<<endl;
        }
        for(ll k = 0; k<=i+1; k++)
            vec[k].clear();
        mp.clear();
        mp2.clear();
    }
}
/*
3
JV PT
KA PT
KA HP
JV HP


2
JV PT
KA HP
JV HP

*/
