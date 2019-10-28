#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll mx,pos;
} tree[100005 * 4];

ll arr[100005];

ll N;

void build(ll node,ll b, ll e)
{

    if(b == e)
    {
        tree[node].mx = arr[b];
        tree[node].pos = b;
        return;
    }
    ll right = node *2LL;
    ll left = node* 2LL + 1LL;
    ll mid = (b + e) / 2LL;

    build(left, b,mid);
    build(right,mid + 1LL,e);

    if(tree[left].mx<tree[right].mx)
    {
        tree[node].mx = tree[left].mx;
        tree[node].pos = tree[left].pos;
    }
    else
    {
        tree[node].mx = tree[right].mx;
        tree[node].pos = tree[right].pos;
    }
}

st query(ll node, ll b, ll e, ll i, ll j)
{
    //cout<<"haha"<<endl;
    if(b>j || e<i)
    {
        st x;
        x.mx = 99999999999999999;
        x.pos = 9999999999999999;
        return x;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll right = node *2LL;
    ll left = node* 2LL + 1LL;
    ll mid = (b + e) / 2LL;
    st l = query(left,b,mid,i,j);
    st r = query(right,mid + 1LL,e,i,j);
    st w;
    if(l.mx<r.mx)
    {
        w.mx = l.mx;
        w.pos = l.pos;
    }
    else
    {
        w.mx = r.mx;
        w.pos = r.pos;
    }
    return w;
}
ll fun(ll beg, ll End)
{
    if(beg>End)
        return 0;

    if(beg == End)
    {
        return arr[beg];
    }
    st val = query(1LL,1LL,N,beg,End);
    ll ans1 = 0LL,ans2 = 0LL;
    ans1 = max(val.mx * (End - beg + 1LL),max(fun(beg,val.pos-1LL),fun(val.pos+1LL,End)));
    return ans1;
}
int main()
{

    while(scanf("%lld",&N)==1 && N!=0)
    {
        for(ll i=1; i<=N; i++)
        {
            scanf("%lld",&arr[i]);
        }

        build(1LL,1LL,N);

        ll Ans = fun(1LL,N);

        printf("%lld\n",Ans);

    }

    return 0;
}
