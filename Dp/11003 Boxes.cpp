#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1005][6009],N;

struct node
{
    ll wt,cap;
}arr[1005];

ll fun(ll pos,ll nibo)
{
    if(pos == N) return 0;
   // cout<<"haha"<<endl;
    if(nibo<0) return 0;
   // if(pos == N && nibo<0) return 0;

    if(dp[pos][nibo]!=-1) return dp[pos][nibo];

    ll ret1 = 0,ret2 = 0;
    if(arr[pos].wt<=nibo)
    {
        ret1 = 1+fun(pos + 1,min(arr[pos].cap,nibo - arr[pos].wt));
    }
        ret2 = fun(pos + 1,nibo);

    return dp[pos][nibo] = max(ret1,ret2);
}
int main()
{
    while(scanf("%lld",&N) == 1 && N!=0)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%lld %lld",&arr[i].wt,&arr[i].cap);

        }
        memset(dp,-1,sizeof(dp));
        ll mx = fun(0,6009);

        printf("%lld\n",mx);


    }
    return 0;
}
