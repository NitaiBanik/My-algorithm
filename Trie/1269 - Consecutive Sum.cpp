#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll nw1;
struct node
{
    bool endmark;
    ll cnt;
    node *next[2];
    node()
    {

        endmark = false;
        cnt = 0;
        for(ll i = 0; i<2; i++)
            next[i] = NULL;

    }
}*root;

void insertt1(ll val)
{
    // cout<<"fiff"<<endl;
    ll i,ck = 0,id ;
    node *curr = root;
    for(i=31; i>=0; i--)
    {
        id  = val &(1<<i) ;
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

void getmax(ll val)
{
    //  cout<<"id"<<endl;
    int i,ck = 0,id ;
    node *curr = root;
    for(i=31; i>=0; i--)
    {
        id  = val &(1<<i) ;
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
void getmin(ll val)
{
    ll i,ck = 0,id ;
    node *curr = root;
    for(i=31; i>=0; i--)
    {
        id  = val &(1<<i);
        if(id!=0)
            id  = 1;
        if(curr->next[id] == NULL)
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
void del(node *curr)
{
    for(ll i=0; i<2; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}
int main()
{
    ll t,ww = 0;
    cin>>t;
    while(t--)
    {
        root = new node();
        ll w,n,val,mx = 0,mn = 9999999999999;
        scanf("%lld",&n);
        val = 0;
        for(ll i = 0; i<n; i++)
        {
            cin>>w;
            val^=w;
            mn = min(mn,val);
            mx = max(mx,val);
            if(i == 0)
            {
                insertt1(val);
                continue;
            }
            nw1 = 0;
            getmax(val);
            mx = max(mx,val^nw1);
            nw1 = 0;
//            getmin(val);
//            mn = min(mn,val^nw1);

            insertt1(val);
            //cout<<"mx = "<<mx<<" mn = "<<mn<<endl;

        }
        cout<<mx<<endl;
       // cout<<"Case "<<++ww<<": "<<mx<<" "<<mn<<endl;
        del(root);
    }
    return 0;
}
