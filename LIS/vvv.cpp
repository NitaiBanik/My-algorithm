#include<bits/stdc++.h>
using namespace std;
vector<char>a,b;
int dp[1005][1005];
int ln1,ln2;
int fun(int i, int j)
{
    if(i == ln1 || j == ln2)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ret1 = 0;
    if(a[i] == b[j])
        ret1 = max(ret1,1+fun(i+1,j+1));
    else
    {
        ret1 = max(ret1,fun(i,j+1));
        ret1 = max(ret1,fun(i+1,j));
    }
    return dp[i][j] = ret1;
}
int main()
{
    int w = 0;
    string f,s;
    while(getline(cin,f))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<f.size(); i++)
        {
            a.push_back(f[i]);
        }


        getline(cin,s);
        for(int i=0; i<s.size(); i++)
        {
            b.push_back(s[i]);
        }

        stringstream sss(s);
        string so;


        ln1 = a.size();
        ln2 = b.size();

            int ans = fun(0,0);
            printf("%d\n",ans);

        a.clear();
        b.clear();
    }

    return 0;
}

