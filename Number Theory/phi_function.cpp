#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    int res = n;
    int sq = sqrt(n);
    for(int i=2;i<=sq;i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
                n/=i;
            res-=(res/i);
        }
    }
    if(res!=n && n!=1) res-=(res/n);
    else res-=1;
    printf("Number of co-prime  = %d\n",res);
    main();
}
