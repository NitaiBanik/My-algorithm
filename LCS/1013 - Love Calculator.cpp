#include<bits/stdc++.h>
using namespace std;

#define ll long long

string a,b;
ll ln1,ln2,lcs;
ll dp[32][32];
ll dp1[32][32][70];
ll ans1;
ll LCS(ll i, ll j)
{
    if(i == ln1 || j == ln2)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret = 0;

    if(a[i] == b[j])
        ret = max(ret,1 + LCS(i + 1, j + 1));

    ret = max(ret,LCS(i, j + 1));
    ret = max(ret,LCS(i + 1, j));

    return dp[i][j] = ret;

}
//string add;
//bool vis1[33];
//bool vis2[33];
//void path(int i, int j)
//{
//    if(i == ln1 || j == ln2)
//        return ;
//    int val = LCS(i,j);
//    if(a[i] == b[j] && 1 + LCS(i + 1,j + 1) == val)
//    {
//        add+=a[i];
//        vis1[i] = true;
//        vis2[j] = true;
//        path(i + 1, j + 1);
//    }
//    else if(LCS(i + 1,j)>LCS(i,j + 1))
//        path(i + 1, j);
//    else
//        path(i, j + 1);
//}

ll fun1(int i, int j,int sz)
{


    if(i == ln1 ||j == ln2)
    {
        if(i == ln1)
        {
            if(sz + ln2 - j == ans1)
                return 1;
            else
                return 0;
        }
        if(j == ln2)
        {
            if(sz + ln1 - i == ans1)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }

    if(dp1[i][j][sz]!=-1)
        return dp1[i][j][sz];

    ll ret1 = 0;

    if(i!=ln1 && j!=ln2 && a[i] == b[j])
        ret1 +=fun1(i+1,j + 1,sz + 1);
    else
    {
        if(i!=ln1)
            ret1 +=fun1(i+1,j,sz + 1);

        if( j!= ln2)
            ret1 +=fun1(i,j + 1,sz + 1);
    }
    // cout<<"ret1= "<<ret1<<endl;
    return dp1[i][j][sz] = ret1;
}
int main()
{
    ll T,w = 0;
    scanf("%lld",&T);
    while(T--)
    {
        cin>>a>>b;
        ln1 = a.size();
        ln2 = b.size();

        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));

        lcs = LCS(0,0);
        ans1 = (ln1 + ln2) - lcs;
        ll ans2 = fun1(0,0,0);
        printf("Case %lld: %lld %lld\n",++w,ans1,ans2);

    }

    return 0;
}
