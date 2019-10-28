#include<bits/stdc++.h>
using namespace std;
#define mx 1429438

int tree[mx * 4];

void update(int node, int l, int r, int idx, int st)
{
    if(l == r && idx == l)
    {
        tree[node] = st;
        return;
    }

    int mid = (l + r) >> 1;

    if(mid>=idx)
        update(node<<1, l, mid, idx,st);
    else
        update((node<<1) + 1, mid + 1, r,idx,st);
    tree[node] = tree[node<<1] + tree[(node<<1) + 1];
}
int sum,id;

void query(int node, int l,int r)
{
    if(l == r)
    {
        id = l;
        return;
    }

    int mid = (l + r)>>1;
    int lf = node<<1;
    int rt = lf + 1;

    if(tree[lf]>=sum)
        query(lf, l, mid);
    else
    {
        sum-=tree[lf];
        query(rt, mid + 1, r);
    }

}
int main()
{

    for(int i = 1; i<= mx-5; i+=2)
        update(1,1,mx-5,i,1);
    for(int i = 2; i<=mx - 2; i++)
    {
        sum = i;
        if(sum>(tree[1]))
            break;
        query(1,1,mx-5);
        int increase = id;
        int dd = id-1;
        // cout<<"id = "<<id<<endl;
        sum = 0;
        while(1)
        {

            sum = increase;
            increase+=dd;
            //  if(i == 3)
            // cout<<"sum = "<<sum<<endl;
            if(sum>(tree[1]))
                break;
            query(1,1,mx-5);
//              if(i == 3){
//            //cout<<"updated at "<<id<<endl;
//            getchar();
//              }
            update(1,1,mx - 5,id,0);

        }
    }
    int t,nth,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&nth);
        sum = nth;
        query(1,1,mx-5);
        printf("Case %d: %d\n",++w,id);
    }

}
