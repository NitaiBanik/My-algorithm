#include<bits/stdc++.h>
using namespace std;
int mat[110][110];
int cnt[110];
int n,i,j,l;
void dfs( int p, int q,int h)
{
    if(p == n+1 || q == n+1 || p < 1 || q < 1)
        return;
    if(mat[p][q] == h)
    {
        mat[p][q] = -1;
        dfs(p,q-1,h);
        dfs(p,q+1,h);
        dfs(p-1,q,h);
        dfs(p+1,q,h);
    }

}
int main()
{
//freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d", &n)==1 && n!=0)
    {
        memset(cnt,0,sizeof(cnt));
        memset(mat,0,sizeof(mat));
        string st;
        getchar();
        for(i = 1 ; i<n ;  i++)
        {
            getline(cin,st);
            stringstream ss(st);
            int a,b;
            while(ss>>a)
            {
                ss>>b;
                mat[a][b] = i;
               // mat[b][a] = i;
            }
        }
        for(l=0; l<n; l++)
        {
            for( i = 1; i<=n; i++)
                for( j = 1 ; j<=n ; j++)
                {
                    if(mat[i][j] == l)
                    {
                        cnt[l]++;
                        dfs(i,j,l);
                    }
                }

        }
        int ck = 0;
        for(l=0; l<n; l++)
        {
            if(cnt[l]>1)
                {ck = 1;
                break;}
         // cout<<l<<"   "<<cnt[l]<<endl;
        }
        if(ck)
            cout<<"wrong"<<endl;
        else
            cout<<"good"<<endl;
    }
}

