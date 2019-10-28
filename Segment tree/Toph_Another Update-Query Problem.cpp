#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 100005
#define mod 1000000007

struct st
{
    ll lazy,sum1,sum2;
} tree[sz * 6];

ll arr[sz];
ll sm[sz];

struct stt
{
    ll cum1,cum2;
} tree1[sz * 6];

void build1(ll node, ll l, ll r)
{
    if(l == r)
    {
        tree1[node].cum1 = arr[l] % mod;
        tree1[node].cum2 = (arr[l] % mod * l) % mod;
        return;
    }
    ll mid = (l + r) / 2;

    ll left = node* 2;
    ll right = left + 1;

    build1(left, l, mid);
    build1(right, mid + 1, r);

    tree1[node].cum1 = (tree1[left].cum1 + tree1[right].cum1) % mod;
    tree1[node].cum2 = (tree1[left].cum2 + tree1[right].cum2) % mod;
}

ll query_cum1(ll node, ll l, ll r, ll x, ll y)
{
    if(l > y || r < x)
        return 0;

    if(l >= x && r <=y)
    {
        return tree1[node].cum1 % mod;
    }

    ll mid = (l + r) / 2;
    ll left = node * 2;
    ll right= node * 2 + 1;

    ll xx =  query_cum1(left, l, mid, x,y);
    ll yy = query_cum1(right,mid + 1,r, x,y);
    return (xx + yy) % mod;
}

ll query_cum2(ll node, ll l, ll r, ll x, ll y)
{
    if(l > y || r < x)
        return 0;

    if(l >= x && r <= y)
    {
        return tree1[node].cum2 % mod;
    }

    ll mid = (l + r ) / 2;
    ll left = node * 2;
    ll right= node * 2 + 1;

    ll xx =  query_cum2(left, l, mid, x,y);
    ll yy = query_cum2(right,mid + 1,r, x,y);

    return (xx + yy) % mod;
}
void build(ll node, ll l, ll r)
{
    if(l == r)
    {
        tree[node].lazy = 0;
        tree[node].sum1 = 0;
        tree[node].sum2 = 0;
        return;
    }
    ll mid = (l + r) / 2;
    ll left = mid * 2;
    ll right = left + 1;

    build(left, l, mid);
    build(right, mid + 1, r);

    tree[node].lazy = 0;
    tree[node].sum1 = 0;
    tree[node].sum2 = 0;

}
void update(ll node, ll l, ll r, ll x, ll y, ll lz)
{
    if(l > y || r < x)
    {
        tree[node].sum1 = ((r - l + 1) * tree[node].lazy) % mod;
        tree[node].sum2 = ((sm[r] - sm[l - 1])%mod * tree[node].lazy) % mod;
        return;

    }

    if(l>=x && r<=y)
    {
        tree[node].lazy += lz;
        tree[node].lazy %= mod;
        tree[node].sum1 = ((r - l + 1) * tree[node].lazy) % mod;
        tree[node].sum2 = ((sm[r] - sm[l - 1])%mod * tree[node].lazy) % mod;
        return ;
    }


    ll mid = (l + r ) / 2;
    ll left = node * 2;
    ll right= node * 2 + 1;

    tree[left].lazy += tree[node].lazy;
    tree[left].lazy %= mod;

    tree[right].lazy += tree[node].lazy;
    tree[right].lazy %= mod;

    tree[node].lazy = 0 ;

    update(left, l, mid, x,y,lz);
    update(right,mid + 1,r, x,y,lz);

    tree[node].sum1 = (tree[left].sum1 + tree[right].sum1) % mod;
    tree[node].sum2 = (tree[left].sum2 + tree[right].sum2) % mod;
}
ll query(ll node, ll l, ll r, ll x, ll y, ll carry)
{
    if(l > y || r < x)
        return 0;

    if(l >= x && r <=y)
    {
        return (tree[node].sum1 + ((r - l + 1) * carry)%mod)% mod;
    }

    ll mid = (l + r ) / 2;
    ll left = node * 2;
    ll right= node * 2 + 1;

    ll xx =  query(left, l, mid, x,y,(carry + tree[node].lazy) % mod);
    ll yy = query(right,mid + 1,r, x,y,(carry + tree[node].lazy) % mod);
    return (xx + yy) % mod;
}

///wererewrewr
ll query2(ll node, ll l, ll r, ll x, ll y, ll carry)
{
    if(l > y || r < x)
        return 0;

    if(l >= x && r <=y)
    {
        return (tree[node].sum2 + ((sm[r] - sm[l-1]) * carry)%mod)% mod;
    }

    ll mid = (l + r ) / 2;
    ll left = node * 2;
    ll right= left + 1;

    ll xx =  query2(left, l, mid, x,y,(carry + tree[node].lazy) % mod);
    ll yy = query2(right,mid + 1,r, x,y,(carry + tree[node].lazy) % mod);
    return (xx + yy) % mod;
}

int main()
{
cout<<0%mod<<endl;
    ll t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(tree1,0,sizeof(tree1));
        memset(sm,0,sizeof(sm));

        ll n,m,type,l,r,id;
        ll val,d,value;

        scanf("%lld %lld",&n,&m);

        for(ll i = 1; i <= n; i++)
        {
            scanf("%lld",&arr[i]);
            sm[i] = sm[i - 1] + i;
        }

        printf("Case %lld:\n",++w);

        build(1,1,n);
        build1(1,1,n);

        while(m--)
        {
            scanf("%lld",&type);
            if(type == 1)
            {
                scanf("%lld %lld %lld",&l,&r,&value);
                value%=mod;
                update(1,1,n,l,r,value);
            }
            else
            {
                scanf("%lld %lld %lld",&l,&r,&value);
                value%=mod;
                ll w = query(1,1,n,l,r,0LL);
                //cout<<"first1 = "<<w<<endl;
                ll first = w + query_cum1(1,1,n,l,r);
                first %= mod;
                //cout<<"first2 = "<<query_cum1(1,1,n,l,r)<<endl;

                ll second = 0;

                if(r>l)
                {
                    ll ww = query2(1,1,n,l+1,r,0LL);
                    second = ww + query_cum2(1,1,n,l+1,r);
                    second%=mod;
                    // cout<<"second = "<<second<<endl;
                    ll third = 0;
                    ll kk = query(1,1,n,l+1,r,0LL);
                    // cout<<"kk1_normal "<<kk<<endl;
                    kk += query_cum1(1,1,n,l+1,r);
                    //   cout<<"kk1_cum "<<kk<<endl;
                    kk%=mod;
                    kk = (kk * (l)) % mod;
                    // cout<<"kk1_main "<<kk<<endl;
                    third = kk;

                    second-=third;
                    second+=mod;
                    second%=mod;
                    second*=value;
                    second%=mod;
                }
                cout<<(second+first) % mod<<endl;
            }
        }
    }
    return 0;
}
