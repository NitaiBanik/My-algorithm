#include<bits/stdc++.h>
using namespace std;
vector<long long >edge[5005],cost[5005];
#define inf 0x3f3f3f3f
long long  dis[5005];
long long  dis2[5005];
struct node
{
    long long city,costt;
    node(long long r,long long ss)
    {
        city =r,costt = ss;
    }
};
bool operator < (node aa, node bb)
{
    if(aa.costt > bb.costt) return true;
    return false;
}
long long dijkstra(long long  src,long long des)
{
    memset(dis,inf,sizeof(dis));
    memset(dis2,inf,sizeof(dis2));
    priority_queue<node>pq;
    pq.push(node(src,0));
    dis[1] = 0;
    while(!pq.empty())
    {
        node Top = pq.top();
        pq.pop();
        long long u = Top.city;
        for(long long  i=0; i<edge[u].size(); i++)
        {
            int v = edge[u][i];
            if(cost[u][i] + dis[u]<dis[v])
            {
                // dis2[v] = min(dis[v],dis2[v]);
                dis[v] = cost[u][i] + dis[u];
                pq.push(node(v,dis[v]));
            }
            if((cost[u][i]+dis[u]<dis2[v]) && (cost[u][i]+dis[u] > dis[v]))
            {
                dis2[v] = cost[u][i] + dis[u];
                pq.push(node(v,dis2[v]));
            }
        }
    }
    return dis2[des];
}
int main()
{
    long long  t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        long long  nod,edg;
        scanf("%lld %lld",&nod,&edg);
        while(edg--)
        {
            long long  f,t,c;
            scanf("%lld %lld %lld",&f,&t,&c);
            edge[f].push_back(t);
            edge[t].push_back(f);
            cost[f].push_back(c);
            cost[t].push_back(c);
        }
        long long kk = dijkstra(1,nod);
       // cout<<dis[nod]<<endl;
        if(dis[nod]*3 <kk)
            kk = dis[nod]*3;
        cout<<kk<<endl;
        for(int i=1; i<=nod+1; i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
