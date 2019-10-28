#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct stt
{
    ll y1,y2,x,type;
} arr[60005];

bool comp(stt f, stt s)
{

    return f.x<s.x;
}

vector<ll>compress;
set<ll>st;
struct tr
{
    ll val,lazy;
} tree[4 * 100005];

ll update(int node, int l, int r, int x, int y,int carry)
{
    if(l > y || r < x)
    {
        if(tree[node].lazy)
            return compress[r + 1] - compress[l];
        return tree[node].val;
    }

    if(l>=x && r<=y)
    {
        tree[node].lazy+=(carry);
        if(tree[node].lazy)
        {
            return compress[r+1] - compress[l];

        }
        else
            return tree[node].val;
    }

    int mid = (l + r )/2;
    int lf = node * 2;
    int rt = lf + 1;
    ll xx = update(lf, l, mid,x,y,carry);
    ll yy = update(rt, mid + 1, r, x,y,carry);
    tree[node].val = xx + yy;

    if(tree[node].lazy)
    {
        return compress[r+1] - compress[l];
    }
    else
        return tree[node].val;

}
int main()
{
    ll t,w = 0;
    cin>>t;

    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll ii = 0;
        ll m = n;
        while(m--)
        {
            ll a,b,c,d;
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            arr[ii].x = a,arr[ii].y1 = b,arr[ii].y2 = d,arr[ii].type = 1;
            ii++;
            arr[ii].x = c,arr[ii].y1 = b,arr[ii].y2 = d,arr[ii].type = -1;
            ii++;
            st.insert(b);
            st.insert(d);
        }
        for(auto it = st.begin(); it != st.end(); it++)
        {
            // cout<<"pos = "<<(*it)<<endl;
            compress.push_back(*it);
        }
        int sz = compress.size();
//        for(int i = 0; i < 2*n; i++)
//            cout<<"Be = "<<arr[i].x<<" "<<arr[i].y1<<" "<<arr[i].y2<<" "<<arr[i].type<<endl;
//
        sort(arr,arr+2*n,comp);

//        for(int i = 0; i < 2*n; i++)
//            cout<<"AF= "<<arr[i].x<<" "<<arr[i].y1<<" "<<arr[i].y2<<" "<<arr[i].type<<endl;

        for(int i = 0; i<2*n; i++)
        {
            // cout<<i<<endl;
            arr[i].y1 = lower_bound(compress.begin(),compress.end(),arr[i].y1) - compress.begin();
            arr[i].y2 = lower_bound(compress.begin(),compress.end(),arr[i].y2) - compress.begin()-1;
            // cout<<arr[i].y1<<" "<<arr[i].y2<<endl;
        }

        ll ans = 0;
        for(int i = 0; i < 2*n-1; i++)
        {
            ll w =  update(1,0,(ll)sz-1,arr[i].y1,arr[i].y2,arr[i].type);

            ans+=(w * (arr[i + 1].x - arr[i].x));
//            cout<<arr[i + 1].x <<" "<< arr[i].x<<endl;
//            cout<<"w = "<<w<<" ans = "<<ans<<endl;
            //cout<<"active = "<<tree[1].val<<endl;
            // cout<<"left = "<<arr[i + 1].x<<" right = "<<arr[i].x<<endl;
            //cout<<"ans = "<<ans<<endl;
        }
        printf("Case %lld: %lld\n",++w,ans);
        memset(tree,0,sizeof(tree));
        st.clear();
        compress.clear();

    }

    return 0;
}
