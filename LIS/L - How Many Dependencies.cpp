#include<bits/stdc++.h>
using namespace std;
vector<int>vec[105];
int dp[105];
int fun(int p)
{
    if(vec[p].size() == 0)
        return dp[p] = 0;
    if(dp[p]!=-1)
        return dp[p];
    int ret = 0;
    for(int k=0; k<vec[p].size(); k++)
    {
        ret = max(ret, 1 + fun(vec[p][k]));
    }
    return dp[p] = ret;
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n!=0)
    {
        for(int i=1; i<=n; i++)
        {
            int node;
            scanf("%d",&node);
            for(int j=1; j<=node; j++)
            {
                int x;
                scanf("%d",&x);
                vec[i].push_back(x);
            }
        }
        memset(dp,-1,sizeof(dp));
        int mx = 0,store = 1;
        for(int i=1; i<=n; i++)
        {
            int res = fun(i);
            if(res>mx)
            {
                mx = res;
                store = i;
            }
        }
        printf("%d\n",store);
        for(int i=1; i<=n; i++)
            vec[i].clear();
    }

    return 0;
}
