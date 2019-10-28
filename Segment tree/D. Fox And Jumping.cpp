///D. Fox And Jumping
#include<bits/stdc++.h>
using namespace std;
#define mx 200000
#define ll long long
vector<ll>tree[mx * 4];
ll cum[mx + 5];
int x = 0;
void mergee(int parent, int child1, int child2)
{
    int sz1 = tree[child1].size();
    int sz2 = tree[child2].size();
    int f = 0, s = 0;
    while(1)
    {
        if(f == sz1 && s == sz2)
            break;

        if((f == (sz1)))
        {
            tree[parent].push_back(tree[child2][s++]);
        }
        else if((s == (sz2)))
        {
            tree[parent].push_back(tree[child1][f++]);
        }
        else if((tree[child2][s] > tree[child1][f]))
        {
            tree[parent].push_back(tree[child1][f++]);
        }
        else
            tree[parent].push_back(tree[child2][s++]);
    }
}

void build(int node, int beg, int End)
{
    if(beg == End)
    {
        tree[node].push_back(cum[beg]);
        return;
    }

    int mid = ( beg + End ) / 2;
    int left = node * 2;
    int right = left + 1;

    build(left,beg, mid);
    build(right, mid + 1, End);
    mergee(node, left, right);
}

ll sum = 0;
void query(int node, int l, int r, int x, int y, ll W)
{
    if(l > y || r < x)
        return;

    if(l >= x && r <= y)
    {
        ll k = lower_bound(tree[node].begin(), tree[node].end(), W) - tree[node].begin();
        //cout<<W<<endl;
        sum+=k;
        return;
    }

    int mid = ( l + r) / 2;
    int left = node * 2;
    int right = left + 1;

    query(left, l, mid, x, y, W);
    query(right, mid + 1, r, x, y, W);
}

int main()
{

    ll n,k,value,p;
    scanf("%lld %lld",&n, &p);

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&value);
        cum[i] = cum[i - 1] + value;
    }

    build(1,1,n);
    for(int i = 1; i<=n; i++)
    {
        query(1,1,n,i,n,cum[i - 1] + p);
    }
    cout<<sum<<endl;
    return 0;
}
