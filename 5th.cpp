#include <iostream>
#include <vector>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef vector <int> VI;

double PI = acos(0) * 2;

class complex
{
public:
	double a, b;
	complex() {a = 0.0; b = 0.0;}
	complex(double na, double nb) {a = na; b = nb;}
	const complex operator+(const complex &c) const
		{return complex(a + c.a, b + c.b);}
	const complex operator-(const complex &c) const
		{return complex(a - c.a, b - c.b);}
	const complex operator*(const complex &c) const
		{return complex(a*c.a - b*c.b, a*c.b + b*c.a);}
	double magnitude() {return sqrt(a*a+b*b);}
	void print() {printf("(%f %f)\n", a, b);}
};

class FFT
{
public:
	vector<complex> data;
	vector<complex> roots;
	vector <int>rev;
	int s, n;

	void setSize(int ns)
	{
		s = ns;
		n = (1 << s);
		int i, j;
		rev = VI(n);
		data = vector<complex> (n);
		roots = vector<complex> (n+1);
		for (i = 0; i < n; i++)
			for (j = 0; j < s; j++)
				if ((i & (1 << j)) != 0)
					rev[i] += (1 << (s-j-1));
		roots[0] = complex(1, 0);
		complex mult = complex(cos(2*PI/n), sin(2*PI/n));
		for (i = 1; i <= n; i++)
			roots[i] = roots[i-1] * mult;
	}

	void bitReverse(vector<complex> &array)
	{
		vector<complex> temp(n);
		int i;
		for (i = 0; i < n; i++)
			temp[i] = array[rev[i]];
		for (i = 0; i < n; i++)
			array[i] = temp[i];
	}

	void transform(bool inverse = false)
	{
		bitReverse(data);
		int i, j, k;
		for (i = 1; i <= s; i++) {
			int m = (1 << i), md2 = m / 2;
			int start = 0, increment = (1 << (s-i));
			if (inverse) {
				start = n;
				increment *= -1;
			}
			complex t, u;
			for (k = 0; k < n; k += m) {
				int index = start;
				for (j = k; j < md2+k; j++) {
					t = roots[index] * data[j+md2];
					index += increment;
					data[j+md2] = data[j] - t;
					data[j] = data[j] + t;
				}
			}
		}
		if (inverse)
			for (i = 0; i < n; i++) {
				data[i].a /= n;
				data[i].b /= n;
			}
	}

	static vector <int>convolution(vector <int>&a, vector <int>&b)
	{
		int alen = a.size(), blen = b.size();
		int resn = alen + blen - 1;	// size of the resulting array
		int s = 0, i;
		while ((1 << s) < resn) s++;	// n = 2^s
		int n = 1 << s;	// round up the the nearest power of two

		FFT pga, pgb;
		pga.setSize(s);	// fill and transform first array
		for (i = 0; i < alen; i++) pga.data[i] = complex(a[i], 0);
		for (i = alen; i < n; i++)	pga.data[i] = complex(0, 0);
		pga.transform();

		pgb.setSize(s);	// fill and transform second array
		for (i = 0; i < blen; i++)	pgb.data[i] = complex(b[i], 0);
		for (i = blen; i < n; i++)	pgb.data[i] = complex(0, 0);
		pgb.transform();

		for (i = 0; i < n; i++)	pga.data[i] = pga.data[i] * pgb.data[i];
		pga.transform(true);	// inverse transform
		vector <int>result = vector <int>(resn);	// round to nearest integer
		for (i = 0; i < resn; i++)	result[i] = (int) (pga.data[i].a + 0.5);

		int actualSize = resn - 1;	// find proper size of array
		while (result[actualSize] == 0)
			actualSize--;
		if (actualSize < 0) actualSize = 0;
		result.resize(actualSize+1);
		return result;
	}
};

int main()
{
    int n1,n2,n;
    cout<<"enter n1\n";
    cin>>n1;
    cout<<"enter the set 1\n";
    vector <int>a = vector <int>(n1);
	for (int i = 0; i <n1; i++)
		cin>>a[i];
    cout<<"enter n2\n";
    cin>>n2;
	cout<<"enter set 2\n";
    vector <int>b = vector <int>(n2);
	for (int i = 0; i <n2; i++)
		cin>>b[i];
		
    if(n1>n2)
    n=n1;
    else 
    n=n2;
	
    vector <int>poly1 = vector <int>(10*n);
    for(int i=0;i<10*n;++i)
    poly1[i]=0;
    
    for(int i=0;i<n1;++i)
    {
        poly1[a[i]]++;
    
    }
    vector <int>poly2 = vector <int>(10*n);
    for(int i=0;i<10*n;++i)
    poly2[i]=0;
    
    for(int i=0;i<n2;++i)
    {
        poly2[b[i]]++;
    
    }
	vector <int>polyx = FFT::convolution(poly1, poly2);
	for(int i=0;i<10*n;++i)
	{
	    if(polyx[i]!=0)
	    {
	    cout<<"product "<<i<<" "<<"is obtained"<<polyx[i]<<"ways\n";
	    
	    }
	
	}
	
	return 0;
}

