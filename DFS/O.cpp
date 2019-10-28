#include<bits/stdc++.h>
using namespace std;
int mat[100][100];
int ck[100],node;
int value(char c)
{
    return c-'A';
}
void dfs(int p)
{
    ck[p] = 1;
    for( int k=0; k<=node; k++)
    {
        if(ck[k] == 0 && mat[p][k]==1)
        {
            dfs(k);
        }
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
   //freopen("ou.txt","w",stdout);
    int t,m=0;
    char p[5],q[5];
    scanf("%d\n\n",&t);
    while(t--)
    {
        if(m>0)
            cout<<endl;
        m++;
        memset(mat,0,sizeof(mat));
        memset(ck,0,sizeof(ck));
        gets(q);
        node = value(q[0]);
        while(gets(p)&&p[0])
        {
            int f = value(p[0]);
            //cout<<f;
            int s = value(p[1]);
           // cout<<s<<endl;
            mat[f][s] = 1;
            mat[s][f] = 1;
        }
        int co =0;
        for(int i=0;i<=node;i++)
        {
            if(ck[i]==0)
            {
                dfs(i);
               co++;
            }
        }
        cout<<co<<endl;
    }

}
