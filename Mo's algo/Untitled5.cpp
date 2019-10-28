#include<bits/stdc++.h>
using namespace std;

#define sq 450
#define ll long long

int arr[200005];
ll prnt[200005];
int fre[1000006];

ll sum, l = 1, r = 0;

struct query
{
    int l,r,id;
} Q[200005];

bool cmp(query A, query B)
{
    if(A.l / sq != B.l / sq)
        return A.l < B.l;

    return (A.r < B.r) ^ (A.l / sq % 2);
}

void add(int x)
{
    sum+=(1LL+fre[arr[x]]+fre[arr[x]]) * arr[x];
    fre[arr[x]]++;
   // sum+=(1LL+fre[arr[x]] + fre[arr[x]]) * arr[x];

}

void rmv(int x)
{
    sum-=(fre[arr[x]] + fre[arr[x]]-1LL) * arr[x];
    fre[arr[x]]--;
    //sum+=(1LL%fre[arr[x]] * fre[arr[x]] * arr[x]);

}


int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < q; i++)
    {
        scanf("%d %d",&Q[i].l, &Q[i].r);
        Q[i].id = i;
    }

    sort(Q, Q + q, cmp);
    sum = 0LL;

    for(int i = 0; i < q; i++)
    {
        while(l < Q[i].l)
            rmv(l++);
        while(l > Q[i].l)
            add(--l);

        while(r < Q[i].r)
            add(++r);
        while(r > Q[i].r)
            rmv(r--);

        prnt[Q[i].id] = sum;
    }
    for(int i = 0; i < q; i++)
        printf("%lld\n", prnt[i]);
}
