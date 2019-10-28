#include<bits/stdc++.h>
using namespace std;
#define ll int
struct st
{
    ll mx,pos;
} tree[2005 * 4];

ll arr[2005];

ll N,M;

void build(ll node,ll b, ll e)
{

    if(b == e)
    {
        tree[node].mx = arr[b];
        tree[node].pos = b;
        return;
    }
    ll right = node *2;
    ll left = node* 2 + 1;
    ll mid = (b + e) / 2;

    build(left, b,mid);
    build(right,mid + 1,e);

    if(tree[left].mx<tree[right].mx)
    {
        tree[node].mx = tree[left].mx;
        tree[node].pos = tree[left].pos;
    }
    else
    {
        tree[node].mx = tree[right].mx;
        tree[node].pos = tree[right].pos;
    }
}

st query(ll node, ll b, ll e, ll i, ll j)
{

    if(b>j || e<i)
    {
        st x;
        x.mx = 99999999;
        x.pos = 9999999;
        return x;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll right = node * 2;
    ll left = node * 2 + 1;
    ll mid = (b + e) / 2;
    st l = query(left,b,mid,i,j);
    st r = query(right,mid + 1,e,i,j);
    st w;
    if(l.mx<r.mx)
    {
        w.mx = l.mx;
        w.pos = l.pos;
    }
    else
    {
        w.mx = r.mx;
        w.pos = r.pos;
    }
    return w;
}
ll fun(ll beg, ll End)
{
    if(beg>End)
        return 0;

    if(beg == End)
    {
        return arr[beg];
    }

    st val = query(1,1,M,beg,End);
    ll ans1 = 0,ans2 = 0;
    ans1 = max(val.mx * (End - beg + 1),max(fun(beg,val.pos-1),fun(val.pos+1,End)));
    return ans1;
}
string str[2005];
int value[2005][2005];

int main()
{
    ll t,w = 0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&N,&M);
        for(int i=1; i<=N; i++)
        {
            string s;
            cin>>s;
            str[i] = '0' + s;

        }
        ll ANS = 0;
        for(int i = N; i>=1; i--)
        {
            for(int j = 1; j<=M; j++)
            {
                if(str[i][j] == '1')
                    value[i][j] = 0;
                else
                    value[i][j] = 1 + value[i + 1][j];
                arr[j] = value[i][j];
                value[i + 1][j] = 0;
            }

            build(1,1,M);

            ANS = max(ANS,fun(1,M));

        }
        printf("Case %d: %d\n",++w,ANS);
    }
    return 0;
}
