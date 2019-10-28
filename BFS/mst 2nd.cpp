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
vector<int>vec2;
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
            vec2.push_back(i);
            Union(u,v);
            node++;
            s+=vec[i].w;
            if(node == sz-1)
                break;

        }

    }
    return s;
}

long long mst2(long long  sz)
{
    long long  s=0;
    //sort(vec.begin(),vec.end());
    for(int i=1; i<=sz; i++)
        par[i] =i;
    for(long long  i=0; i<(long long )vec.size(); i++)
    {
        if(vec[i].w!=inf)
        {

            long long u = findd(vec[i].u);
            long long v =findd(vec[i].v);
            if(u!=v)
            {
                //vec2.push_back(i);
                Union(u,v);
                node++;
                s+=vec[i].w;
                if(node == sz-1)
                    break;

            }

        }
    }
    // cout<<"s"<<s<<endl;
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
        node=0;
        //cin>>n>>m>>air;
        scanf("%lld %lld",&n,&m);
        long long cntt = 0;
        while(m--)
        {
            scanf("%lld %lld %lld",&frm,&to,&cost);
            edge k(frm,to,cost);
            vec.push_back(k);

        }
        long long first_mst = mst(n);

        if(node!=n - 1) printf("Case #%lld : No way\n",++w);

        else
        {
            long long mn = 999999999;
            for(int i=0; i<vec2.size(); i++)
            {
                long long st = vec[vec2[i]].w;
                vec[vec2[i]].w = inf;
                node=0;
                long long chk = mst2(n);
//            cout<<"node "<<node<<endl;
//            cout<<"aaa "<<chk<<endl;
                vec[vec2[i]].w=st;
                if(node == n - 1)
                    mn = min(mn,chk);
            }
            if((mn == 999999999))
                printf("Case #%lld : No second way\n",++w);
            else
            printf("Case #%lld : %lld\n",++w,mn);
        }

        memset(par,0,sizeof(par));
        vec.clear();
        vec2.clear();
    }

    return 0;
}

/*
4
5 4
1 2 5
3 2 5
4 2 5
5 4 5
5 3
1 2 5
3 2 5
5 4 5
5 5
1 2 5
3 2 5
4 2 5
5 4 5
4 5 6
1 0
*/


