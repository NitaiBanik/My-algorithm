///D - Fast Bit Calculations
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[32][2][2][32];
string s;
int sz;
ll fun(int pos, int choto, int prev, int cnt)
{
    if(pos == sz)
        return cnt;
    ll &ret = dp[pos][choto][prev][cnt];

    if(ret != -1)
        return ret;

    int lo = 0, hi = 1;

    if(choto == 0)
        hi = s[pos] - '0';
ret = 0;
    for(int i = lo; i<= hi; i++)
    {
        if(prev == i && prev == 1)
            ret+=fun(pos + 1, choto | (i < hi), i, cnt + 1);
        else
            ret+=fun(pos + 1, choto | (i < hi), i, cnt);
    }
    return dp[pos][choto][prev][cnt] = ret;
}

int main()
{
    int t,w = 0;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);

        while(n != 0)
        {
            int k = n % 2;
            s+=char(k + '0');
            n/=2;
        }
        reverse(s.begin(), s.end());
        sz = s.size();
        //cout<<s<<endl;
        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0);
        s.clear();
        printf("Case %d: %lld\n",++w,ans);
    }

}
