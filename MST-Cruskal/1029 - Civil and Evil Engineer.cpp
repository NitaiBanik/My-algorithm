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
};
bool cmp(edge p, edge q)
{
    return p.w<q.w;
}
bool cmp1(edge p, edge q)
{
    return p.w>q.w;
}
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
long long mst1(long long  n,long long sz)
{
    long long  s=0,nod = 0;

    for(int i=0; i<=n; i++)
        par[i] =i;
    for(long long i=0; i<(long long )vec.size(); i++)
    {
        long long u = findd(vec[i].u);
        long long v =findd(vec[i].v);
        if(u!=v)
        {
            Union(u,v);
            nod++;
            s+=vec[i].w;
            if(nod == sz)
                break;

        }

    }
    return s;
}
int main()
{
    long long t,w = 0;
    scanf("%lld",&t);
    int cnt;
    while(t--)
    {
        cin>>cnt;
        long long frm,to,cost,edg = 0;
        while(scanf("%lld %lld %lld",&frm,&to,&cost) == 3)
        {
            if(!frm && !to && !cost)
                break;
            edge k(frm,to,cost);
            vec.push_back(k);
            edg++;
        }
        sort(vec.begin(),vec.end(),cmp);
        long long val1 = mst1(cnt,edg),val2 = 0;
        sort(vec.begin(),vec.end(),cmp1);
        val2 += mst1(cnt,edg);
        val1+=val2;
        if(val1%2!=0)
            printf("Case %lld: %lld/2\n",++w,val1);
        else
            printf("Case %lld: %lld\n",++w,val1/2);
        vec.clear();
    }

    return 0;
}
