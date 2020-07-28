///aladin

#include<bits/stdc++.h>
using namespace std;
#define gen 30000

vector<int>graph[gen + 5];

int lvl[gen + 5];
int start[gen + 5];
int End[gen + 5];
int Gen[gen + 5];
int par[gen + 5][22];
int L;
void dfs(int src, int pr,int level)
{
    start[src] = ++L;
    par[src][0] = pr;
    lvl[src] = level;
    for(int i = 0; i < graph[src].size(); i++)
    {
        int node = graph[src][i];
        if(node != pr)
        {
            dfs(node, src, level + 1);
        }
    }

    End[src] = ++L;



}

int tree[gen * 4 + 3];

int lca(int p,int q)
{
    if(lvl[p]>lvl[q])
        swap(p,q);
    for(int i = 20; i>=0; i--)
    {
        if((lvl[q] - (1<<i))>=lvl[p])
        {
            q = par[q][i];
        }
    }

    if(p == q)
        return p;

    for(int i = 20; i>=0; i--)
    {
        if (par[p][i] != -1 && par[p][i] != par[q][i])
            p = par[p][i], q = par[q][i];

    }
    return par[p][0];

}
int query(int node, int l, int r, int x, int y)
{
    if(l >= x && r <= y)
    {

        return tree[node];
    }

    if(l > y || r < x)
        return 0;

    int lf = node * 2;
    int rt = lf + 1;
    int mid = (l + r) / 2;

    int xx = query(lf, l, mid, x, y);
    int yy = query(rt, mid + 1,r,x,y);
    return xx + yy;
}
void update(int node, int l, int r, int idx, int st)
{
    if(l == r && r == idx)
    {
        tree[node] = st;
        return;
    }

    if(l>idx || r < idx)
        return;

    int lf = node * 2;
    int rt = lf + 1;
    int mid = (l + r) / 2;

    if(mid>=idx)
        update(lf, l, mid, idx, st);
    else
        update(rt, mid + 1,r, idx, st);
    tree[node] = tree[lf] + tree[rt];

}

void table(int n)
{
    for(int i = 1; i<=20; i++)
    {
        for(int j = 1; j<=n; j++)
            if(par[j][i-1] != -1)
                par[j][i] = par[par[j][i-1]][i-1];
    }
}

int main()
{
    int t,w = 0;
    scanf("%d",&t);

    while(t--)
    {
        L = 0;
        int n,u,v;
        scanf("%d",&n);
        for(int i = 1; i<=n; i++)
            scanf("%d", &Gen[i]);

        for(int i = 1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            u++,v++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(par,-1, sizeof(par));
        dfs(1,-1,1);

        table(n);
        //cout<<"he"<<endl;
        for(int i = 1; i<= n; i++)
        {
            update(1,1,L,start[i], Gen[i]);
            update(1,1,L,End[i], -Gen[i]);
        }
        int q;
       scanf("%d",&q);
        printf("Case %d:\n",++w);
        while(q--)
        {
            int type, x1,x2;
            scanf("%d %d %d", &type, &x1, &x2);

            if(type == 0)
            {
                x1++,x2++;
                int common = lca(x1,x2);
               // cout<<"common = "<<common<<endl;
                int ans = query(1,1, L, start[common], start[x1]);
               // cout<<"ans1 = "<<ans<<endl;
                ans += query(1,1, L, start[common], start[x2]);
               // cout<<"ans2 = "<<ans<<endl;
                printf("%d\n",ans-Gen[common]);
            }
            else
            {
                x1++;
                Gen[x1] = x2;
                update(1,1,L,start[x1],Gen[x1]);
                update(1,1,L,End[x1],-Gen[x1]);
            }
        }
          for(int i = 1; i<=n; i++) graph[i].clear();
    }
    return 0;
}
