#include<bits/stdc++.h>
using namespace std;
#define sz 1000005
#define ll long long

struct tree
{
    ll cost,cap;
} tree[sz * 4];

vector<pair<ll,ll> > vec[sz];

void update(ll node, ll beg, ll End, ll idx, ll c)
{
    if(beg>idx || End < idx)
        return;
    if(beg == idx && End == idx)
    {
        tree[node].cost+=(c * idx);
        tree[node].cap+=(c);
        return;
    }
    ll mid = (beg + End) / 2;

    if(mid>=idx)
        update(node * 2, beg, mid,idx,c);
    else
        update(node * 2 + 1,mid + 1,End,idx,c);

    tree[node].cap = tree[node * 2].cap + tree[node * 2 + 1].cap;
    tree[node].cost = tree[node * 2].cost + tree[node * 2 + 1].cost;
}

ll query(ll node, ll beg, ll End, ll how)
{
    if(tree[node].cap<=how)
    {
        return tree[node].cost;
    }
    if(beg == End)
    {
        return beg * how;
    }
    ll mid = (beg + End) / 2;
    if(tree[node * 2].cap>=how)
        return query(node * 2,beg,mid,how);
    else
        return tree[node * 2].cost + query(node * 2 + 1,mid + 1,End,how - tree[node * 2].cap);
}
int main()
{
    ll n,k,m;
    scanf("%lld %lld %lld",&n,&k,&m);
    while(m--)
    {
        ll l,r,c,p;
        scanf("%lld %lld %lld %lld",&l,&r,&c,&p);
        vec[l].push_back({c,p});
        vec[r + 1].push_back({-c,p});///remove
    }
    ll res = 0;
    for(int i = 1; i<= n; i++)
    {
        int siz = vec[i].size();
        for(int j = 0; j < siz; j++)
            update(1,1,sz-1,vec[i][j].second,vec[i][j].first);

        res+=query(1,1,sz - 1, k);

    }
    printf("%lld\n",res);
}
