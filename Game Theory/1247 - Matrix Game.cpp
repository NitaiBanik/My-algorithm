#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,WWE = 0,w[105],b[105],Xor;
    scanf("%d",&t);
    while(t--)
    {
        int m,val,sum = 0,Xor = 0;
        scanf("%d %d",&n, &m);
        for(int i = 0; i < n; i++)
        {
            sum = 0;
            for(int j = 0; j < m; j++)
            {
                scanf("%d",&val);
                sum+=val;
            }

            Xor^=sum;
        }
//
        if(Xor != 0)
            printf("Case %d: Alice\n",++WWE);
        else
            printf("Case %d: Bob\n",++WWE);
    }
    return 0;
}
