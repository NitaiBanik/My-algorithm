#include<bits/stdc++.h>
using namespace std;

#define ll int
int tree[10000007 * 4];


void update(ll node, ll b, ll e, ll idx)
{
    if(b>idx || e<idx)
        return;
    if(b == e && b ==  idx)
    {
        tree[node] = 1;
        return;
    }
    ll mid = (b + e)/2;
    ll left = node *2;
    ll right = left+ 1;

    update(left, b, mid, idx);
    update(right, mid + 1, e, idx);
    tree[node] = tree[left] + tree[right];

}

int query(ll node, ll b, ll e, ll x, ll y)
{

    if(b>y || e<x)
        return 0;
    if(b>=x && e<=y)
        return tree[node];
    ll mid = (b + e)/2;
    ll left = node *2;
    ll right = left+ 1;
    int xx = query(left, b,mid, x, y);
    int yy = query(right, mid + 1, e, x, y);
    return xx+ yy;


}

int main()
{


    int t;
    cin>>t;
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        int n,x;
        scanf("%d",&n);
        long long cn = 0LL;
        for(int i=1;  i<=n; i++)
        {
            scanf("%d",&x);
            cn+=(long long)query(1,1, 10000000+1,x+1,10000000+1);
            update(1,1,10000000+1, x);
        }
        printf("%lld\n",cn);
    }
}
