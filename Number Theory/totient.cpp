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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int value;
        scanf("%d",&value);
        printf("%d\n",phi[value]);
        ///   printf("Co-prime with %d is  = %d numbers\n",value,phi[value]);
    }
    return 0;

}
