#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SQ(a) abs(a)*abs(a)
ll dp[5005][5005];
ll arr[5005],n,k;

ll fun(int pos, int koita)
{
    if(koita == 0)
        return 0;

    ll &ret = dp[pos][koita];

    if(ret != -1)
        return ret;

    ret = 9999999999999999;

    ret = min(ret, fun(pos + 2, koita - 1) + SQ(arr[pos + 1] - arr[pos]));
    int z = n-pos;

    if(z>(koita *3))
        ret = min(ret, fun(pos + 1, koita));

    return ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld", &k, &n);
        k+=8;
        for(int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        memset(dp, -1, sizeof dp);
       //  getchar();
        cout<<fun(0,k)<<endl;
      //  getchar();
       // getchar();
    }

    return 0;
}
