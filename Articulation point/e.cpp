#include<bits/stdc++.h>
using namespace std;
int vis[200005];

vector<int>graph[200005],vc;

int deg[200005];

void dfs(int src, int par)
{

    vis[src] = 1;
    vc.push_back(src);
    for(int i=0; i<graph[src].size(); i++)
    {
        int v = graph[src][i];

        if(par == v)
            continue;
            if(vis[v] == 0)
        dfs(v,src);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int ans = 0;
    for(int i = 1; i < n ; i++)
    {
        vc.clear();
        if(vis[i] == 0)
        {
            int ck = 0;
            dfs(i,-1);
            for(int j = 0; j < vc.size(); j++)
                if(deg[vc[j]] != 2)
                    ck = 1;
            if(!ck && vc.size()>=3)
                ans++;
        }
    }
    cout<<ans<<endl;
}
