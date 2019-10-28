
//#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

using namespace std;
#define ll int
ll arr[1000005];
struct sr
{
    ll mx,mn;
} tree[1000005 * 8],vec[1000005];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].mn = arr[b];
        tree[node].mx = arr[b];
        return;
    }

    ll mid = (b + e) / 2;

    ll left = node * 2;

    ll right = node * 2 + 1;

    init(left,b, mid);

    init(right, mid+1,e);

    tree[node].mn = min(tree[left].mn,tree[right].mn);

    tree[node].mx = max(tree[left].mx,tree[right].mx);
}

sr query(ll node, ll b,ll e, ll i, ll j)
{
    if(e<i || b>j)
    {
        sr xx;
        xx.mn = 9999999;
        xx.mx  = -9999999;
        return xx;
    }
    if(b>=i && e<=j)
    {
        //cout<<tree[node].mx - tree[node].mn<<endl;
        return tree[node];
    }

    ll mid = (b + e) / 2;

    ll left = node * 2;

    ll right = node * 2 + 1;

    sr aa =  query(left,b,mid,i,j);
    sr bb = query(right, mid+1,e,i,j);
    sr save;
    save.mn = min(aa.mn,bb.mn);
    save.mx = max(aa.mx,bb.mx);

    return save;

}
int main()
{
    ll t,w = 0;
    ll n,d;

    scanf("%d %d",&n,&d);

    for(int ii=1; ii<=n; ii++)
        scanf("%d",&arr[ii]);

    init(1,1,n);

    int k = 0;
    if(d>n)
        d = n;
    for(int ii=1; ii<=n-d+1; ii++)
    {
        sr calc = query(1,1,n,ii,ii+d-1);
        vec[k].mx = calc.mx;
        vec[k].mn = calc.mn;
        k++;
    }
    for(int i=0; i<k; i++)
    {
        if(i>0) printf(" ");
        printf("%d",vec[i].mn);
    }
     printf("\n");
    for(int i=0; i<k; i++)
    {
        if(i>0) printf(" ");
        printf("%d",vec[i].mx);
    }
    printf("\n");

}
