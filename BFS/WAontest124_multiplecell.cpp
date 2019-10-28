#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
string str[200005];

int fx[]= {+1,-1,+0,+0};
int fy[]= {+0,+0,+1,-1};

map< pair<int,int>, int>vis,vis1;
int x1,y1,x2,y2,fg = 0;
int n,m,k;
queue<pair<int,int> >Q1;

void bfs()
{
    while(!Q1.empty())
    {
        int frmx = Q1.front().first;
        int frmy = Q1.front().second;

        Q1.pop();

        for(int i = 0; i < 4; i++)
        {
            int sx = frmx + fx[i];
            int sy = frmy + fy[i];
            if(sx>=0 && sy>=0 && sx<n && sy<m && vis[ {sx,sy}] == inf)
            {
                vis[ {sx,sy}] = 1 + vis[ {frmx,frmy}];
                Q1.push({sx,sy});
            }
        }

    }

}

void bfs1(int x, int y)
{
    queue<pair<int,int> >Q;
    Q.push({x,y});
    while(!Q.empty())
    {
        int frmx = Q.front().first;
        int frmy = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int sx = frmx + fx[i];
            int sy = frmy + fy[i];
            if(sx>=0 && sy>=0 && sx<n && sy<m && vis1[ {sx,sy}] == inf && vis[ {sx,sy}] > k)
            {
                vis1[ {sx,sy}] = 1 + vis1[ {frmx,frmy}];

                Q.push({sx,sy});

                if(sx == x2 && sy ==  y2)
                {
                    fg = vis1[ {sx,sy}];
                    return;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i = 0; i <n; i++)
        cin>>str[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vis[ {i,j}] = inf;
            vis1[ {i,j}] = inf;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(str[i][j] == 'M')
            {
                vis[ {i,j}] = 0;
                Q1.push({i,j});
            }
            if(str[i][j] == 'S')
            {
                x1 = i,y1 = j;
            }
            if(str[i][j] == 'F')
            {
                x2 = i,y2 = j;
            }
        }
    }
    bfs();
    if(vis[ {x1,y1}]<= k || vis[ {x2,y2}]<= k )
    {
        cout<<-1<<endl;
    }
    else
    {
        vis1[ {x1,y1}] = 0;
        bfs1(x1,y1);
        if(fg == 0)
            cout<<-1<<endl;
        else
            cout<<fg<<endl;
    }
}
