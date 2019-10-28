#include<bits/stdc++.h>
using namespace std;

int tree[100005 * 4];
int ck[100005 * 4];
int arr[100005 * 4];

void update(int node, int l, int r, int cap)
{
    if(l == r)
    {
        ck[l] = 1;
        tree[node]-=cap;
        arr[l]-=cap;
        return ;
    }

    int mid = (l + r) / 2;

    int lf = node * 2;
    int rt = node * 2 + 1;

    if(tree[lf]>=cap)
        update(lf, l, mid, cap);
    else
        update(rt, mid + 1, r, cap);

    tree[node] = max(tree[lf], tree[rt]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int cap;
        scanf("%d", &cap);

        for(int i = 1; i<= 100000 * 4; i++)
            tree[i] = cap, ck[i] = 0,arr[i] = cap;

        int z;
        scanf("%d", &z);

        int k = 0;
        while(k!=z)
        {
            char str[15];
            scanf("%s", str);

            if(str[0] == 'b')
            {
                int x, y;
                scanf("%d %d", &x, &y);
                k+=x;
                while(x--)
                    update(1,1, 100000, y);
            }
            else
            {
                k++;
                int w = 0;
                int ln = strlen(str);
                for(int i = 0; i < ln; i++)
                    w = w * 10 + (str[i] - '0');
                update(1,1,100000, w);

            }
        }

        int cnt = 0,wt = 0;

        for(int i = 1; i<= 100000; i++)
            if(ck[i] == 1)
                cnt++, wt+=arr[i];

        printf("%d %d\n", cnt,wt);
    }
    return 0;
}
