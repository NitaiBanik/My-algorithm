#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1005];
int dp[1005][2];

int vis[1005];

void dfs(int node)
{
    vis[node] = 1;

    dp[node][0] = 0;
    dp[node][1] = 1;
    for(int i = 0; i < graph[node].size(); i++)
    {
        int k = graph[node][i];

        if(vis[k]  == 0)
        {
            vis[k] = 1;
            dfs(k);
            dp[node][1]+=dp[k][0];
            dp[node][0]+=max(dp[k][0], dp[k][1]);

        }
    }

}
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d %d", &n, &k);
        while(k--)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        memset(vis,0,sizeof vis);
        int sum = 0;
        for(int i = 1; i<= n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);

                int xx = dp[i][0],yy = dp[i][1];
                sum+=max(xx,yy);
            }
        }

        printf("Case %d: %d\n",++w,sum);
        for(int i = 1; i<=n; i++)
            graph[i].clear();
    }
}
