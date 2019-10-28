#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define mxx 30
#define sfll(a) scanf("%lld",&a)
ll matrix[mxx + 5][mxx + 5];

int main()
{

    ll edge,ww =0;
    while(sfll(edge)==1)
    {
        memset(matrix,0,sizeof(matrix));
        ll mx = 0;
        for(ll i=0; i<edge; i++)
        {
            ll frm,to;
            sfll(frm);
            sfll(to);
            mx = max(mx,max(frm,to));
            //sfll(cst);
            matrix[frm][to] = 1;
        }
        for(int k = 0; k<=mx ; k++)
            for(int i = 0; i<=mx ; i++)
                for(int j = 0; j<=mx ; j++)
                    if(matrix[i][k] !=0 && matrix[k][j] !=0)
                        matrix[i][j] += (matrix[i][k] * matrix[k][j]);

        for(int k = 0; k<=mx ; k++)
            if(matrix[k][k]!=0)
            {
                for(int i = 0; i<=mx ; i++)
                    for(int j = 0; j<=mx ; j++)
                        if(matrix[i][k] !=0 && matrix[k][j] !=0)
                        {
                            //matrix[i][k]  = -1;
                            matrix[i][j]  = -1;
                        }
            }
        printf("matrix for city %lld\n",ww++);
        for(int i = 0; i<=mx ; i++)
        {
            for(int j = 0; j<=mx ; j++)
            {
                printf("%lld",matrix[i][j]);
                if(j<mx)
                    printf(" ");
            }
            printf("\n");

        }
    }
    return 0;
}
