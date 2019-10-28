#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mx 1000
#define sfll(a) scanf("%lld",&a)
ll matrix[mx + 5][mx + 5];

int main()
{

    ll edge,node,Q,w = 0;
    while(sfll(node))
    {
        sfll(edge);
        sfll(Q);
        if(node == 0 && edge == 0 && Q == 0)
            break;
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
                    matrix[i][j] = min(matrix[i][j],max(matrix[i][k], matrix[k][j]));
        if(w>0)
            cout<<endl;
        printf("Case #%lld\n",++w);
        while(Q--)
        {
            int frm,to;
            cin>>frm>>to;
            if(matrix[frm][to] >= inf)
                printf("no path\n");
            else
                printf("%lld\n",matrix[frm][to]);

        }
    }
    return 0;

}



/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0

*/
