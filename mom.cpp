#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int te=a;
    a=b;
    b=te;
}
int findkth(int *v, int n, int k) {
    if (n == 1 && k == 0) return v[0];

    int m = (n + 4)/5;
    int *medians = new int[m];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    int pivot = findkth(medians, m, m/2);
    delete [] medians;

    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v[i], v[n-1]);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store], v[n-1]);

    if (store == k) {
        return pivot;
    } else if (store > k) {
        return findkth(v, store, k);
    } else {
        return findkth(v+store+1, n-store-1, k-store-1);
    }
}

int main()
{

int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout<<"enter k";
	int k;
	cin>>k;

int b=(n-k)/2;
int e=(n+k)/2;
int me=n/2;
int be=findkth(a, n, b);
int ee=findkth(a, n, e);
int mee=findkth(a, n, me);
int newarr[n];
for(int i=0;i<n;++i)
{
if(a[i]!=mee)
{
    if(a[i]>mee)
        newarr[i]=a[i]-mee;
    else
        newarr[i]=mee-a[i];
}

}
for(int i=0;i<n;++i)
{
    if(a[i]>=be&& a[i]<=ee&& a[i]!=mee)
    {
        cout<<a[i];
    }
    

}
return 0;
}
