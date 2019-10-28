#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st
{
    ll frm,to,val,id;
} Q[100005];

ll tree[100005 * 4];

ll prev[100005];
ll Val[100005];
ll arr[100005];
bool comp(st A, st B)
{
    if(A.to == B.to)
        return A.frm<B.frm;
    else return A.to<B.to;
}
bool comp1(st A, st B)
{
        return A.id<B.id;
}

void update(long long node, long long b, long long e, long long i,long long v)
{
    if(e<i || b>i) return;
    if(b== e)
    {
        if(v== 0)
        {
            tree[node]-=1;
            Val[i] = 0;
        }
        else
        {
            tree[node]+=1;
            Val[i] = 1;
        }
        return;
    }
    ll left = node * 2;

    ll right = node * 2 + 1;

    ll mid = (b + e)/2;

    update(left,b , mid,i,v);

    update(right,mid + 1 , e,i,v);

    tree[node] = tree[left] + tree[right];

}

ll query(long long node, long long b, long long e, long long i, long long j)
{
    if(e<i || b>j) return 0 ;
    if(b>= i &&  e<=j)
    {
        return tree[node];
    }
    ll left = node * 2;

    ll right = node * 2 + 1;

    ll mid = (b + e)/2;

    ll x = query(left,b , mid,i,j);

    ll y = query(right,mid + 1 , e,i,j);

    return x + y;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(prev,-1,sizeof(prev));
        memset(prev,0,sizeof(val));
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
            int cnn = 0;
        for(int i=1; i<=n-q+1; i++)
        {
            cnn++;
            scanf("%d %d",&Q.frm,&Q.to);
            Q.id = i;
        }
        int track = 0,anns = 0;
        sort(Q,Q+q,comp);
        for(int i=1; i<=n; i++)
        {
            if(prev[arr[i]] == -1)
            {
                update(1,1,n,i,1);
                prev[arr[i]] = i;
            }
            else
            {
                update(1,1,n,prev[arr[i]],0);
                update(1,1,n,i,1);
                prev[arr[i]] = i;
            }
            while(track<cnn && Q[track].to == i)
            {
                ll ans = query(1,1,n,Q[track].frm,Q[track].to);
                Q[track].val = ans;
                anns = max(anns,ans)
            }
        }
      cout<<anns<<endl;
    }
    return 0;
}
