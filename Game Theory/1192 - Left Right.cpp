#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,WWE = 0,w[205];
    scanf("%d",&t);
    while(t--)
    {
        int m,val,sum = 0,Xor = 0;
        scanf("%d",&n);

        for(int i = 0; i < 2*n; i++)
        {
            scanf("%d",&w[i]);
        }
        for(int i = 0; i < 2*n; i+=2)
        {
            Xor^=(w[i + 1] - w[i] - 1);
        }
        if(Xor != 0)
            printf("Case %d: Alice\n",++WWE);
        else
            printf("Case %d: Bob\n",++WWE);
    }
    return 0;
}
