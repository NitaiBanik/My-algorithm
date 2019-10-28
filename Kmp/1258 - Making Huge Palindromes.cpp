#include<bits/stdc++.h>
using namespace std;
int fail[1000007];
void failure(char *patt)
{
    fail[0] = 0;
    int k = 1,len = 0;
    int len_patt = strlen(patt);
    while(k<len_patt)
    {
        if(patt[k] == patt[len])
            fail[k++] = ++len;
        else
        {
            if(len)
                len = fail[len-1];
            else
                fail[k++] = 0;
        }
    }
    return;
}
int KMP( char *patt,char *tx)
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
                // cout<<"Found at position = "<<ret<<endl;
                j = fail[j - 1];
            }
        }
        else
        {
            if(j)
                j = fail[j-1];
            else
                i++;
        }
    }
    return j;
}
int main()
{
    int t,w = 0;
    cin>>t;
    getchar();
    while(t--)
    {
        char txt[1000007];
        char pat[1000007];
        //gets(pat);
        gets(txt);
        int len_pat = strlen(txt);
        int j = 0;
        for(int i = len_pat-1; i>=0; i--)
        {
            pat[i] = txt[j++];
        }
        if(strcmp(txt,pat) == 0)
            printf("Case %d: %d\n",++w,len_pat);
        else
        {
            failure(pat);
            int sz = KMP(pat,txt);
            printf("Case %d: %d\n",++w,len_pat * 2 - sz);
        }
    }
    return 0;
}

