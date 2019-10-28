#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx1 = 0,mx2 = 0;

    while(n--)
    {
        char c;
        int x,y;
        getchar();
        scanf("%c %d %d",&c,&x,&y);

        if(x>y)
            swap(x,y);

        if(c == '?')
        {
         if(x>=mx1 && y>=mx2)
           printf("YES\n");
         else  printf("NO\n");
        }
        else
        {
            mx1 = max(mx1,x);
            mx2 = max(mx2,y);
        }
    }
}
