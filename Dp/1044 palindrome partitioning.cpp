#include<bits/stdc++.h>
using namespace std;

vector<int>vec[1005];

int dp[1005],ln;
int fun(int pos)
{
    if(pos == ln)
        return 0;

    int &ret = dp[pos];
    if(ret != -1)
        return ret;

    ret = 99999999;
    for(int i = 0; i < vec[pos].size(); i++)
        ret = min(ret, 1 + fun(vec[pos][i]));

    return ret;
}
int main()
{
    int t,w = 0;
    string str;
    cin>>t;

    while(t--)
    {
        cin>>str;
        // cout<<str<<endl;
        ln = str.size();
        for(int mid = 0; mid < ln; mid++ )
        {
            int start = mid,End = mid;

            while(str[start] == str[End])
            {
                vec[start].push_back(End+1);
                start--,End++;
                if(start < 0 || End == ln)
                    break;
            }
        }

        for(int mid = 0; mid < ln-1; mid++)
        {
            int start = mid,End = mid + 1;
            while(str[start] == str[End])
            {
                vec[start].push_back(End+1);
                start--,End++;
                if(start < 0 || End == ln)
                    break;
            }
        }

//        for(int i = 0; i < ln; i++)
//        {
//            cout<<"From " <<i<<endl;
//            for(int j = 0; j < vec[i].size(); j++)
//                cout<<vec[i][j]<<" ";
//
//            cout<<endl;
//        }

        memset(dp, - 1, sizeof(dp));
        int ans = fun(0);
        printf("Case %d: %d\n", ++w, ans);
        for(int i = 0; i<= ln; i++)
            vec[i].clear();

    }
    return 0;
}
