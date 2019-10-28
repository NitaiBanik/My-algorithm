#include<bits/stdc++.h>
using namespace std;
int mx2;
struct node
{
    bool endmark;
    int cnt;
    node *next[3];
    node()
    {

        endmark = false;
        cnt = 0;
        for(int i = 0; i<2; i++)
            next[i] = NULL;

    }
}*root;
void insertt(char *s,int len)
{
    int i,ck = 0          ;
    node *curr = root;
    for(i=0; i<len; i++)
    {
        int id  = s[i] -'0';
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
    for(int i=0; i<2; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        root = new node();
        int n;
        scanf("%d",&n);
        char str[1000];
        int mx = 0;
         mx2 = 0;
        while(n--)
        {
             scanf("%s",str);
            int q = strlen(str);
            mx = max(mx,q);
            insertt(str,q);
        }
        printf("%d\n",max(mx,mx2));
        del(root);
    }
    return 0;
}
