
#include <iostream>
#include <vector>


using namespace std;
 int count(const vector<int> &a, int left, int right, int element)
{
	 int count = 0;
	for (unsigned int i = left; i <= right; i++)
	{
		if (a[i] == element)
		{
			count++;
		}
	}
	return count;
}

int getmajorityelement(vector<int> &a, int left, int right) {
	
	if (left > right) return -1;
	if (left == right) return a[left];
	int mid = left + (right - left) / 2;
	int lc = getmajorityelement(a, left, mid);
	int rc = getmajorityelement(a, mid + 1, right);
	if (lc == -1 && rc != -1)
	{
		 int num = count(a, left, right, rc);
		if (num > (right - left + 1) / 2)
		{
			return rc;
		}
		else
		{
			return -1;
		}

	}
	else if (rc == -1 && lc != -1)
	{
		 int num = count(a, left, right, lc);
		if (num > (right - left + 1) / 2)
		{
			return lc;
		}
		else
		{
			return -1;
		}
	}
	else if (lc != -1 && rc != -1)
	{
		 int ln = count(a, left, right, lc);
		 int rn = count(a, left, right, rc);
		if (ln > (right - left + 1) / 2)
		{
			return lc;
		}
		else if (rn > (right - left + 1) / 2)
		{
			return rc;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

}


int main() {
	int n;
	cin>> n;
	vector<int> a(n);
	for (int i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	cout << (getmajorityelement(a, 0, a.size() - 1) ) << '\n';
}
