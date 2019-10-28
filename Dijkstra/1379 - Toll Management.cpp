#include<bits/stdc++.h.
using namespace std;

#define ll long long
#define siz 100005
vector<ll>graph[siz],cost[siz];
ll dis[size];

struct node
{

    ll frm,cost,mx;
    bool operator < (const node & b ) const
    {
        return cost > b.cost;
    }
};

int main()
{

}
