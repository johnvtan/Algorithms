// Mary Forde
// John Tan
// Project 3

// This file declares a heap, which is used for heap sorting
#include<vector>

using namespace std;

template <typename T>
class heap {
	public:
		heap(vector<T> objects);
		
		int parent(int i);
		int left(int i);
		int right(int i);
		T getItem(int n);
		
		void initializeMaxHeap();
		void maxHeapify(int i);
		void buildMaxHeap();
		
		vector<T> heapSort();
		
	private:
		vector<T> objects;
		
		int heapSize;
		
		void swap(int i, int j);
		
	
};

template <typename T>
heap<T>::heap(vector<T> v)
// constructor for a heap
{
	objects.resize(v.size() + 1);
		
	for (int i = 1; i <= v.size(); i++)
	{
		objects.at(i) = v.at(i - 1);
	}
	
	heapSize = objects.size() - 1;
}

template <typename T>
int heap<T>::parent(int i)
// returns the index of the parent node of the given index
{
	return i / 2;
}

template <typename T>
int heap<T>::left(int i) 
// returns the index of the left child node of the given index
{
	return i* 2;
}

template <typename T>
int heap<T>::right(int i)
// returns the index of the right child node of the given index
{
	return (i*2) + 1;
}

template <typename T>
T heap<T>::getItem(int n)
// returns the object at the nth item
{
	if (n <= 0 || n > objects.size())
	{
		cout << "Something went wrong.";
		//return;
	}
	return objects.at(n);
}

template <typename T>
void heap<T>::swap(int i, int j)
// swaps the values at index i and index j
{
	T temp;
	temp = objects.at(i);
	objects.at(i) = objects.at(j);
	objects.at(j) = temp;
} // end swap

template <typename T>
void heap<T>::maxHeapify(int i)
// maintains the heap property from the starting node at index 'i'
{
	int l = left(i);
	int r = right(i);
	
	int largest;
	if (l <= heapSize && getItem(l) > getItem(i)) 
		largest = l;
	else 
		largest = i;
		
	if (r <= heapSize && getItem(r) > getItem(largest))
		largest	= r;
		
	if (largest != i)
	{
		swap(i, largest);
		maxHeapify(largest);
	}

}

template <typename T>
void heap<T>::buildMaxHeap()
// turns vector into heap
{
	for(int i = heapSize / 2; i > 0; i--)
	{
		maxHeapify(i);
	}
}

template <typename T>
vector<T> heap<T>::heapSort()
// sorts vector using heapsort
{
	buildMaxHeap();
	for(int i = heapSize; i > 1; i--)
	{
		swap(1, i);
		heapSize --;
		maxHeapify(1);
	}
	
	return objects;
}
