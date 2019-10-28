#include<bits/stdc++.h>
using namespace std;
char s[100][100];
multiset<int>st;
multiset<int>:: iterator it;
int co,p,q;
void dfs1(int m,int n);
void dfs( int r, int ss )
{
        //cout<<lx<<" "<<ly<<endl;
    if(r == q || ss == p || r < 0 || ss < 0||s[r][ss]!='X')
        return;
        s[r][ss] = '*';
        dfs(r,ss-1);
        dfs(r,ss+1);
        dfs(r-1,ss);
        dfs(r+1,ss);

}

void dfs1(int m,int n)
{
    if(m>=q||n>=p ||m<0 ||n<0 || s[m][n]=='.')
        return;
    if(s[m][n] == 'X')
    {
        co++;
        dfs(m,n);

        //dfs1(lx,ly);
    }
   //   co=0;
        s[m][n] = '.';
        dfs1(m,n-1);
        dfs1(m,n+1);
        dfs1(m-1,n);
        dfs1(m+1,n);

}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int i,j,test = 0,z;
    while(scanf("%d %d",&p,&q) == 2 && p!=0 && q!=0)
    {
        for(i = 0 ; i <q; i++)
            scanf("%s",s[i]);

        for(i=0; i<q; i++)
            for(j=0; j<p; j++)
            {
                co= 0;
                if(s[i][j] != '.')
                {
                    dfs1(i,j);
                     if(co!=0)
                    st.insert(co);
                }
            }
        int sp = 0;
        cout<<"Throw "<<++test<<endl;
        if(st.empty())
            {
                 cout<<endl<<endl;
                 //continue;
            }
        else{
            for(it=st.begin(); it!=st.end(); it++)
            {
                if(sp>0)
                    cout<<" ";
                sp++;
                cout<<*it;
            }
        cout<<endl<<endl;}
        st.clear();
    }
}

/*

3 3

XX*
..X
..X

*/
