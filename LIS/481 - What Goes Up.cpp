#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 9999999999
ll I[1000005];
ll L[1000005];
ll sequence[1000005],n;

ll LIS()
{
    //cout<<"enter"<<endl;
    I[0] = -inf;
    for(int i=1; i<=n; i++)
        I[i] = inf;

    ll length = 0;

    for(int i=0; i<n; i++)
    {
        ll low = 0,mid,hi = length;
        while(low<=hi)
        {
            mid = (low + hi)/2;
            if(I[mid]<sequence[i])
                low = mid + 1;
            else hi = mid - 1;
        }
        I[low] = sequence[i];
        L[i] = low;
        if(length<low)
            length = low;
        //cout<<"pos = "<<i<<"length  = "<<length<<endl;

    }
    return length;
}

int main()
{
    ll val;
    while(scanf("%lld",&val) == 1)
    {
        sequence[n++] = val;
    }
    ll ans = LIS();
    cout<<ans<<endl;
    vector<ll>vec;

    for(int i=n-1; i>=0; i--)
    {
        if(L[i] == ans)
        {
            // cout<<"haha"<<endl;
            ans--;
            vec.push_back(sequence[i]);
        }
    }
    //cout<<"haha"<<endl;
    reverse(vec.begin(),vec.end());
    cout<<"-"<<endl;
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<< " ";
    vec.clear();


return 0;
}
