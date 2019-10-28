#include<bits/stdc++.h>
using namespace std;
vector<string>a,b;
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
    int w = 0;
    string f,s;
    while(getline(cin,f))
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<f.size(); i++)
        {
            if((f[i]>='a' && f[i]<='z') ||(f[i]>='A' && f[i]<='Z')|| (f[i]>='0' && f[i]<='9'))
                continue;
            else f[i] = ' ';
        }
        stringstream ss(f);
        string ff;
        while(ss>>ff)
            a.push_back(ff);

        getline(cin,s);
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')|| (s[i]>='0' && s[i]<='9'))
                continue;
            else s[i] = ' ' ;
        }

        stringstream sss(s);
        string so;

        while(sss>>so) b.push_back(so);

        ln1 = a.size();
        ln2 = b.size();
        if(ln1!=0 && ln2!=0){
        int ans = fun(0,0);
        printf("%2d. Length of longest match: %d\n",++w,ans);
        }
        else
            printf("%2d. Blank!\n",++w);
        a.clear();
        b.clear();
    }

    return 0;
}
