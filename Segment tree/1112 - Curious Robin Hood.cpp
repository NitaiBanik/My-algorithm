#include<bits/stdc++.h>
using namespace std;
#define ll int
ll tree[30][100005 * 4];

void update(int node, int b, int e, int i,int val,int ch)
{
    if(e<i || b>i)
        return;
    if(b== e)
    {
        tree[ch][node]+=val;
        return;
    }
    ll left = node * 2;

    ll right = node * 2 + 1;

    ll mid = (b + e)/2;

    if(mid>=i)update(left,b, mid,i,val,ch);

   else update(right,mid + 1, e,i,val,ch);

    tree[ch][node] = tree[ch][left] + tree[ch][right];

}

ll query(int node, int b, int e, int i, int j, int ch)
{
    if(e<i || b>j)
        return 0 ;
    if(b>= i &&  e<=j)
    {
        return tree[ch][node];
    }
    ll left = node * 2;

    ll right = node * 2 + 1;

    ll mid = (b + e)/2;

    ll x = query(left,b, mid,i,j,ch);

    ll y = query(right,mid + 1, e,i,j,ch);

    return x + y;

}

int main()
{
    memset(tree,0,sizeof(tree));
    string str;
    cin>>str;
    str = '0' + str;
    int n = str.size();
    for(int i = 1; i < n; i++)
    {
        int xx = str[i] - 'a';
        update(1,1,n,i,1,xx);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type == 1)
        {
            int po;
            char cc;
            scanf("%d %c",&po,&cc);
            update(1,1,n,po,-1,str[po]-'a');
            str[po] = cc;
            update(1,1,n,po,1,cc-'a');
        }
        else
        {
            int ii,jj;
            scanf("%d %d", &ii, &jj);
            int cn = 0;

            for(char y = 'a'; y<='z'; y++)
            {
                int xz = y - 'a';
                int ww = query(1,1,n,ii,jj,xz);
                if(ww>0)
                    cn++;
            }
            printf("%d\n",cn);
        }
    }
}
