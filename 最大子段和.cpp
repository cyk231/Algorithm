#include<bits/stdc++.h>
using namespace std; 

int n;
int dp[100005];
int a[1000005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxVal=a[1];
	for(int i=1;i<=n;i++) 
	{
		dp[i]=max(dp[i-1]+a[i],a[i]);
		maxVal=max(maxVal,dp[i]);
	}
	cout<<maxVal;
}
