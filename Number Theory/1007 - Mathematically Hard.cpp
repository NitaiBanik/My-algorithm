#include<bits/stdc++.h>
using namespace std;
#define mx 5000003
#define ll unsigned long long

bool check[mx + 5];
ll phi[mx + 5];

void  totientPhi()
{
    memset(check,true,sizeof(check));

    phi[2] = 1;
    phi[1] = 1;
    for(int i=3; i<=mx; i++) phi[i] = i;
    for(int i=4; i<=mx; i+=2)
    {
        phi[i] = i/2;
        check[i] = false;
    }

    for(int i=3; i<=mx; i+=2)
    {
        if(check[i] == true)
        {
            phi[i] = i - 1;
            for(int j= i + i; j<=mx; j+=i)
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
    ll t,w = 0;
    phi[1] = 1;

    for(int i=2; i<=mx; i++)
        phi[i] = phi[i - 1] + (phi[i] * phi[i]);

    scanf("%d",&t);
    while(t--)
    {
        unsigned long long value1,value2;
        scanf("%llu %llu",&value1,&value2);
        unsigned long long ans = phi[value2] - phi[value1 - 1];
        printf("Case %d: %llu\n",++w,ans);
    }
    return 0;

}
