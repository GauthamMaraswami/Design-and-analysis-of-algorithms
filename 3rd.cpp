#include <iostream>
#include <vector>
using namespace std;
 

void print(vector<int>& arr)
{
    
    for(int i=0;i<arr.size();++i)
    {
        cout<<arr[i];
    }
    
}
 

void construct(int arr[], int n)
{
    
    vector<vector<int> > L(n);
 
    
    L[0].push_back(arr[0]);
 
    
    for (int i = 1; i < n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {

            if ((arr[i] > arr[j]) &&
                    (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }
 

        L[i].push_back(arr[i]);
    }
 

    vector<int> max = L[0];
 

    for (int i=0;i<L.size();++i)
        if (L[i].size() > max.size())
            max = L[i];
 
   print(max);
}
 

int main()
{
 int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
    construct(arr, n);
 
    return 0;
}
