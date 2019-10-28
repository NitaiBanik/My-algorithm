#include<bits/stdc++.h>
using namespace std;

int or_xor[15];
int oR[15];
int XOOr[15];

bool chk(int num, int pos)
{
    return (bool)(num & (1<<pos));
}

int main()
{
    int q;
    cin>>q;

    int all_on = 1023;
    int all_off = 0;
    string s;
    int val;

    for(int i=0; i<q; i++)
    {
        cin>>s>>val;
        if(s == "&")
        {
            all_on = all_on & val;
            all_off = all_off & val;
        }
        else if(s == "|")
        {
            all_on = all_on | val;
            all_off = all_off | val;
        }
        else
        {
            all_on = all_on ^ val;
            all_off = all_off ^ val;
        }

    }
//cout<<"on = "<<all_on<<endl;
//cout<<"off = "<<all_off<<endl;
    for(int i=0; i<10; i++)
    {
        bool c1 = chk(all_on,i);
        bool c2 = chk(all_off,i);
       // cout<<"pos = "<<i<<" "<<"c1 = "<<c1<<" c2 = "<<c2<<endl;
        if(c1 == false && c2 == false)
        {
            or_xor[i]  = 1;
        }
        else if(c1 == true && c2 == true)
        {
            oR[i] = 1;
        }
        else if(c1 == false && c2 == true)
        {
            XOOr[i] = 1;
        }
        else if(c1 == true && c2 == false)
        {
            ////no operation
        }
    }

    int A = 0,O = 0,X = 0;

    for(int i=0; i<10; i++)
    {
        if(or_xor[i])
            A = A | (1<<i);
        if(XOOr[i])
            X = X | (1<<i);
        if(oR[i])
            O = O | (1<<i);
    }

    int cn = 0;

    if(A !=0) cn+=2;
    if(O!=0) cn++;
    if(X!=0) cn++;

    cout<<cn<<endl;

    if(A)
    {
        cout<<"| "<<A<<endl;
        cout<<"^ "<<A<<endl;
    }

    if(O) cout<<"| "<<O<<endl;
    if(X) cout<<"^ "<<X<<endl;

    return 0;
}
