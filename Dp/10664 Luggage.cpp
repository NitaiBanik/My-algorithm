#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[22][202];
ll vec[22];
ll n;

ll fun(ll pos, ll sum)
{
    if(sum == 0) return 1;
    if(sum<0) return 0;
    if(pos == n)
    {
        if(sum == 0) return 1;
        else return 0;

    }
    if(dp[pos][sum] !=-1) return dp[pos][sum];

    ll ret1 = 0,ret2 = 0;

    ret1 = fun(pos+1,sum-vec[pos]);
    ret2 = fun(pos+1,sum);

    return dp[pos][sum] = ret1|ret2;
}
int main()
{
    int t;
    string line;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,line);
        ll sum =0;
        n = 0;
        ll val;
        stringstream ss(line);
        while(ss>>val)
        {
            vec[n] = val;
            n++;
            sum+=val;
        }

        if(sum%2!=0 || n == 1)
            cout<<"NO"<<endl;

        else
        {
            sum/=2;
            memset(dp,-1,sizeof(dp));
            ll ans = fun(0,sum);
            if(ans == 1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
