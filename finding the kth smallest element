#include<bits/stdc++.h>
using namespace std;
int find_median(vector<int> A, int k)
{
	int i, j;
	int length = A.size();
	if(length <= 5)
	{
		sort(A.begin(), A.end());
		return A[k - 1];
	}
	vector<int> M;
	for(i = 5; i < length; i = i + 5)
	{
	     vector<int> temp(A.begin()+i-5, A.begin() + i - 1);
		 sort(temp.begin(), temp.end());
		 M.push_back(temp[2]);
		 temp.clear();
	}
	vector<int> temp;
	for(j = i - 5; j < length; j++)
	{
		temp.push_back(A[j]);
	}
	M.push_back(temp[(temp.size()- 1)/2]);
	int m = find_median(M, M.size()/2);
	int c = 0, e = 0;
	vector<int> s;
	vector<int> g;
	for(i = 0; i < length; i++)
	{
		if(m > A[i])
		{
		    c++;
			s.push_back(A[i]);
		}
	   else if(m < A[i])
		g.push_back(A[i]);
		else
		 e++;
	}
	if(c+1 == k)
	return m;
	else if(c+1 > k)
	return find_median(s, k);
	else
	return find_median(g, k - (c + 1) -(e - 1));
}
int main()
{
	cout<<"Enter the number of elements: ";
	int n;
	cin>>n;
	vector<int> A(n);
	int i;
	cout<<"\Enter "<<n<<" elements: ";
	for(i = 0; i < n; i++)
	cin>>A[i];
	cout<<"\nThe kth element of the given array is: "<<find_median(A, 3);
	return 0;
}
