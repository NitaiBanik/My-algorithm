#include<bits/stdc++.h>
using namespace std;
#define ll int
#define sz 100005
struct st
{
    ll lazy,sum;
} tree[sz * 4];

ll arr[sz];

vector<int>graph[sz];

int cn;
int vis[sz];
int start[sz];
int End[sz];

void dfs(int src)
{
    start[src] = ++cn;
    vis[src] = 1;

    for(int i = 0; i < graph[src].size(); i++)
    {
        int x = graph[src][i];
        if(vis[x] == 0)
        {
            dfs(x);
        }
    }

    End[src] = cn;
}
void update(int node, int l, int r, int x, int y)
{
    if(l>y || r < x)
    {
        return;
    }
    if(l>=x && r<=y)
    {
        tree[node].lazy++;
        return;
    }

    int mid = (l + r) / 2;
    int left = node * 2;
    int right = left + 1;

    tree[left].lazy+=tree[node].lazy;
    tree[right].lazy+=tree[node].lazy;
    tree[node].lazy = 0;

    update(left, l, mid, x, y);
    update(right,mid + 1,r, x,y);
}
int query(int node, int l, int r, int id, int carry)
{

    if(l == r && l == id)
        return tree[node].lazy+carry;

    int mid = (l + r) / 2;
    int left = node * 2;
    int right = left + 1;
    if(mid>=id)
        return query(left, l, mid, id, carry + tree[node].lazy);
    else
        return query(right,mid + 1, r,id, carry + tree[node].lazy);

}
int main()
{
    int t,m,n,u,v,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);

        for(int i = 1; i<=n; i++)
            scanf("%d",&arr[i]);

        int k = n - 1,node;

        while(k--)
        {
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cn = 0;
        dfs(1);

        while(m--)
        {
            scanf("%d",&node);
            int frm = start[node];
            int to = End[node];
            update(1,1,cn,frm,to);
        }
        printf("Case %d:",++w);
        for(int i  = 1; i<=n; i++)
        {
            int ans = query(1,1,cn,start[i],0);
            if(ans%2 == 0)
                printf(" %d",arr[i]);
            else
            {
                if(arr[i] == 0)
                    printf(" 1");
                else
                    printf(" 0");
            }
            graph[i].clear();
        }
        printf("\n");
    }
}
