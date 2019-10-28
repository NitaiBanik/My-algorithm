#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f

vector<ll>graph[1005];
vector<ll>cost[1005];

ll dis[10005];

class node
{
    public:
    ll city,cst;
//    node(ll x, ll y)
//    {
//        city = x,cst = y;
//    }
    bool operator <(const node & x)const
    {

        return cst>x.cst;
    }
};

ll X,Y;
ll dijkstra(ll src, ll des)
{
    priority_queue<node>pq;

    memset(dis,inf,sizeof(dis));

    node u,v;
    u.city =src;
    u.cst = 0;
    dis[src] = 0;
    pq.push(u);
    while(!pq.empty())
    {

        u = pq.top();
        pq.pop();
        ll x  = u.city;
        ll y = u.cst;
        for(int i=0; i<graph[x].size(); i++)
        {
            ll w = cost[x][i];
            ll d = graph[x][i];
            if(w>= y && w<dis[d] && w>=X && w<=Y)
            {

                dis[d] = w;
                v.city  = d;
                v.cst  = w;
                if(d == des) return dis[des];
                pq.push(v);
            }
        }

    }
    return dis[des];

}

int main()
{
    ll e;
    scanf("%lld",&e);
    while(e--)
    {
        ll p,q,r;

        scanf("%lld %lld %lld",&p,&q,&r);

        graph[p].push_back(q);
        graph[q].push_back(p);
        cost[p].push_back(r);
        cost[q].push_back(r);
    }
    ll q;

    scanf("%lld",&q);
    while(q--)
    {
        ll p,q,x,y;
         scanf("%lld %lld %lld %lld",&p,&X,&q,&Y);
         ll D = dijkstra(p,q);

        // cout<<D<<" "<<endl;
         if(D<inf) printf("Yes\n");
         else printf("No\n");
    }
    return 0;
}
