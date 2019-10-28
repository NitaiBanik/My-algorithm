#include<bits/stdc++.h>
using namespace std;
#define mx 405
#define inf 99999999
long long  par[mx+5];
long long mp[mx + 5];
struct edge
{
    long long  u,v,w,ck;
    edge(long long  a,long long  b,long long c,long long st)
    {
        u = a,v = b,w = c;
        ck = st;
    }
    bool operator <(const edge&p) const
    {
        return w<p.w;
    }
};

vector<edge>vec,vec2;
long long findd(long long val)
{
    if(par[val] == val) return val;
    return par[val]=findd(par[val]);
}

void Union(long long a,long long b)
{
    par[findd(b)] = findd(a);
}
int node;
long long mst(long long  sz)
{
    long long  s=0;
    sort(vec.begin(),vec.end());
    for(int i=1; i<=sz; i++)
        par[i] =i;
    for(long long  i=0; i<(long long )vec.size(); i++)
    {
        long long u = findd(vec[i].u);
        long long v =findd(vec[i].v);
        if(u!=v)
        {
            vec2.push_back(vec[i]);
            Union(u,v);
            node++;
            s+=vec[i].w;
            if(node == sz-1)
                break;

        }

    }
    if(node == sz-1)
        return s;
    else
        return -1;
}

int main()
{
    long long t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        long long  n,m,frm,to,cost;
        node=0;
        //cin>>n>>m>>air;
        scanf("%lld %lld",&n,&m);
        long long cntt = 0;
        int zz = 0;
        bool flag = 0;
        printf("Case %d:\n",++w);
        while(m--)
        {
            scanf("%lld %lld %lld",&frm,&to,&cost);
            if(n == 1)
            {
                printf("0\n");
                continue;
            }
            if(flag  == 0)
            {
                node = 0;
                edge k(frm,to,cost,zz);
                vec.push_back(k);
                long long ans = mst(n);
                if(ans!=-1)
                {
                    vec.clear();
                    for(int i=0; i<vec2.size(); i++)
                        vec.push_back(vec2[i]);
                    vec2.clear();
                    printf("%lld\n",ans);
                    flag = 1;
                }
                else printf("-1\n");
                vec2.clear();
            }
            else
            {
                node = 0;

                edge k(frm,to,cost,zz);

                vec.push_back(k);

                long long ans = mst(n);

                vec.clear();

                for(int i=0; i<vec2.size(); i++)
                    vec.push_back(vec2[i]);

                vec2.clear();
                printf("%lld\n",ans);
            }

        }
        vec.clear();
        vec2.clear();
    }

    return 0;
}



