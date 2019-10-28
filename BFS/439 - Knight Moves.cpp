#include<bits/stdc++.h>
using namespace std;
long long mat[1005][1005];
long long dis[1005][1005];
long long fx[] = {+2,-2,+1,-1,+2,-2,+1,-1};
long long fy[] = {-1,-1,-2,-2,+1,+1,+2,+2};
long long i;
long long sx,sy,dx,dy;
char ff,mm,ss;
long long int ff1,ss1;
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
    if(r == sx && c == sy)
        return 0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            long long tx = p.first + fx[i];
            long long ty = p.second + fy[i];
            if(tx>=1 && tx<=8 && ty>=1 && ty<=8 && dis[tx][ty] == -1)
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

    while(scanf("%c%lld%c%c%lld",&ff,&ff1,&mm,&ss,&ss1) == 5)
    {
        getchar();

            memset(mat[i],0,sizeof(mat[i]));
            memset(dis[i],-1,sizeof(dis[i]));


        printf("To get from %c%lld to %c%lld takes ",ff,ff1,ss,ss1);
        dy = ff - 'a' + 1;
        dx = ff1;
        sy = ss - 'a' + 1;
        sx = ss1;
        long long w = bfs(dx,dy);
        printf("%lld knight moves.\n",w);
    }
    return 0;
}

