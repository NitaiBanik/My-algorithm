#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[8][120005];
int a[8];
ll make;
ll flag;

ll fun(ll pos, ll sum)
{
    if(flag == 1)
        return 1;
    else if(sum == make)
    {
        flag =1 ;
        return 1;
    }
    else if(sum>make) return 0;
    else if(pos == 6) return 0;
    if(dp[pos][sum]!=-1) return dp[pos][sum];
    ll ret = 0,ret2 = 0;
    if(a[pos]>0)
    for(int i=0;i<a[pos];i++)
    {
        ret = max(ret,fun(pos+1,sum+((pos+1)* (i + 1))));
    }
    ret2 = fun(pos + 1,sum);
    return dp[pos][sum] = ret|ret2;
}

int main()
{
    int w = 0;
    while(1)
    {
        for(int i=0;i<6;i++) scanf("%d",&a[i]);
        make = 0;
        for(int i=0;i<6;i++)
            make = make + (a[i] * (i + 1));
            //cout<<"make = "<<make<<endl;
        if(make == 0) break;
        if(make%2!=0)
            printf("Collection #%d:\nCan't be divided.\n\n",++w);
        else
        {
            flag = 0;
            memset(dp,-1,sizeof(dp));
            make/=2;
            //cout<<"make = "<<make<<endl;
            int k = fun(0,0);
            if(k == 1)
              printf("Collection #%d:\nCan be divided.\n\n",++w);
            else
                printf("Collection #%d:\nCan't be divided.\n\n",++w);

        }
    }
}
