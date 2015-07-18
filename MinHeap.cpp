#include<iostream>
using namespace std;

//Prototype of a utility function to swap two integers
void swap(int* x, int* y);

//A class for Min Heap
class MinHeap
{
	int *harr;
	int heap_size;
	
	public:
		//Constructor
		MinHeap(int a[], int size);
		
		void MinHeapify(int);
		
		//to get index to left child of node at index i
		int left(int i)
		{return i<<1 + 1;}
		
		//to get index of right child at index i
		int right(int i)
		{return (i+1)<<1;}		
		
		//to remove min (or root), and a new value x, and return old root
		int replaceMin(int x);
		
		//to extract the root which is the minimum element
		int extractMin();
};

	//Given an array of size n, where every element is k away from its target position, 
	//sorts the array in O(nlogk) time.
	int sortK(int arr[], int n, int k)
	{
		//Create a Min Heap of first (k+1) elements from 
		//input array
		int *harr = new int[k+1];
		for(int i=0; i <= k && i < n; i++)
			harr[i] = arr[i];

		MinHeap hp(harr, k+1);

		//i is index for remaining elements in arr[] and ti is target
		// index for current minimum element in Min Heap 'hp'
	
		for(int i = k+1, ti = 0; ti < n; i++, ti++)
		{
			//If there are remaining elements, then place root of heap at target index and arr[i] to Min Heap
			if(i<n)
				arr[ti] = hp.replaceMin(arr[i]);
			//Otherwise place root at its target index and reduce heap size
			else 
				arr[ti] = hp.extractMin();
		} 
	}
	//FOLLOWING ARE IMPLEMENTATIONS of standard min heap methods from
	MinHeap::MinHeap(int a[], int size)
	{
		heap_size = size;
		harr = a; //store address of array
		int i = (heap_size - 1)/2;
		while(i >= 0)
		{
			MinHeapify(i);
			i--;
		}
	}

	// Method to remove minimum elemeent (or root) from min heap
	int MinHeap::extractMin()
	{
		int root = harr[0];
		if(heap_size > 1)
		{
			harr[0] = harr[heap_size - 1];
			heap_size--;
			MinHeapify(0);
		}
		return 0;
	}

	int MinHeap::replaceMin(int x)
	{
		int root = harr[0];
		harr[0] = x;
		if(root < x)
			MinHeapify(0);
		return root;
	}

	void MinHeap::MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if(l < heap_size && harr[l] < harr[i])
			smallest = l;
		if(r < heap_size && harr[r] < harr[smallest])
			smallest = r;
		if(smallest != i)
		{
			swap(&harr[i], &harr[smallest]);
			MinHeapify(smallest);
		}
	}

	void swap(int *x, int *y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	void printArray(int arr[], int size)
	{
		for(int i = 0; i < size; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}	

	//Driver program to test the above functions
	int main()
	{
		int k = 3;
		int arr[] = {2, 6, 3, 12, 56, 8};
		int n = sizeof(arr)/sizeof(arr[0]);
		sortK(arr, n, k);

		cout<< "Following is sorted array\n";
		printArray(arr, n);

		return 0;
	}

