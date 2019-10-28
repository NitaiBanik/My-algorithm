#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[12][12];

struct s
{
    ll row,col;
} arr[13];

ll ans;

vector<pair<ll,ll> > vec;

ll MCM(ll b, ll e)
{
    if(b>=e) return 0;
    if(dp[b][e]!=-1) return dp[b][e];

    ll ret = 100000000000000000;
    for(ll i=b; i<e; i++)
    {
        ll left = MCM(b,i);
        ll right = MCM(i+1,e);
        ll cur = arr[b].row * arr[i].col * arr[e].col;

        ret = min(ret,left + right + cur);
    }
    return dp[b][e] = ret;
}

void path(ll b, ll e)
{
    if(b>=e) return;
    ll s = MCM(b,e);
    for(ll i=b; i<e; i++)
    {
        ll p = MCM(b,i);
        ll q = MCM(i+1,e);
        ll c = arr[b].row * arr[i].col * arr[e].col;
        if(p+q+c == s)
        {
            if(b!=i)vec.push_back(make_pair(b,i));
            if(i+1!=e)vec.push_back(make_pair(i+1,e));
            path(b,i);
            path(i+1,e);
            break;
        }
    }
}
int main()
{
    //freopen("in.txt","w",stdout);
    ll t,w = 0;

    while(scanf("%lld",&t) == 1 && t!=0)
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<t; i++)
        {
            scanf("%lld %lld",&arr[i].row,&arr[i].col);
        }
        ans = MCM(0,t-1);
        // cout<<ans<<endl;
        path(0,t-1);
        string s1[1000];
        string s2[1000];
//        s1[0]+='(';
//        s2[t-1]+=')';
        int vis[12][12];
        memset(vis,-1,sizeof(vis));
        for(int i=0; i<vec.size(); i++)
        {

            int f = vec[i].first;
            int ss = vec[i].second;

            s1[f]+='(';
            s2[ss]+=')';

        }
        vec.clear();

        printf("Case %lld: (",++w);
        for(int i=0; i<t; i++)
        {
            cout<<s1[i]<<"A"<<i+1<<s2[i];
            if(i!=t-1)
                cout<<" x ";
        }
        cout<<")"<<endl;
    }
    return 0;
}
