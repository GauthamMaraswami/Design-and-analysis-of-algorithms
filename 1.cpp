#include <stdio.h>
#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x,int mid)
{
    
   if (r >= l)
   {
        mid = l + (r - l)/2;
 

        if (arr[mid] == x)  return mid;
 

        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x,mid);
 

        return binarySearch(arr, mid+1, r, x,mid);
   }
 

   return mid;
}

int kth(int a[],int n,int k,int b[])
{
    if(k>n){
    for(int i=0;i<n;++i)
        b[i]=a[i];
    
    return 0;
    }
    int pt=0;
    
    int small,sear;
    int ctr=0;
    while(ctr<k)
    {
    small=a[pt];
    sear=small+1;
    b[ctr]=small;
    pt=binarySearch(a,0,n-1,sear,0);
    small=a[pt];
    
    
    ++ctr;
    }
    for(int i=0;i<k;++i)
    {
    //cout<<b[i];
    }



return 0;
}
int main(){
  int a[] = {1,2,2,7,9};
  int b[] = {3,4,6,8,10};
 int drr[120],crr[120];
  int sizeA  ;
  int sizeB ;
  cin>>sizeA>>sizeB;
  cout<<"enter a"<<endl;
	
	for (int i = 0; i<sizeA; ++i) {
		cin >> a[i];
	}
	cout<<"enter b"<<endl;
	
	for (int i = 0; i<sizeB; ++i) {
		cin >> b[i];
	}
	cout<<"enter k"<<endl;
	int k;
	cin>>k;
	kth(a,sizeA,k,crr);
	kth(b,sizeB,k,drr);
	int i0=0,i1=0;
	int frr[100];
	for(int j=0;j<k;++j)
	{
	    if(crr[i0]<drr[i1])
	    {
	        frr[j]=crr[i0];
	        ++i0;
	    }
	    else if(crr[i0]>drr[i1])
	    {
	        frr[j]=drr[i1];
	        ++i1;
	    }
	    else
	    {
	        frr[j]=drr[i1];
	        ++i1;
	        ++i0;
	    }
	    cout<<frr[j];
	
	}
  printf("\n Kth smallest element is : %d", 
             frr[k-1]);
  return 0;
}
/*int main()
{
int arr[]={1,2,2,4,4,4,5,7,7,9,9};
int n=11;

kth(arr,n,k,brr);
kth()
return 0;
}*/
