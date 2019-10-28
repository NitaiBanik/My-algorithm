#include<bits/stdc++.h>
using namespace std;
#define mx 505

int  par[mx + 5];
vector<int>vec2;
vector<int>adj[mx + 5];

int sec_par[mx + 5];
map<pair<int,int>, int> mp;
struct edge
{
    int  u,v,w;
    edge(int  a,int  b,int  c)
    {
        u = a,v = b,w = c;
    }
    bool operator <(const edge&p) const
    {
        return w<p.w;
    }
};

vector<edge>vec;

int  findd(int  val)
{
    if(par[val] == val) return val;
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
    for(int  i= 0; i<(int )vec.size(); i++)
    {
        int u = findd(vec[i].u);
        int v =findd(vec[i].v);
        if(u!=v)
        {
            Union(u,v);
            nod++;
            vec2.push_back(i);

            s+=vec[i].w;
            if(nod == sz-1)
                break;

        }

    }
}
bool vis[505];
void bfs(int s)
{
    queue<int>qq;
    qq.push(s);
    vis[s] = true;
    while(!qq.empty())
    {
        int uu = qq.front();
        qq.pop();
        for(int i=0; i<adj[uu].size(); i++)
        {
            int vv = adj[uu][i];
            if(!vis[vv])
            {
                par[vv] = uu;
                qq.push(vv);
                vis[vv] = true;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","rt",stdin);
    //freopen("out.txt","wt",stdout);
    int t,w = 0;
    cin>>t;
    while(t--){
    int  n,m,frm,to,cost;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!m && !n)
            break;
        int cntt = 0;
        while(m--)
        {
            scanf("%d %d %d",&frm,&to,&cost);
            edge k(frm,to,cost);
            vec.push_back(k);
        }
        mst(n);
        // cout<<"haha"<<endl;
        for(int i =0 ; i < vec2.size(); i++)
        {
            adj[vec[vec2[i]].u].push_back(vec[vec2[i]].v);
            adj[vec[vec2[i]].v].push_back(vec[vec2[i]].u);
            mp[make_pair(vec[vec2[i]].u,vec[vec2[i]].v)] = vec[vec2[i]].w;
            mp[make_pair(vec[vec2[i]].v,vec[vec2[i]].u)] = vec[vec2[i]].w;
        }
        int des,src,tot;

        cin>>src;
        memset(vis,false,sizeof(vis));
    for(int i=0; i<=n+1; i++)
        sec_par[i] = i;
        bfs(src);
        sec_par[src]=-1;
        printf("Case %d:\n",++w);
        for(int kk =0; kk< n ; kk++)
        {

            int xx = kk;
            int f,s = kk;
            if(vis[kk] == false){
                printf("Impossible\n");
                continue;
            }
            int mn = 0;
            while(sec_par[xx]!=-1)
            {
                f = par[xx];
                mn = max(mn,mp[make_pair(f,s)]);
                s = f;
                //cout<<par[xx]<<endl;
                xx = par[xx];
            }
            printf("%d\n",mn);
        }
        vec.clear();
        vec2.clear();
        mp.clear();
        for(int i=0; i<=n+1; i++)
            adj[i].clear();}
    }

    return 0;
}
