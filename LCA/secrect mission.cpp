#include<bits/stdc++.h>
using namespace std;
struct st
{
    int x,y,z;
    st(int p, int q,  int r)
    {
        x = p,y = q, z = r;
    }
    bool operator <(const st&p) const
    {
        return z<p.z;
    }
};
vector<st>vec;
vector<int>graph[50005],cost[50005];
int  par[50005];
int  dis[50005];
int  lvl[50005];
int n,m;
int sparse[50005][16];
int ans[50005][16];

int  findd(int val)
{
    if(par[val] == val)
        return val;
    return par[val]=findd(par[val]);
}

void Union(int a,int b)
{
    par[findd(b)] = findd(a);
}

void mst(int  sz)
{
    int  s=0,nod = 0;

    sort(vec.begin(),vec.end());

    for(int i=0; i<=sz; i++)
        par[i] =i;

    for(int  i=0; i<(int )vec.size(); i++)
    {
        int a = vec[i].x;
        int b = vec[i].y;
        int c = vec[i].z;
        int u = findd(vec[i].x);
        int v =findd(vec[i].y);

        if(u!=v)
        {
            Union(u,v);
            nod++;

            graph[a].push_back(b);
            graph[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
            if(nod == sz-1)
                break;
        }

    }

}


void dfs(int src, int from, int l)
{
    par[src] = from;
    lvl[src] = l;
    for(int i = 0; i< graph[src].size(); i++)
    {
        int now = graph[src][i];

        if(from!=now)
        {
            dis[now] = cost[src][i];
            dfs(now, src, l+1);
        }
    }
}

void table()
{
    memset(sparse, -1, sizeof(sparse));

    for(int i = 1; i<=n; i++)
        sparse[i][0] = par[i], ans[i][0] = dis[i];

    for(int i = 1; (1<<i)<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(sparse[j][i-1] != -1)
            {
                sparse[j][i] = sparse[sparse[j][i-1]][i-1];
                ans[j][i] = max(ans[j][i-1],ans[sparse[j][i-1]][i-1]);
            }
        }
    }

}
int query(int frm, int to)
{
    int mx = 0;
    if(lvl[frm]>lvl[to])
        swap(frm,to);
    int log=log2(lvl[to]);
    for(int i = log; i>=0; i--)
    {
        if((lvl[to]-(1<<i))>=lvl[frm])
        {
            mx = max(mx,ans[to][i]);
            to = sparse[to][i];

        }
    }

    if(frm == to)
        return mx;
    for(int i = log; i>=0; i--)
    {
        if(sparse[frm][i] !=-1 && sparse[to][i] != sparse[frm][i])
        {
            mx= max(mx, ans[frm][i]);
            mx= max(mx, ans[to][i]);
            to = sparse[to][i];
            frm = sparse[frm][i];

        }
    }
    int f = max(dis[frm], dis[to]);
    mx = max(mx,f);
    return mx;
}
int main()
{
    // freopen("out.txt","wt", stdout);
    int t, w = 0 ;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        while(m--)
        {
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            vec.push_back(st(x,y,z));

        }
        mst(n);
        memset(lvl, -1, sizeof(lvl));

        dis[1] = 0;
        dfs(1,1,0);

        table();
        int q;
        cin>>q;
        printf("Case %d:\n",++w);
        while(q--)
        {
            int frm, to;
            scanf("%d %d", &frm, &to);
            // cout<<"frm = "<<frm<<" to = "<<to<<endl;
            int val =  query(frm,to);
            printf("%d\n", val);
        }
        vec.clear();
        for(int i = 0; i<=n; i++)
        {
            graph[i].clear(), cost[i].clear();
        }

    }
}
