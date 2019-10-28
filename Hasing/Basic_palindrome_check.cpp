#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 100000000+7;
#define prime 3

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
int main()
{

    string s;
    while(cin>>s)
    {
        ll has1 = 0;
        ll has2 = 0;

        ll ln = s.size();
        ll End = ln - 1;
        for(int i=0; i<ln; i++)
        {
            ll f = (s[i] - 'a');
            ll fp = power(prime,i)%mod;
            has1+=(f * fp) % mod;
            ll snd =(s[End] - 'a');
            ll snd2 = power(prime,i)%mod;
            has2+=(snd * snd2) % mod;
            End--;
        }
        if(has1 == has2)
            cout<<"Palindrome"<<endl;
        else
            cout<<"Not palindrome"<<endl;
    }

}
