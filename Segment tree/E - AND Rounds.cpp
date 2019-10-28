#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[20005];

ll tree[20005 * 4];
void build(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    int lf = node * 2;
    int rt = lf + 1;

    build(lf,  l, mid);
    build(rt, mid + 1, r);

    tree[node] = tree[lf] & tree[rt];
}
ll query(int node, int l, int r, int x, int y)
{
    if(l>y || r < x)
    {
        ll k = 1<<60;
        return k-1;
    }

    if(l>=x && r <= y)
        return tree[node];
    int mid = (l + r) / 2;

    int lf = node * 2;
    int rt = lf + 1;

    ll xx = query(lf,  l, mid, x, y);
    ll  yy = query(rt, mid + 1, r, x, y);

    return xx & yy;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n,k;
        scanf("%d %d",&n, &k);
        for(int i = 1; i<=n; i++)
            scanf("%lld", &arr[i]);

        build(1,1,n);
        k = min(k,n);

        for(int i = 1; i<=n; i++)
        {
            ll ans  = arr[i];
            int pos = i - k;
            if(pos<=0)
            {
                ans&=query(1,1,n,1,i);
                ans&=query(1,1,n,n+pos,n);
            }
            else
                ans&=query(1,1,n,pos,i);

            pos = i + k;

            if(pos>n)
            {
                ans&=query(1,1,n,i,n);
                ans&=query(1,1,n,1,pos-n);
            }
            else
                ans&=query(1,1,n,i,pos);
            if(i!=1)
                printf(" ");
            printf("%lld",ans);
        }
        printf("\n");
    }


    return 0;
}
