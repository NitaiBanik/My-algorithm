#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,WWE = 0,w[105],b[105],Xor;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&w[i]);
        Xor = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&b[i]);
            Xor^=(b[i] - w[i] - 1);
        }
        if(!Xor)
            printf("Case %d: black wins\n",++WWE);
        else
            printf("Case %d: white wins\n",++WWE);

    }
}
