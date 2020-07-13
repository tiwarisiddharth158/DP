#include<bits/stdc++.h>
using namespace std;

string lcs(string s1,string s2,int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i=n,j=m;
    string str = "";
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            str += s1[i-1];
            --i;--j;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i = i-1;
            }
            else
                j = j-1;
        }
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    string s1 = "acbcf";
    string s2 = "abcdaf";
    int n = s1.length();
    int m = s2.length();
    cout<<lcs(s1,s2,n,m);
}
