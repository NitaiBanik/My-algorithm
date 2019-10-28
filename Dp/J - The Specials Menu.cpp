#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ln1,ln2;
string a1,a2,add;
ll dp[105][105][9];

ll lcs(int i,int j, int ckk)
{
    if(i == ln1 || j == ln2)
    {
        if(ckk == 1)
            return 1;
        else
            return 0;
    }

    if(dp[i][j][ckk]!=-1)
        return dp[i][j][ckk];

    ll ret = 0;

    if(a1[i] == a2[j])
    {

        ret += lcs(i+1,j+1, 1);

    }
    else
    {
        ret += lcs(i+1,j, ckk);
        ret += lcs(i,j+1, ckk);
        //ret -= lcs(i+1,j+1, ckk);
    }

    return dp[i][j][ckk] = ret;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        cin>>a1;
        a2 = a1;

        ln1 =a1.size();
        ln2 =a1.size();

        reverse(a2.begin(), a2.end());
        memset(dp,-1,sizeof(dp));
        ll ans = lcs(0,0,0);

        cout<<ans<<endl;

    }

    return 0;
}
