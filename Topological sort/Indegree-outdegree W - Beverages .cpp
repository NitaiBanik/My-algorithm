#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll>mp1;
map<ll,string>mp2;
vector<ll>vec[105],ans;
ll ind[105],taken[105];
int main()
{
    ll t,w = 0;
    while(scanf("%lld",&t) == 1)
    {
       // if(w>0) cout<<endl;
        string s,f;
        for(ll i=1; i<=t; i++)
        {
            cin>>s;
            mp1[s] = i;
            mp2[i] = s;
        }

        ll edge;
        cin>>edge;
        for(ll i=1; i<=edge; i++)
        {
            cin>>f>>s;
            ind[mp1[s]]++;
            vec[mp1[f]].push_back(mp1[s]);
        }

        for(ll i=1; i<=t; i++)
        {
            for(ll j=1; j<=t; j++)
            {
                if(ind[j] == 0 && taken[j]==0)
                {
                    taken[j] = 1;
                    ans.push_back(j);
                    for(int k=0; k<vec[j].size(); k++)
                        ind[vec[j][k]]--;
                    break;

                }

            }
        }
        printf("Case #%lld: Dilbert should drink beverages in this order:",++w);
        for(int i=0; i<t; i++)
            cout<<" "<<mp2[ans[i]];
        cout<<"."<<endl<<endl;

        memset(ind,0,sizeof(ind));
        memset(taken,0,sizeof(taken));

        for(int i=0; i<=t; i++) vec[i].clear();
        mp1.clear();
        mp2.clear();
        ans.clear();

    }
    return 0;
}
