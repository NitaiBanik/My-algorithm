#include<bits/stdc++.h>
using namespace std;

int ls[40005];
int rs[40005];
bool tree[40005 * 4];


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
set<int>st;
unordered_map<int,int>Map;
int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        for(int i = 0; i <= 40005 *4; i++)
            tree[i] = 1;

        int q;

        scanf("%d",&q);

        for(int i = 0; i < q; i++)
        {
            scanf("%d %d",&ls[i], &rs[i]);
            st.insert(ls[i]);
            st.insert(rs[i]);
        }
        int idx = 1;
        for(auto it = st.begin(); it != st.end(); it++)
        {
            Map[(*it)] = idx++;
        }
        int cn = 0;
        for(int i = q - 1; i >=0; i--)
        {
            bool ans = query(1, 1, 40000, Map[ls[i]], Map[rs[i]]);
            if(ans)
            {
                cn++;
                update(1, 1, 40000,Map[ls[i]], Map[rs[i]]);
            }
        }
        st.clear();
        Map.clear();
        printf("%d\n",cn);

    }
}
