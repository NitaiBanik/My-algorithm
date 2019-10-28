#include<bits/stdc++.h>
using namespace std;
long long dp[1002][2];
int arr[1002],n;
long long f(int pos, int ck)
{
    //cout<<pos<<" "<<lf<<" "<<rt<<endl;
    if(pos >= n)
        return 0;

    if(pos == (n - 1))
    {
        if(ck == 0)
            return arr[pos];

        else
            return 0;
    }

    long long &ret = dp[pos][ck];
    if(ret != -1)
        return ret;
    ret = 0;

    if(pos == 0)
    {
        ret = max(ret, f(pos + 2, 1) + arr[pos]);
        ret = max(ret, f(pos + 1, 0));
    }
    else
    {
        ret = max(ret, f(pos + 2, ck) +arr[pos]);
        ret = max(ret, f(pos + 1, ck));
    }

    return ret;
}
int main()
{
    int t,w = 0;
    scanf("%d", &t);

    while(t--)
    {
        set<int>st;
        map<int,int>mp;

        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);

        }


        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",++w, f(0,0));
    }
    return 0;

}
