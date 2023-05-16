#include<bits/stdc++.h>
using namespace std;
#define int long long

int t;// 总时间  
int m;// 物品数 
int w[10000005];// 每个物品的时间 
int v[10000005];// 每个物品的价值 
int dp[10000005];



signed main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=w[i];j<=t;j++)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[t]; 
}
