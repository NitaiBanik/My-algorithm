#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 100000+7;
#define prime 3
ll value[2000005];
ll cum[105];
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

    for(int i = 0; i<=2000003; i++)
        value[i] = (power(3,i));

    long long t, w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        string s;
        cin>>s;

        ll has1 = 0;
        ll has2 = 0;

        ll ln = s.size();
        ll End = ln - 1;
        for(int i=0; i<ln; i++)
        {
            ll f = (s[i] - 'a');
            ll fp = power(prime,i) ;
            has1+=(f * fp);
            ll snd =(s[End] - 'a');
            ll snd2 = power(prime,i) ;
            has2+=(snd * snd2);
            End--;
        }
        ln--;
        long long Q;
        printf("Case %lld:\n",++w);
        scanf("%lld",&Q);
        while(Q--)
        {
            char where,key;
            ll how;
            cin>>where>>key>>how;
            if(where == 'L')
            {
                has1*=value[how];
                ll sum = 0;
                for(int i =0;i<how;i++) sum+=value[i];
                has1+= ((key - 'a') *sum);
                sum = 0;
                for(int i =ln+1;i<= ln + how;i++) sum+=value[i];
                has2+=((key - 'a') * sum);
                ln+=how;
            }
            else
            {
                has2*=value[how];
                ll sum = 0;
                for(int i =0;i<how;i++) sum+=value[i];
                has2+= ((key - 'a') *sum);
                sum = 0;
                for(int i =ln+1;i<= ln + how;i++) sum+=value[i];
                has1+=((key - 'a') * sum);
                ln+=how;
            }
            if(has1 == has2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        }

    }


}
