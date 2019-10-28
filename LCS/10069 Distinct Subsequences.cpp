#include<bits/stdc++.h>
using namespace std;

string dp[10005][105];
bool chk[10000][105];

string A,B;
int Ln1,Ln2;

string ADD(string a, string sum)
{
    string b = "";
//cout<<a<<endl<<" "<<sum<<endl;
    reverse(sum.begin(),sum.end());

    reverse(a.begin(),a.end());

    int ln1 = sum.size(),i;

    int ln2 = a.size();

    int diff = abs(ln1-ln2);

    if(ln1 > ln2)
    {
        while(diff--)
            a+='0';
    }

    if(ln1 < ln2)
    {
        while(diff--)
            sum+='0';
    }

    int temp = 0;
    for(i= 0 ; i < sum.size(); i++)
    {
        int t = temp +(a[i] - '0') + (sum[i] - '0');
        b+=((t % 10) +'0');
        temp = t/10;
    }

    if(temp!=0)
        b+=(temp+'0');

    reverse(b.begin(),b.end());
    //cout<<b<<endl;
    return b;
}

string LCS(int i,int j)
{
   // cout<<i<<" "<<j<<endl;
    if(i == Ln1 || j == Ln2)
    {
        if(j == Ln2) return "1";
        else return "0";
    }
    if(chk[i][j]!=0) return dp[i][j];

    string ret= "";

    if(A[i] == B[j])
        ret= ADD(ret,LCS(i+1,j+1));

    ret = ADD(ret,LCS(i+1,j));

    chk[i][j] = 1;
   // cout<<ret<<"";
    return dp[i][j] = ret;

}

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,A);
        getline(cin,B);
        Ln1 = A.size();
        Ln2 = B.size();
        //cout<<Ln1<<" "<<Ln2<<endl;
        memset(chk,0,sizeof(chk));
        string ans = LCS(0,0);
        cout<<ans<<endl;

    }
    return 0;
}
