#include<bits/stdc++.h>
using namespace std;
#define ll int
struct
{
    ll on,of,lazy;
}tree[100005 * 4];

void build(ll node, ll b ll e)
{
    if(b == e)
    {
        tree[node].on = 0;
        tree[node].of = 1;
        tree[node].lazy = 0;
        return ;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    build(left,b,mid);
    build(right,mid + 1, e);
    tree[node].lazy = 0;
    tree[node].on = 0;
    tree[node].of = tree[left].of + tree[right].of;
}

int main()
{

}
