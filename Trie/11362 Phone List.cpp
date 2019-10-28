#include<bits/stdc++.h>
using namespace std;
bool cnt;

struct node
{
    bool endmark;
    node *next[10+1];
    node()
    {

        endmark = false;
        for(int i = 0; i<10; i++)
            next[i] = NULL;

    }
}*root;

void insertt(string s,int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id  = s[i] -'0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool searchh(string s,int len)
{
    node *curr = root;

    for(int i=0; i<len; i++)
    {
        int id = s[i] - '0';
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }

    for(int i=0; i<10; i++)
        if(curr->next[i]!=NULL)
        {
            cnt = true;
        }
    return curr->endmark;
}

void del(node *curr)
{
    for(int i=0; i<10; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<string>v;
        string str;
        //printf("Enter how many words : ");
        root = new node();
        int n;
        cin>>n;
        while(n--)
        {
            cin>>str;
            v.push_back(str);
            insertt(str,str.size());
        }
        //printf("Enter how many words to search: ");
        //int q;
        //cin>>q;
        int sz = v.size(),ck = 0;
        sort(v.begin(),v.end());
        for(int i=0; i<sz; i++)
        {
            cnt= false;

            if(searchh(v[i],v[i].size()) && cnt)
            {
                //cout<<cnt<<endl;
                ck = 1;
                break;
            }
        }
        if(ck)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        v.clear();
        del(root);
    }
}
