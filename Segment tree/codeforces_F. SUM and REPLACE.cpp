#include<bits/stdc++.h>
using namespace std;

vector<long long>prime;

bool chk[1005];

long long arr[300005];
long long N[1000005];


void sieve()
{
    for(long long i=2; i<=1000; i++)
    {
        if(chk[i] == 0)
        {
            prime.push_back(i);

            for(long long j= i + i; j<=1000; j+=i)
                chk[j] = 1;
        }
    }
}

long long nod(long long w)
{
    if(w == 1)
        return 1;

    if(w == 2)
        return 2;

    long long nd = 1;

    for(long long j=0; j<prime.size() && prime[j]<=w; j++)
    {
        long long cn = 0;

        if(w%prime[j] == 0)
        {
            while(w%prime[j] == 0)
            {
                w/=prime[j];
                cn++;
            }
        }

        nd*=(cn+1);
    }

    if(w!=1)
        nd*=2;

    return nd;
}

struct st
{
    long long sum,mx;
} tree[6 * 300005];

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

    if(tree[node].mx<=2)
        return;

    if((b>=i && e<=j) && (b == e))
    {
        long long k = tree[node].mx,x;
        if(N[k] == 0)
      x = (long long )nod(k);
      else x = N[k];

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
    sieve();

    long long n,q;

    cin>>n>>q;

    for(long long i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    build(1,1,n);

    long long l,r,type;

    while(q--)
    {
        scanf("%lld %lld %lld",&type,&l,&r);

        if(type == 1)
            update(1,1,n,l,r);
        else
            printf("%lld\n",query(1,1,n,l,r));

    }
    return 0;
}
