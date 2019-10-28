#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll make[12][2][2];
ll dp[12][2][2][2];
char arr[12],brr[12];
int sz;

ll how_many(int pos, int choto, int boro)
{
    if(pos == sz)
        return 1;

    ll &res = make[pos][choto][boro];

    if(res !=-1 )
        return res;

    int lo = 0,hi = 9;

    if(choto == 0)hi = brr[pos] -'0';

    if(boro == 0)lo = arr[pos] -'0';

    res = 0;
    for(int i = lo; i <= hi; i++)
        res+=how_many(pos + 1,choto | (i < hi), boro | (i > lo));

    return make[pos][choto][boro] = res;
}

ll fun(int pos, int choto, int boro, int suru)
{
    if(pos == sz) return 0;

    ll &res = dp[pos][choto][boro][suru];

    if(res != -1) return res;

    int lo = 0,hi = 9;

    res = 0;

    if(choto == 0) hi = brr[pos] - '0';

    if(boro == 0) lo = arr[pos] - '0';

    for(int i = lo; i <= hi; i++)
    {
        ll cnt = 0;

        if(i == 0 && suru == 1)
            cnt = how_many(pos + 1, choto | (i < hi), boro | (i > lo));

        res+=fun(pos + 1, choto | (i < hi), boro | (i > lo), suru | (i > 0)) + cnt;
    }

    return dp[pos][choto][boro][suru] = res;
}
int main()
{
    int t,w = 0;
    scanf("%d", &t);

    while(t--)
    {
        memset(make,-1,sizeof(make));
        scanf("%s %s",arr,brr);
        ll add = strcmp(arr,"0");
        int ln1 = strlen(arr);
        int ln2 = strlen(brr);
        sz = max(ln1,ln2);

        if(ln1 > ln2)
        {
            int dif = ln1 - ln2;
            char temp[12];
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
            char temp[12];
            int id = 0;
            for(int i = 0 ; i < dif; i++)
                temp[i] = '0';

            temp[dif] = '\0';
            strcat(temp,arr);
            strcpy(arr,temp);
        }
//        printf("%s\n%s\n",arr,brr);
        // cout<<how_many(0,0,0)<<endl;

        memset(dp,-1,sizeof(dp));
        ll ans = fun(0,0,0,0);
        printf("Case %d: %lld\n",++w,ans + (add == 0LL));
    }
    return 0;
}
