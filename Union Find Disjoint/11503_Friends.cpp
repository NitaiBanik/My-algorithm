#include<bits/stdc++.h>
using namespace std;
map<string,long long >m;
long long  par[100005];
long long  findd(long long  aa)
{
    if(par[aa] == aa) return aa;
    else
        return findd(par[aa]);
}
int main()
{
    long long  c,r,t;
    scanf("%lld",&t);
    while(t--)
    {
        memset(par,0,sizeof(par));
        scanf("%lld",&r);
        long long cn[r+5] = {0};
        long long  cnt = 1;
        for(long long  i=0; i<r; i++)
        {
            string a,b;
            cin>>a>>b;
            if(m[a] == 0)
            {
                m[a] = cnt++;
                par[m[a]] = m[a];
                cn[m[a]] =1;
            }
            if(m[b] == 0)
            {
                m[b] = cnt++;
                par[m[b]] = m[b];
                cn[m[b]] =1;
            }

            long long  f = findd(m[a]);
            long long  s = findd(m[b]);
            //cout<<"f = "<<m[a]<<"s = "<<m[b]<<endl;
            if(f!=s)
            {
//                if(cn[f]>cn[s])
//                {
                par[f] = s;
                cn[s]+=cn[f];
                cout<<cn[s]<<endl;
//                }
//                else
//                {
//                    par[f] = s;
//                    cn[s]+=cn[f];
//                    cout<<cn[s]<<endl;
//                }
            }
            else
                cout<<cn[s]<<endl;
            //
        }
        //prlong long f("%lld\n",mx);
        m.clear();
       // cout<<"step";
    }
    return 0;
}
