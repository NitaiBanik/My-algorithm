#include<bits/stdc++.h>
using namespace std;
#define mx 100
vector<int>graph[mx + 5];
int par[mx + 5],dis[mx + 5],low[mx + 5],tym;
bool vis[mx + 5];
set<int>arti;
void dfs(int u)
{
    vis[u] = true;
    low[u] = dis[u] = tym++;
    int child = 0;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!vis[v])
        {
            child++;
            par[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if((par[u] == u && child>1) || (par[u]!=u && dis[u]<=low[v]))
                arti.insert(u);
        }
        else if(v!=par[u])
            low[u] = min(low[u],dis[v]);

    }
}
int main()
{
    int node,edge,t,w = 0,to,frm;
    while(scanf("%d",&node) == 1 && node!=0)
    {
        getchar();
        while(scanf("%d",&to) == 1 && to!=0)
        {
            string s;
            getline(cin,s);
            stringstream ss(s);
        while(ss>>frm){
                graph[frm].push_back(to);
            graph[to].push_back(frm);}
        }
        tym = 0;

        for(int i=1; i<=node; i++)
        {
            par[i] = i;
            low[i] = 10000000;
        }
        for(int i=1; i<=node; i++)
            if(!vis[i])
                dfs(i);
        printf("%d\n",arti.size());
        arti.clear();
        for(int i=1; i<=node; i++)
            graph[i].clear();
        memset(vis,false,sizeof(vis));

    }
}
