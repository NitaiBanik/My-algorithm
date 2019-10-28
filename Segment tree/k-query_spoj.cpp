#include<bits/stdc++.h>
using namespace std;
#define ll int
ll l[200005],r[200005],ans[200005];
ll tree[30005 * 6];
struct st
{
    ll val,id;
} value[30005],Q[200005];

bool comp(st a, st b)
{
    if(a.val == b.val)
        return a.id < b.id;

    return a.val < b.val;
}
void build(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node*2 + 1, mid + 1, r);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(int node, int l, int r, int pos)
{
    if(l == r && l == pos)
    {
        tree[node] = 0;
        return;
    }
    int mid = (l + r) / 2;

    if(mid>=pos)
        update(node * 2, l, mid, pos);
    else
        update(node * 2 + 1, mid + 1, r, pos);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}
ll sum(int node, int l, int r, int x, int y)
{
    if((l > y) || (r < x))
        return 0;

    if((l>=x) && (r<=y))
        return tree[node];

    int mid = (l + r) / 2;
    return sum(node * 2, l, mid, x, y) + sum(node * 2 + 1, mid + 1, r, x,y);
}
int main()
{

    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++)
    {
        int arr;
        scanf("%d", &arr);
        value[i].val = arr,value[i].id = i;
    }
    ll kk, q;
    scanf("%d",&q);
    for(int i = 1; i<= q; i++)
    {
        scanf("%d %d %d",&l[i],&r[i], &kk);
        Q[i].val = kk;
        Q[i].id = i;
    }
    sort(value + 1,value + n + 1,comp);
    sort(Q + 1,Q + q + 1,comp);

    build(1,1,n);

    int idx = 1;

    for(int i = 1; i <= q; i++)
    {
       // cout<<"YO|"<<endl;
        while(idx<=n && value[idx].val<= Q[i].val)
        {
            update(1,1,n,value[idx].id);
            idx++;
        }

        int x = Q[i].id;
        ans[x] = sum(1,1,n,l[x], r[x]);
    }

    for(int i = 1; i <= q; i++)
        printf("%d\n",ans[i]);
    return 0;
}
