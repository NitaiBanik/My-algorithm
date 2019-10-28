#include<bits/stdc++.h>
using namespace std;
#define mxx 50005
#define inf 0x3f3f3f3f
vector<int>graph[mxx + 5],cost[mxx + 5];
vector<int>graph2[mxx + 5],cost2[mxx + 5];
int dist1[mxx + 5], dist2[mxx + 5];

class st
{
public:
   int u,costt;
    bool operator < (const st & b)const
    {
        return costt > b.costt;
    }
};
void dijkastra1(int src)
{

    priority_queue<st>pq;
    st now;
    now.u = src;
    now.costt = 0;
    pq.push(now);
    dist1[src] = 0;
    //cout<<"Here"<<endl;
    while(!pq.empty())
    {
      //  cout<<"loop1"<<endl;
        int x = pq.top().u;
        pq.pop();
        //cout<<"visit = "<<x<<endl;
        for(int i = 0 ; i < graph[x].size(); i++)
        {
            int v = graph[x][i];
            if(dist1[v] > dist1[x] + cost[x][i])
            {
                dist1[v] = dist1[x] + cost[x][i];
                st now1;
                now1.u = v;
                now1.costt = dist1[v];
      //          cout<<"child = "<<v<<"cost = "<<now1.costt<<endl;
                pq.push(now1);
            }
        }
    }
    //cout<<"end"<<endl;
}

void dijkastra2(int src)
{

    priority_queue<st>pq;
    dist2[src] = 0;
    st now;
    now.u = src;
    now.costt = 0;
    pq.push(now);
    while(!pq.empty())
    {
        int x = pq.top().u;
        pq.pop();
        for(int i = 0 ; i < graph2[x].size(); i++)
        {
            int v = graph2[x][i];
            if(dist2[v] > dist2[x] + cost2[x][i])
            {
                dist2[v] = dist2[x] + cost2[x][i];
                st now1;
                now1.u = v;
                now1.costt = dist2[v];
                pq.push(now1);
            }
        }
    }

}


int main()
{

    int t,w = 0;
    scanf("%d",&t);

    while(t--)
    {
        int node,edge,frm,to,p;
        scanf("%d %d %d %d %d",&node,&edge,&frm,&to,&p);
        while(edge--)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(v);
            graph2[v].push_back(u);
            cost[u].push_back(w);
            cost2[v].push_back(w);
        }

        memset(dist1,inf,sizeof(dist1));
        memset(dist2,inf,sizeof(dist2));
        dijkastra1(frm);
        dijkastra2(to);
        int mx = -1;
        for(int i = 1; i<= node; i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                int x = dist1[i];
                int y = dist2[graph[i][j]];
                int tot = x + y + cost[i][j];
                if(tot<=p)
                {
//                    cout<<"i = "<<i<<" j = "<<graph[i][j]<<endl;
//                    cout<<"cost = "<<x<<" "<<y<<" "<<cost[i][j]<<endl;
                    mx = max(mx,cost[i][j]);
                }
            }
            graph[i].clear();
            cost[i].clear();
             graph2[i].clear();
            cost2[i].clear();
        }
        if(mx == inf) mx = -1;
       printf("Case %d: %d\n",++w,mx);
    }
    return 0;
}
