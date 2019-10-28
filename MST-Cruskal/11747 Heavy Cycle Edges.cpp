#include<bits/stdc++.h>
using namespace std;
#define mx 10005
#define inf 99999999

long long  par[mx+5];
struct edge
{
    long long  u,v,w;
    edge(long long  a,long long  b,long long c)
    {
        u = a,v = b,w = c;
    }
    bool operator <(const edge&p) const
    {
        return w<p.w;
    }
};

vector<edge>vec;
vector<long long>vec2;
long long findd(long long val)
{
    if(par[val] == val) return val;
    return par[val]=findd(par[val]);
}

void Union(long long a,long long b)
{
    par[findd(b)] = findd(a);
}

long long node;

void mst(long long sz)
{
    sort(vec.begin(),vec.end());
    for(long long  i=0; i<sz; i++)
        par[i] = i;
    for(long long  i=0; i<(long long )vec.size(); i++)
    {
        long long u = findd(vec[i].u);
        long long v = findd(vec[i].v);
        if(u ==v)
            vec2.push_back(vec[i].w);
        else
        {
            //vec2.push_back(i);
            Union(u,v);
            node++;
            // vec[i].w = inf;
            if(node == sz-1)
                break;

        }

    }
}

int main()
{
    long long  n,m,frm,to,cost;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==0 && m == 0)
            break;
        node=0;
        while(m--)
        {
            scanf("%lld %lld %lld",&frm,&to,&cost);
            edge k(frm,to,cost);
            vec.push_back(k);
        }
        mst(n);
        if(vec2.size() == 0)
            cout<<"forest"<<endl;
        else
        {
            sort(vec2.begin(),vec2.end());
            cout<<vec2[0];
            for(int i=1; i<vec2.size(); i++)
                cout<<" "<<vec2[i];
            cout<<endl;
        }
        vec.clear();
        vec2.clear();

    }
    return 0;
}
