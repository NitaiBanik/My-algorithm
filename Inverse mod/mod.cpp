#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define ll long long
ll M;
ll F(ll N,ll P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		ll ret=F(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(F(N,P-1)%M))%M;

}
int main()
{
    ll a,b;
    cin>>a>>b>>M;
    if(__gcd(a,b)!=1) cout<<"Not possible";
    else{
    ll ans = F(a,b-2);
    cout<<ans<<endl;}
}
