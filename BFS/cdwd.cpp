#include<bits/stdc++.h>
using namespace std;

struct st
{
    int l,r,id;
} arr[100005];
int p[100005];
bool comp(st x, st y)
{
    if(x.l == y.l)
        return x.r > y.r;
    else
        return x.l < y.l;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        int n,ans = 0;
        scanf("%d",&n);
        for(int i = 0; i< n; i++)
        {
            scanf("%d %d",&arr[i].l, &arr[i].r);
            arr[i].id = i;
        }
        sort(arr,arr+n,comp);
        int lf = arr[0].l;
        int rt = arr[0].r;
        p[arr[0].id] = 1;
        int cn = 1;
        for(int i = 1; i< n; i++)
        {
            if(arr[i].l<=rt)
            {
                cn++;
                rt = max(rt,arr[i].r);
                p[arr[i].id] = 1;
            }
        }
        if(cn == n)
            cout<<-1<<endl;
        else
        {
            for(int i = 0; i < n; i++)
                if(p[i] == 0)
                    p[i] = 2;
            for(int i = 0; i < n; i++)
                printf("%d ",p[i]);
            cout<<endl;
        }
    }

}
