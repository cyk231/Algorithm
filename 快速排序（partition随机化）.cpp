#include<bits/stdc++.h>
using namespace std;
#define N 5

int partition(int a[],int p,int r)// 划分，返回分界线下标 
{
	int i=p;
	int j=r+1;
	int x=a[p];
	while(true)
	{
		while(a[++i]<x&&i<r) ;
		while(a[--j]>x) ;
		if(i>=j) break;
		swap(a[i],a[j]); 
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

int Randomized_partition(int a[],int p,int r)
{
	int i=(rand()%(r-p+1))+p;// i=Random(p,r)
	swap(a[i],a[p]);
	return partition(a,p,r);
}

void quicksort(int a[],int p,int r)// 递归排序 
{
	if(p>=r) return ;
//	int q=partition(a,p,r);
	int q=Randomized_partition(a,p,r);// 随机化 
	quicksort(a,p,q-1);// 左边排序 
	quicksort(a,q+1,r);// 右边排序 
}

int main()
{
	int a[N]={2,3,1,5,4};
	
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
	cout<<endl;
	quicksort(a,0,N-1);
	for(int i=0;i<N;i++) cout<<a[i]<<" ";
}
