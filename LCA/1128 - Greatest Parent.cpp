#include<bits/stdc++.h>
using namespace std;
int par[100005][30];
int dis[100005];
void build(int node)
{
  par[0][0] = 0;
    for(int j = 1; j <= 20; j++)
    {
        for(int i = 0; i < node; i++)
            par[i][j] = par[par[i][j-1]][j-1];
    }
}

int query(int node, int value)
{
    for(int i = 20; i>=0; i--)
    {
        if(par[node][i] != -1 && dis[par[node][i]] >= value)
            node = par[node][i];
    }

    return node;
}
int main()
{
    int t, w = 0;

    scanf("%d", &t);

    while(t--)
    {
        int node, q;
        scanf("%d %d", &node, &q);

        memset(par,-1,sizeof(par));

        for(int i = 1; i< node; i++)
        {
            int parr,value;
            scanf("%d %d", &parr, &value);
            par[i][0] = parr;
            dis[i]= value;
        }
        dis[0] = 1;
        build(node);

        printf("Case %d:\n", ++w);

        while(q--)
        {
            int nd, cost;
            scanf("%d %d", &nd,&cost);
            int answer = query(nd, cost);

            printf("%d\n", answer);
        }

    }
    return 0;
}
