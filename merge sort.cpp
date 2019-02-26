#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> L, vector<int> R);
vector<int> merge_sort(vector<int> v, int l, int r)
{
	int mid = (l+r)/2;
	vector<int> L;
	vector<int> R;
	vector<int> A;
	if(r-l == 1)
	{
		L.push_back(v[l]);
		R.push_back(v[r]);
	}
	else if(l == r)
	{
		A.push_back(v[l]);
		return A;
	}
	else
	{
		L = merge_sort(v, l, mid-1);
      	R = merge_sort(v, mid, r);
	}
	A = merge(L, R);
	return A;
}
vector<int> merge(vector<int> L, vector<int> R)
{
	int i=0, j=0, k;
	vector<int> v;
	while(i < L.size() && j < R.size())
	{
		if(L[i] < R[j])
		{
			v.push_back(L[i]);
			i++;
		}
		else
		{
			v.push_back(R[j]);
			j++;
		}
	}
		while(i < L.size())
		{
			v.push_back(L[i]);
			i++;
		}
		while(j < R.size())
		{
			v.push_back(R[j]);
			j++;
		}
		return v;
}
int main()
{
	cout<<"Enter the number of element in the array: ";
	int n;
	cin>>n;
	vector<int> a(n);
	int i;
	cout<<"\nEnter "<<n<<" elements: ";
	for(i = 0; i < n; i++)
	cin>>a[i];
	a = merge_sort(a, 0, n-1);
	cout<<"\nThe sorted array is: ";
	for(i = 0; i < n; i++)
	cout<<a[i]<<" ";
	return 0;
}
