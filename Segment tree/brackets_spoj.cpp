#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct st
{
    ll open,close;
} tree[30005 * 4];
string str;
void build(int node, int b, int e)
{
    if(b == e)
    {

        if(str[b] == '(')
            tree[node].open = 1;
        else
            tree[node].close = 1;

        return;
    }

    int mid = (b + e) / 2;
    int lf = node * 2;
    int rt = lf + 1;

    build(lf, b, mid);
    build(rt, mid + 1, e);

    int mn = min(tree[lf].open, tree[rt].close);

    tree[node].open = tree[lf].open + tree[rt].open - mn;
    tree[node].close = tree[lf].close + tree[rt].close - mn;
}

void update(int node, int b, int e, int idx)
{
    if(b == e)
    {
        tree[node].open^=1;
        tree[node].close^=1;

        return;
    }
    int mid = (b + e) / 2;
    int lf = node * 2;
    int rt = lf + 1;

    if(mid>=idx)
        update(lf, b, mid, idx);
    else
        update(rt, mid + 1, e, idx);


    int mn = min(tree[lf].open, tree[rt].close);

    tree[node].open = tree[lf].open + tree[rt].open - mn;
    tree[node].close = tree[lf].close + tree[rt].close - mn;
}

int main()
{
    int t = 10,w = 0;

    while(t--)
    {
        memset(tree,0,sizeof tree);
        int n;
        cin>>n>>str;
        build(1,0,n-1);
        int m;
        scanf("%d",&m);
        printf("Test %d:\n",++w);
        while(m--)
        {
            int idd;
            scanf("%d", &idd);

            if(idd == 0)
            {
                int k1 = tree[1].open;
                int k2 = tree[1].close;
                if(k1 == 0 && k2 == 0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }

            else
                update(1,0,n-1,idd-1);
        }
    }
    return 0;
}
