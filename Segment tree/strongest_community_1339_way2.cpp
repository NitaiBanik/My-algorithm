#include<bits/stdc++.h>
using namespace std;
#define ll int
///Mo's algorithm
///counted the frequency of a value
///counted the frequency of values(frequency)
///Stored the max frequency during add
///compared my res(which is maximum frequency).If it is zero(means no frequency is available with my current res)
///So res is decremented by 1(res--)
ll arr[100005];
ll value_fre[100005];
ll fre_fre[100005];
ll prnt[50005];
ll  sq,res; // 175 * 175 > 30000

struct st
{
    ll l,r,id;
} qu[50005];
bool comp(st &a, st &b)
{
    if (a.l / sq != b.l / sq)
        return a.l< b.l;
    return (a.r < b.r)^(a.l/sq%2);
}

void add(int idx)
{
    fre_fre[value_fre[arr[idx]]]--;
    value_fre[arr[idx]]++;
    fre_fre[value_fre[arr[idx]]]++;
    res = max(res, value_fre[arr[idx]]);
}
void rmv(int idx)
{
    fre_fre[value_fre[arr[idx]]]--;
    value_fre[arr[idx]]--;
    fre_fre[value_fre[arr[idx]]]++;

    if(fre_fre[res] == 0)
        res--;
}
int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        int n,c,q;
        scanf("%d %d %d",&n,&c,&q);

        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);

        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&qu[i].l, &qu[i].r);
            qu[i].id = i;

        }
        sq = sqrt(c);
        sort(qu,qu+q,comp);

        ll l = 1,r = 0;

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

            prnt[qu[i].id] = res;

        }
        printf("Case %d:\n",++w);
        for(int i = 0; i < q; i++)
            printf("%d\n",prnt[i]);

        memset(value_fre,0,sizeof(value_fre));
        memset(fre_fre,0,sizeof(fre_fre));
        res=0;
    }
    return 0;
}
