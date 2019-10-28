#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct st
{
    ll lazy,zero,one,two;
} tree[100005 * 4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].lazy = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(left,b,mid);
    init(right,mid + 1, e);
    tree[node].zero = (e - b + 1);
    tree[node].one = 0;
    tree[node].two = 0;
    tree[node].lazy = 0;
}

void update(ll node, ll b, ll e, ll i, ll j)
{
    // cout<<"update"<<endl;

    if(b>j || e<i)
    {
        ll x = tree[node].lazy;
        x = x%3;

        ll z = tree[node].zero;
        ll o = tree[node].one;
        ll t = tree[node].two;
        if(x == 1)
        {
            tree[node].zero = 0;
            tree[node].one = z;
            tree[node].two = o;
        }
        else if(x == 2)
        {
            tree[node].zero = 0;
            tree[node].one = t;
            tree[node].two = z;
        }
        else tree[node].zero = (e - b + 1);
        return;
    }

    if(b>=i && e<=j)
    {
        tree[node].lazy++;
        ll x = tree[node].lazy;


        ll z = tree[node].zero;
        ll o = tree[node].one;
        ll t = tree[node].two;
        if(x%3 == 1)
        {
            tree[node].zero = 0;
            tree[node].one = z;
            tree[node].two = o;
        }
        else if(x%3 == 2)

        {
            tree[node].zero = 0;
            tree[node].one = t;
            tree[node].two = z;
        }
        else tree[node].zero = (e - b + 1);
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/2;

    tree[left].lazy+=tree[node].lazy;
    tree[right].lazy+=tree[node].lazy;

    tree[node].lazy = 0;

    update(left,b,mid,i,j);
    update(right,mid + 1, e, i, j);

    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;

}

ll query(ll node,ll b, ll e, ll i , ll j, ll carry)
{
    if(b>j || e<i)
    {
        return 0;
    }

    if(b>=i && e<=j)
    {
        if(carry % 3  == 0)
            return tree[node].zero ;
        else return 0;

    }

    ll left = node * 2;
    ll right = node * 2 + 1;

    ll mid = (b + e) / 2;

    ll x =  query(left,b,mid,i,j,tree[node].lazy + carry);
    ll y =   query(right,mid + 1, e,i,j,tree[node].lazy + carry);

    return x + y;
}

int main()
{
    ll t,n,q,w = 0;
    scanf("%lld",&t);

    while(t--)
    {
        memset(tree,0,sizeof(tree));
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
                for(int i=1;i<=6;i++)
                    printf("node = %d lazy = %lld zero = %lld\n",i,tree[i].lazy,tree[i].zero);
            }
            else
                printf("%lld\n",query(1,0,n-1,frm,to,0));
        }
    }
    return 0;
}
