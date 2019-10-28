#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>mp,fre;

ll arr[20005];
ll res[20005],n;

vector<ll>vec;

ll tree[20002 * 4];

#define sq 143
ll ans;

struct query
{
    ll l,r,id;
} Q[20005];

bool comp(query &a, query &b)
{
    ll block_a = a.l / sq, block_b = b.l / sq;

    if(block_a == block_b)
        return a.r < b.r;

    return block_a < block_b;
}

void update(ll node, ll b, ll e, ll idx, ll val)
{
    if(b > idx || e < idx)
        return;

    if(b == e && b == idx)
    {
        //cout<<idx<<endl;
        tree[node] += val;
        return;
    }

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = node * 2 + 1;

    update(left, b, mid, idx, val);
    update(right, mid + 1, e, idx, val);
    tree[node] = tree[left] + tree[right];

}

ll query(ll node, ll b, ll e, ll x, ll y)
{
    if(b > y || e < x)
        return 0;

    if(b >= x & e <= y)
    {
        return tree[node];
    }

    ll mid = (b + e) / 2;
    ll left = node * 2;
    ll right = node * 2 + 1;

    ll k1 = (ll)query(left, b, mid, x, y);
    ll k2 = (ll)query(right, mid + 1, e, x, y);

    return k1 + k2;

}

void Add(ll x)
{
    // cout<<"mp = "<< mp[arr[x]]<<" "<<"ans1 = "<<ans<<endl;

    ans+=query(1,1,n,mp[arr[x]] + 1, n);

    update(1,1,n,mp[arr[x]],1);
}

void Remove(ll x)
{

    ans-=query(1,1,n,mp[arr[x]] + 1, n);
    update(1,1,n,mp[arr[x]],-1);
}
void lAdd(ll x)
{
    // cout<<"mp = "<< mp[arr[x]]<<" "<<"ans1 = "<<ans<<endl;

   // ans+=query(1,1,n,mp[arr[x]] + 1, n);
    ans+=query(1,1,n,1,mp[arr[x]]- 1);

    update(1,1,n,mp[arr[x]],1);
}

void lRemove(ll x)
{
    //cout<<"rmv = "<<x<<endl;

    //ans-=query(1,1,n,mp[arr[x]] + 1, n);

    ans-=query(1,1,n,1,mp[arr[x]] - 1);

    update(1,1,n,mp[arr[x]],-1);
}

int main()
{

    scanf("%lld", &n);

    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        vec.push_back(arr[i]);
    }

    sort(vec.begin(), vec.end());

    for(ll i = 0; i < n; i++)
        if(mp.find(vec[i]) == mp.end())
            mp[vec[i]] = i + 1;

    ll q;
    scanf("%lld", &q);

    for(ll i =0 ; i < q; i++)
    {
        scanf("%lld %lld", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }

//    for(ll i=1; i<=n; i++)
//        cout<<mp[arr[i]]<<" ";
//    cout<<endl;

    sort(Q, Q + q, comp);

    ll l = 1, r = 0;
    ans = 0;
    for(ll i = 0; i < q ; i++)
    {
        while(l<Q[i].l)
            lRemove(l++);
        while(l>Q[i].l)
            lAdd(--l);

        while(r<Q[i].r)
            Add(++r);
        while(r>Q[i].r)
            Remove(r--);
        res[Q[i].id] = ans;
    }

    for(ll i = 0; i < q ; i++)
        printf("%lld\n",res[i]);


}
