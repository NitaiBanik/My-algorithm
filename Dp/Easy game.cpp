#include<bits/stdc++.h>
using namespace std;
///MCM checked all possible max from start and end alternatively
int dp[105][105];

int arr[105];

int fun(int i, int j)
{
    if(i>j)
        return 0;

    if(dp[i][j] !=-1)
        return dp[i][j];

    int mx = -9999999,sum = 0;
    for(int k = i; k<=j; k++)
    {
        sum+=arr[k];
        mx = max(mx,sum - fun(k + 1,j));
    }
    sum = 0;
    for(int k = j; k>=i; k--)
    {
        sum+=arr[k];
        mx = max(mx,sum - fun(i,k-1));
    }
    return dp[i][j] = mx;
}
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++w,fun(1,n));
    }
}
