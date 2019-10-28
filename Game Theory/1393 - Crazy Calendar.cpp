#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, WWE = 0;

    cin>>t;
    while(t--)
    {
        int r,c,val,Xor = 0;
        scanf("%d %d",&r, &c);
        for(int i = 1; i<=r; i++)
            for(int j = 1; j<=c; j++)
            {
                scanf("%d",&val);
                if((r - i + c - j) % 2 == 1)
                Xor^=val;
            }
        if(!Xor)
            printf("Case %d: lose\n",++WWE);
        else
            printf("Case %d: win\n",++WWE);
        }
}
