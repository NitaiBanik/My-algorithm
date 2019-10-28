#include<bits/stdc++.h>
using namespace std;
int mx2;
struct node
{
    bool endmark;
    int cnt;
    node *next[5];
    node()
    {

        endmark = false;
        cnt = 0;
        for(int i = 0; i<5; i++)
            next[i] = NULL;

    }
}*root;
void insertt(char *s,int len)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=0; i<len; i++)
    {
        if(s[i] == 'A')
      id  = s[i] -'A';
        else if(s[i] == 'T')
       id  = s[i] -'T' + 1;
        else if(s[i] == 'G')
        id  = s[i] -'G' + 2;
        else
         id  = s[i] -'C'+3;
        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->cnt++;
        mx2 = max(mx2,(curr->cnt) *(i+1) );
    }
    curr->endmark = true;
}
void del(node *curr)
{
    for(int i=0; i<5; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}
int main()
{
    int t,w = 0;
    scanf("%d",&t);
    while(t--)
    {
        root = new node();
        int n;
        scanf("%d",&n);
        char str[55];
        int mx = 0;
         mx2 = 0;
        while(n--)
        {
             scanf("%s",str);
            int q = strlen(str);
            mx = max(mx,q);
            insertt(str,q);
        }
        printf("Case %d: %d\n",++w,max(mx,mx2));
        del(root);
    }
    return 0;
}
