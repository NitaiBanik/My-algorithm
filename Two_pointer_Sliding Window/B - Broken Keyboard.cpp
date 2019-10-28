
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll m;

    while(scanf("%lld",&m) == 1 && m!=0)
    {
         string s;
        //memset(arr,0,sizeof(s));
        ll arr[150] = {0};
        getchar();

        getline(cin,s);
       // cout<<s<<endl;
        ll mx = 0,cnt = 0;
        ll frm= 0 ,to = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(arr[s[i]] == 0)
            {
                cnt++;
            }
            arr[s[i]]++;
            if(cnt <=m)
                mx = max(mx,i - frm + 1);
            if(cnt>m)
            {
                while(cnt>m)
                {
                    arr[s[frm]]--;
                    if(arr[s[frm]] == 0)
                        cnt--;
                    frm++;
                }
                mx = max(mx,i - frm + 1);
            }
        }
        printf("%lld\n",mx);

    }
    return 0;
}
