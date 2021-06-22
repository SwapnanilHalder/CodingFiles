// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#define INT_MAX 2147483647
using namespace std; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 

// A class for Min Heap 
class MinHeap 
{ 
    private:
        int *heap_arr; // pointer to array of elements in heap 
        int capacity; // maximum possible size of min heap 
        int heap_size; // Current number of elements in min heap 
    public: 
        MinHeap(int capacity); 
        
        void MinHeapify(int x); // to heapify a subtree with the root at given index

        int parent(int i) { return (i-1)/2; } 

        int left(int i) { return (2*i + 1); } // index of left child of node at i

        int right(int i) { return (2*i + 2); } // index of right child of node at i

        int extractMin();         // to extract the root which is the minimum element 

        void decreaseKey(int i, int new_val);         // Decreases key value of key at index i to new_val 

        int getMin() { return heap_arr[0]; }         // Returns the minimum key (key at root) from min heap 

        void deleteKey(int i);         // Deletes a key stored at index i 

        void insertKey(int k);         // Inserts a new key 'k' 
}; 

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	heap_arr = new int[cap]; 
} 

// Inserts a new key 'k' 
void MinHeap::insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	// First insert the new key at the end 
	heap_size++; 
	int i = heap_size - 1; 
	heap_arr[i] = k; 

	// Fix the min heap property if it is violated 
	while (i != 0 && heap_arr[parent(i)] > heap_arr[i]) 
	{ 
	swap(&heap_arr[i], &heap_arr[parent(i)]); 
	i = parent(i); 
	} 
} 

// Decreases value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than heap_arr[i]. 
void MinHeap::decreaseKey(int i, int new_val) 
{ 
	heap_arr[i] = new_val; 
	while (i != 0 && heap_arr[parent(i)] > heap_arr[i]) 
	{ 
	swap(&heap_arr[i], &heap_arr[parent(i)]); 
	i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return heap_arr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = heap_arr[0]; 
	heap_arr[0] = heap_arr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 


// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i) 
{ 
	decreaseKey(i, -INT_MAX); 
	extractMin(); 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && heap_arr[l] < heap_arr[i]) 
		smallest = l; 
	if (r < heap_size && heap_arr[r] < heap_arr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&heap_arr[i], &heap_arr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

void swap(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

int main() 
{ 
	MinHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0; 
} 
