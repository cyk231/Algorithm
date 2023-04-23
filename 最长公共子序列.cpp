#include<bits/stdc++.h>
using namespace std; 

int dp[10005][10005];

int main()
{
    string a="ABCBDAB";
    string b="BDCABA";
    int len1=a.length();
    int len2=b.length();
    for(int i=1;i<=len1;i++)
    {
    	for(int j=1;j<=len2;j++)
    	{
    		if(a[i]!=b[j]) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		else dp[i][j]=dp[i-1][j-1]+1; 
	}
    }
	cout<<dp[len1][len2];
}
