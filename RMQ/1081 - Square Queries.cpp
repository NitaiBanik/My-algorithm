#include<bits/stdc++.h>
using namespace std;
#define ll int
ll a[505][505];
ll mat[505][505][15];
int main()
{
    int t,ww = 0;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n",++ww);
        ll n,q,aa,b;
        scanf("%d %d",&n,&q);
        for(ll i = 1; i <= n ; i++)
            for(ll j = 1; j <= n ; j++)
            {
                scanf("%d",&a[i][j]);
                mat[i][j][0] = j;
            }
        for(int k = 1; k<=n; k++)
        {
            for(ll j = 1; (1<<j)<=n; j++)
            {
                for(ll i = 1; (i + (1<<j) - 1) <=n ; i++)
                {
                    ll x = mat[k][i][j-1];
                    ll y = mat[k][i + (1<<(j-1))][j-1];
                    if(a[k][x]<a[k][y])
                        mat[k][i][j] = y;
                    else
                        mat[k][i][j] = x;
                }
            }
        }

        while(q--)
        {
            ll i,j,s,me = 0;
            scanf("%d %d %d",&i,&j,&s);
            aa = j,b = j + s - 1;
            ll k = log2(b - aa + 1);
            for(int p = i ; p < i + s; p++)
            {
                ll x = mat[p][aa][k];
                ll y = mat[p][b - (1<<k) + 1][k];

                me = max(me,max(a[p][x],a[p][y]));
            }
          printf("%d\n",me);
        }
    }

}
