#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mx 200005

ll arr[mx];

struct st
{
    ll val,sum;
} tree[mx * 8];

void  build(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(arr[b]!=0)
        {
            //cout<<"haha"<<endl;
            tree[node].val = arr[b];
            tree[node].sum = 1;
        }
        else
        {
            tree[node].val = 0;
            tree[node].sum = 0;
        }
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;

    ll mid = (b + e) / 2;

    build(left, b, mid);
    build(right, mid + 1, e);


    tree[node].sum = tree[left].sum + tree[right].sum;

}

ll ans;

void update_clear(ll node, ll b , ll e, ll pos)
{

    if(tree[node].sum<pos)
        return;

    if(b == e)
    {
        ans = tree[node].val;
        tree[node].val = 0;
        tree[node].sum = 0;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;

    ll mid = (b + e) / 2;

    if(tree[left].sum >= pos)
    {
        update_clear(left,b,mid,pos);
    }
    else
        update_clear(right,mid + 1,e,pos-tree[left].sum);

    //tree[node].val = 0;

    tree[node].sum = tree[left].sum + tree[right].sum;

}

void update_add(ll node, ll b , ll e, ll pos,ll value)
{
    if(pos>e || pos <b)
        return;

    if(b == e && b == pos)
    {
       // cout<<"haha"<<endl;
        //cout<<"idx = "<<b<<endl;
        tree[node].val = value;
        tree[node].sum = 1;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;

    ll mid = (b + e) / 2;


    update_add(left,b, mid,pos,value);
    update_add(right,mid + 1,e,pos,value);

    tree[node].val = 0;

    tree[node].sum = tree[left].sum + tree[right].sum;

}

int main()
{

    ll t,w = 0;
    scanf("%lld",&t);

    while(t--)
    {
        printf("Case %lld:\n",++w);
        ll m,n;
        scanf("%lld %lld",&n,&m);

        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]);

        for(int i=n+1; i<=n+m; i++)
            arr[i] = 0;

        build(1,1,m+n);

        ll sz = n;

        for(int i=1; i<=m; i++)
        {
            getchar();

            char c;
            ll val;

            scanf("%c %lld",&c,&val);

            if(c == 'c')
            {
                ans = -1000;
                update_clear(1,1,m + n,val);

                if(ans == -1000)
                    printf("none\n");

                else
                    printf("%lld\n",ans);
            }
            else
            {
                update_add(1,1,m+n,sz+1,val);
                sz++;
            }

        }

    }
    return 0;
}
