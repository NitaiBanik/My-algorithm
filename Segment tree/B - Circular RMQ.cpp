#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 99999999999999
struct st
{
    ll val,lazy;
} tree[200002 * 4];

ll arr[200005];
void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].val = arr[b];

        //cout<<"b = "<<b<<" e = "<<e<<endl;
        //cout<<"ok= "<<tree[node].val<<endl;
        return;
    }


    int mid = (b + e)/2;
    int lf = node*2;
    int rt = lf + 1;
    build(lf,b, mid);
    build(rt,mid + 1, e);

    tree[node].val = min(tree[lf].val,tree[rt].val);
}
void update(int node, int b, int e, int x, int y, ll carry, ll  w)
{
   // cout<<"up = "<<endl;
    if(b>y || e < x)
    {
        tree[node].lazy+=carry;
        tree[node].val+=carry;
        return;
    }

    if(b>=x && e<=y)
    {
       // cout<<"carry "<<carry<<" w = "<<w<<endl;
        tree[node].lazy+=(carry + w);
        tree[node].val+=(carry + w);
        return;
    }

    int mid = (b + e)/2;
    int lf = node*2;
    int rt = lf + 1;
    //  cout<<"hi"<<endl;
    update(lf, b, mid, x, y, carry + tree[node].lazy,w);
    update(rt,mid + 1, e,x, y, carry + tree[node].lazy,w);
    tree[node].lazy = 0;
    tree[node].val = min(tree[lf].val, tree[rt].val);

}

ll query(int node, int b, int e, int x, int y, ll carry)
{
    if(b>y || e < x)
    {

        return mxx;
    }

    if(b>=x && e<=y)
    {
//        cout<<"b = "<<b<<" e = "<<e<<endl;
        //cout<<"carr = "<<carry<<endl;
       // cout<<"haha = "<<tree[node].val<<endl;
        return tree[node].val+(carry);
    }

    int mid = (b + e)/2;
    int lf = node*2;
    int rt = lf + 1;

    ll xx = query(lf, b, mid, x, y, carry + tree[node].lazy);
    ll yy = query(rt,mid + 1, e,x, y, carry + tree[node].lazy);
    //cout<<"xx = "<<xx<<" yy = "<<yy<<endl;
    return min(xx,yy);
}

int main()
{
    memset(tree,0,sizeof(tree));
    int n;
    cin>>n;
    for(int i = 1; i<=n ; i++)
        scanf("%lld", &arr[i]);
    build(1,1,n);
    int q;
    cin>>q;
    getchar();
    while(q--)
    {
        string w;
        getline(cin,w);
        // cout<<"w = "<<w<<endl;
        istringstream ss(w);
        int cn = 0;
        int x,y,z,p;
        while(ss>>p)
        {
            cn++;
            if(cn == 1)
                x = p;
            if(cn == 2)
                y = p;
            if(cn == 3)
                z = p;
        }
        x++,y++;
        //   cout<<"x = "<<x<<"y = "<<y<<endl;
        if(cn == 2)
        {
            if(x<=y)
                cout<<query(1,1,n,x,y,0)<<endl;
            else
            {
                ll p = query(1,1,n,x,n,0);
                ll q = query(1,1,n,1,y,0);
               // cout<<"yo = "<<p<<" "<<q<<endl;
                cout<<min(p,q)<<endl;
            }
        }
        else
        {
            if(x<=y)
                update(1,1,n,x,y,0,z);
            else
            {
                update(1,1,n,x,n,0,z);
                update(1,1,n,1,y,0,z);
            }
        }
    }
}
