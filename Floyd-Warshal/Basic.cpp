#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mx 10000
#define sfll(a) scanf("%lld",&a)
ll matrix[mx + 5][mx + 5];

int main()
{

    ll edge,node;
    sfll(node);
    sfll(edge);
    memset(matrix,inf,sizeof(matrix));
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

    for(int i = 1; i<=node ; i++)
    {
        for(int j = 1; j<=node ; j++)
            printf("%lld ",matrix[i][j]);
        printf("\n");
    }

    return 0;
}
