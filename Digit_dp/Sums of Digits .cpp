#include<bits/stdc++.h>
using namespace std;
int sum;
int sz = 600;
string arr,brr,print;
int dp[603][303][2];
int fun(int pos,int boro,int sum)
{

    if(pos == 600)
    {
        //cout<<"yoy"<<endl;
        if(boro == 1 && sum == 0)
            return 1;
        else
            return 0;
    }

    int &ret = dp[pos][sum][boro];
    if(ret != -1)
        return ret;
    int lo = 0, hi = 9;

    if(boro == 0)
        lo = arr[pos] - '0';
    ret = 0;
    for(int i = lo; i <= 9; i++)
    {
        if((sum-i)>=0)
        {
            ret|=fun(pos + 1, boro | (i > lo),sum-i);

        }
    }
    return ret;
}

void path(int pos,int boro, int sum)
{
    // cout<<"yoy"<<endl;
    if(pos == 600)
        return;
    int lo = 0, hi = 9;

    if(boro == 0)
        lo = arr[pos] - '0';
    int ret = 0;
    for(int i = lo; i <= 9; i++)
    {
        int w = fun(pos + 1,boro | (i > lo),sum-i);
        if((sum-i)>=0 && (w == 1))
        {
            print+=(char)(i +'0');
            path(pos + 1,boro | (i > lo),sum-i);
            break;

        }
    }
}
int main()
{
    for(int i = 0; i<=599; i++)
        arr+='0',brr+='9';

    int t;
    cin>>t;

    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d", &sum);
        print = "";
        int k = fun(0,0,sum);
        //cout<<k<<endl;
        path(0,0,sum);
        int ck = 0;
        for(int i = 0; i < 600; i++)
        {
            if(print[i] != '0')
                ck = 1;
            if(ck)
                cout<<print[i];
        }
        //  cout<<arr.size()<<endl<<print.size()<<endl;
        //cout<<print<<endl;
        arr = print;
        cout<<endl;

    }

    return 0;
}
