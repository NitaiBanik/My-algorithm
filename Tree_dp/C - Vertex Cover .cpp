#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>graph[100005];
ll dp[100005][5];
int vis[100005];


void fun(int src)
{

    //getchar();
    if(vis[src] == 1) return ;
 //cout<<"src = "<<src<<endl;
    vis[src] = 1;
    dp[src][0] = 0;
    dp[src][1] = 1;
    for(int i=0;i<graph[src].size();i++)
    {
        int x = graph[src][i];
         if(vis[x] == 1) continue;
        fun(x);
        dp[src][0]+=dp[x][1];
//        cout<<"par = "<<src<<" chile = "<<x<<endl;
//        cout<<"val = "<<dp[x][0]<<" "<<dp[x][1]<<endl;
        dp[src][1]+=min(dp[x][0],dp[x][1]);
    }
}
int main()
{

    memset(dp,0,sizeof(dp));

    int n;
    cin>>n;

    int u,v;
    n--;
    while(n--)
    {
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);


    }
    fun(1);

  //  cout<<dp[1][0]<<" "<<dp[1][1]<<endl;
    ll ans = min(dp[1][0],dp[1][1]);

    cout<<ans<<endl;

    return 0;

}
