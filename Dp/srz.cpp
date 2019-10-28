#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int main()
{

    int t,n,k,s,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&k,&s);

        int dp_now[s + 5];
        int dp_prev[s + 5];

        memset(dp_now,0,sizeof(dp_now));
        memset(dp_prev,0,sizeof(dp_prev));
        dp_prev[0] = 1;

        for(int pos = 1; pos<=n; pos++)
        {
            for(int i = 1; i<=s; i++)
            {
                int z =  i - k - 1;
                if(z>=0)
                {
                    dp_now[i] = ((dp_now[i-1] + dp_prev[i-1])%mod - dp_prev[z])%mod;
                    if(dp_now[i]<0) dp_now[i] += mod;
                }
                else
                {
                    dp_now[i] = (dp_now[i-1] + dp_prev[i-1])%mod;
                }
            }
            for(int i = 0; i<=s; i++)
            {
                dp_prev[i] = dp_now[i];
                //printf("%d ",dp_now[i]);

            }
           // cout<<endl;

        }
        printf("Case %d: %d\n",++w,dp_now[s]);
    }
    return 0;
}
