#include<bits/stdc++.h>
using namespace std;

long long arr[100005];

struct st
{
    long long sum,mx;
} tree[6 * 100005];

void build(long long node, long long b, long long e)
{
    if(b == e)
    {
        tree[node].mx = arr[b];
        tree[node].sum = arr[b];

        return;
    }

    long long mid = (b + e ) / 2;

    long long left = node * 2;

    long long right = node * 2 + 1;

    build(left, b, mid);

    build(right,mid +1, e);

    tree[node].mx = max(tree[right].mx,tree[left].mx);

    tree[node].sum = (tree[right].sum + tree[left].sum);

}

void update(long long node, long long b,long long e, long long i,long long j)
{
    if(e<i || b>j)
        return;

    if(tree[node].mx<=1)
        return;

    if((b>=i && e<=j) && (b == e))
    {
        long long k = tree[node].mx,x;
        x = (long long )sqrt(k);

        tree[node].mx = x;
        tree[node].sum = x;
        return;
    }
    long long mid = (b + e ) / 2;

    long long left = node * 2;

    long long right = node * 2 + 1;

    update(left, b, mid,i,j);

    update(right,mid + 1, e,i,j);

    tree[node].mx = max(tree[right].mx,tree[left].mx);

    tree[node].sum = (tree[right].sum + tree[left].sum);


}

long long query(long long node, long long b, long long e, long long i, long long j)
{
    if(b>j || e<i)
        return 0;

    if(b>=i && e<=j)
        return tree[node].sum;

    long long mid = (b + e ) / 2;

    long long left = node * 2;

    long long right = node * 2 + 1;

    long long aa = query(left, b, mid,i,j);

    long long bb = query(right,mid + 1, e,i,j);

    //tree[node].mx = (tree[right].mx,tree[left].mx);

    return aa + bb;

}


int main()
{

    long long n,q,w = 0;

    while(scanf("%lld",&n) == 1)
    {
        for(long long i=1; i<=n; i++)
            scanf("%lld",&arr[i]);

        build(1,1,n);

        scanf("%lld",&q);

        long long l,r,type;

        printf("Case #%lld:\n",++w);
        while(q--)

        {
            scanf("%lld %lld %lld",&type,&l,&r);
if(l>=r) swap(l,r);
            if(type == 0)
                update(1,1,n,l,r);
            else
                printf("%lld\n",query(1,1,n,l,r));

        }
        printf("\n");
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
