#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
string a,b;
int ln1,ln2;
int lcs(int i,int j)
{
    if(i == ln1 || j == ln2)
     return abs(i-ln1) + abs(j - ln2);
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret1 = 9999999,ret2 = 9999999,ret3 = 9999999,ret4 = 999999;

    if(a[i] == b[j])
      ret1 =  min(ret1,lcs(i+1,j+1));
      else
      ret4 =  min(ret1,1 + lcs(i+1,j+1));

    ret2 = 1 + lcs(i + 1,j); ///delete
    ret3 = 1 + lcs(i,j+1); ///insert;
//cout<<"ret1 = "<<ret1<<"ret2 = "<<ret2<<" ret3 = "<<ret3<<endl;
    return dp[i][j] = min(ret4,min(ret1,min(ret2, ret3)));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ln1 = a.size(),ln2 = b.size();
        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        cout<<ans<<endl;
    }
}
