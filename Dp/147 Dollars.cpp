#include<bits/stdc++.h>
using namespace std;
//float arr[] = {.05,.10,.20,.50,1.0,2.0,5.0,10.0,20.0,50.0,100.0};
long long arr[] = {2,4,8,20,40,80,200,400,800,2000,4000};
long long dp[15][1200005];
long long fun(long long pos,long long am)
{
    if(pos ==11)
    {
        if(am == 0)
            return 1;
        else
            return 0;
    }
//    if(am == 0) return 1;
//    if(am < 0) return 0;
    if(dp[pos][am]!=-1)
        return dp[pos][am];

    long long res1 = 0,res2 = 0;

    if((am-arr[pos])>=0)
        res1 = fun(pos,am - arr[pos]);

    res2 = fun(pos+1,am);
//    getchar();
//   cout<<"am = "<<am<<"pos = "<<pos<<" "<<"res1 = "<<res1<<"res1 = "<<res2<<endl;
    return dp[pos][am] = res1 + res2;
}

int main()
{

    double val;
    long long v;
      memset(dp,-1,sizeof(dp));
    while(scanf("%lf",&val))
    {
        if(val == 0) break;

        v = (long long)(val * 40.0);///I hv chosen 5c(.005$) as 2 so(2/.0050 = 40 .If i use .005 as 1 then it is impossible to check modulo by 1.
        //printf("%lld\n",v);
        // cout<<"v = "<<v<<endl;
        if(v%2!=0) v+=2;
       // cout<<"v = "<<v<<endl;
        long long ans = fun(0,v);
        printf("%6.2lf%17lld\n",val,ans);
    }
}
