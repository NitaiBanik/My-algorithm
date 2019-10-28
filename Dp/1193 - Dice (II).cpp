#include<bits/stdc++.h>
using namespace std;
#define mod 100000007

int main()
{

    int t,w = 0;
    scanf("%d",&t);

    while(t--)
    {
        long long n,k,s;

        scanf("%lld %lld %lld",&n,&k,&s);

        long long pre[s + 5];
        long long now[s + 5];
        long long cum[s + 5];

        memset(pre,0,sizeof(pre));
        memset(cum,0,sizeof(cum));
        memset(now,0,sizeof(now));

        for(int i=0; i<=s; i++)
        {
            if(i<=k)
            {
                pre[i] = i;
                now[i] = i;
            }

            else
            {
                pre[i] = 0;
                now[i] = 0;
            }

        }

        for(int i=1; i<=s; i++)
            cum[i] = cum[i - 1] + pre[i];
//            for(int i=0;i<=s;i++) cout<<cum[i]<<" ";
//            cout<<endl;
//              for(int i=0;i<=s;i++) cout<<pre[i]<<" ";
//            cout<<endl;
        if(n == 0 && s == 0) now[0] = 1;
        for(int pos = 2; pos<=n; pos++)
        {
            for(int i = 1; i<=s; i++)
            {
                if((i>(pos * k))||(pos>i))
                {
                    now[i] = 0;
                    //cout<<now[i]<<" ";
                    continue;
                }
                now[i] = now[i - 1];

                int z = i - k - 1;
                int x = i - 1;
                int y = i - k - 1;
                if(x<0) x = 0;
                if(z<0) z = 0;
                if(y<0) y = 0;
                //if(x>=0 && y>=0)
                now[i]+=(cum[x] - cum[y]);
                now[i]-=(pre[z] * k);
                now[i] %=mod;
                if(now[i]<0) now[i]+=mod;


            }
            //cout<<endl;
            for(int i=0; i<=s; i++)
                pre[i] = now[i];
            cum[0] = 0;
            for(int i=1; i<=s; i++)
                cum[i] = cum[i - 1] + pre[i];
        }
        printf("Case %d: %lld\n",++w,now[s]);
    }
    return 0;
}
