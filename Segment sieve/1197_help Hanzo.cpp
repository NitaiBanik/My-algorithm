a#include<bits/stdc++.h>
using namespace std;
#define mx 400345
#define ll long long
vector<ll>prime;
bool a[400455];
bool b[1000006];
ll cnt[1000006];
void sieve()
{
    prime.push_back(2);
    for(ll i=4; i<=mx; i+=2)
        a[i] = 1;
    for(ll i=3; i<=mx; i++)
    {
        if(a[i] == 0)
        {
            prime.push_back(i);
            for(ll j = i * i ; j<=mx; j+=i)
                a[j] = 1;
        }
    }
}
int main()
{
    sieve();
    ll t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        ll frm,to;
        scanf("%lld %lld",&frm,&to);
        if(frm>to)
            swap(frm,to);
        memset(b,false,sizeof(b));
        ll ln = prime.size();
        ll cntt = 0;
        for(long long i=0; i<ln && prime[i]*prime[i]<=to; i++)
        {
            ll start = (frm/prime[i]) * prime[i];
            if(start<frm)
                start+=prime[i];
            if(start == prime[i])
                start+=prime[i];
            for(ll j = start; j<=to; j+=prime[i])
                b[j-frm] = true;

        }
        if(frm==1)
            b[0] = true;
        for(ll i=frm; i<=to; i++)
        {
            if(b[i-frm] == false)
            {
                // cout<<i<<endl;
                cntt++;
            }
        }
        printf("Case %lld: %lld\n",++w,cntt);
    }
}
