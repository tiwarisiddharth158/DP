#include<bits/stdc++.h>
#define n 4
#define W 10
using namespace std;

int dp[n+1][W+1];

int knapSack(int wt[],int val[])
{
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=0;j<=W;j++)
        dp[0][j] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else if(wt[i-1]>j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    cout<<knapSack(wt,val);
}
