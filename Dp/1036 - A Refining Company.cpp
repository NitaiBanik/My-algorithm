#include<bits/stdc++.h>
using namespace std;

int arr[502][502],n,m;
int brr[502][502];
int dp[502][502];

int fun(int r, int c)
{
    if(r == 0 || c == 0)
        return 0;

    int &ans = dp[r][c];

    if(ans != -1)
        return ans;
    ans = 0;
    ans = max(ans, arr[r][c] + fun(r-1,c));
    ans = max(ans, brr[r][c] + fun(r,c-1));
    return ans;

}

int main()
{
    int t,ww = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= m; j++)
            {
                scanf("%d",&arr[i][j]);
                arr[i][j]+=arr[i][j-1];
            }

        for(int i = 1; i<= n; i++)
            for(int j = 1; j<= m; j++)
            {
                scanf("%d",&brr[i][j]);
                brr[i][j]+=brr[i-1][j];
            }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++ww,fun(n,m));
    }
    return 0;
}
