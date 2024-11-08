#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void maxHeapify(int heap[], int n, int i);
void insertMaxHeap(int heap[], int *n, int value);
int deleteRootMaxHeap(int heap[], int *n);
void printHeap(int heap[], int n);

int main() {
    int maxHeap[MAX_SIZE];
    int size = 0;

    // Insert elements into Max Heap
    insertMaxHeap(maxHeap, &size, 10);
    insertMaxHeap(maxHeap, &size, 20);
    insertMaxHeap(maxHeap, &size, 5);
    insertMaxHeap(maxHeap, &size, 30);
    insertMaxHeap(maxHeap, &size, 15);

    printf("Max Heap after insertions: ");
    printHeap(maxHeap, size);

    // Delete root element from Max Heap
    int deleted = deleteRootMaxHeap(maxHeap, &size);
    printf("Deleted root element: %d\n", deleted);

    printf("Max Heap after deletion: ");
    printHeap(maxHeap, size);

    return 0;
}

// Function to heapify a subtree rooted with node i in Max Heap
void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeapify(heap, n, largest);
    }
}

// Function to insert an element into Max Heap
void insertMaxHeap(int heap[], int *n, int value) {
    heap[*n] = value;
    int i = *n;
    (*n)++;

    // Fix the max heap property
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to delete the root element from Max Heap
int deleteRootMaxHeap(int heap[], int *n) {
    if (*n <= 0) return -1;
    if (*n == 1) {
        (*n)--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[(*n) - 1];
    (*n)--;
    maxHeapify(heap, *n, 0);

    return root;
}

// Function to display the content of the Max Heap
void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
