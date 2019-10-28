#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define siz 100005

ll arr[siz];
ll block_mn[siz];

void process(int n)
{
    int block_size = sqrt(n);

    int cn = 0,block = 0;

    ll mn = 99999999;

    for(int i=0; i<n; i++)
    {
        cn++;
        mn = min(mn,arr[i]);
        if(cn == block_size)
        {
            cn = 0;
            block_mn[block] = mn;
            //      cout<<mn<<" ";
            mn = 999999999;
            block++;
        }
    }

    block_mn[block] = mn;
    //cout<<mn<<endl;
}

long long query(int n,int frm, int to)
{
    int sz = sqrt(n);
    int frm_block = frm / sz;
    int to_block = to / sz;
    ll mn = 999999999;
    if(frm_block == to_block)
    {
        for(int i=frm; i<=to ; i++)
        {
            mn = min(mn,arr[i]);
        }
    }
    else
    {
        for(int i = frm_block+1; i<to_block; i++)
        {
            mn = min(mn,block_mn[i]);
        }

        int frm_end = (frm_block + 1) * sz - 1;
        for(int i=frm; i<=frm_end; i++)
            mn = min(mn,arr[i]);
        int to_start = to_block * sz;
        for(int i=to_start; i<=to; i++)
            mn = min(mn,arr[i]);

    }
    return mn;
}


void update(int n,int pos,int val)
{
    int block_num = pos/sqrt(n);

    ll st = block_num * sqrt(n);
    ll en = (block_num + 1) * sqrt(n) - 1;
    en = min((ll)n-1,en);
    arr[pos] = val;
    ll mn = 999999999;
    for(int i=st; i<=en; i++)
        mn = min(mn,arr[i]);
    block_mn[block_num] = mn;


}
int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        int m,q;

        scanf("%d%d",&m,&q);

        for(int i=0; i<m; i++)
        {
            scanf("%lld",&arr[i]);
        }

        process(m);
        printf("Case %d:\n",++w);
        while(q--)
        {
            int type;
            scanf("%d",&type);
            if(type == 1)
            {
                int l,r;
                scanf("%d %d",&l,&r);
                l--,r--;
                ll ans = query(m,l,r);
                printf("%lld\n",ans);
            }
            else
            {
                int idx,value;
                scanf("%d %d",&idx,&value);
                idx--;
                update(m,idx,value);
            }
        }
    }
    return 0;
}
