#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(nlogn) Average case running time
// Time complexity: O(n*n) worst case running time
// In place algorithm

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int* arr, int low, int high)
{
	int pivot = arr[high];

	int i= (low-1);

	for(int j= low; j<=high-1; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}


void quickSort(int* arr, int low, int high)
{
	if(low<high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}