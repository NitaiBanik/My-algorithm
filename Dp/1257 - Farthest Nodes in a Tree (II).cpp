#include<bits/stdc++.h>
using namespace std;
#define mxx 30000

vector<int>graph[mxx + 5],cost[mxx + 5];
int cot[mxx + 5],vis[mxx + 5],mx,nd;

void fun(int src, int costt)
{
    vis[src] = 1;
    cot[src] = max(cot[src],costt);
    // getchar();
    //cout<<"src = "<<src<<endl;
    if(costt>=mx)
    {
        mx = costt,nd = src;
    }

    for(int i = 0 ; i < graph[src].size(); i++)
    {
        int now = graph[src][i];
        if(vis[now] == 0)
        {
            // cout<<"vis = "<<now<<endl;
            fun(now,costt + cost[src][i]);
        }
    }
}

int main()
{

    int t,n,w = 0;

    scanf("%d",&t);

    while(t--)
    {
        int edge;
        scanf("%d",&n);
        for(int i =0 ; i < n -1; i++)
        {
            int frm,to,cst;

            scanf("%d %d %d",&frm,&to,&cst);
            graph[to].push_back(frm);

            graph[frm].push_back(to);
            cost[frm].push_back(cst);
            cost[to].push_back(cst);
        }

        mx = 0;
        memset(vis,0,sizeof(vis));
        memset(cot,0,sizeof(cot));
        fun(0,0);
        memset(vis,0,sizeof(vis));
        fun(nd,0);
        memset(vis,0,sizeof(vis));
        fun(nd,0);
        // cout<<"cost = "<<mx<<" node = "<<nd<<endl;
        printf("Case %d:\n",++w);
        for(int i = 0; i<n; i++)
        {
            printf("%d\n",cot[i]);
            graph[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}

