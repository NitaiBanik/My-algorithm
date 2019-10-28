#include<bits/stdc++.h>
using namespace std;

#define ll int
ll n;

ll lazy[320];
ll arr[100005];
ll block[320][40];
ll power_two[40];

void process()
{
    ll block_sz = sqrt(n);

    int blk = 0;
    int cn = 0;

    for(int i = 0; i < n; i++)
    {
        cn++;
        for(int j = 0 ; j < 20; j++)
        {
            int bit = arr[i] &(1<<j);
            if(bit)
                block[blk][j]++;
        }
        if(cn == block_sz)
        {
            cn = 0;
            blk++;
        }
    }
}
long long query(ll l, ll r)
{
    ll sz = (ll)sqrt(n);
    ll frm_block = l/sz;
    ll to_block = r/sz;
    long long sum = 0;
    if(frm_block == to_block)
    {
        ll lazy1 = lazy[frm_block];
        for(int i = l ; i <=r; i++)
            sum+=(lazy1 ^ arr[i]);
    }
    else
    {
        ll lazy_frm = lazy[frm_block];
        ll frm_end = (frm_block + 1) * sz - 1;

        for(int i = l ; i <= frm_end; i++)
            sum+=(lazy_frm ^ arr[i]);

        ll lazy_to = lazy[to_block];
        ll to_start = (to_block) * sz;

        for(int i = to_start; i <= r; i++)
            sum+=(lazy_to ^ arr[i]);

        for(int i = frm_block + 1; i < to_block; i++)
        {
            ll lz = lazy[i];
            for(int j = 0 ; j<20 ; j++)
            {
                ll x = lz & (1 << j);
                if(x == 0)
                {
                    sum+=(block[i][j] * power_two[j]);
                }
                else
                {
                    sum+=(abs(block[i][j] - sz) * power_two[j]);
                }
            }

        }
    }
    return sum;
}

void update(ll l, ll r, ll val)
{
    ll sz = (ll)sqrt(n);
    ll frm_block = l/sz;
    ll to_block = r/sz;

    if(frm_block == to_block)
    {
        for(int i = l; i<=r; i++)
        {
            ll prev = arr[i];
            ll now = prev ^ val;
            for(int j = 0; j < 20; j++)
            {
                ll bit = prev & (1 << j);
                if(bit)
                    block[frm_block][j]--;
                bit = now & (1 << j);
                if(bit)
                    block[frm_block][j]++;
            }
            arr[i] = now;
        }
    }
    else
    {

        ll lazy_frm = lazy[frm_block];
        ll frm_end = (frm_block + 1) * sz - 1;

        for(int i = l; i<=frm_end; i++)
        {
            ll prev = arr[i];
            ll now = prev ^ val;
            for(int j = 0; j < 20; j++)
            {
                ll bit = prev & (1 << j);
                if(bit)
                    block[frm_block][j]--;
                bit = now & (1 << j);
                if(bit)
                    block[frm_block][j]++;
            }
            arr[i] = now;
        }

        ll lazy_to = lazy[to_block];
        ll to_start = (to_block) * sz;

        for(int i = to_start; i<=r; i++)
        {
            ll prev = arr[i];
            ll now = prev ^ val;
            for(int j = 0; j < 20; j++)
            {
                ll bit = prev & (1 << j);
                if(bit)
                    block[to_block][j]--;
                bit = now & (1 << j);
                if(bit)
                    block[to_block][j]++;
            }
            arr[i] = now;
        }
        for(int i = frm_block + 1; i < to_block; i++)
        {
            lazy[i]^=val;

        }
    }
}

int main()
{
    power_two[0] = 1;

    for(int i = 1; i<20; i++)
        power_two[i] = power_two[i - 1] * 2;

    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    process();
    ll q;

    scanf("%d",&q);
    while(q--)
    {
        ll  type,l,r,val;
        scanf("%d",&type);
        if(type == 1)
        {
            scanf("%d %d",&l,&r);
            l--,r--;
            long long ans = query(l,r);
            printf("%lld\n",ans);
        }
        else
        {
            scanf("%d %d %d",&l,&r,&val);
            l--,r--;
            update(l, r, val);
        }
    }

}
