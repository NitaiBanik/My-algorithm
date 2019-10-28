#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int sum[100][100];
int main()
{

    int i,j,row,col;
    cin>>row>>col;
    for(i=1; i<=row; i++)
        for(j=1; j<=col; j++)
        {
            cin>>a[i][j];
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]+a[i][j];
        }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
       int ans = sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
       cout<<ans<<endl;
    }
}
