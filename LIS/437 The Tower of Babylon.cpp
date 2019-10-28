#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll B,W,cst;
    node(ll a, ll b, ll c)
    {
        B = a,W = b,cst = c;
    }
};
vector<node>graph;
vector<ll>graph2[105];
ll dp[110];

ll fun(ll s)
{
    if(graph2[s].size() == 0)
        return 0;
    if(dp[s]!=-1) return dp[s];

    ll res = 0;
    for(int i=0;i<graph2[s].size();i++)
    {
        ll v = graph2[s][i];
        res = max(res, graph[v].cst + fun(v));
    }
    return dp[s] = res;
}
int main()
{
    ll n,w = 0;
    while(scanf("%lld",&n) == 1 && n!=0)
    {
        ll a,b,c;
        ll arr[5];
        graph.push_back(node(0,0,0));
        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2]);
            sort(arr,arr+3);
            graph.push_back(node(arr[0],arr[1],arr[2]));
            graph.push_back(node(arr[0],arr[2],arr[1]));
            graph.push_back(node(arr[1],arr[2],arr[0]));

        }
        for(int i=0; i<graph.size(); i++)
        {
            for(int j=0; j<graph.size(); j++)
            {
                if(graph[j].B>graph[i].B && graph[j].W>graph[i].W)
                    graph2[i].push_back(j);

            }
        }
        memset(dp,-1,sizeof(dp));
        ll ans = 0;
        for(int i=0; i<graph.size(); i++)
            ans = max(ans,fun(i));
            printf("Case %lld: maximum height = %lld\n",++w,ans);
            graph.clear();
            for(int i=0;i<=102;i++)
                graph2[i].clear();
    }
return 0;
}
