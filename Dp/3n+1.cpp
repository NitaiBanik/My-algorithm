#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000005];
ll fun(ll n)
{
    // prllf("%d ")
    //maxx = max(maxx,n);
    if(n == 1) return 1;

    if(n<=1000000)
        if(dp[n]!=0) return dp[n];

    //prllf("%d=%d\n",i,n);
    ll res = 0;

    if(n%2 ==0)
        res =  1 + fun(n/2);
    else
        res =  1 + fun( (n * 3) + 1);

    if(n<=1000000)return dp[n] = res;
    else return res;
    //return dp[n] = res; =
    //return res;
}


int main()
{
    ll frm,to;
    //memset(dp,-1,sizeof(dp));
    for(ll i=1; i<= 1000000; i++)
    {
        ll x = fun(i);
        dp[i]=x;
        //cout<<"i ="<<i<<" val = "<<x<<endl;
        //mat[i][0] = i;
    }
    //cout<<"maxx = "<<maxx<<endl;
//    ll n = 1000000;
//    for(ll j = 1; (1<<j)<=n; j++)
//    {
//        for(ll i = 1; (i + (1<<j) - 1) <=n ; i++)
//        {
//            ll x = mat[i][j-1];
//            ll y = mat[i + (1<<(j-1))][j-1];
//            if(dp[x]>dp[y])
//                mat[i][j] = x;
//            else
//                mat[i][j] = y;
//        }
//    }

//    for(ll l = 1; l <= 1000000; l++)
//    {
//        ll cnt=1;
//        ll n = l;
//        while(n!=1)
//        {
//            cnt++;
//            if(n%2==0)
//                n=n/2;
//            else
//                n = (3*n)+1;
//            goto p;
//        }
//
//        cp[l]=cnt;
//    }
//    vector<ll>vv;
//    for(ll i=1; i<=10000; i++)
//    {
//        if(dp[i]!=cp[i]){
//            vv.push_back(i);
//        }
//        //printf("yes\n");
//    }
//
//    for(int i=0; i<vv.size(); i++){
//        ll u = vv[i];
//        printf("%lld %lld %lld\n",u,dp[u],cp[u]);
//    }

    while(scanf("%lld %lld",&frm,&to) == 2)
    {
        ll a = frm,b = to;
        ll ans=0;
        if(frm>to) swap(frm,to);
//        ll k = log2(to - frm + 1);
//        ll x = mat[frm][k];
//        ll y = mat[to - (1<<k) + 1][k];
//        ans = max(dp[x],dp[y]);
        for(ll i=frm; i<=to; i++)
        {
            ans = max(ans,dp[i]);
        }
        printf("%lld %lld %lld\n",a,b,ans);
    }
    return 0;

}
