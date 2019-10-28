#include<bits/stdc++.h>
using namespace std;
int ln1,ln2;
string a1,a2,add;
int dp[105][105];
vector<char>vec;
int lcs(int i,int j)
{
    if(i == ln1 || j == ln2)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret = 0;
    if(a1[i] == a2[j])
        ret = max(ret,1 + lcs(i+1,j+1));
    ret = max(ret,lcs(i+1,j));
    ret = max(ret,lcs(i,j+1));
    return dp[i][j] = ret;
}
void path(int i,int j)
{
    if(i == ln1 || j == ln2)
        return;
    int val = lcs(i,j);
    if(a1[i] == a2[j] && 1 + lcs(i+1,j+1) == val)
    {
        add+=a1[i];
        path(i+1,j+1);
    }
    else if(lcs(i+1,j)>lcs(i,j+1))
        path(i+1,j);
    else
        path(i,j+1);
    return ;
}
int main()
{
    while(getline(cin,a1)&& a1!="#")
    {
        getline(cin,a2);
        ln1 = a1.size();
        ln2 = a2.size();
        memset(dp,-1,sizeof(dp));
        int ans = lcs(0,0);
        printf("The size is %d\n",ans);
        path(0,0);
        cout<<add<<endl;
        add.clear();
    }
}
