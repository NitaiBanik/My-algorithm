#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mx 100
#define sfll(a) scanf("%lld",&a)
ll matrix[mx + 5][mx + 5];

int main()
{
    ll w = 0;
    while(1)
    {
        ll mp[105] = {0};
        ll frm,to;
        ll node = 1,ck = 0;
        memset(matrix,inf,sizeof(matrix));
        while(scanf("%lld %lld",&frm,&to) == 2) {
            if(frm == 0 && to == 0)
                break;
            ck = 1;
            if(mp[frm] == 0) {
                mp[frm] = node;
                node++;
            }
            if(mp[to] == 0) {
                mp[to] = node;
                node++;
            }
            matrix[mp[frm]][mp[to]] = 1;

        }
        if(ck == 0)break;
        node--;
        for(int i=1; i<=node; i++)
            matrix[i][i] = 0;
        double cst;
        ll  sum = 0;
        for(int k = 1; k<=node ; k++)
            for(int i = 1; i<=node ; i++)
                for(int j = 1; j<=node ; j++) {
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
        for(int i = 1; i<=node ; i++)
            for(int j = 1; j<=node ; j++)
                sum+=matrix[i][j];
        cst = (double)sum /(node * (node - 1));
        //cout<<sum<<endl;
        printf("Case %lld: average length between pages = %.3lf clicks\n",++w,cst);
    }
    return 0;
}
