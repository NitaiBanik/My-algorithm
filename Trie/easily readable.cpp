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

int searchh(string s,int len)
{
    node *curr = root;

    for(int i=0; i<len; i++)
    {
        int id = (int)s[i];
        if(curr->next[id] == NULL)
            return 0LL;
        curr = curr->next[id];
    }
   //  return curr->cnt;
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
        int n;
        cin>>n;

        while(n--)
        {
            string st;
            cin>>st;
            if(st.size()>2)
                sort(st.begin() + 1, st.end() - 1);
            cout<<"ekhane1 "<<st<<endl;
            insertt(st, st.size());
        }

        int ln;
        cin>>ln;

        while(ln--)
        {
            string line,nw;
            getline(cin,line);

            cout<<"line = "<<line<<endl;

            stringstream ss(line);
           // ll ans= 1LL;
            while(ss>>nw)
            {
                if(nw.size()>2)
                    sort(nw.begin() + 1, nw.end() - 1);
               // ans*=searchh(nw,(int)nw.size());
            }
            //cout<<ans<<endl;

        }
        del(root);
    }

    return 0;
}
