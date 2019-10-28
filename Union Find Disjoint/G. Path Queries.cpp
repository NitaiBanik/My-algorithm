#include<bits/stdc++.h>
using namespace std;
struct st
{
    long long x,y,z;
    st(long long p, long long q,  long long r)
    {
        x = p,y = q, z = r;
    }
    bool operator <(const st&p) const
    {
        return z<p.z;
    }
};
struct qq
{
    long long x,y;
} Q[200005];
bool comp1(qq x, qq y)
{
    return x.y<y.y;
}

vector<st>vec;
long long par[200005];
long long fre[200005];
long long print[200005];

long long findd(long long x)
{
    if(par[x] == x)
        return x;
    return par[x] = findd(par[x]);
}

void Union(long long a, long long b)
{
    par[findd(b)] = findd(a);
}

int main()
{
    long long n,q;
    cin>>n>>q;
    for(long long i = 0; i <= n; i++)
        par[i] = i,fre[i]++;

    n--;
    while(n--)
    {
        long long x,y,z;
        scanf("%lld %lld %lld", &x, &y, &z);
        vec.push_back(st(x,y,z));

    }
    sort(vec.begin(),vec.end());
    vec.push_back(st(-1,-1,9999999));
    for(long long i = 0; i< q; i++)
    {
        long long x;
        scanf("%lld", &x);
        Q[i].x = i;
        Q[i].y = x;
    }
    sort(Q, Q+q,comp1);
    long long now = 0;
    long long ans = 0;
    for(long long i = 0; i< q; i++)
    {
        long long cost = Q[i].y;
        //cout<<"check cost = "<<cost<<endl;
        while(vec[now].z<=cost)
        {
            long long a = findd(vec[now].x);
            long long b = findd(vec[now].y);

            if(a!=b)
            {
                long long f = fre[a];
                long long s = fre[b];
                fre[a]-=f;
                fre[b]-=s;

                ans-=((f * (f-1))/2);
                ans-=((s * (s-1))/2);
                par[b] = a;
                fre[a]+=(f+s);
                f+=s;
                ans+=((f * (f-1))/2);

                // cout<<"edge_cost "<<vec[now].z<<endl;
                //cout<<"ans = "<<ans<<endl;
            }

            now++;
        }
        print[Q[i].x] = ans;
    }
    for(long long i = 0; i< q; i++)
        cout<<print[i]<<" ";
    return 0;
}
