#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define siz 200005
#define mnn  1e18
ll arr[siz];
ll block_mn[600];
ll block_lazy[600];
ll n,q;
void process()
{
    ///Building each block
    ll block_size = sqrt(n);

    ll cn = 0,block = 0;

    ll mn = mnn;

    for(ll i=0; i<n; i++)
    {
        cn++;
        mn = min(mn,arr[i]);
        if(cn == block_size)
        {
            cn = 0;
            block_mn[block] = mn;
            block_lazy[block] = 0;
            mn = mnn;
            block++;
        }
    }
    ///last block
    block_mn[block] = mn;
    block_lazy[block] = 0;
}

void update(ll frm, ll to, ll val)
{
    ll sz = sqrt(n);
    ll frm_block = frm / sz;
    ll to_block = to / sz;
    ll mn = mnn;

    if(frm_block == to_block)
    {
        /// inside a block
        for(ll i=frm; i<=to ; i++)
        {
            arr[i] += val;
        }

        ll mn1 = mnn;

        ll frm_end = (frm_block + 1) * sz - 1;
        ll frm_st = (frm_block) * sz;

        ///For updating the minimum value
        for(ll i=frm_st; i<=min(frm_end,n-1); i++)
            mn1 = min(mn1,arr[i]);

        block_mn[frm_block] = mn1;

    }
    else
    {
        ///totally overlapped blocks lazy updated
        for(ll i = frm_block+1; i<to_block; i++)
        {
            block_lazy[i]+= val;
        }
        ///partially overlapped, so directly array updated
        ll frm_end = (frm_block + 1) * sz - 1;
        for(ll i=frm; i<=min(frm_end,n-1); i++)
            arr[i] += val;
        ///For updating the minimum value
        ll mn1 = mnn;
        ll frm_st = (frm_block) * sz;

        for(ll i=frm_st; i<=min(frm_end,n-1); i++)
            mn1 = min(mn1,arr[i]);

        block_mn[frm_block] = mn1;
        mn1 = mnn;

        ll to_start = to_block * sz;
        ll to_end = (to_block + 1)* sz - 1;
        ///partially overlapped, so directly array updated
        for(ll i=to_start; i<=to; i++)
            arr[i] += val;
        ///For updating the minimum value
        for(ll i=to_start; i<=min(to_end,n-1); i++)
            mn1 = min(mn1,arr[i]);

        block_mn[to_block] = mn1;

    }
}

long long query(ll frm, ll to)
{
    ll sz = sqrt(n);
    ll frm_block = frm / sz;
    ll to_block = to / sz;
    ll mn = mnn;

    if(frm_block == to_block)
    {
        /// query inside a block, so directly values are checked with adding the lazy
        for(ll i=frm; i<=to ; i++)
        {
            mn = min(mn,arr[i] + block_lazy[frm_block]);
        }
    }

    else
    {
        ///total overlapped, so lazy and minimum values are checked with addition
        for(ll i = frm_block+1; i<to_block; i++)
        {
            mn = min(mn,block_mn[i] + block_lazy[i]);
        }
        ///partial overlapped checked manually by index to index
        ll frm_end = (frm_block + 1) * sz - 1;
        for(ll i=frm; i<=min(frm_end,n-1); i++)
            mn = min(mn,arr[i] + block_lazy[frm_block]);
         ///partial overlapped checked manually by index to index
        ll to_start = to_block * sz;
        for(ll i=to_start; i<=to; i++)
            mn = min(mn,arr[i] + block_lazy[to_block]);
    }

    return mn;
}

int main()
{


    scanf("%lld",&n);

    for(ll i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }

    process();
    scanf("%lld",&q);

    getchar();
    while(q--)
    {

        string w;
        getline(cin,w);

        istringstream ss(w);
        ll cn = 0;
        ll x,y,z,p;

        while(ss>>p)
        {
            cn++;
            if(cn == 1)
                x = p;
            if(cn == 2)
                y = p;
            if(cn == 3)
                z = p;
        }

        if(cn == 2)
        {
            if(x<=y)
                cout<<query(x,y)<<endl;
            else
            {
                ll pp = query(x,n-1);
                ll q = query(0,y);

                cout<<min(pp,q)<<endl;
            }
        }
        else
        {
            if(x<=y)
                update(x,y,z);
            else
            {
                update(x,n-1,z);
                update(0,y,z);
            }
        }
    }
    return 0;
}
