#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a[10];
    int i;
    cout<<"Enter 4 strings"<<endl;
    for(i = 0 ; i < 4;i++)
        getline(cin,a[i]);
    sort(a,a+4);
    cout<<"The sorted strings are"<<endl;
     for(i = 0 ; i < 4;i++)
        cout<<a[i]<<endl<<endl;
}
