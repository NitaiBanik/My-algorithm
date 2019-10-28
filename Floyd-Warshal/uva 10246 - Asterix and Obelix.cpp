#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mx 78
#define sfll(a) scanf("%lld",&a)
ll matrix[mx + 5][mx + 5];
ll tool[mx + 5];
int main()
{

    ll edge,node,qu;
    while(scanf("%lld %lld %lld",&node,&edge,&qu) == 3) {
        memset(matrix,inf,sizeof(matrix));
        for(int i=1; i<=node; i++) {
            scanf("%lld",&tool[i]);
            matrix[i][i] = tool[i];
}
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
                        matrix[i][j] = min(matrix[i][j] + tool[j],matrix[i][k] + matrix[k][j] + tool[k] + tool[j]);
            while(qu--)
            {
                ll ff,ss;
                sfll(ff);
                sfll(ss);
                cout<<matrix[ff][ss]<<endl;
            }
        }
        return 0;
    }
