#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int par[100000];
int findd(int aa)
{
    if(par[aa] == aa) return aa;
    else
        return findd(par[aa]);
}
int main()
{
    int c,r;
    while(scanf("%d %d",&c,&r) == 2)
    {
        if(c == 0 && r==0)
            break;
        int cn[c+5];
        for(int i=0; i<c; i++)
        {
            string s;
            cin>>s;
            mp[s] = i;
            par[i] = i;
            cn[i] = 1;
        }
        int mx = 1;
        for(int i=0; i<r; i++)
        {
            string a,b;
            cin>>a>>b;
            int f = findd(mp[a]);
            int s = findd(mp[b]);
            if(f!=s)
            {
                par[s] = f;
                cn[f]+=cn[s];
                mx = max(mx,cn[f]);
            }
        }
        printf("%d\n",mx);
        mp.clear();
    }
}
