#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>vec[1000*15 + 2];

ll n,m;
ll coin[20];
ll arr[1005];


int Chk(ll n, ll pos)
{
    return (n &(1<<pos));
}

void calc()
{
    ll sz = (1<<n);
    for(ll i=1; i<sz; i++)
    {
        ll tot = 0;

        for(ll j=0; j<n; j++)
            if(Chk(i,j) != 0) tot+=coin[j];
       // cout<<"tot = "<<tot<<endl;
        vec[tot].push_back(i);
    }
}


ll dp[16][1<<15 + 2];
bool ase;

ll call(ll pos, ll mask)
{
    if(pos == m)
    {
        ase = true;
        ll cn = __builtin_popcountll(mask);
        return cn;
    }

    if(dp[pos][mask]!=-1) return dp[pos][mask];
    ll ans = 28;
    for(int i=0; i<vec[arr[pos]].size(); i++)
    {
        ll mk = vec[arr[pos]][i];

        if((mask&mk)!=0)continue;

        ans = min(ans,call(pos+1,mask|mk));
       // ll cn = __6builtin_popcountll(mk);
//        bool zero = true;
//        for(int j=0; j<n; j++)
//        {
//
//            if(Chk(mask,i) == 1 && Chk(mk,i) == 1)
//            {
//                zero = false;
//                break;
//            }
//        }
//        if(zero == true)
//            ans = min(ans,call(pos+1,mask|mk));

    }
    return dp[pos][mask] = ans;

}

int main()
{

    ll t;
    scanf("%lld",&t);
    int ks=0;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&n);
        for(int i=0; i<n; i++)
            scanf("%lld",&coin[i]);
        scanf("%lld",&m);
        for(int i=0; i<m; i++)
            scanf("%lld",&arr[i]);

        calc();
//        int ck = 0;
//        for(int i=0; i<m; i++)
//            if(vec[arr[i]].size() == 0)
//                ck = 1;
//        if(ck == 1)
//        {
//            //cout<<"not calc"<<endl;
//            cout<<-1<<endl;
//            continue;
//        }
//        ase = false;
        cout << "Case " << ++ks << ": ";
        ll Ans = call(0,0);
        if(Ans>n) cout<<-1<<endl;
        else cout<<Ans<<endl;
        for(int i=0;i<=1000*15+ 2;i++) vec[i].clear();
    }

    return 0;
}
