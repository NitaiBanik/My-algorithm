#include<bits/stdc++.h>
using namespace std;
#define inf 9999999999
#define ll long long
char arr[12][12];
ll ans[12][12];
ll vis[12][12];
ll r,c;
ll xx[]= {-2, -2, -1, -1,  1,  1,  2,  2}; // Knights Move
ll yy[]= {-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int chk(int px, int py)
{
    if((px>=0 && px< r) && (py>=0 && py < c))
        return 1;
    return 0;
}
void bfs(int sx,int sy, int kth)
{
    vis[sx][sy] = 0;

    queue<pair<int, int> >Q;
    Q.push({sx,sy});

    while(!Q.empty())
    {
        int fxx = Q.front().first;
        int fyy = Q.front().second;
        Q.pop();

        vector<pair<int,int>>now,temp;
        now.push_back({fxx,fyy});
        for(int j = 1; j<=kth; j++)
        {
            for(int p = 0; p< now.size(); p++)
            {
                int fx=now[p].first;
                int fy=now[p].second;
                for(int i = 0; i<8; i++)
                {
                    int wx = fx + xx[i];
                    int wy = fy + yy[i];
                    if(chk(wx,wy))
                    {

                        temp.push_back({wx,wy});
                    }
                }
            }
            now = temp;
            temp.clear();
        }
        for(int p = 0; p< now.size(); p++)
        {

            int fx=now[p].first;
            int fy=now[p].second;
            if(vis[fx][fy] == -1)
            {
                vis[fx][fy] = vis[fxx][fyy] + 1;
                Q.push({fx,fy});

            }
        }
    }
}
int main()
{
    ll w = 0, t;
    scanf("%lld", &t);
    while(t--)
    {
        cin>>r>>c;
        memset(ans,0,sizeof(ans));

        for(int i = 0; i< r; i++)
            for(int j = 0; j < c; j++)
                cin>>arr[i][j];

        for(int i = 0; i< r; i++)
            for(int j = 0; j < c; j++)
            {
                if(arr[i][j]!='.')
                {
                    memset(vis,-1,sizeof(vis));
                    bfs(i,j, arr[i][j] - '0');
                    for(int ii = 0; ii< r; ii++)
                        for(int jj = 0; jj < c; jj++)
                        {
                            if(vis[ii][jj] == -1)
                                ans[ii][jj]+=inf;
                            else
                                ans[ii][jj]+=vis[ii][jj];
                        }
                }
            }
        ll mn = 3*inf;
        for(int i = 0; i< r; i++)
            for(int j = 0; j < c; j++)
                mn = min(mn,ans[i][j]);

        if(mn>=inf)
            mn = -1;
        printf("Case %lld: %lld\n",++w,mn);

    }
    return 0;
}
