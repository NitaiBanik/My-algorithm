#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>graph[mx],cost[mx];
int mxx,mn;

int vis[mx],par[mx],P[mx][22],Max[mx][22],Min[mx][22],level[mx];

void dfs(int u, int par, int lvl, int cst)
{
    vis[u] = 1;

    P[u][0] = par;
    level[u] = lvl;
    Min[u][0] = cst;
    Max[u][0] = cst;

    for(int i = 0 ; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(par!=v)
        {
            dfs(v,u,lvl + 1, cost[u][i]);
        }
    }

}

void process_table(int n)
{
    for(int i = 1; i<=n ; i++)
    {
        for(int j = 1; j<=20; j++)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j] = P[P[i][j-1]][j-1];
                Max[i][j] = max(Max[i][j - 1],Max[P[i][j-1]][j-1]);
                Min[i][j] = min(Min[i][j - 1],Min[P[i][j-1]][j-1]);
            }
        }
    }
    //cout<<"yoyoy"<<endl;
}
void query(int p,int q)
{
    if(level[p]>level[q])
        swap(p,q);

    for(int i = 20; i>=0; i--)
    {
        if((level[q] - (1<<i))>=level[p])
        {

            mxx = max(mxx,Max[q][i]);
            mn = min(mn,Min[q][i]);
            q = P[q][i];
        }
    }

    if(p == q)
        return;

    for(int i = 20; i>=0; i--)
    {
        if(P[p][i] != P[q][i])
        {
            mxx = max(mxx,Max[q][i]);
            mn = min(mn,Min[q][i]);
            q = P[q][i];
            mxx = max(mxx,Max[p][i]);
            mn = min(mn,Min[p][i]);
            p = P[p][i];
        }

    }

    mxx = max(mxx,Max[q][0]);
    mn = min(mn,Min[q][0]);

    mxx = max(mxx,Max[p][0]);
    mn = min(mn,Min[p][0]);

}
int main()
{
    int t,ww = 0;
    scanf("%d",&t);
    while(t--)
    {
        int node;
        scanf("%d",&node);
        int frm,to,cst;
        for(int i = 1; i < node; i++)
        {
            scanf("%d %d %d",&frm,&to,&cst);
            graph[frm].push_back(to);
            graph[to].push_back(frm);
            cost[frm].push_back(cst);
            cost[to].push_back(cst);
        }
        for(int i = 0; i<=node; i++)
        {
            level[i] = 0;
            for(int j = 0; j<=20; j++)
            {
                Max[i][j] = 0;
                Min[i][j] = 99999999;
                P[i][j] = -1;
            }

        }
        dfs(1,-1,0,0);
        Max[1][0] = 0;
        Min[1][0] = 99999999;
        process_table(node);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++ww);
        while(q--)
        {
            scanf("%d %d",&frm,&to);
            mn = 99999999;
            mxx = 0;
            query(frm,to);
           printf("%d %d\n",mn,mxx);
        }
         for(int i = 0; i <= node; i++)
         {
             graph[i].clear();
             cost[i].clear();
         }
    }
    return 0;
}
