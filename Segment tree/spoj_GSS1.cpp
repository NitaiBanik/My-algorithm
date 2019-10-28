#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

struct st
{
    long long sum,suffix,prefix,ans;
} tree[50000 * 6];

long long arr[50005],n;

void build(long long node, long long b, long long e)
{
    if(b == e)
    {
        tree[node].sum = arr[b];
        tree[node].ans = arr[b];
        tree[node].suffix = arr[b];
        tree[node].prefix = arr[b];
        return;
    }

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid  = (b + e) / 2;

    build(left,b,mid);
    build(right,mid + 1,e);

    tree[node].sum = tree[left].sum + tree[right].sum;

    tree[node].prefix = max(tree[left].prefix,tree[left].sum + tree[right].prefix);
    tree[node].suffix = max(tree[right].suffix,tree[right].sum + tree[left].suffix);

    tree[node].ans = max(tree[left].ans,tree[right].ans);
    tree[node].ans = max(tree[node].ans,tree[left].suffix+tree[right].prefix);


}

st query(long long node,long long b, long long e, long long i, long long j)
{
    if(b>j || e<i)
    {
        //cout<<1<<endl;
        st w;
        w.sum = 0;
        w.ans = -inf;
        w.prefix = -inf;
        w.suffix = -inf;

        return w;
    }

    if(b>=i && e<=j)
        return tree[node];

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid  = (b + e) / 2;

    st lf = query(left,b,mid,i,j);
    st rt = query(right,mid+1,e,i,j);

    st ret;

        ret.sum = lf.sum + rt.sum;

        ret.suffix = max(rt.suffix,lf.suffix + rt.sum);
        ret.prefix = max(lf.prefix, lf.sum + rt.prefix);

        ret.ans = max(rt.ans,lf.ans);
        ret.ans = max(ret.ans,lf.suffix + rt.prefix);

        return ret;
}
int main()
{
   // memset(tree,-inf,sizeof(tree));
    //cout<<tree[11].sum<<endl;
    scanf("%lld",&n);

    for(long long i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    build(1,1,n);

//    for(long long i = 1;i<=15;i++)
//    {
//        prlong longf("\nNode = %lld\nn",i);
//        prlong longf("  sum = %lld\n",tree[i].sum);
//        prlong longf("  prefix = %lld\n",tree[i].prefix);
//        prlong longf("  suffix = %lld\n",tree[i].suffix);
//        prlong longf("  ans = %lld\n",tree[i].ans);
//    }
    long long Q;
    scanf("%lld",&Q);

    while(Q--)
    {
        long long l,r;

        scanf("%lld %lld",&l,&r);
        st anss = query(1,1,n,l,r);
        if(l>r) swap(l,r);
        printf("%lld\n",anss.ans);
    }


    return 0;
}
