#include<bits/stdc++.h>
using namespace std;
long long dp[102][102][102];
int arr[102],n;
long long f(int pos, int lf, int rt)
{
    //cout<<pos<<" "<<lf<<" "<<rt<<endl;
    if(pos == n)
        return 0;

    long long &ret = dp[pos][lf][rt];

    if(ret != -1)
        return ret;

    ret = 0;

    if(arr[pos] >= lf && arr[pos]<= rt ){
        ret = max(ret, 1 + f(pos + 1, arr[pos], rt));
        ret = max(ret, 1 + f(pos + 1,lf, arr[pos]));
        }

    ret = max(ret,f(pos + 1,lf,rt));
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
            st.insert(arr[i]);
        }


        int id = 1;
        for( auto it  = st.begin(); it != st.end(); it++)
        {
            mp[*it] = id++;
            // cout<<"value = "<<*(it)<<endl;
        }

        for(int i = 0; i <n; i++)
        {
            arr[i] = mp[arr[i]];
           // cout<<arr[i]<<" ";
        }

        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",++w, f(0,0,n+1));
    }
    return 0;

}
