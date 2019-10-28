#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    int pos1 = - 1,pos2 = -1;
    cin>>st;
    for(int i = 0; i < st.size() ; i++)
    {
        if(st[i] == '[')
        {
            pos1 = i;
            break;
        }
    }
    for(int i = st.size()-1; i >=0  ; i--)
    {
        if(st[i] == ']')
        {
            pos2 = i;
            break;
        }
    }
    if(pos1 == -1 || pos2 == -1)
    {
        cout<<-1<<endl;
    }
    else
    {
        int pos3 = -1,pos4 = -1;
        for(int i = pos1+1; i < pos2 ; i++)
        {
            if(st[i] == ':')
            {
                pos3 = i;
                break;
            }
        }
        for(int i = pos2 - 1; i > pos1  ; i--)
        {
            if(st[i] == ':' && i != pos3)
            {
                pos4 = i;
                break;
            }
        }
        if(pos3 == pos4 || pos3 == -1 || pos4 == -1)
            cout<<-1<<endl;
        else
        {
            int cn = 0;
            for(int i = pos3 + 1; i< pos4;i++)
                if(st[i] == '|')  cn++;
            cout<<cn+4<<endl;

        }
    }
}
