#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf -787878

int main()
{
    // freopen("in.txt","rt",stdin);
 //   freopen("out.txt","wt",stdout);
    ll node,cn = 0;
    while(scanf("%lld",&node) == 1)
    {
        if(cn>0) cout<<endl;
        cn++;
        map<string,ll>mp;
        map<ll,string>mp2;
        ll dis[node * 2 + 5];
        vector<ll>vec[node * 2 + 5];
        ll par[node * 2 + 5];
        ll i = 0,nod = node;
        string a,b;
        while(nod--)
        {
            cin>>a>>b;
            if(mp.find(a) == mp.end())
            {
                i++;
                mp[a] = i;
                mp2[i] = a;
            }

            if(mp.find(b) == mp.end())
            {
                i++;
                mp[b] = i;
                mp2[i] = b;
            }

            vec[mp[a]].push_back(mp[b]);
            vec[mp[b]].push_back(mp[a]);
        }

        cin>>a>>b;
        if(a == b)
        {
            cout<<a<<" "<<a<<endl;
            continue;
        }
        else if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
        {
            cout<<"No route"<<endl;
            continue;
        }
        memset(par,-1,sizeof(par));
        par[mp[a]] = -1;
        for(ll i=0; i<=node+3; i++)
            dis[i]=inf;
        queue<ll>Q;
        Q.push(mp[a]);
        dis[mp[a]] = 0;
        while(!Q.empty())
        {
            ll u = Q.front();
            Q.pop();
            for(ll i = 0; i<vec[u].size(); i++)
            {
                ll v = vec[u][i];
                if(dis[v] == inf)
                {
                    dis[v] = dis[u] + 1;
                    par[v] = u;
                    Q.push(v);

                }
            }
        }
        if(dis[mp[b]] == inf)
            cout<<"No route"<<endl;
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
            {
                for(ll k = 2; k<path.size(); k++)
                    cout<<mp2[path[k-1]]<<" "<<mp2[path[k]]<<endl;
            }
        }
        for(ll k = 0; k<=node * 2 + 3; k++)
            vec[k].clear();
    }

    return 0;
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
