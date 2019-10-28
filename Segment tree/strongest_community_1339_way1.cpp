#include<bits/stdc++.h>
using namespace std;
#define ll int
///All the communities will be consecutive,this the key idea of this problem
///1st : checked partially overlapped frequency(community)
///2nd : Total overlapped maximum frequency(community) by segment tree
ll arr[100005];
ll cnt[100005];
ll l[100005];
ll r[100005];
ll tree[4 * 100005];

void update(ll node,ll b, ll e,ll idx,ll st)
{

    if(b == e && e == idx)
    {
        tree[node] = st;
        return;
    }

    ll right = node * 2;
    ll left = node * 2 + 1;
    ll mid = (b + e) / 2;

    if(mid>=idx)
        update(left, b,mid,idx,st);
    else
        update(right,mid + 1,e,idx,st);

    if(tree[left]>tree[right])
    {
        tree[node] = tree[left];
    }
    else
    {
        tree[node]= tree[right];
    }
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    //cout<<"haha"<<endl;
    if(b>j || e<i)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll right = node *2;
    ll left = node* 2 + 1;
    ll mid = (b + e) / 2;
    ll li = query(left,b,mid,i,j);
    ll ri = query(right,mid + 1,e,i,j);
    return max(li,ri);
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
        {
            scanf("%d", &arr[i]);
            if(l[arr[i]] == 0)
                l[arr[i]] = i;
            r[arr[i]] = i;
            cnt[arr[i]]++;
        }
        for(int i = 1; i<=n; i++)
            update(1,1,n,i,cnt[arr[i]]);///updated each index with the frequency of it's containing value
        printf("Case %d:\n",++w);
        while(q--)
        {
            int lf,rt;
            scanf("%d %d",&lf,&rt);
            if(arr[lf] == arr[rt])///consecutive element
                printf("%d\n",rt - lf + 1);
            else
            {
                int mx = 0;
                mx = max(mx, r[arr[lf]] - lf + 1);///checked max right position of query's left value
                mx = max(mx, rt - l[arr[rt]] + 1);///checked left position of query's right value
                lf = r[arr[lf]] + 1;
                rt = l[arr[rt]] - 1;
                /// now all the values are totally overlapped in the range as partially
                /// overlapped have checked before
                int ans = query(1,1,n,lf,rt);
                printf("%d\n",max(mx,ans));
            }
        }
        memset(l,0,sizeof(l));
        memset(cnt,0,sizeof(cnt));
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
