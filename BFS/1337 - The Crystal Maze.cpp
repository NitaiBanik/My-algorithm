#include<bits/stdc++.h>
using namespace std;

char grid[505][505];
int col[505][505];
int ans[1005],r,c,q;
int xx[]= {+1,-1,+0,+0};
int yy[]= {+0,+0,+1,-1};

int chk(int px, int py)
{
    if((px>=0 && px< r) && (py>=0 && py < c) && (grid[px][py]!='#'))
        return 1;
    return 0;
}
void bfs(int sx, int sy, int step)
{
    int cn = 0;
    col[sx][sy] = step;
    queue<pair<int, int> > Q;
    Q.push({sx,sy});

    while(!Q.empty())
    {
        int fx = Q.front().first;
        int fy = Q.front().second;
        Q.pop();
        if(grid[fx][fy] == 'C')
            cn++;

        for(int i = 0; i<4; i++)
        {
            int wx = fx + xx[i];
            int wy = fy + yy[i];
            if(chk(wx,wy)&&  (col[wx][wy] == 0))
            {

                col[wx][wy] = step;
                //   cout<<wx<<" "<<wy<<endl;
                //  cout<<grid[wx][wy]<<endl;
                Q.push({wx,wy});
            }
        }
    }
    ans[step] = cn;

}
int main()
{
    int t,w = 0;
    cin>>t;
    while(t--)
    {
        scanf("%d %d %d",&r, &c, &q);

        for(int i = 0 ; i < r; i++)
            for(int j = 0 ; j < c; j++)
                cin>>grid[i][j];

        printf("Case %d:\n", ++w);
        int st = 1;
        memset(col,0,sizeof(col));
        memset(ans,0,sizeof(ans));
        while(q--)
        {
            int dx,dy;
            scanf("%d %d", &dx, &dy);
            dx--,dy--;
            int colorr = col[dx][dy];
            if(colorr == 0)
            {
                st++;
                bfs(dx,dy,st);
            }
            colorr = col[dx][dy];
            printf("%d\n",ans[colorr]);

        }


    }
    return 0;
}
