#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f,mod = 10000007;
int dp[10008];
int fn( int n )
{
    if(dp[n]!=-1) return dp[n] % mod;
    else
    {
        dp[n] = (fn(n-1)  + fn(n-2) + fn(n-3)+ fn(n-4)+ fn(n-5) + fn(n-6) ) % mod;
        return dp[n];
    }
}
int main()
{

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
         memset(dp,-1,sizeof(dp));
         dp[0] = a % mod;
         dp[1] = b % mod;
         dp[2] = c% mod;
         dp[3] = d% mod;
         dp[4] = e% mod;
         dp[5] = f% mod;
        fn(n);
        printf("Case %d: %d\n", ++caseno, dp[n] % 10000007);
    }
    return 0;
}
