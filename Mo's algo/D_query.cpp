#include<bits/stdc++.h>
using namespace std;
#define ll int

ll arr[300005];
ll prnt[300005];
#define sq 550 // 175 * 175 > 30000

struct st
{
    ll l,r,id;
} qu[200005];

//bool comp(st &a, st &b)
//{
//    int block_a = a.l / sq, block_b = b.l / sq;
//    if(block_a == block_b)
//        return a.r < b.r;
//    return block_a < block_b;
//}

bool comp(st &a, st &b)
{
  if (a.l / sq != b.l / sq) return a.l< b.l;
  return (a.r < b.r)^(a.l/sq%2);
}

ll sum;
ll fre[1000005];

void add(ll x)
{
    if(fre[arr[x]] == 0)
        sum++;
    fre[arr[x]]++;
}
void rmv(ll x)
{
    fre[arr[x]]--;
    if(fre[arr[x]] == 0)
        sum--;

}
int main()
{

    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        scanf("%d %d",&qu[i].l, &qu[i].r);
        qu[i].id = i;

    }
    sort(qu,qu+q,comp);

    ll l = 1,r = 0;
    sum = 0;
    for(int i = 0; i < q; i++)
    {


        while(l<qu[i].l)
            rmv(l++);
        while(l>qu[i].l)
            add(--l);
        while(r<qu[i].r)
            add(++r);
        while(r>qu[i].r)
            rmv(r--);

        prnt[qu[i].id] = sum;

    }
    for(int i = 0; i < q; i++)
        printf("%d\n",prnt[i]);
}
