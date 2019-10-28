#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 9999999999
ll I[100005];
ll L[100005];
ll sequence[100005],n;

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
    ll t,w = 0;
    scanf("%lld",&t);
    getchar();
    getchar();
    while(t--)
    {

        if(w>0)cout<<endl;
        w++;
        n = 0;
        string s;
        while(getline(cin,s))
        {

            if(s=="")
                break;
            stringstream ss(s);
            ll val;
            ss>>val;
            sequence[n++] = val;
        }
        ll ans = LIS();
        cout<<"Max hits: "<<ans<<endl;
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
        for(int i=0; i<vec.size(); i++) cout<<vec[i]<<endl;
        vec.clear();

    }

    return 0;
}
