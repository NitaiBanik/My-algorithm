#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100003

vector<ll>vec[mx * 4 + 5];
ll arr[mx + 5];
vector<ll>store;

void mrg(ll num, ll one, ll two)
{
    ll f = vec[one].size();
    ll s = vec[two].size();
    int p=0,q =0;
    while(f>p|| s>q)
    {
        if(p < f && q< s && vec[one][p]>vec[two][q])
        {
            vec[num].push_back(vec[two][q]);
            q++;
        }
        else if(p < f && q< s && vec[one][p]<vec[two][q])
        {
            vec[num].push_back(vec[one][p]);
            p++;
        }
        else if(p==f)
        {
            vec[num].push_back(vec[two][q]);
            q++;
        }
        else
        {
            vec[num].push_back(vec[one][p]);
            p++;
        }
    }
}

void init(ll node, ll b, ll e)
{
    if( b == e)
    {
        vec[node].push_back(arr[b]);
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e )/ 2;
    init(left,b,mid);
    init(right,mid+1,e);
    mrg(node, left,right);


}

void qu(ll node, ll b, ll e,ll i, ll j)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
        store.push_back(node);
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e )/ 2;
    qu(left,b,mid,i,j);
    qu(right,mid+1,e,i,j);
}

ll binary(ll th,ll ln)
{
    ll Beg = 0;
    ll End = ln - 1;
    ll ans,pos;
    while(Beg<=End)
    {
        ll cnt = 0;
        ll mid = (Beg + End) / 2;
        for(ll i=0;i<store.size();i++)
        {
            ll kk =  (upper_bound(vec[store[i]].begin(),vec[store[i]].end(),vec[1][mid]-1) - vec[store[i]].begin());
            //cout<<kk<<endl;
           // pos = (upper_bound(vec[store[i]].begin(),vec[store[i]].end(),vec[1][mid-1]) - vec[store[i]].begin());
            cnt+= kk;
        }
        if(cnt>=th)
        {
            End = mid-1;
        }
        else
        {
            ans = vec[1][mid];
            //cout<<ans<<endl;
            Beg = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ll sz,query;
    scanf("%lld %lld",&sz,&query);
    for(ll i=0; i<sz; i++)
        scanf("%lld",&arr[i]);
    init(1,0,sz-1);
//    for(int i=0; i<vec[1].size(); i++)
//        cout<<vec[1][i]<<" ";
    while(query--)
    {
        ll frm,to,tomo;
        scanf("%lld %lld %lld",&frm,&to,&tomo);
        store.clear();
        qu(1,0,sz-1,frm-1,to-1);
        ll val = binary(tomo,sz);
        printf("%lld\n",val);
    }

}
