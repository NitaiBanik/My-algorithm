#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1 << 16];

char arr[16][16];
ll normal[16];
int n;
ll fun(ll mask)
{

    if(mask == ((1<<n) -1))
        return 0;

    ll &ret = dp[mask];

    if(ret != -1)
        return ret;


    ret = 999999999999999;

    for(int i = 0; i < n; i++)
    {
        if((mask & (1<<i)) == 0)
        {
            ret = min(ret,normal[i] + fun(mask | (1 << i)));
            for(int j = 0; j < n; j++)
            {
                if((mask & (1<<j)))
                {
                    if((arr[j][i] - '0') != 0)
                    {
                        ll w = normal[i] / (arr[j][i] - '0');
                        if((normal[i] % (arr[j][i] - '0')) != 0)
                            w++;
                        ret = min(ret, w + fun(mask | (1 << i)));
                    }
                }
            }
            //
        }
    }
    return ret;
}

int main()
{
    int t,w = 0;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n;
        memset(dp, - 1, sizeof(dp));
        for(int i = 0; i<n; i++)
            scanf("%lld", &normal[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>arr[i][j];
        printf("Case %d: %lld\n",++w, fun(0));
    }
    return 0;
}
