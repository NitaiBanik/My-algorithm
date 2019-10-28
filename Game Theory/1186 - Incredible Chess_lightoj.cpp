#include<bits/stdc++.h>
using namespace std;
int main()
{
    int val,t,n,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ck = 0,x;
        int XXor = 0;
        for(int i = 1; i<=n ;i++)
        {
            scanf("%d",&x);
            XXor^=x;
            if(x>1) ck = 1;
        }
        if(ck == 1)
        {
            if(XXor!=0)
                printf("Case %d: Alice\n",++w);
            else
                printf("Case %d: Bob\n",++w);
        }
        else
        {
            if(n%2 == 0)
                printf("Case %d: Alice\n",++w);
            else
                printf("Case %d: Bob\n",++w);
        }
    }
}
