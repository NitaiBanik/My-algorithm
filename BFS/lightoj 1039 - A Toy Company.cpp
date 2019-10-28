#include<bits/stdc++.h>
using namespace std;
int vis[128][128][128];
#define inf 0x3f3f3f3f
int fx[] = {1,-1,0,0,0,0};
int fy[] = {0,0,1,-1,0,0};
int fz[] = {0,0,0,0,1,-1};
string frm,to;
int bfs()
{
    queue<string>Q;
    Q.push(frm);

    vis[frm[0]][frm[1]][frm[2]] = 0;
    while(!Q.empty())
    {
        string temp;
        temp = Q.front();
        Q.pop();
        if(temp == to)
            return vis[to[0]][to[1]][to[2]];
        for(int i=0; i<6; i++)
        {
            string chk = "";
            if(fx[i] == 1 && temp[0] == 'z')
                chk+='a';
            else if(fx[i] == -1 && temp[0] == 'a')
                chk+='z';
            else
                chk+=(temp[0] + fx[i]);
            if(fy[i] == 1 && temp[1] == 'z')
                chk+='a';
            else if(fy[i] == -1 && temp[1] == 'a')
                chk+='z';
            else
                chk+=(temp[1] + fy[i]);
            if(fz[i] == 1 && temp[2] == 'z')
                chk+='a';
            else if(fz[i] == -1 && temp[2] == 'a')
                chk+='z';
            else
                chk+=(temp[2] + fz[i]);
            if(vis[chk[0]][chk[1]][chk[2]] == inf)
            {
               // cout<<"chk = "<<chk<<endl;
                vis[chk[0]][chk[1]][chk[2]] = vis[temp[0]][temp[1]][temp[2]] + 1;
                Q.push(chk);
            }

        }

    }
    return vis[to[0]][to[1]][to[2]];
}
int main()
{

    int t,w =0;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,inf,sizeof(vis));
        cin>>frm>>to;
        int qu;
        scanf("%d",&qu);
        while(qu--)
        {
            string one,two,three;
            cin>>one>>two>>three;
            int ii = one.size();
            int jj = two.size();
            int kk = three.size();
            for(int i=0; i<ii; i++)
                for(int j=0; j<jj; j++)
                    for(int k=0; k<kk; k++)
                        vis[one[i]][two[j]][three[k]] = -1;
        }
        int val;
        if(vis[frm[0]][frm[1]][frm[2]] == -1)
            val = -1;
            else
        val = bfs();
        printf("Case %d: %d\n",++w,val);
    }
}
