#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long long  par[mx+5];
struct edge
{
    long long  u,v,w;
    edge(long long  a,long long  b,long long  c)
    {
        u = a,v = b,w = c;
    }
    bool operator <(const edge&p) const
    {
        return w<p.w;
    }
};
vector<edge>vec;
long long  findd(long long  val)
{
    if(par[val] == val) return val;
    return par[val]=findd(par[val]);
}
void Union(long long a,long long b)
{
    par[findd(b)] = findd(a);
}
long long air;
long long mst(long long  sz)
{
    long long  s=0,nod = 0;
    sort(vec.begin(),vec.end());
    for(int i=0; i<=sz; i++)
        par[i] =i;
    for(long long  i=0; i<(long long )vec.size() && vec[i].w<air; i++)
    {
        long long u = findd(vec[i].u);
        long long v =findd(vec[i].v);
        if(u!=v)
        {
            Union(u,v);
            nod++;
            s+=vec[i].w;
            if(nod == sz-1)
                break;

        }

    }
    return s;
}
int main()
{
    //freopen("in.txt","rt",stdin);
    //freopen("out.txt","wt",stdout);
    long long t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        long long  n,m,frm,to,cost;
        //cin>>n>>m>>air;
        scanf("%lld %lld %lld",&n,&m,&air);
        long long cntt = 0;
        while(m--)
        {
            scanf("%lld %lld %lld",&frm,&to,&cost);
            if(cost<air)
            {
                edge k(frm,to,cost);
                vec.push_back(k);
            }

        }
        long long ms = mst(n);
        // cout<<ms<<endl;
        for(int i=1; i<=n; i++)
            if(par[i] == i)
                cntt++;

        printf("Case #%lld: %lld %lld\n",++w,ms+(cntt* air),cntt);
        vec.clear();
    }

    return 0;
}

/*
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
*/
