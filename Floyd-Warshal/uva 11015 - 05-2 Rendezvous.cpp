#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mx 20
#define sfll(a) scanf("%lld",&a)
ll matrix[mx + 5][mx + 5];

int main()
{

    ll edge,node,w = 0;
    while(scanf("%lld %lld",&node,&edge) == 2)
    {
        if(node == 0 && edge == 0)
            break;
       // map<string,ll>mp1;
        map<ll,string>mp2;
        memset(matrix,inf,sizeof(matrix));
        string s;
        for(int i =1; i<=node; i++)
        {
            cin>>s;
            //mp1[s] = i;
            mp2[i] = s;

        }
        for(int i=1; i<=node; i++)
            matrix[i][i] = 0;

        for(ll i=0; i<edge; i++)
        {
            ll frm,to,cst;
            sfll(frm);
            sfll(to);
            sfll(cst);
            matrix[frm][to] = cst;
            matrix[to][frm] = cst;
        }
        for(int k = 1; k<=node ; k++)
            for(int i = 1; i<=node ; i++)
                for(int j = 1; j<=node ; j++)
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
        ll mn = 999999999999,sol,sum;
        for(int i = 1; i<=node ; i++) {
            sum = 0;
            for(int j = 1; j<=node ; j++)
                sum+=matrix[i][j];
            if(sum<mn)
            {
                mn = min(mn,sum);
                sol = i;
            }
        }
        printf("Case #%lld : ",++w);
        cout<<mp2[sol]<<endl;
    }
    return 0;
}
