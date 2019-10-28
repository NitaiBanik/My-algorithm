#include<bits/stdc++.h>
using namespace std;
int nw1;
struct node
{
    bool endmark;
    int cnt;
    node *next[2];
    node()
    {

        endmark = false;
        cnt = 0;
        for(int i = 0; i<2; i++)
            next[i] = NULL;

    }
}*root;

void insertt1(int val)
{
    int i,ck = 0,id ;
    node *curr = root;
   for(i=30; i>=0; i--)
    {
        id  = val &(1<<i);
        if(id!=0)
            id  = 1;
        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}
void insertt2(int val)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=30; i>=0; i--)
    {
        id  = val &(1<<i);
        if(id!=0)
            id  = 1;
        curr = curr->next[id];
        curr->cnt--;
    }

}
void insertt3(int val)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=30; i>=0; i--)
    {
        id  = val &(1<<i);
        if(id!=0)
            id  = 1;
        id^=1;
        if(curr->next[id] == NULL || curr->next[id]->cnt == 0)
        {
            id^=1;
            curr = curr->next[id];
           if(id == 1)
                nw1|=(1<<i);

        }
        else
        {
            curr = curr->next[id];
         if(id == 1)
                nw1|=(1<<i);
        }
    }
    curr->endmark = true;
}
int main()
{
    int t,w = 0;

    root = new node();
    int n,val;
    scanf("%d",&n);
    insertt1(0);

    while(n--)
    {
        char ch;
        cin>>ch>>val;
        nw1 = 0;
        if(ch =='+')
            insertt1(val);
        else if(ch =='-')
            insertt2(val);
        else
        {
            insertt3(val);

            cout<<(val ^ nw1)<<endl;
        }

    }
    return 0;
}
