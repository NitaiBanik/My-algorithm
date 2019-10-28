#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>graph[6005];

ll dp[6005][5];
ll val[6005];

int vis[6005];
int par[6005];


void fun(int src)
{
    if(vis[src] == 1)
        return ;

    vis[src] = 1;
    dp[src][0] = 0;

    dp[src][1] = val[src];

    for(int i=0; i<graph[src].size(); i++)
    {
        int x = graph[src][i];
        if(vis[x] == 1)
            continue;
        fun(x);
        dp[src][0]+=max(0LL,max(dp[x][1],dp[x][0]));

        dp[src][1]+=dp[x][0];
    }
}

int main()
{

    memset(dp,0,sizeof(dp));
    memset(par,-1,sizeof(par));

    int n;
    cin>>n;

    int u,v;
    for(int i=1; i<=n; i++)
        scanf("%lld",&val[i]);
    while(scanf("%d %d",&u,&v) == 2)
    {
        if(u == 0 && v == 0)
            break;
        graph[v].push_back(u);
        par[u] = v;
        //graph[u].push_back(v);
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(par[i] == -1)
        {
            fun(i);
            ans += max(dp[i][0],dp[i][1]);
        }
    }
    cout<<ans<<endl;

    return 0;

}
