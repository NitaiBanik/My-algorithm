#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 99999999999999
ll n,m,k,d;

vector<ll>edg[10005],cost[10005],status[10005];

ll dis[10005];

struct node
{
    ll frm,cst,taken;
    bool operator <(const node & b)const
    {
        return taken>b.taken;
    }
};

ll dijkstra(ll x, ll y)
{
    for(int i=0; i<=n; i++)
        dis[i] = inf;


    priority_queue<node>pq;

    dis[x] = 0;

    node u,v;
    u.frm = x;

    u.cst = 0;
    u.taken = 0;
    pq.push(u);

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        ll city = u.frm;
        ll fare = u.cst;
        ll st = u.taken;
        int sz= edg[city].size();
        for(int i=0; i<sz; i++)
        {
            ll new_cst = fare + cost[city][i];
            ll new_des = edg[city][i];
            ll new_stat = st + status[city][i];
            if(dis[new_des] > new_cst && new_stat<=d)
            {
                v.frm = new_des;
                v.cst = new_cst;
                v.taken = new_stat;
                pq.push(v);
                dis[new_des] = new_cst;
            }
//            else if(new_stat<=d)
//            {
//                v.frm = new_des;
//                v.cst = new_cst;
//                v.taken = new_stat;
//                pq.push(v);
//            }
        }
    }
    return dis[y];
}
void reset()
{
    for(int i=0; i<=10003; i++)
    {
        edg[i].clear();
        cost[i].clear();
        status[i].clear();
    }
}
int main()
{

    ll a,b,c,t,w = 0;
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&n,&m,&k,&d);
        while(m--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            edg[a].push_back(b);
            cost[a].push_back(c);
            status[a].push_back(0);

        }

        while(k--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            edg[a].push_back(b);
            cost[a].push_back(c);
            status[a].push_back(1);
        }

        ll ans = dijkstra(0,n-1);

        if(ans == inf)
            printf("Case %lld: Impossible\n",++w);
        else
            printf("Case %lld: %lld\n",++w,ans);

        reset();
    }
    return 0;
}
