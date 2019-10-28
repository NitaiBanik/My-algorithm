#include<bits/stdc++.h>
using namespace std;
int arr[102][102];

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d",&arr[i][j]);
        int upr,lowr,lfc,rtc;
        int mx = -1000000;
        for(int i = 1; i <= n; i++)
        {
            int cum[n + 1] = {0};
            for(int col = i; col<= n; col++)
            {
                for(int row = 1; row <= n ; row++)
                    cum[row]+=arr[row][col];
                int sum = 0,str = 1;
                for(int row = 1; row <= n; row++)
                {
                    sum+=cum[row];
                    if(sum>mx)
                    {
                        mx = sum;
                        lfc = i,rtc = col;
                        upr = str,lowr = row;
                    }
                    if(sum < 0)
                    {
                        sum = 0;
                        str = row + 1;
                    }
                }
            }
        }
        cout<<upr<<" "<<lfc<<endl;
        cout<<lowr<<" "<<rtc;
        printf("%d\n",mx);
    }
    return 0;
}
