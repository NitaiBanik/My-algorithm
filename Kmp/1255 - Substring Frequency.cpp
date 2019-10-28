#include<bits/stdc++.h>
using namespace std;
int fail[1000007];
int cnt = 0;
void failure(char *patt)
{
    fail[0] = 0;
    int k = 1,len = 0;
    int len_patt = strlen(patt);
    while(k<len_patt)
    {
        if(patt[k] == patt[len]) fail[k++] = ++len;
        else
        {
            if(len) len = fail[len-1];
            else
                fail[k++] = 0;
        }
    }
    return;
}
void KMP( char *patt,char *tx)
{
  int ln_p = strlen(patt);
  int ln_txt = strlen(tx);
  int i=0,j=0,ret = -1;
  while(i<ln_txt)
  {
      if(tx[i] == patt[j])
      {
          i++,j++;
          if(j == ln_p)
          {
              ret = i - ln_p;
              cnt++;
             // cout<<"Found at position = "<<ret<<endl;
              j = fail[j - 1];
          }
      }
      else
      {
          if(j) j = fail[j-1];
          else
            i++;
      }
  }
}
int main()
{
    int t,w=0;
    cin>>t;
    getchar();
    while(t--)
    {
        cnt = 0;
    ///0 based index;
    char txt[1000007];
    char pat[1000007];
    gets(txt);
    gets(pat);
    int len_pat = strlen(pat);
    failure(pat);///pattern first
    KMP(pat,txt);
    printf("Case %d: %d\n",++w,cnt);
    }

}
