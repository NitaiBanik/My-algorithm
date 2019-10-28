#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cap,n;
ll cost[1005],weight[1005],profit1,profit2;
ll knap(ll i, ll w)
{
    if(i == n + 1) return 0;
    if(w+weight[i]<=cap)
        profit1 = cost[i] + knap(i+1,w+weight[i]);
    else
        profit1 = 0;
    profit2 = knap(i+1,w);
    return max(profit1,profit2);
}

int main()
{
    ll test;
    scanf("%lld",&test);
    while(test--)
    {
      //  int n;
        scanf("%lld",&n);
        for(ll i = 1; i<=n; i++)
            scanf("%lld %lld",&cost[i],&weight[i]);
        ll sum = 0,g;
        scanf("%lld",&g);
        while(g--)
        {
            scanf("%lld",&cap);
           // profit1 = 0,profit2 = 0;
            ll p = knap(1,0);
            cout<<"Knap = "<<p<<endl;
            sum+=p;
        }
       printf("%lld\n",sum);
    }
    return 0;
}
