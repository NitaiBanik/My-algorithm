#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll tree[1000006 * 4];

void update(int node, int l, int r,int idx)
{
    if(r<idx || l>idx)
        return;
    if(l == idx && r == idx)
    {
        tree[node]++;
        return ;
    }

    int mid = (l + r)/2;
    update(node*2,l,mid,idx);
    update(node*2+1,mid+1,r,idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find_kth(int node, int l, int r, int kth)
{
    if(tree[node]<kth) return -1;
    if(l == r)
        return l;

    int mid = (l + r)/2;

    if(tree[node*2]>=kth)
        return find_kth(node*2,l,mid,kth);

    else
        return find_kth(node * 2+1,mid+1,r,kth-tree[node * 2]);
}

int main()
{

    int n,q,val;

    cin>>n;

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&val);
        update(1,1,1000000,val);

      val = find_kth(1,1,1000000,3);
      printf("3rd value = %d\n",val);
    }

    return 0;


}
