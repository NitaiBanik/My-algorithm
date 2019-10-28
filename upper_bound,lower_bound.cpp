#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>sum1,sum2;
ll lower(ll n,ll val)
{
    ll beg = 0,endd = n-1,mid,loc = -1;
    while(beg<=endd)
    {
        mid = (beg + endd)/2;
        if(sum2[mid] == val)
        {
            endd = mid -1 ;
            loc = mid;
        }
        else if(val>sum2[mid])
            beg = mid +1 ;
        else
            endd = mid-1 ;
    }
    if(loc!=-1)
        return beg;
    else
        return -1;
}
ll upper(ll n,ll val)
{
    ll beg = 0,endd = n-1,mid,loc = -1;
    while(beg<=endd)
    {
        mid = (beg + endd)/2;
        if(sum2[mid] == val)
        {
            beg = mid + 1 ;
            loc = mid;
        }
        else if(val>sum2[mid])
            beg = mid + 1 ;
        else
            endd = mid - 1;
    }
    if(loc!=-1)
        return endd;
    else
        return -1;
}
int main()
{
    for(int i=0; i<5; i++)
    {
        int x;
        cin>>x;
        sum2.push_back(x);
    }
    sort(sum2.begin(),sum2.end());
//

    ll l  = lower(5,5) + 1;
    cout<<l;
    ll u  = upper(5,5) + 1;
    cout<<u;
    //cout<<" l = "<<l<<" u = "<<u<<endl;

}
