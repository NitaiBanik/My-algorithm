#include<bits/stdc++.h>
using namespace std;

long long par[100005];
long long cnt[100005];

vector<long long>vec;

long long findd(long long x)
{
    if(par[x] == x) return x;
    else return par[x] = findd(par[x]);

}

void unio(long long a, long long b)
{
    par[findd(b)] = findd(a);
}

int main()
{
    for(int i=0; i<=100001; i++) par[i] = i;

    long long n;

    scanf("%lld",&n);
    long long x;

    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&x);
        unio(i,x);
    }

    for(int i=1; i<=n; i++)
        cnt[findd(i)]++;
//    for(int i=1; i<=n; i++)
//        cout<<"parent of "<<i<<" = "<<par[i]<<endl;
    for(int i=1; i<=n; i++)
    {
        //cout<<cnt[i]<<endl;
        vec.push_back(cnt[i]);
    }
    sort(vec.begin(),vec.end());

    int sz = vec.size();

    if(sz == 1) cout<<vec[0] * vec[0]<<endl;
    else
    {
        long long a = vec[sz - 1];
        long long b = vec[sz - 2];
        a+=b;

        long long ans = a * a;

        for(int i=0; i<sz - 2; i++)
        {
            long long w = vec[i];
            ans+=(w * w);
        }
        cout<<ans<<endl;
    }
}
