#include<bits/stdc++.h>
using namespace std;
#define n 5
void quicksort(int first,int last,int a[])
{
	if(first>=last) return;
	int i=first;
	int j=last;
	int p=a[first];
	while(i!=j)
	{
		while(a[j]>=p&&i<j) j--;
		while(a[i]<=p&&i<j) i++;
		if(i<j) swap(a[i],a[j]);
	}
	swap(a[i],a[first]);
	quicksort(first,i-1,a);
	quicksort(i+1,last,a);
}
int main()
{
	int a[n]={2,3,1,5,4};
	quicksort(0,n-1,a);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
