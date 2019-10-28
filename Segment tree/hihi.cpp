#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll zero,one,two;
} tree[100005 * 4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(left,b,mid);
    init(right,mid + 1, e);
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
}

st update(ll node, ll b, ll e, ll i, ll j)
{
    if(e<i || b>j) {
            st xx;
        xx.zero = 0;
        xx.one = 0;
        xx.two = 0;
    return xx;
    }
    if(b>=i && e<=j)
    {
        ll aa = tree[node].zero;
        ll bb = tree[node].one;
        ll cc = tree[node].two;
        tree[node].zero = cc;
        tree[node].one = aa;
        tree[node].two = bb;
        st xx;
        xx.zero = cc;
        xx.one = aa;
        xx.two = bb;
        return xx;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    st lf = update(left,b,mid,i,j);
    st rr = update(right,mid + 1, e,i,j);
    st yy;
    yy.zero = lf.zero + rr.zero;
    yy.one = lf.one  + rr.one ;
    yy.two = lf.two + rr.two;
    return yy;
}
ll query(ll node,ll b, ll e, ll i , ll j)
{
    if(e<i || b>j) return 0;
    if(b>= i &&  e<=j)
    {
        return tree[node].zero ;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll x =  query(left,b,mid,i,j);
    ll y =   query(right,mid + 1, e,i,j);
    return x + y;
}
int main()
{
    ll t,n,q,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        init(1,0,n-1);
        printf("Case %lld:\n",++w);
        while(q--)
        {
            ll type,frm,to;
            scanf("%lld %lld %lld",&type,&frm,&to);
            if(type == 0)
            {
                update(1,0,n-1,frm,to);
            }
            else
                printf("%lld\n",query(1,0,n-1,frm,to));

        }
    }
}

