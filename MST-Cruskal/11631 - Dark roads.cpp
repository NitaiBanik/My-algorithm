#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int par[mx+5];
struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
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

int mst(int sz)
{
    int s=0,nod = 0;
    sort(vec.begin(),vec.end());
    for(int i=0; i<=sz; i++)
        par[i] =i;
    for(int i=0; i<(int)vec.size(); i++)
    {
        int u = findd(vec[i].u);
        int v =findd(vec[i].v);
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
    //freopen("output.txt","wt",stdout);
    int n,m,frm,to,cost;
    while(scanf("%d %d",&m,&n) == 2)
    {
        if(!n && !m)
            break;
        int cst = 0;
        while(n--)
        {
            cin>>frm>>to>>cost;
            cst+=cost;
            edge k(frm,to,cost);
            vec.push_back(k);
        }
        cout<<"mst = "<<mst(m)<<endl;


        cout<<cst - mst(m)<<endl;
        vec.clear();
    }
    return 0;
}
