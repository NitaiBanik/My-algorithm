#include<bits/stdc++.h>
using namespace std;
int dp[85][85];
string a,b;
int ln1,ln2;
int mxx = 1000000;
int cn;
int lcs(int i,int j)
{
    if(i == ln1)return (ln2-j);
    if(j == ln2)return (ln1-i);

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ret1 = mxx,ret2 = mxx,ret3 = mxx,ret4 = mxx;

    if(a[i] == b[j])
        ret1 =  lcs(i+1,j+1);
    else
    {
        ret4 = 1 + lcs(i+1,j+1);///changed

        ret2 = 1 + lcs(i + 1,j); ///delete
        ret3 = 1 + lcs(i,j+1); ///insert;
    }
    return dp[i][j] = min(ret4,min(ret1,min(ret2, ret3)));
}
void path(int i, int j)
{
    if(i == ln1 || j == ln2)
    {
        if(i == ln1)
        {
            int x=0;
            int k=j;
            while(k<ln2)
            {

                cout<<++cn<<" Insert"<<" "<<j+1+x<<","<<b[k]<<endl;
                x++;
                k++;
            }
            return;
        }
        if(j == ln2)
        {
            int k=i;
            while(k<ln1)
            {
                cout<<++cn<<" Delete "<<j+1<<endl;
                k++;
            }
            return;
        }
        return;
    }

    int ret1 = mxx,ret2 = mxx,ret3 = mxx,ret4 = mxx;
    if(a[i] == b[j])
        path(i+1,j+1);
    else
    {
        ret4 = 1 + lcs(i+1,j+1);///change

        ret2 = 1 + lcs(i + 1,j); ///delete
        ret3 = 1 + lcs(i,j+1); ///insert;

        int comp = lcs(i,j);


        if(ret4 == comp) //change
        {
            cout<<++cn<<" Replace "<<j+1<<","<<b[j]<<endl;
            path(i + 1,j + 1);
        }
        else if(ret3 == comp)
        {
            cout<<++cn<<" Insert"<<" "<<j+1<<","<<b[j]<<endl;
            path(i,j+1);
        }
        else
        {
            cout<<++cn<<" Delete "<<j+1<<endl;
            path(i+1,j);
        }




    }
//cout<<"ret1 = "<<ret1<<"ret2 = "<<ret2<<" ret3 = "<<ret3<<endl;



}
int main()
{
    //freopen("out.txt","wt",stdout);
    int t,w = 0;
    while(getline(cin,a))
    {
       getline(cin,b);
        cn = 0;
        ln1 = a.size(),ln2 = b.size();
        memset(dp,-1,sizeof(dp));
        int x = lcs(0,0);

        cn = 0;
        if(w>0) cout<<endl;
        w++;
        cout<<x<<endl;
        path(0,0);
    }
}
