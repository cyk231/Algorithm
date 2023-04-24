#include<bits/stdc++.h>
using namespace std; 

int n=6;
int k=4;
int a[6]={2,5,3,1,4,6};

int Partition(int a[],int p,int r)// 划分 
{
    int i=p;
    int j=r+1;
    int x=a[p];
    while(true)// 类似于快排的过程 
    {
        while(a[++i]<x&&i<r) ;
        while(a[--j]>x) ;
        if (i>= j) break;
        swap(a[i],a[j]);
    }
    a[p]=a[j];
    a[j]=x;
    return j;
}

int RandomizedPartition(int a[],int p,int r)// 随机划分 
{
    int i=p+rand()%(r-p);// i=Random(p,r) ，在p和r之间找一个随机数
    swap(a[i],a[p]);// 交换基准 
    return Partition(a,p,r);// 划分 
}

int RandomizedSelect(int a[],int p,int r,int k)// RandomizedSelect算法（分治） 
{
    if(p==r) return a[p];// 若左右区间重合，则该位置就是要找的第k小元素 
    int i=RandomizedPartition(a,p,r);// 划分位置 
    int len=i-p+1;
    if(k<=len) return RandomizedSelect(a,p,i,k);// 对左区间递归查找 
    else return RandomizedSelect(a,i+1,r,k-len);// 对右区间递归查找 
}

int main()
{	
    cout<<RandomizedSelect(a,0,n-1,k);
}
