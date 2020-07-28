#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<tuple<ll,ll,ll> >vec;

ll x[2005];
ll y[2005];
ll c[2005];
ll k[2005];
ll sz[2005];
ll par[2005];

int findd(ll p)
{
    if(par[p] == p)
        return p;

    else
        return findd(par[p]);
}


int Union(ll u, ll v)
{
    u = findd(u);
    v = findd(v);

    if(u == v)
        return 0;

    if(sz[u]<sz[v])
        swap(u,v);
    par[v] = u;
    sz[u]+=sz[v];

    return 1;
}
int main()
{

    ll n;
    cin>>n;

    for(ll i = 1; i<=n ; i++)
        scanf("%lld %lld",&x[i], &y[i]);

    for(ll i = 1; i<=n ; i++)
        scanf("%lld",&c[i]);

    for(ll i = 1; i<=n ; i++)
        scanf("%lld",&k[i]);

    for(ll i = 1; i<= n; i++)
        vec.push_back(make_tuple(c[i],0,i));
    for(ll i = 0; i<= n; i++)
        sz[i] = 1, par[i] = i;

    for(ll i = 1; i<= n; i++)
        for(ll j = i+1; j<= n; j++)
        {
            ll cc = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            cc *= (k[i] + k[j]);
           vec.push_back(make_tuple(cc,i,j));
        }

    sort(vec.begin(),vec.end());
    ll ans = 0;
    vector<ll>center;

    vector<pair<ll,ll> >Pair;

    for(ll i = 0; i < vec.size(); i++)
    {
        ll cc =  get<0>(vec[i]);
        ll u =  get<1>(vec[i]);
        ll v =  get<2>(vec[i]);
        if(Union(u,v))
        {
            ans+=cc;
            if(u == 0)
            {
                center.push_back(v);
            }
            else
                Pair.push_back({u,v});

        }
    }

    cout<<ans<<endl;
    cout<<center.size()<<endl;
    for(auto x : center)
        cout<<x<<" ";
    cout<<endl<<Pair.size()<<endl;
    for(auto x : Pair)
        cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
