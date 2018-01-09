#include<iostream>
using namespace std;


int majority(int data[],int n,int tiebreaker=-1)
{
    int ctr=0;
    if (n == 0)
        return tiebreaker ;
    int pairs[n];   
    if (n % 2 == 1)
        tiebreaker = data[n-1];

 for(int i = 0; i < n-1; i+=2)
    {
    if (data[i] == data[i+1])
        {

           pairs[ctr]=data[i];
           ++ctr; 
        }
     }
     int major;
major = majority(pairs,ctr, tiebreaker);
if (major ==-1)
    return -1;
int nMajor=0;
 for(int j=0;j<n;++j)
 {
    if(data[j]==major)
    ++nMajor;
 }

if ((2*nMajor > n)|| (2*nMajor == n && major == tiebreaker ))
    return major;
return -1;
}
int main()
{
    int n;
	cin >> n;
	int a[n];
	//vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << (majority(a, n,-1));
}




