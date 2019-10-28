#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<int,int>mp;

int arr[20005];
int vec[20005];
ll res[20005];
int n;

ll tree[20002];

#define sq 142
ll ans;

struct query
{
    int l,r,id;
} Q[20005];

bool comp(query &a, query &b)
{
    if (a.l / sq != b.l / sq)
        return a.l< b.l;
    return (a.r < b.r)^(a.l/sq%2);
}
void update(int idx,int x)
{
    while(idx<=n)
    {
        tree[idx]+=(ll)x;
        idx+=(idx & (-idx));
    }
}

ll query(int idx)
{
    ll sum = 0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main()
{
    int q;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        vec[i-1] = arr[i];
    }

    sort(vec, vec + n);

    for(int i = 0; i < n; i++)
        if(mp.find(vec[i]) == mp.end())
            mp[vec[i]] = i + 1;

    for(int i=1; i<=n; i++)
        arr[i] = mp[arr[i]];
scanf("%d", &q);
    for(int i = 0 ; i < q; i++)
    {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }

//    for(ll i=1; i<=n; i++)
//        cout<<arr[i<<" ";
//    cout<<endl;

    sort(Q, Q + q, comp);

    int l = 1, r = 0;
    ans = 0;
    for(int i = 0; i < q ; i++)
    {
        while(l<Q[i].l)
        {
            ans-=query(arr[l] - 1);

            update(arr[l],-1);
            l++;
        }
        while(l>Q[i].l)
        {
            l--;
            ans+=query(arr[l]- 1);

            update(arr[l],1);
        }

        while(r<Q[i].r)
        {
            ++r;
            ans+=( query(n) -  query(arr[r]));

            update(arr[r],1);
        }
        while(r>Q[i].r)
        {
            ans-=( query(n) -  query(arr[r]));
            update(arr[r],-1);
            r--;
        }
        res[Q[i].id] = ans;
    }

    for(int i = 0; i < q ; i++)
        printf("%lld\n",res[i]);


}
