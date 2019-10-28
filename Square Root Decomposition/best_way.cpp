#include<bits/stdc++.h>
using namespace std;
#define siz 300005
#define ll long long

ll arr[siz];
vector<ll>vec[570];

ll n,m,u;

void process()
{

    ll block_size = sqrt(n);

    ll ck = 0, block = 0;

    for(int i=0; i<n; i++)
    {
        ck++;
        vec[block].push_back(arr[i]);
        if(ck == block_size)
        {
            sort(vec[block].begin(),vec[block].end());
            block++;
            ck = 0;
        }
    }

    sort(vec[block].begin(),vec[block].end());

    // cout<<"done"<<endl;
}

void update(ll frm, ll to, ll idx, ll fre)
{
    ll block_size = sqrt(n);
    ll src = arr[idx];
    arr[idx] = (u * fre ) /(to - frm + 1);

    ll p_block = idx/block_size;

    ll p_start = (p_block) * block_size;
    ll p_end = (p_block + 1) * block_size - 1;


    ll id = lower_bound(vec[p_block].begin(),vec[p_block].end(),src) - vec[p_block].begin();

    vec[p_block][id] = arr[idx];


    sort(vec[p_block].begin(),vec[p_block].end());
}
void query(ll frm, ll to, ll v, ll idx)
{
    ll block_size = sqrt(n);

    ll frm_block = frm/block_size;

    ll to_block = to/block_size;

    ll fre = 0;

    if(frm_block == to_block)
    {
        for(int i=frm; i<=to; i++)
        {
            if(arr[i]<v)
                fre++;
        }
    }

    else
    {
        for(int i=frm_block + 1; i<to_block; i++)
        {
            ll beg = 0,ed = block_size - 1,ans = -1,mid;
            ll id = lower_bound(vec[i].begin(),vec[i].end(),v) - vec[i].begin();
            fre+=(id);
        }

        ll frm_end = (frm_block + 1) * block_size - 1;

        for(int i=frm; i<=frm_end; i++)
            if(arr[i]<v)
                fre++;

        ll to_start = to_block * block_size;

        for(int i=to_start; i<=to; i++)
            if(arr[i]<v)
                fre++;
    }

    update(frm,to,idx,fre);
}

int main()
{


    scanf("%lld %lld %lld",&n,&m,&u);


    for(int i=0; i<n; i++)
        scanf("%lld",&arr[i]);

    process();

    ll l,r,v,p;

    while(m--)
    {
        scanf("%lld %lld %lld %lld",&l, &r, &v, &p);

        l--,r--,p--;

        query(l, r, v, p);
    }

    for(int i=0; i<n; i++)
        printf("%lld\n",arr[i]);


}
