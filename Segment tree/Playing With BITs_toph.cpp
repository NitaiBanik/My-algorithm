#include<bits/stdc++.h>
using namespace std;

#define ll int

int tree[4 * 100005][62];

void update(ll node,ll l, ll r, ll idx,long long val)
{

//cout<<"update"<<endl;
    if(l>r ||l>idx || r<idx)
        return;

    if(l>=idx && r<=idx)
    {
        //cout<<"val = "<<val<<endl;

        for(ll i=0; i<=61; i++)
        {
            ll x = (bool)(val&(1LL<<i));
            tree[node][i] = x;
            // cout<<x<<" ";
        }
        //cout<<endl;
        return;
    }

    ll mid = (l + r) / 2;

    ll left = node * 2;
    ll right = node * 2 + 1;

    update(left,l,mid,idx,val);
    update(right,mid+1,r,idx,val);

    for(ll i=0; i<=61; i++)
        tree[node][i] = tree[left][i] + tree[right][i];


}
ll query(ll node,ll l, ll r, ll x, ll y,long long k)
{

    if(l>r || l>y || r<x)
        return 0;

    if( l>=x && r<=y)
    {
        return tree[node][k];
    }

    ll mid = (l + r) / 2;

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll aa = query(left,l,mid,x,y,k);
    ll bb = query(right,mid+1,r,x,y,k);

    return (aa+bb);
}
int main()
{
    memset(tree,0,sizeof tree);
    ll n,q;
    long long x;
    scanf("%d",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&x);
        update(1,1,n,i,x);
    }

    scanf("%d",&q);

    while(q--)
    {
        ll type,a,b,c;
        scanf("%d",&type);
        if(type == 1)
        {
            scanf("%d%lld",&a,&x);
            update(1,1,n,a,x);
        }

        else
        {
            scanf("%d%d%d",&a,&b,&c);

            ll w =  query(1,1,n,a,b,c);

            printf("%d\n",w);
        }
    }

    return 0;
}
