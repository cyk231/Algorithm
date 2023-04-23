#include<bits/stdc++.h>
using namespace std;
#define N 5
int a[N]={5,8,1,3,2},b[N];// b为辅助数组 

void merge(int left,int mid,int right)// 合并 
{
	int i=left;
	int j=mid+1;
	int k=left;
	while(i<=mid&&j<=right)// 类似于合并链表
	{
		if(a[i]<a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	while(i<=mid)   b[k++]=a[i++];
	while(j<=right) b[k++]=a[j++];
	for(int i=left;i<=right;i++) a[i]=b[i];
}

void mergesort(int left,int right)// 排序 
{
	if(left>=right) return ;
	int mid=(left+right)/2;
	mergesort(left,mid);   // 左边排序 
	mergesort(mid+1,right);// 右边排序 
	merge(left,mid,right); // 合并 
} 

int main()
{
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
	cout<<endl;
	mergesort(0,N-1);
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
}
