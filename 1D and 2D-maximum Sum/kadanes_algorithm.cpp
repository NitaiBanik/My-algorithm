#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int a[100],n,start,endd,maxleft,maxright,mx = 0;
int kadane()
{
    int sum = 0,left =1;
    for(int i = 1; i<=n; i++)
    {
        sum+=a[i];
        if(sum<=0)
        {
            sum = 0;
            left = i + 1;

        }
        if(sum>mx)
        {
            maxleft = left;
            maxright = i;
            mx = sum;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    kadane();
    cout<<"max = "<<mx<<" maxleft = "<<maxleft<<" maxright = "<<maxright<<endl;
}

