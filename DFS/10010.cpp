#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,k;
int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};
string str[52],chk;
bool flag,grid[52][52];
ll sz;

void bfs(int x, int y, int ln,int dr)
{
    grid[x][y] = true;
    if(flag) return;
//    for(int ii = 0; ii<8; ii++)
//    {
        ll yo = x+fx[dr];
        ll bro = y + fy[dr];
        if(yo>=0 && yo<m && bro>=0 && bro<n && grid[yo][bro] == false && str[yo][bro] == chk[ln])
        {
            if(ln + 1 == sz)
            {
                //cout<<yo+1<<" "<<bro+1<<endl;
                flag = true;
                return;
            }
            else bfs(yo,bro,ln + 1,dr);
        }
//    }
    return;
}


int main()
{
    ll t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        if(w >0)
            cout<<endl;
        w++;
        scanf("%lld %lld",&m,&n);
        for(int i=0; i<m; i++)
        {
            cin>>str[i];
            transform(str[i].begin(), str[i].end(), str[i].begin(),:: toupper);

        }

        scanf("%lld",&k);
        for(int l =0; l<k; l++)
        {
            cin>>chk;
            sz = chk.size();

            transform(chk.begin(), chk.end(), chk.begin(), ::toupper);
            flag = false;
            for(int i=0; i<m; i++)
            {
                if(flag)
                    break;
                for(int j=0; j<n; j++)
                {
                    if(str[i][j] == chk[0])
                    {

                       // grid[i][j]=true;
                       for(int k=0; k<8; k++)
                       {
                           memset(grid,false,sizeof(grid));
                           bfs(i,j,1,k);

                           if(flag)break;
                       }
                        //bfs(i,j,1);
                        if(chk.size() == 1)
                        {
//cout<<1<<" "<<1<<endl;
                            flag = true;
                        }

                        if(flag)
                        {
                            cout<<i+1<<" "<<j+1<<endl;
                            break;
                        }
                    }
                }
            }

        }
    }
    return 0;
}

