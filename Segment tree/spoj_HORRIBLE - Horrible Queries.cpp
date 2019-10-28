#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
struct st
{
    ll lazy,sum;
} tree[100005 * 4];

void update(ll node, ll b, ll e, ll start, ll End, ll prop)
{
    if(e<start || b>End)
        return;
    if(b>=start && e<=End)
    {
        tree[node].lazy+=prop;
        tree[node].sum+=((e - b + 1) * prop);
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/ 2;
    update(left, b, mid,start,End,prop);
    update(right, mid+1,e,start,End,prop);
    tree[node].sum  = tree[left].sum + tree[right].sum + (e - b +1)*tree[node].lazy;
}

ll query(ll node, ll b, ll e, ll start, ll End, ll carry)
{
    if(e<start || b>End)
        return 0;
    if(b>=start && e<=End)
    {
        //cout<<carry<<endl;
        return tree[node].sum+((e - b + 1) * carry);
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e)/ 2;
    ll x = query(left, b, mid,start,End,carry + tree[node].lazy);
    ll y = query(right, mid+1,e,start,End,carry + tree[node].lazy);
    return x + y;
}

int main()
{
    ll T, N,Q,type;
    scanf("%lld",&T);
    while(T--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%lld %lld",&N, &Q);
        while(Q--)
        {
            scanf("%lld",&type);
            if(type == 0)
            {
                ll frm,to,val;
                scanf("%lld %lld %lld",&frm,&to,&val);
                update(1,1,N,frm,to,val);
            }
            else
            {
                ll frm,to;
                scanf("%lld %lld",&frm,&to);
                ll ans = query(1,1,N,frm,to,0);
                printf("%lld\n",ans);
            }
        }

    }
}
