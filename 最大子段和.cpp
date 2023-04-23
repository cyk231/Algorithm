#include<bits/stdc++.h>
using namespace std; 

int n;
int dp[100005];
int a[1000005];

int main()
{
	// 动态规划法
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxVal=a[1];
	for(int i=1;i<=n;i++) 
	{
		dp[i]=max(dp[i-1]+a[i],a[i]);
		maxVal=max(maxVal,dp[i]);
	}
	cout<<maxVal;
	
	// 三重循环暴力求解
//      cin>>n;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	int maxVal=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			int sum=0;
//			for(int k=i;k<=j;k++) sum+=a[k];
//			if(sum>maxVal) maxVal=sum;
//		}
//	}
//	cout<<maxVal;
}
