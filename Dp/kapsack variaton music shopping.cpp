#include<bits/stdc++.h>
using namespace std;
struct st
{
    int ai, pi, bi;
} arr[1005];

int full_price[1005];
int full_great[1005];
int how_much[1005];
int dp[1005][1005];

bool comp(st x, st y)
{
    return x.ai < y.ai;
}
int n,m,p;

int fun(int pos, int price)
{

    //cout<<"fun"<<endl;
    if(price < 0)
        return -999999999;
    if(pos == (n + 1))
        return 0;

        int &ret = dp[pos][price];

        if(ret != -1) return ret;

        ret = 0;

        ret = max(ret, fun(pos + 1, price));
        ret = max(ret, arr[pos].bi +fun(pos + 1, price - arr[pos].pi) );

        int album = arr[pos].ai;
        int sz = how_much[album];
        int next = pos + sz - 1;
        if(next<=n && arr[next].ai == album)
             ret = max(ret, full_great[album] + fun(pos + sz, price - full_price[album]));

        return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp) );
    memset(arr, 0, sizeof(arr) );
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &arr[i].ai, &arr[i].pi, &arr[i].bi);
        how_much[arr[i].ai]++;
        full_great[arr[i].ai]+= arr[i].bi;

    }

    sort(arr + 1, arr + n + 1, comp);

    for(int i = 1; i <= m; i++)
        scanf("%d",&full_price[i]);

    int ans = fun(1,p);
    cout<<ans<<endl;

}
