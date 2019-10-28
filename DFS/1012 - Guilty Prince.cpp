#include<bits/stdc++.h>
using namespace std;
char s[25][25];
int cnt,row,col;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
void dfs(int i,int j)
{
    if(i<0 || j<0 || i==row || j==col||s[i][j] == '#'||s[i][j] == '1')
        return;
    //cout<<s[i][j];
    s[i][j] = '1';
    for(int k = 0; k<4; k++)
    {
        dfs(i+fx[k],j+fy[k]);
    }
}

int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        //int row,col;
        scanf("%d %d",&col,&row);
        for(int i=0; i<row; i++)
            scanf("%s",s[i]);
        cnt = 0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(s[i][j] == '@')
                {
                    dfs(i,j);
                   // break;
                }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(s[i][j] == '1')
                    cnt++;
                //cout<<s[i][j];
            }
            //cout<<endl;
        }
        printf("Case %d: ",++w);
        cout<<cnt<<endl;
    }
    return 0;
}
