#include<bits/stdc++.h>
using namespace std;
#define mx 10000003
#define ll long long

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

int main()
{

    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll a,m;
        scanf("%lld %lld",&a,&m);
        ll gc = __gcd(a,m);
        ll ak = m/gc;
        // phi[1] = 0;
        printf("%lld\n",phi(ak));
        ///   prllf("Co-prime with %d is  = %d numbers\n",value,phi[value]);
    }
    return 0;

}
