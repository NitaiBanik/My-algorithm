#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1005][1005];
int ln1,ln2;
int fun(int i, int j)
{
    if(i == ln1 || j == ln2)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ret1 = 0;
    if(a[i] == b[j]) ret1 = max(ret1,1+fun(i+1,j+1));
    else
    {
        ret1 = max(ret1,fun(i,j+1));
        ret1 = max(ret1,fun(i+1,j));
    }
    return dp[i][j] = ret1;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getline(cin,b);
        a = b;
        ln1 = a.size();
        ln2 = ln1;
        reverse(b.begin(),b.end());
        memset(dp,-1,sizeof(dp));
        int ans = fun(0,0);
        printf("%d\n",ans);
        a.clear();
        b.clear();
    }
    return 0;
}
