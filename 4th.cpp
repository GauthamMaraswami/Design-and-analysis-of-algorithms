#include <iostream>
using namespace std;
struct arr{
    int val;
    int sign;
};
void swap(struct arr &a,struct arr &b)
{
    struct arr te=a;
    a=b;
    b=te;
}

struct arr findkth(struct arr *v, int n, int k) {
    if (n == 1 && k == 0) return v[0];

    int m = (n + 4)/5;
    struct arr *medians = new struct arr[m];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            struct arr *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j].val < w[jmin].val) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }

    struct arr pivot = findkth(medians, m, m/2);
    delete [] medians;

    for (int i=0; i<n; i++) {
        if (v[i].val == pivot.val) {
            swap(v[i], v[n-1]);
            break;
        }
    }

    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i].val < pivot.val) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store].val, v[n-1].val);

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
	struct arr a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].val;
		a[i].sign=0;
	}
	cout<<"enter k";
	int k;
	cin>>k;

int b=(n-k)/2;
int e=(n+k)/2;
int me=n/2;
struct arr be=findkth(a, n, b);
struct arr ee=findkth(a, n, e);
struct arr mee=findkth(a, n, me);

for(int i=0;i<n;++i)
{
if(a[i].val!=mee.val)
{
    if(a[i].val>mee.val)
        {
        a[i].val=a[i].val-mee.val;
        a[i].sign=1;
        }
    else if(a[i].val<mee.val)
    {
            a[i].val=mee.val-a[i].val;
            a[i].sign=-1;
    }
    else
    {
            a[n-1]=a[i];
            --n;
    }
}

}
struct arr kthval=findkth(a,n-1,k);
cout<<kthval.val<<endl;
int ctr=0;
for(int i=0;i<n-1;++i)
{
    if(a[i].val<=kthval.val&& ctr<k)
    {
        if(a[i].sign==-1)
        cout<<-a[i].val+mee.val<<" ";
        else 
        cout<<a[i].val+mee.val<<" ";
        ++ctr;
    }
    

}
return 0;
}
