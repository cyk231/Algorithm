#include<bits/stdc++.h>
using namespace std; 

int t;// 总时间 
int m;// 物品数 
int w[105];// 每个物品的时间 
int v[105];// 每个物品的价值 
int dp[1005][1005];

int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=t;j>=0;j--)
		{
			if(j<w[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	} 
	cout<<dp[m][t];
}
