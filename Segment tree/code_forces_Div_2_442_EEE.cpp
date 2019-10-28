#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll start[200005];
ll End[200005];
bool vis[200005];

vector<ll>graph[200005];
ll node;

ll arr[500005];

ll tym = 0;

struct st
{
    ll zero,one,lazy;
} tree[200005 * 8];

void dfs(ll src)
{
    if(vis[src] == true) return;
    vis[src] = true;
    start[src] =++tym;
    for(int i=0; i<graph[src].size(); i++)
        if(vis[graph[src][i]] == false )
            dfs(graph[src][i]);
    End[src] = tym;
}

void build(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(arr[b] == 1)
            tree[node].one = 1;
        else
            tree[node].zero = 1;
        tree[node].lazy = 0;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    build(left,b,mid);
    build(right,mid + 1, e);

    tree[node].one = tree[left].one + tree[right].one;
    tree[node].zero = tree[left].zero + tree[right].zero;
    //tree[node].lazy = tree[left].lazy+ tree[right].lazy;
}

void update(ll node, ll b, ll e, ll i, ll j, ll carry)
{

    if(b>j || e<i)
    {
         if(carry%2 == 1) swap(tree[node].zero,tree[node].one);
          tree[node].lazy+=carry;
        return;
    }

    if(b>=i && e<=j)
    {

        if((carry + 1)%2 == 1) swap(tree[node].zero,tree[node].one);
        tree[node].lazy++;
        tree[node].lazy+=carry;
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    update(left,b,mid,i,j,carry+ tree[node].lazy);
    update(right,mid+1,e,i,j,carry+ tree[node].lazy);

    tree[node].lazy = 0;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].zero = tree[left].zero + tree[right].zero;
}

ll query(ll node, ll b, ll e,ll i,ll j, ll carry)
{
    if(b>j || e < i) return 0;

    if(b>=i && e<=j)
    {
        if(carry%2 == 0)
          return tree[node].one;
          else
          return tree[node].zero;

    }
     ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    ll lf = query(left,b,mid,i,j,carry+ tree[node].lazy);
    ll rt = query(right,mid + 1, e,i,j,carry+ tree[node].lazy);

  // tree[node].lazy = 0;
//    tree[node].one = tree[left].one + tree[right].one;
//    tree[node].zero = tree[left].zero + tree[right].zero;
    return lf + rt;
}

int main()
{
    scanf("%lld",&node);

    int x;

    for(int i=2; i<=node; i++)
    {
        scanf("%lld",&x);
        graph[x].push_back(i);
    }

    dfs(1);

//    for(int i=1; i<=node; i++)
//    {
//        cout<<start[i]<<" "<<End[i]<<endl;
//    }

    for(int i=1; i<=node; i++)
    {
        scanf("%lld",&x);
        arr[start[i]] = x;
    }

    build(1,1,node);
    int Q,pos;
    string op;
    cin>>Q;
    while(Q--)
    {
        cin>>op>>pos;
        if(op == "pow") update(1,1,node,start[pos],End[pos],0);
        else
        {
            ll ans = query(1,1,node,start[pos],End[pos],0);
            printf("%lld\n",ans);
        }

    }

    return 0;
}
