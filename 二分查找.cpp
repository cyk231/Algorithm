#include<bits/stdc++.h>
using namespace std;
#define N 10

int BinarySearch(int a[],int x,int n)// 找到返回下标，未找到返回-1 
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) right=mid-1;
		else left=mid+1;
	}
	return -1;
}

int main()
{
	int a[N]={1,2,4,7,8,9,11,13,14,18};
	int x=13;
	int index=BinarySearch(a,x,N); 
	if(index==-1) cout<<"不存在";
	else cout<<"下标为"<<index; 
}
