#include<bits/stdc++.h>
using namespace std;
#define mx 10005
long long  par[mx+5];

long long air;
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
long long mxx;
long long  findd(long long  val)
{
    if(par[val] == val) return val;
    return par[val]=findd(par[val]);
}
void Union(long long a,long long b)
{
    par[findd(b)] = findd(a);
}
long long mst(long long  sz)
{
    long long  s=0,nod = 0;
    sort(vec.begin(),vec.end());
    for(int i=0; i<=sz; i++)
        par[i] =i;
    for(long long  i=0; i<(long long )vec.size(); i++)
    {
        long long u = findd(vec[i].u);
        long long v =findd(vec[i].v);
        if(u!=v)
        {
            Union(u,v);
            nod++;
            s+=vec[i].w;
            mxx = max(mxx,vec[i].w);
            if(nod == sz-1)
                break;
        }

    }
    return s;
}

int main()
{
    long long t,cas = 0;
    scanf("%lld",&t);
    while(t--)
    {
        long long  n,m,frm,to,cost;
        //cin>>n>>m>>air;
        scanf("%lld %lld",&n,&m);
        long long cntt = 0;
        while(m--)
        {
            scanf("%lld %lld %lld",&frm,&to,&cost);
            edge k(frm,to,cost);
            vec.push_back(k);
        }
        mxx = 0;
        long long ms = mst(n);
        printf("Case %lld: %lld\n",++cas,max(ms - mxx,0LL));
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
