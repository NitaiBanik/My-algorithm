#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[20][2][2][2];

char arr[20],brr[20];
int sz,k;
string ss;
ll fun(int pos,int choto, int boro,int suru)
{
    if(pos == sz)
        return 1;
    ll &res = dp[pos][choto][boro][suru];

    if(res != -1)
        return res;

    int lo = 0, hi = 9,k = 1;

    if(choto == 0)
        hi = brr[pos] - '0';
    if(boro == 0)
        lo = arr[pos] - '0';

    res = 0;

    for(int i = lo; i<= hi; i++)
    {

        if(suru == 1 || i > 0)
            k = i;
        res = max(res,fun(pos + 1, choto |(i < hi),boro | (i > lo), suru | (i > 0)) * k);
    }
    return dp[pos][choto][boro][suru] = res;

}
void path(int pos,int choto, int boro,int suru)
{
    if(pos == sz)
        return;

    ll need = dp[pos][choto][boro][suru];
    int lo = 0, hi = 9,k = 1;

    if(choto == 0)
        hi = brr[pos] - '0';
    if(boro == 0)
        lo = arr[pos] - '0';

    for(int i = lo; i<= hi; i++)
    {

        if(suru == 1 || i > 0)
            k = i;
        ll now = fun(pos + 1, choto |(i < hi),boro | (i > lo), suru | (i > 0)) * k;
        if(need == now)
        {

            //cout<<"now = "<<now;
            //  cout<<" need = "<<need<<" i = "<<i<<" k = "<<k<<endl;
            ss+=char(i + '0');
            //  cout<<"ss = "<<ss<<endl;
            path(pos + 1, choto |(i < hi),boro | (i > lo), suru | (i > 0));
            break;
        }
    }

}
int main()
{
    scanf("%s %s",arr,brr);
    int ln1 = strlen(arr);
    int ln2 = strlen(brr);
    sz = max(ln1,ln2);

    if(ln1 > ln2)
    {
        int dif = ln1 - ln2;
        char temp[20];
        int id = 0;
        for(int i = 0 ; i < dif; i++)
            temp[i] = '0';
        temp[dif] = '\0';
        strcat(temp,brr);
        strcpy(brr,temp);
    }
    else
    {

        int dif = ln2 - ln1;
        char temp[20];
        int id = 0;
        for(int i = 0 ; i < dif; i++)
            temp[i] = '0';

        temp[dif] = '\0';
        strcat(temp,arr);
        strcpy(arr,temp);
    }

    memset(dp,-1,sizeof(dp));
    ll ans = fun(0,0,0,0);
    ss = "";
    path(0,0,0,0);
    //  printf("%lld\n",ans);
    int ck = 0;
    for(int i = 0; i < ss.size(); i++)
    {
        if(ss[i] > '0')
            ck = 1;
        if(ck)
            cout<<ss[i];
    }


    return 0;
}
