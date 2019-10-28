#include<bits/stdc++.h>
using namespace std;
int main()
{
    istringstream iss;
    string value="32 40 50 80 902";

    iss.str (value);
    for(int i=0; i<5; i++)
    {
        // cout<< " " <<i<<"\n";
        int val;
        iss >> val;
        cout << i <<" "<< val <<endl;
    }
}
