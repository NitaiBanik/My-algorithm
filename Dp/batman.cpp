#include<bits/stdc++.h>
using namespace std;
int ln1,ln2,ln3;
string a1,a2,a3;
int dp[55][55][55];
int lcs(int i,int j, int k)
{
    if(i == ln1 || j == ln2 || k == ln3)
        return 0;
    int &ret = dp[i][j][k];
    if(ret !=-1)
        return dp[i][j][k];
    ret = 0;
    if(a1[i] == a2[j] && a3[k] == a1[i])
        ret = max(ret,1 + lcs(i+1,j+1, k + 1));

    ret = max(ret,lcs(i+1,j,k));
    ret = max(ret,lcs(i,j+1,k));
    ret = max(ret,lcs(i,j,k+1));

    return ret;
}

int main()
{
    int w = 0,t;
    cin>>t;
    while(t--)
    {
        cin>>a1>>a2>>a3;

        ln1 = a1.size();
        ln2 = a2.size();
        ln3 = a3.size();
        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0,0);
        printf("Case %d: %d\n",++w,ans);
    }
}
