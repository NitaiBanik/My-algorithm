#include<bits/stdc++.h>
using namespace std;
string nw1,nw2;
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

void insertt1(string s,int len)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=0; i<len; i++)
    {
        id  = s[i] -'0';
        if(curr->next[id] == NULL)
        {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}
void insertt2(string s,int len)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=0; i<len; i++)
    {
        id  = s[i] -'0';
        curr = curr->next[id];
        curr->cnt--;
    }

}
void insertt3(string s,int len)
{
    int i,ck = 0,id ;
    node *curr = root;
    for(i=0; i<len; i++)
    {
        id  = s[i] -'0';
        id^=1;
        if(curr->next[id] == NULL || curr->next[id]->cnt == 0)
        {
            id^=1;
            curr = curr->next[id];
            nw1+=char(id + '0');

        }
        else
        {
            curr = curr->next[id];
            nw1+=char(id + '0');
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
    string str;
    val = 0;
    for(int i = 30; i>=0; i--)
    {
        if((val & (1<<i)) == 0)
            str+='0';
        else
            str+='1';
    }
    insertt1(str,31);

    while(n--)
    {
        str = "";
        char ch;
        cin>>ch>>val;
        for(int i = 30; i>=0; i--)
        {
            if((val & (1<<i)) == 0)
                str+='0';
            else
                str+='1';
        }
        if(ch =='+')
            insertt1(str,31);
        else if(ch =='-')
            insertt2(str,31);
        else
        {
            nw1 = "",nw2 = "";
            insertt3(str,31);
            int sm = 0;
            reverse(str.begin(),str.end());
            reverse(nw1.begin(),nw1.end());
             //cout<<str<<endl<<endl;
           //cout<<nw1<<endl<<endl;
            for(int i = 30; i >=0; i--)
            {
                if((str[i] == '0') && (nw1[i] == '0'))
                    sm+=0;
                else if((str[i] == '1') && (nw1[i] == '1'))
                    sm+=0;
                else
                {
                    int j = (1<<i);
                    //cout<<"j = "<<j<<endl;
                    sm+=j;

                }

//            cout<<str<<endl<<endl;
//            cout<<nw1<<endl<<endl;

            }
             cout<<sm<<endl;
        }

    }
    return 0;
}
