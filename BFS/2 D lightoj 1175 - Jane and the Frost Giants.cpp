#include<bits/stdc++.h>
using namespace std;
char str[1005][1005];
int cost1[1005][1005];
int cost2[1005][1005];
int fx[] = {0, 0,1, -1};
int fy[] = {1,-1, 0,  0};
int r,c;
int maxval = 9999999;
void bfs1(int p,int q)
{
    queue<pair<int, int> > Q;
    Q.push(make_pair(p,q));
    cost1[p][q]=0;
    while(!Q.empty())
    {
        int x =  (Q.front()).first;
        int y =  (Q.front()).second;
        Q.pop();
        for(int ii=0; ii<4; ii++)
        {
            int mm = x+ fx[ii];
            int nn = y+ fy[ii];
            if((mm>=0 && mm<r) &&(nn>=0 && nn<c) && (str[mm][nn] != '#') &&(cost1[mm][nn]== maxval))
            {
                cost1[mm][nn] = cost1[x][y] + 1;
                Q.push(make_pair(mm,nn));
            }
        }
    }
}
queue<pair<int, int> > Q1;
void bfs2()
{
    while(!Q1.empty())
    {
        int x =  (Q1.front()).first;
        int y =  (Q1.front()).second;
        Q1.pop();
        for(int ii=0; ii<4; ii++)
        {
            int mm = x+ fx[ii];
            int nn = y+ fy[ii];
            if((mm>=0 && mm<r) &&(nn>=0 && nn<c) && (str[mm][nn] != '#') &&(cost2[mm][nn]== maxval))
            {
                cost2[mm][nn] = cost2[x][y] + 1;
                Q1.push(make_pair(mm,nn));

            }
        }
    }
}
int main()
{
   // freopen("in.txt","rt",stdin);
   // freopen("ou.txt","wt",stdout);
    int test,w = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&r,&c);
        for(int i=0; i<r; i++)
            scanf("%s",str[i]);

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                cost1[i][j] = maxval;
                cost2[i][j] = maxval;
                if(str[i][j] == 'F')
                {
                    cost2[i][j]=0;
                    Q1.push(make_pair(i,j));
                }
            }
        bfs2();
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                if(str[i][j] == 'J')
                {
                    bfs1(i,j);
                }
            }
        int z=maxval;
        for(int i=0; i<r; i++)
        {
            if(cost1[i][0]<cost2[i][0])
                z=min(z,cost1[i][0]);
            if(cost1[i][c-1]<cost2[i][c-1])
                z=min(z,cost1[i][c-1]);
        }
        for(int j=0; j<c; j++)
        {
            if(cost1[0][j]<cost2[0][j])
                z=min(z,cost1[0][j]);
            if(cost1[r-1][j]<cost2[r-1][j])
                z=min(z,cost1[r-1][j]);
        }
        printf("Case %d: ",++w);
        if(z!=maxval)
            printf("%d\n",z+1);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
/*
3
3 3
#.J
##F
...
*/
