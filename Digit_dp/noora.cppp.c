#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[19][2][2][1026];
string arr;
int sz;
ll fun(int pos, int choto, int suru, int mask, int mx)
{

    if(pos < 0)
    {
        int need = __builtin_popcount(mask);
        if(suru==0) return 0;
        if(mx == need)
            return 1;
        else
            return 0;
    }

    ll &res = dp[pos][choto][suru][mask];

    if(res != -1 && choto)
        return res;
    int hi = 9;
    if(choto == 0)
        hi = arr[pos] - '0';

    res = 0;

    for(int i = 0; i<=hi; i++)
    {
        int new_mask = mask;
        if((i==0 && suru) || i>0)new_mask = mask |(1<<i);
        res+=fun(pos - 1, choto | (i < hi), suru | (i>0), new_mask,max(mx,i));
    }

    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin>>arr;
        reverse(arr.begin(), arr.end());
        ll ans = fun(arr.size()-1,0,0,0,0);
        printf("%lld\n",ans);
    }

    return 0;
}
