#include<bits/stdc++.h>
using namespace std;
int dp[205][205];
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
int cn,x;
void path(int i, int j)
{
    if(i == ln1 || j == ln2)
    {
        cout<<"E";
        return;
    }
    int ret1 = 9999999,ret2 = 9999999,ret3 = 9999999,ret4 = 999999;
    if(a[i] == b[j])
        ret1 =  min(ret1,lcs(i+1,j+1));
    else
        ret4 =  min(ret1,1 + lcs(i+1,j+1));

    ret2 = 1 + lcs(i + 1,j); ///delete
    ret3 = 1 + lcs(i,j+1); ///insert;
//cout<<"ret1 = "<<ret1<<"ret2 = "<<ret2<<" ret3 = "<<ret3<<endl;
    int comp = min(ret4,min(ret1,min(ret2, ret3)));
    if(i!=ln1 && j!=ln2 && ret1 == comp) path(i+1,j+1);

    else if(i!=ln1 && j!=ln2 && ret4 == comp)
    {
        cout<<"C"<<b[j];
        if(i+1<10) cout<<"0"<<i+1+cn;
        else cout<<i+1+cn;
        path(i + 1,j + 1);
    }
    else if(i!=ln1 && ret2 == comp)
    {
        cout<<"D"<<a[i];
        if(i+1+cn<10) cout<<"0"<<i+cn+1;
        else cout<<i+cn+1;
        cn--;
        path(i+1,j);
    }
    else if(j!=ln2)
    {

        cout<<"I"<<b[j];
        if(i+1+cn<10) cout<<"0"<<i+cn+1;
        else cout<<i+cn+1;
        cn++;
        path(i,j+1);
    }
    return;
}
int main()
{
    int t;
    while(cin>>a)
    {
        if(a == "#") break;
        cin>>b;
        ln1 = a.size(),ln2 = b.size();
        memset(dp,-1,sizeof(dp));
        x = lcs(0,0);
        cn = 0;
        cout<<x<<endl;
        path(0,0);
        cout<<endl;
    }
}
