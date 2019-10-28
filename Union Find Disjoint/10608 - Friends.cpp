#include<bits/stdc++.h>
using namespace std;
long long par[30000+5];
long long findd(long long a)
{
    if(par[a] == a) return a;
    else return findd(par[a]);
}
int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {

        long long mx = 1;
        long long n,e;

        scanf("%lld %lld",&n,&e);
        long long cn[n+5] ;
        for(long long i =1; i<=n; i++)
        {
            par[i] = i;
            cn[i] = 1;
        }
        for(long long i = 0; i<e; i++)
        {
            long long f,s;
            scanf("%lld %lld",&f,&s);
            long long o = findd(f);
            long long p = findd(s);
            if(o!=p)
            {
                if(cn[o]>cn[p])
                {
                    par[p] = o;
                    cn[o]+=cn[p];
                    mx = max(mx,cn[o]);
                }
                else
                {
                    par[o] = p;
                    cn[p]+=cn[o];
                    mx = max(mx,cn[p]);
                }
            }

        }
        printf("%lld\n",mx);
    }
    return 0;
}
