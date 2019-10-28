#include<bits/stdc++.h>
using namespace std;

int lazy[320];
int fre[320][200005];

int arr[100005];

void process(int n)
{
    int sq = sqrt(n);
    int block = 0,ck = 0;
    for(int i = 0; i < n; i++)
    {
        ck++;
        fre[block][arr[i]]++;
        if(ck == sq)
        {
            ck = 0;
            block++;
        }
    }
}

void update(int  n, int l, int r, int val)
{
    int sq = sqrt(n);

    int frm_block = l / sq;
    int to_block = r / sq;

    if(frm_block == to_block)
    {
        for(int i = l ; i <= r; i++)
        {
            fre[frm_block][arr[i]]--;

            fre[frm_block][arr[i] + val]++;
            arr[i] +=val;
        }
    }

    else
    {

        for(int i = frm_block + 1 ; i < to_block ; i++)
            lazy[i]+=val;

        int frm_end = (frm_block + 1 ) * sq - 1;
        for(int i = l ; i <= frm_end; i++)
        {
            fre[frm_block][arr[i]]--;

            fre[frm_block][arr[i] + val]++;
            arr[i] +=val;
        }

        int to_start = to_block * sq;

        for(int i = to_start ; i <= r; i++)
        {
            fre[to_block][arr[i]]--;

            fre[to_block][arr[i] + val]++;
            arr[i] +=val;

        }

    }
}

int query(int n, int l, int r, int val)
{
    int ans = 0;
    int sq = sqrt(n);

    int frm_block = l / sq;
    int to_block = r / sq;

    if(frm_block == to_block)
    {
        int x = lazy[frm_block];

        for(int i = l ; i <= r; i++)
        {
            if((arr[i] + x) == val)
                ans++;
        }
    }

    else
    {

        for(int i = frm_block + 1 ; i < to_block ; i++)
        {
            int x = lazy[i];
            ans+=fre[i][val - x];
        }

        int frm_end = (frm_block + 1 ) * sq - 1;

        int x = lazy[frm_block];

        for(int i = l ; i <= frm_end; i++)
        {
            if((arr[i] + x) == val)
                ans++;
        }

        int to_start = to_block* sq;
        x = lazy[to_block];

        for(int i = to_start ; i <= r; i++)
        {
            if((arr[i] + x) == val)
                ans++;
        }


    }
    return ans;
}
int main()
{
    int t,w = 0;
    scanf("%d", &t);

    while(t--)
    {
        int n,q;
        scanf("%d %d",&n, &q);

        for(int i = 0; i < n; i++)
            scanf("%d",&arr[i]);

        process(n);

        printf("Case %d:\n",++w);

        while(q--)
        {
            int type,x,y,v;
            scanf("%d %d %d %d",&type, &x, &y, &v);

            x--,y--;

            if(type == 1)
                update(n, x, y, v );
            else
                printf("%d\n",query(n, x, y, v));
        }

        memset(fre,0,sizeof(fre));
        memset(lazy,0,sizeof(lazy));
    }
}
