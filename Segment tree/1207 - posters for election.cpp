#include<bits/stdc++.h>
using namespace std;

int ls[200005];
int rs[200005];
bool tree[200005 * 6];


void update(int node, int b, int e, int x, int y)
{
    if(b>y || e < x)
        return;

   if(tree[node] == 0)
        return;

    if(b >= x && e <= y)
    {
        tree[node] = 0;
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    update(left, b, mid, x, y);
    update(right, mid + 1, e, x, y);
    tree[node] = tree[left] | tree[right];
}

bool query(int node, int b, int e,int x, int y)
{
    if(b>y || e < x)
        return 0;

   if(tree[node] == 0)
        return 0;
    if(b >=x && e <= y)
        return tree[node];

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left + 1;

    bool xx = query(left, b, mid, x, y);
    bool yy = query(right,mid + 1,e, x, y);
    return xx|yy;

}

int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        for(int i = 0; i <= 200000 * 6; i++)
            tree[i] = 1;

        int q;

        scanf("%d",&q);

        for(int i = 0; i < q; i++)
            scanf("%d %d",&ls[i], &rs[i]);

        int cn = 0;
        for(int i = q - 1; i >=0; i--)
        {
            bool ans = query(1, 1, 200000, ls[i], rs[i]);
            if(ans)
            {
                cn++;
                update(1, 1, 200000, ls[i], rs[i]);
            }
        }

        printf("Case %d: %d\n",++w,cn);

    }
}
