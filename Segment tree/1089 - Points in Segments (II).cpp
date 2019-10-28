#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct nod
{
    ll start,End;
} arr[500005];

ll yoyo;

ll QQ[500005];
ll tree[500005 * 4];

void update(ll node, ll b, ll e, ll ii, ll j)
{
    if(b>j|| e<ii)
        return;
    if(b>=ii && e<=j)
    {
        tree[node]+=1;
        return;
    }
    ll right = node * 2;
    ll left = node * 2 + 1;
    ll mid = (b + e ) / 2;
    update(left,b, mid, ii,j);
    update(right, mid + 1, e, ii, j);
}

ll query(ll node, ll b, ll e, ll ii,ll carry)
{
    if(ii<b ||ii>e) return 0;

    if(b == e && ii == b)
    {
        return tree[node] + carry;
    }
    ll right = node * 2;

    ll left = node * 2 + 1;

    ll mid = (b + e ) / 2;

    ll x = query(left,b, mid, ii,tree[node]+carry);

    ll y =   query(right,mid+ 1,e, ii,tree[node]+carry);

    return max(x,y);

}

int main()
{
    ll t,w = 0;
    scanf("%lld",&t);

    while(t--)
    {
        memset(tree,0,sizeof(tree));

        map<ll,ll>mp;
        set<ll>st;
        set<ll> :: iterator it;

        ll up,Q,frm,to;

        scanf("%lld %lld",&up,&Q);

        for(int i= 0; i<up; i++)
        {
            scanf("%lld %lld",&arr[i].start,&arr[i].End);
            if(arr[i].start>arr[i].End) swap(arr[i].start,arr[i].End);
            st.insert(arr[i].End);
            st.insert(arr[i].start);
        }

        for(int i=0; i<Q; i++)
        {
            scanf("%lld",&QQ[i]);
            st.insert(QQ[i]);
        }
        ll sz = st.size();
        ll k = 1;
        for(it = st.begin(); it!=st.end(); it++)
        {
            ll va = (*it);
            mp[va] = k;
            k++;
        }

        for(int i=0; i<up; i++)
        {
            update(1,1,sz,mp[arr[i].start],mp[arr[i].End]);
        }

        printf("Case %lld:\n",++w);
        for(int i=0; i<Q; i++)
        {
            ll ans = query(1,1,sz,mp[QQ[i]],0);
            printf("%lld\n",ans);

        }



    }
    return 0;
}
