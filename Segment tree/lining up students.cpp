#include<bits/stdc++.h>
using namespace std;

int tree[4 * 100005];
int arr[100005];
///Idea : Iterate from right
///Suppose I'm at a position(i) and I need 3 values greater than it.
///If I have 8 values I have to put 5th value at this position.After putting 5th value I have made 5th value off.
///decremented by N by 1(N--), as one value is positioned.
void build(int node, int l, int r)
{

    if(l == r)
    {
        //cout<<1<<endl;
        tree[node] = 1;
        return;
    }
    int md = (l + r)/2;
    int lf = node*2;
    int rt = lf + 1;

    build(lf, l, md);
    build(rt, md+1, r);
    tree[node] = tree[lf] + tree[rt];

}
int ans;
void query(int node, int l, int r, int idx)
{
    if(l == r)
    {
        //cout<<l<<endl;
        tree[node] = 0;
        ans = l;
        return;
    }

    int md = (l + r)/2;
    int lf = node * 2;
    int rt = lf + 1;

    if(tree[lf] >= idx)
        query(lf, l,md, idx);
    else
        query(rt, md + 1, r,idx - tree[lf]);
    tree[node] = tree[lf] + tree[rt];

}
int main()
{
    int t,w = 0;

    cin>>t;

    while(t--)
    {
        int n;
        scanf("%d", &n);

        for(int i = 1; i<=n ; i++)
            scanf("%d", &arr[i]);
        build(1,1,n);
        int k;
        k = n;
        for(int i = k; i >=1; i--)
        {
            query(1,1,k,n - arr[i]);
            n--;
        }
        printf("Case %d: %d\n",++w, ans);

    }
    return 0;

}
