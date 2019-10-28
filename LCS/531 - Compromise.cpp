#include<bits/stdc++.h>
using namespace std;
vector<string>vec1,vec2,vec3;
int ln1,ln2,ans;
int dp[102][102];
int lcs(int i,int j)
{
    if(i== ln1 || j == ln2)
        return 0;
    int ret1 = 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(vec1[i] == vec2[j])
        ret1 =max(ret1,1+ lcs(i + 1,j+1));
    else
    {
        ret1 =max(ret1,lcs(i,j+1));
        ret1 =max(ret1,lcs(i + 1,j));
    }
    return dp[i][j] = ret1;

}
void path(int i, int j)
{
    if(i== ln1 || j == ln2)
        return ;
    int w = dp[i][j];
    if(vec1[i] == vec2[j] && 1 + lcs(i+1,j+1) == w)
    {
        vec3.push_back(vec1[i]);
        path(i+1,j+1);
    }
    else
    {
        if(w == lcs(i,j+1))
            path(i,j+1);
        else
            path(i+1,j);
    }
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s!="#")
        {
            vec1.push_back(s);
            while(cin>>s && s!="#")
            {
                vec1.push_back(s);
            }
        }
        while(cin>>s && s!="#")
        {
            vec2.push_back(s);
        }
        ln1 = vec1.size();
        ln2 = vec2.size();
        memset(dp,-1,sizeof(dp));
        ans = lcs(0,0);
        path(0,0);
        cout<<vec3[0];
        for(int i=1; i<vec3.size(); i++)
            cout<<" "<<vec3[i];
        cout<<endl;
        vec3.clear();
        vec2.clear();
        vec1.clear();
    }
}
