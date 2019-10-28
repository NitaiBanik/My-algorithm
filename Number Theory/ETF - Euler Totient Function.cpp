#include<bits/stdc++.h>
using namespace std;
#define mx 10000003
#define ll long long

bool check[mx + 5];
ll phi[mx + 5];

void  totientPhi()
{
    memset(check,true,sizeof(check));

    phi[2] = 1;
    phi[1] = 1;
    for(ll i=3; i<=mx; i++)
        phi[i] = i;
    for(ll i=4; i<=mx; i+=2)
    {
        phi[i] = i/2;
        check[i] = false;
    }

    for(ll i=3; i<=mx; i+=2)
    {
        if(check[i] == true)
        {
            phi[i] = i - 1;
            for(ll j= i * i; j<=mx; j+=2*i)
            {
                phi[j]-=(phi[j]/i);
                check[j] = false;
            }
        }
    }

}

int main()
{
    totientPhi();
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll value;
        scanf("%lld",&value);
        phi[1] = 0;
        printf("%lld\n",phi[value]);
        ///   prllf("Co-prime with %d is  = %d numbers\n",value,phi[value]);
    }
    return 0;

}
