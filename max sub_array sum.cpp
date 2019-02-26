#include<bits/stdc++.h>
using namespace std;
int max(int x, int y)
{
	if(x > y)
	return x;
	else
	return y;
}
int MSS(vector<int> a, int L, int R)
{
	int mid = (L + R)/2;
	if(R - L == 1)
	return max(a[R], a[L]);
	if(R == L)
	return a[R];
	int lmss = MSS(a, L, mid-1);
	int rmss = MSS(a, mid, R);
	int lmax = a[mid - 1];
	int rmax = a[mid];
	int sum = 0;
	int i;
	for(i = mid-1; i>=0; i--)
	{
		sum+=a[i];
		if(sum>lmax)
		lmax = sum;
	}
	sum = 0;
	for(i = mid; i<=R; i++)
	{
		sum += a[i];
		if(sum > rmax)
		rmax = sum;
	}
	int maximum = rmax + lmax;
	int mss = max(rmss, lmss);
	return max(maximum, mss);
}

int main()
{
	cout<<"Enter the number of elements: ";
	int n;
	cin>>n;
	vector<int> a(n);
	int i;
	cout<<"\nEnter "<<n<<" elements: ";
	for(i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	cout<<"\n The maximum subsequence sum is: "<<MSS(a, 0, n-1);
	return 0;
}
