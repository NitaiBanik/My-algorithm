#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod  1000000007

ll tree[4 * 100002];
ll arr[100005];
ll arr1[100005];
map<ll,ll>mp;

void update(ll node, ll b, ll e,  ll idx, ll val)
{
    if(b>idx || e<idx)
        return ;

    if(b == e && b == idx)
    {
        tree[node] = (tree[node] + val) % mod;
        // cout<<"node = "<<tree[node]<<endl;
        return ;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    update(left, b, mid, idx, val);
    update(right, mid + 1,e,  idx, val);
    tree[node] = tree[left] + tree[right];
}


ll query(ll node,ll b, ll e, ll x, ll y)
{
    if(b>y || e<x)
        return 0;
    if(b>=x && e<=y)
        return tree[node];
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;
    ll p = query(left, b, mid, x, y);
    ll q = query(right,mid + 1, e, x, y);
    return (p + q) % mod;

}
int main()
{

    int t,w = 0;

    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
            arr1[i] = arr[i];
        }

        sort(arr1+1,arr1+n+1);

        for(int i=1; i<=n; i++)
        {
            mp[arr1[i]] = i;
            //cout<<arr[i]<<" "<<i<<endl;
        }

        for(int i=1; i<=n; i++)
        {
            arr[i] = mp[arr[i]];
            //cout<<arr[i]<<" "<<i<<endl;
        }
        ll sum = 0;
        for(int i=1; i<=n; i++)
        {

            ll ans = query(1LL,1LL,n,1LL,arr[i]-1) % mod;
            sum+=ans+1;
            //cout<<"ans = "<<ans<<endl;
            sum%=mod;
            update(1LL,1LL,n,arr[i],ans+1);
        }
        printf("Case %d: %lld\n",++w,sum);
        memset(tree,0,sizeof(tree));
        mp.clear();
    }


    return 0;
}
