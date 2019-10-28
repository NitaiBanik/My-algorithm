#include<bits/stdc++.h>
using namespace std;
long long a[105],n,start,endd,maxleft,maxright,mx = 0;
long long mat[105][105];
long long kadane()
{
    long long sum = 0,left =1;
    for(long long i = 1; i<=n; i++)
    {
        sum+=a[i];
        if(sum<=0)
        {
            sum = 0;
            left = i + 1;

        }
        if(sum>=mx)
        {
            maxleft = left;
            maxright = i;
            mx = sum;
        }
    }
    return mx;
}

int main()
{
    cin>>n;
    long long int ans =0,left,right;
    for(long long i=1; i<=n; i++)
        for(long long j=1; j<=n; j++)
            cin>>mat[i][j];
    for(long long int i=1; i<=n; i++)
    {
        memset(a,0,sizeof(a));
        for(long long j=i; j<=n; j++)
        {
            for(long long k=1; k<=n; k++)
            {
                a[k]+=mat[k][j];

            }
            long long k = kadane();
            if(k>=ans)
            {
                ans = k;
                left = i;
                right = j;
            }
        }
    }
    cout<<"ans = "<<ans<<endl;
    cout<<"left = "<<left<<" right = "<<right<<" up = "<<maxleft<<" down = "<<maxright<<endl;

    return 0;
}
