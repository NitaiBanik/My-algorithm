#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans+=((n-i)*(i+1) - i );
        }
        cout<<ans<<endl;
    }
}
