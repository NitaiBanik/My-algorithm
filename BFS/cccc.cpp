#include<bits/stdc++.h>
using namespace std;
long long mat[1005][1005];
long long dis[1005][1005];
long long fx[] = {1,-1,0,0};
long long fy[] = {0,0,1,-1};
long long row,col,i;
long long sx,sy,dx,dy;
long long bfs(long long r, long long c)
{
//    for(i=0; i<1005; i++)
//        memset(dis[i],-1,sizeof(dis[i]));
//    //for(j=0;j<1005;j++)

    queue< pair < long long, long long> > q;
    pair < long long, long long> p,pp;
    p = make_pair(r,c);
    q.push(p);
    dis[r][c] = 0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            long long tx = p.first + fx[i];
            long long ty = p.second + fy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && dis[tx][ty] == -1 && mat[tx][ty]!=-1)
            {
                dis[tx][ty] = dis[p.first][p.second] + 1;
                if(tx == sx && ty == sy)
                    return dis[tx][ty];
                pp = make_pair(tx,ty);
                q.push(pp);
            }

        }
    }

}
int main()
{
    while(scanf("%lld %lld",&row,&col) == 2)
    {
        if(row == 0 && col == 0)
            break;
        for(i=0; i<=row; i++)
        {
            memset(mat[i],0,sizeof(mat[i]));
            memset(dis[i],-1,sizeof(dis[i]));
        }
        long long step;
        scanf("%lld",&step);
        while(step--)
        {
            long long num,cnt;
            scanf("%lld %lld",&num,&cnt);
            while(cnt--)
            {
                long long x;
                scanf("%lld",&x);
                mat[num][x] = -1;
            }
        }

        scanf("%lld %lld %lld %lld",&sx,&sy,&dx,&dy);
        long long w = bfs(dx,dy);
        printf("%lld\n",w);
    }
}
