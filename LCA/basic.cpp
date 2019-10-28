#include<bits/stdc++.h>
using namespace std;
#define mx 100005

vector<int>graph[mx],cost[mx];

int mxx,mn;
int vis[mx],par[mx],P[mx][22],level[mx];

void dfs(int u, int pr, int lvl)
{
    vis[u] = 1;
    P[u][0] = pr;
    level[u] = lvl;

    for(int i = 0 ; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(pr!=v)
        {
            dfs(v,u,lvl + 1);
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
            }
        }
    }

}

int query(int p,int q)
{
    if(level[p]>level[q])
        swap(p,q);
    for(int i = 20; i>=0; i--)
    {
        if((level[q] - (1<<i))>=level[p])
        {
            q = P[q][i];
        }
    }

    if(p == q)
        return p;

    for(int i = 20; i>=0; i--)
    {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    }
    return P[p][0];

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
            scanf("%d %d",&frm,&to);
            graph[frm].push_back(to);
            graph[to].push_back(frm);

        }

        for(int i = 0; i<=node; i++)
        {
            level[i] = 0;
            for(int j = 0; j<=20; j++)
            {
                P[i][j] = -1;
            }

        }

        dfs(1,-1,0);
        process_table(node);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++ww);

        while(q--)
        {
            scanf("%d %d",&frm,&to);

            int common = query(frm,to);
            printf("Common parent  = %d\n",common);
        }

        for(int i = 0; i <= node; i++)
        {
            graph[i].clear();
        }
    }
    return 0;
}
