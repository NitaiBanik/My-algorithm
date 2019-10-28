#include<bits/stdc++.h>
using namespace std;
#define mx 10000
vector<int>graph[mx + 5];
int par[mx + 5],dis[mx + 5],low[mx + 5],tym;
bool vis[mx + 5];
vector<pair<int, int> >pr;
void dfs(int u)
{
    vis[u] = true;
    low[u] = dis[u] = tym++;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!vis[v])
        {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(dis[u]<low[v])
            {
                if(u<v)
                pr.push_back(make_pair(u,v));
                else
                pr.push_back(make_pair(v,u));
            }
        }
        else if(v!=par[u])
            low[u] = min(low[u],dis[v]);

    }
}
int main()
{
    int node,edge,t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        tym = 0;
        scanf("%d",&node);
        for(int i=0; i<node; i++)
        {
            int frm,to;
            scanf("%d",&frm);
            //cout<<frm<<endl;
            string ss;
            cin>>ss;
            edge =0;
            for(int ii=1; ii<ss.size()-1; ii++)
                edge =edge * 10 + ss[ii] - '0';
//           cout<<edge<<endl;
            while(edge--)
            {
                scanf("%d",&to);
                graph[frm].push_back(to);
                graph[to].push_back(frm);
            }

        }
        for(int i=0; i<=node; i++)
        {
            par[i] = i;
            dis[i]= low[i] = 10000000;
        }
        for(int i=0; i<node; i++)
            if(!vis[i])
                dfs(i);
        printf("Case %d:\n%d critical links\n",++w,pr.size());

        sort(pr.begin(),pr.end());
        for(int j=0; j<pr.size(); j++)
            cout<<pr[j].first<<" - "<<pr[j].second<<endl;

        for(int i=0; i<=node; i++)
            graph[i].clear();
        pr.clear();
        memset(vis,false,sizeof(vis));

    }
}
