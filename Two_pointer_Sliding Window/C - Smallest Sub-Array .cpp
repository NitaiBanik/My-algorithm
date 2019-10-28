#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s[1000005];

int main()
{
    ll m,n,k,t,w=0;
    scanf("%lld",&t);

    while(t--)
    {
        ll arr[105] = {0};
        scanf("%lld %lld %lld",&n,&m,&k);

        s[1] = 1;
        s[2] = 2;
        s[3] = 3;

        for(int i=4;i<=n;i++)
            s[i] = (s[i-1] + s[i-2] + s[i-3]) % m + 1;

            ll frm=0,cnt = 0;

            ll mx = 99999999999;
        for(int i=1; i<=n; i++)
        {
            //cout<<s[i]<<" ";
            if(s[i]<=k && arr[s[i]] == 0)
            {
                cnt++;
            }

            if(s[i]<=k)
            arr[s[i]]++;

            if(cnt == k){
                mx = min(mx,i - frm + 1);
                while(cnt == k)
                {
                    ll x = s[frm];
                    if(x>k)
                    {
                        frm++;
                    }
                    else
                    {
                        arr[x]--;
                        if(arr[x] == 0)
                        {
                              mx = min(mx,i-frm+1);
                            cnt--;
                            frm++;
                        }
                        else
                        {
                            mx = min(mx,i-frm+1);
                            frm++;
                        }

                    }
                }
            }

            if(cnt>k)
            {
                while(cnt>k)
                {
                    if(s[frm]<=k){
                    arr[s[frm]]--;
                    if(arr[s[frm]] == 0)
                        cnt--;
                    }
                    frm++;
                }
                mx = min(mx,i - frm + 1);
            }
        }

        if(mx == 99999999999)
            printf("Case %lld: sequence nai\n",++w);

            else
        printf("Case %lld: %lld\n",++w,mx);

    }
    return 0;
}
