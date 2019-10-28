#include<bits/stdc++.h>
using namespace std;
vector<long long >edge[100005],cost[100005];
#define inf 0x3f3f3f3f
long long  dis[100005],parent[100005];
struct node
{
    long long city,costt;
    node(int r,int ss)
    {
        city =r,costt = ss;
    }
};
bool operator < (node aa, node bb)
{
    if(aa.costt > bb.costt) return true;
    return false;
}
void dijkstra(long long  src,long long des)
{
   memset(dis,inf,sizeof(dis));
   memset(parent,-1,sizeof(parent));
    priority_queue<node>pq;
    pq.push(node(src,0));
    dis[1] = 0;
    while(!pq.empty())
    {
        node Top = pq.top();
         pq.pop();
        long long u = Top.city;
        if(u == des) return;
        for(long long  i=0; i<edge[u].size(); i++)
        {
            int v = edge[u][i];
            if(cost[u][i] + dis[u]<dis[v])
            {
                dis[v] = cost[u][i] + dis[u];

                parent[v] = u;
                pq.push(node(v,dis[v]));
            }
        }
    }
    return;
}
int main()
{
    //long long  t,w = 0;
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
    dijkstra(1,nod);

    if(parent[nod] == -1)
    {
        cout<<-1;
        //return 0;
    }
    else
    {
        long long xx = nod;
        vector<long long >vv;
        while(xx!=-1)
        {
            vv.push_back(xx);
            xx = parent[xx];
        }
        reverse(vv.begin(),vv.end());
        for(long long  i=0; i<vv.size(); i++)
            cout<<vv[i]<<" ";
    }
    return 0;
}
