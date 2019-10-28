
///Codeforces D. Welfare State
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[200005];
ll tree[2 * 400005];
void update(int node, int b, int e, int idx, int val)
{
    if(b == e && e == idx)
    {
        tree[node] = val;
        return;
    }
    if(b> idx  || e <idx)
        return;

    int mid = (b + e) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;

    tree[lf] = max(tree[lf], tree[node]);
    tree[rt] = max(tree[rt], tree[node]);
    tree[node] = 0;
    if(mid>=idx)
        update(lf, b, mid, idx, val);
    else
        update(rt, mid + 1, e, idx, val);
}
void build(int node, int b, int e)
{
    if(b == e)
    {
        arr[b] = max(arr[b], tree[node]);
        return;
    }


    int mid = (b + e) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;

    tree[lf] = max(tree[lf], tree[node]);
    tree[rt] = max(tree[rt], tree[node]);
    build(lf,b,mid);
    build(rt,mid+1,e);

}
int  main()
{
    ll n,I;
    scanf("%lld", &n);
    for(int i = 1; i<= n; i++)
        cin>>arr[i];

    int q;
    cin>>q;
    for(int i = 1; i<=q; i++)
    {
        int tp;
        scanf("%d", &tp);
        if(tp == 1)
        {
            ll id,val;
            scanf("%lld %lld", &id, &val);
            arr[id] = val;
            update(1,1,n,id,val);

        }
        else
        {
            ll w;

            scanf("%lld", &w);
            tree[1] = max(tree[1],w);
        }
    }
    build(1,1,n);
    for(int i = 1; i<= n; i++)
        cout<<arr[i]<<" ";
    return 0;

}
