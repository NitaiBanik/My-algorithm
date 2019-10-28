#include<bits/stdc++.h>
using namespace std;
long long a[105],n,start,endd,maxleft,maxright,mx;
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
    int t;
    scanf("%d",&t);
    while(t--)
    {

        cin>>n;
        long long int ans =0,left,right;
        for(long long i=1; i<=n; i++)
            for(long long j=1; j<=n; j++)
                mat[i][j] = 1;
        int how;
        scanf("%d",&how);
        while(how --)
        {
            int r1,r2,c1,c2;
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            for(int i=r1; i<=r2; i++)
                for(int j=c1; j<=c2; j++)
                    mat[i][j] = -99999999;
        }
        mx = 0;
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
        cout<<ans<<endl;
        // cout<<"left = "<<left<<" right = "<<right<<" up = "<<maxleft<<" down = "<<maxright<<endl;
    }

    return 0;
}
