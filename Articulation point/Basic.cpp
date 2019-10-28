#include<bits/stdc++.h>
using namespace std;
#define mx 10000
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
    int node,edge,t,w = 0;
    scanf("%d",&t);
    while(t--){
            tym = 0;
    scanf("%d %d",&node,&edge);
    for(int i=0; i<edge; i++)
    {
        int frm,to;
        scanf("%d %d",&frm,&to);
        graph[frm].push_back(to);
        graph[to].push_back(frm);

    }
    for(int i=1; i<=node; i++)
    {
        par[i] = i;
        low[i] = 10000000;
    }
    for(int i=1; i<=node; i++)
        if(!vis[i])
            dfs(i);
   printf("Case %d: %d\n",++w,arti.size());
   arti.clear();
    for(int i=1; i<=node; i++)
        graph[i].clear();
    memset(vis,false,sizeof(vis));

    }
}
