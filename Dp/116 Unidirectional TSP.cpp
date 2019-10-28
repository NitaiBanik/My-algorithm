#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[12][101];
ll dp[12][110];
ll row,col;

ll fun(int i, int j)
{
    if(i <0) return 9999999999;
    if(i == row) return 9999999999;
    if(j == col)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ret1 = 99999999999;
    ret1 = min(ret1,arr[i][j] + fun(i,j+1));
    if(i-1<0)
        ret1 = min(ret1,arr[i][j] + fun(row-1,j+1));
    else
        ret1 = min(ret1,arr[i][j] + fun(i-1,j+1));
    if(i+1 == row)
        ret1 = min(ret1,arr[i][j] + fun(0,j+1));
    else
        ret1 = min(ret1,arr[i][j] + fun(i+1,j+1));

    return dp[i][j] = ret1;
}

vector<ll>vec;
ll mn;

void path(int i, int j)
{
    if(i <0) return ;
    if(i == row) return ;
    if(j == col)
        return ;

    ll ans = dp[i][j];
    vec.push_back(i+1);
    ll ret1 = 99999999999;
    ll ret2 = 99999999999;
    ll ret3 = 99999999999;
    ll ret4 = 99999999999;
    ll ret5 = 99999999999;

    ret1 = min(ret1,arr[i][j] + fun(i,j+1));///
    if(i-1<0)
        ret2 = min(ret2,arr[i][j] + fun(row-1,j+1));
    else
        ret3 = min(ret3,arr[i][j] + fun(i-1,j+1));///
    if(i+1 == row)
        ret4 = min(ret4,arr[i][j] + fun(0,j+1));///
    else
        ret5 = min(ret5,arr[i][j] + fun(i+1,j+1));///

    if(ret4 == ans) path(0,j+1);
    else if(ret3 == ans) path(i-1,j+1);
    else if(ret1 == ans) path(i,j+1);
    else if(ret5 == ans) path(i+1,j+1);
    else path(row-1,j+1);
}
int main()
{
    while(scanf("%lld %lld",&row,&col) == 2)
    {
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                scanf("%lld",&arr[i][j]);
        mn = 9999999999;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<row; i++)
        {

            mn = min(mn,fun(i,0));
        }
        for(int i=0; i<row; i++)
        {
            if(dp[i][0] == mn)
            {
//                    vec.push_back(i+1);
//                    mn-=arr[i][0];
                path(i,0);
                break;
            }
        }
        cout<<vec[0];
        for(int i=1; i<vec.size(); i++)
            cout<<" "<<vec[i];
        cout<<endl<<mn<<endl;
        vec.clear();
    }

}
