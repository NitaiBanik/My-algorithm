#include<bits/stdc++.h>
using namespace std;
string mat[105];
#define ll long long
long long dis[105][105];
long long fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
long long fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};
long long row,col;
long long bfs(long long r, long long c)
{
//    for(i=0; i<1005; i++)
    memset(dis,-1,sizeof(dis));
//    //for(j=0;j<1005;j++)
    ll cn = 0;
    queue< pair < long long, long long> > q;
    pair < long long, long long> p,pp;
    p = make_pair(r,c);
    q.push(p);
    dis[r][c] = 0;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(ll i=0; i<8; i++)
        {
            long long tx = p.first + fx[i];
            long long ty = p.second + fy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && dis[tx][ty] == -1 && mat[tx][ty]!='L')
            {
                cn++;
                dis[tx][ty] = dis[p.first][p.second] + 1;
                pp = make_pair(tx,ty);
                q.push(pp);
            }

        }
    }
    return cn;
}


int main()
{
    ll test,c = 0;
    cin>>test;
    while(test--)
    {
        if(c>0) cout<<endl;
        c++;
        cin>>mat[0];

        row = mat[0].size();
        col = row;
        for(ll i=1; i<row; i++)
            cin>>mat[i];
        ll sx,sy;
        while(scanf("%lld %lld",&sx,&sy) == 2)
        {
            sx--,sy--;
            ll ans = 0;
            if(mat[sx][sy] == 'W') ans++;
            ans += bfs(sx,sy);
            cout<<ans<<endl;
        }
        for(ll i = 0; i<=row+1; i++) mat[i].clear();
    }
    return 0;
}
