#include<bits/stdc++.h>
using namespace std;
int main()
{
    stringstream m;
    m<<40<<" "<<50<<" " <<60;
    int a,b,c;
    m>>a>>b>>c;
    cout<<"a : "<<a+b<<endl;
    cout<<"b : "<<b-c<<endl;
    cout<<"c : "<<c*b<<endl;
}
