#include<bits/stdc++.h>
using namespace std;

double dp[105];

int n;
double arr[103];

double fun(int pos)
{
    if(pos == n)
        return 0.0;


    double &ans = dp[pos];

    if(ans>=0.00000000)
        return ans;

    int baki = n - pos;

    if(baki>=6)
        baki = 6;
    double prov = 1.0 / (double)baki;
    ans = 0.0;

    for(int i = 1; i <= 6; i++)
    {
        int j = pos + i;
        if(j<=n)
            ans+=(prov * (arr[j] + fun(j)));
            ///expected value = probability * value;
            ///here I have calculated the probability for a position and then multiplied the values
            ///of the indexes where I can go from my current position;
    }
    return ans;

}

int main()
{
    int t,ww = 0;
    cin>>t;
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i<=n; i++)
            scanf("%lf", &arr[i]);
        memset(dp,-1.0,sizeof(dp));
        double w = fun(1);
        printf("Case %d: %.7f\n",++ww,arr[1]+w);
    }
}
