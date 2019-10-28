#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull dp[55][55][2];

ull fun(int choto, int boro, int state)
{
//    getchar();
//    cout<<"choto = "<<choto<<" boro = "<<boro<<" state = "<<state<<endl;
    if(choto == 0 && boro == 0)
        return 1;
    if(state == 0 && choto <= 0)
        return 0;
    if(state == 1 && boro <= 0)
        return 0;


    ull &ret = dp[choto][boro][state];

    if(ret != -1)
        return ret;

    ret = 0;

    if(state == 1)
    {
        for(int i = 1; i <= boro; i++)
            ret+=fun(choto + (i - 1), boro - i, 0);
    }
    if(state == 0)
    {
        for(int i = 1; i <= choto; i++)
            ret+=fun(i-1, boro + (choto - i), 1);
    }
    return ret;
}
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(dp, -1, sizeof(dp));
        ull ans = 0;
        if(m == 1)
            ans = fun(1, n - 3, 0);
        else
            ans = fun(m - 1, n - m, 0);
        printf("Case %d: %llu\n",++w,max(ans,1ull));
    }
}
