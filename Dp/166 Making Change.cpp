#include<bits/stdc++.h>
using namespace std;
//float arr[] = {.05,.10,.20,.50,1.0,2.0,5.0,10.0,20.0,50.0,100.0};
#define ll long long
ll arr[] = {2,4,8,20,40,80};
ll val[8];
ll dp[8][1005];
ll dp2[8][1005];
ll v,mx = 0;
ll fun1(ll pos,ll am)
{
    if(am ==0) return 0;
    if(pos == 6)
    {
        return 9999999999999;
    }
    if(dp2[pos][am]!=-1)
        return dp2[pos][am];

    ll res1 = 9999999999999,res2 = 9999999999999;

    if(am-arr[pos]>=0 )
    {

        res1 = 1 + fun1(pos,am - arr[pos]);
    }

    res2 = fun1(pos+1,am);
    return dp2[pos][am] = min(res1,res2);
}

ll fun(ll pos1,ll sum1)
{
    //cout<<"pos = "<<pos1<<endl;
    if(sum1>=v)
    {
        // if(sum1-v<=800)
        return fun1(0,sum1-v);
//        else
//            return 999999999;
    }

    if(pos1 == 6)
    {
        return 9999999999999;
    }

    if(dp[pos1][sum1]!=-1)
        return dp[pos1][sum1];

    ll res11 = 9999999999999,res21=9999999999999;

    for(int j=1; j<=val[pos1]; j++)
        res11 = min(res11,j+fun(pos1+1,sum1 + arr[pos1] * j));

    res21 = fun(pos1+1,sum1);

    //cout<<res11<<" "<<res21<<endl;

    return dp[pos1][sum1] = min(res11, res21);
}

int main()
{

    memset(dp2,-1,sizeof(dp2));
    for(int i=2; i<=800; i+=2)
        ll kkk = fun1(0,i);
    double vall;
    while(scanf("%lld %lld %lld %lld %lld %lld",&val[0],&val[1],&val[2],&val[3],&val[4],&val[5]) == 6)
    {
      if(val[0] == 0 && val[1] == 0 && val[2] == 0 && val[3] == 0 && val[4] == 0 && val[5] == 0)
          break;
        scanf("%lf",&vall);
        memset(dp,-1,sizeof(dp));

        v = (ll)(vall * 40.0);///I hv chosen 5c(.005$) as 2 so(2/.0050 = 40 .If i use .005 as 1 then it is impossible to check modulo by 1.
        //prllf("%lld\n",v);
        // cout<<"v = "<<v<<endl;
        if(v%2!=0) v++;
        ll ans = fun(0,0);
        printf("%3lld\n",ans);
    }
}

