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
		
		void heapSort();
		
	private:
		vector<T> objects;
		int heapSize;
		
		void swap(int i, int j);
		
		
};

