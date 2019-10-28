#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll tot = 0;
map<ll,ll>mp;
map<ll,ll>::iterator it;
ll power(ll b, ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1)ans*=b;
        b*=b;
        p/=2;
    }
    return ans;
}

string st;
ll how;
map<ll,int>mp1;
void calc(ll Hash,ll pos, ll sz)
{

    if(sz == how)
    {
        if(mp.find(Hash)!=mp.end())
        {
            if(mp1.find(Hash)!=mp1.end())
            {

            }
            else
            {
                tot+=mp[Hash];
                mp1[Hash] = 1;
//            cout<<"hash = "<<Hash<<endl;
//            cout<<"map = "<<mp[Hash]<<endl;
            }
        }
        return;
    }
    if(st[sz] == '?')
    {
        calc(Hash,pos,sz+1);
        for(int i='a'; i<='e'; i++)
        {
            ll f = ( i - 'a'+1);
            ll fp = power(31,pos) ;
            calc(Hash+(f*fp),pos+1,sz+1);
        }
    }
    else
    {
        ll f = (st[sz] - 'a'+1);
        ll fp = power(31,pos) ;
        calc(Hash+(f*fp),pos+1,sz+1);
    }

}
int main()
{
    ll word,pat;
    scanf("%llu %llu",&word,&pat);
    string s;
    for(int j=1; j<=word; j++)
    {
        cin>>s;
        ll ln = s.size();
        ll sum = 0;
        for(int i=0; i<ln; i++)
        {
            ll f = (s[i] - 'a'+1);
            ll fp = power(31,i) ;
            sum+=(f * fp);
        }
        mp[sum]++;
    }
    for(int i=0; i<pat; i++)
    {
        cin>>st;
        how = st.size();
        mp1.clear();
        calc(0,0,0);
        cout<<tot<<endl;
        tot = 0;
    }

}
