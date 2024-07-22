#include<bits/stdc++.h>
using namespace std;

int uglyNumber(int n)
{
	
	int p2=0,p3=0,p5=0;
	vector<int>arr(n);
	arr[0]=1;	

	for(int i=1;i<n;i++)
	{
		arr[i] = min(arr[p2]*2,min(arr[p3]*3,arr[p5]*5));
		if(arr[p2]*2 == arr[i]) p2++;
		if(arr[p3]*3 == arr[i]) p3++;
		if(arr[p5]*5 == arr[i]) p5++;		

	}
	return arr[n-1];


}


int main()
{
	int n = 10;
	int ans = uglyNumber(n);
	cout<<ans;

	return 0;

}
