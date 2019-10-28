#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];
ll krr[100005];
ll sum[400005];
ll prop[400005];

void build(int node,int l, int r)
{
    if(l == r)
    {
        sum[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

ll query(int node, int l, int r, int x, int y, ll cary)
{
    if(l > y || r < x)
        return 0LL;

    if(l>=x && r<= y)
        return sum[node] + (r - l + 1) * cary;
    int mid = (l + r) / 2;
    ll xx = 0, yy = 0;
    xx = query(node * 2, l, mid, x, y, cary + prop[node]);
    yy = query(node * 2 + 1,mid + 1, r, x, y, cary + prop[node]);

    return xx + yy;
}

void update(int node, int l, int r, int x, int y, ll add)
{
    if(l > y || r < x)
        return;

    if(l>=x && r<= y)
    {
        prop[node]+=add;
        sum[node] +=  (r - l + 1) * add;
        return;
    }

    int mid = (l + r) / 2;

    update(node * 2, l, mid, x, y, add);
    update(node * 2 + 1,mid + 1, r, x, y,add);

    sum[node] = sum[node * 2] + sum[node * 2 + 1] + (r - l + 1) * prop[node];

}
set<ll>st;


int main()
{
    int n,k;
    scanf("%d", &n);

    for(int i = 1; i<=n ; i++)
        scanf("%lld",&arr[i]);
    build(1,1,n);
    for(int i = 1; i<n ; i++)
        scanf("%lld",&krr[i]);

    for(int i = 1; i<= n + 1; i++)
        st.insert(i);

    int q;
    scanf("%d",&q);

    while(q--)
    {
        char s;
        ll x,y;
        cin>>s;
        scanf("%lld %lld",&x,&y);
        if(s == 's')
        {
            ll suum = query(1,1,n,x,y,0);
            printf("%lld\n",suum);
        }
        else
        {
            st.insert(x);
            auto it1 = st.lower_bound(x);
            auto it2 = it1;
            it2++;
            update(1,1,n,*it1, (*it2) - 1,y);///range update
            it1++;
            while(1)
            {
                if((*it1) == n + 1)
                    break;

                ll next = query(1,1,n,(*it1),(*it1),0);///i+1 check
                ll prev = query(1,1,n,(*it1) - 1,(*it1) - 1,0) + krr[(*it1) - 1] ;///i - 1 check
                if(prev > next)
                {
                    it2 = it1;
                    it2++;///for next index
                    update(1,1,n,(*it1),(*it2) - 1,prev - next);///range updated, as we add something in a index,
                    /// all the indexes that was updated previously for that index will be increased by same value.

                    st.erase((*it1));///updated index is deleted for making it as range update
                    it1 = it2;

                }
                else break;
            }
        }
    }
    return 0;
}
