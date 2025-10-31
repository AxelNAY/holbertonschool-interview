# Heap Sort

## Description

This project implements the **Heap Sort** algorithm, an efficient comparison-based sorting technique that uses a binary heap data structure. Heap Sort builds a max heap from the input array and repeatedly extracts the maximum element to achieve ascending order sorting.

## What is Heap Sort?

**Heap Sort** is a sorting algorithm that:

1. **Builds a max heap** from the unsorted array
2. **Repeatedly extracts** the maximum element (root) and places it at the end
3. **Reduces heap size** and re-heapifies after each extraction
4. **Results in** a sorted array in ascending order

### Key Characteristics

- **Time Complexity**: O(n log n) in all cases (best, average, worst)
- **Space Complexity**: O(1) - sorts in-place
- **Stability**: Not stable (relative order of equal elements may change)
- **Comparison-based**: Uses element comparisons for sorting
- **In-place**: Requires no additional storage beyond input array

## Algorithm Overview

### Phase 1: Build Max Heap
Convert the array into a max heap structure where every parent is greater than or equal to its children.

### Phase 2: Extract and Sort
Repeatedly swap the root (maximum) with the last element, reduce heap size, and heapify.

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-heap_sort.c` | Implementation of heap sort algorithm |
| `0-main.c` | Test file demonstrating the sorting |
| `print_array.c` | Utility function to display arrays |
| `README.md` | Project documentation |

## Function Prototypes
```c
void heap_sort(int *array, size_t size);
void heapify(int arr[], size_t size, size_t n, size_t i);
void print_array(const int *array, size_t size);
```

### Main Functions

**`heap_sort`**

Sorts an array of integers in ascending order using the Heap sort algorithm.

**Parameters**:
- `array`: Pointer to the first element of the array to be sorted
- `size`: Number of elements in the array

**Returns**: void (sorts in-place)

**`heapify`**

Maintains the max heap property for a subtree rooted at index i.

**Parameters**:
- `arr`: Pointer to the array
- `size`: Total size of the original array (for printing)
- `n`: Size of the heap portion being considered
- `i`: Index of the root of the subtree to heapify

**Returns**: void

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-heap_sort.c print_array.c -o heap_sort
```

## Usage Example
```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
heap_sort(array, n);
print_array(array, n);
```

## Expected Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 71, 13, 52, 96, 73, 86, 7
19, 48, 99, 86, 13, 52, 96, 73, 71, 7
19, 86, 99, 48, 13, 52, 96, 73, 71, 7
19, 86, 99, 73, 13, 52, 96, 48, 71, 7
19, 86, 96, 73, 13, 52, 99, 48, 71, 7
99, 86, 96, 73, 13, 52, 19, 48, 71, 7
7, 86, 96, 73, 13, 52, 19, 48, 71, 99
96, 86, 7, 73, 13, 52, 19, 48, 71, 99
96, 86, 52, 73, 13, 7, 19, 48, 71, 99
71, 86, 52, 73, 13, 7, 19, 48, 96, 99
71, 86, 52, 48, 13, 7, 19, 73, 96, 99
86, 71, 52, 48, 13, 7, 19, 73, 96, 99
19, 71, 52, 48, 13, 7, 86, 73, 96, 99
71, 19, 52, 48, 13, 7, 86, 73, 96, 99
71, 48, 52, 19, 13, 7, 86, 73, 96, 99
7, 48, 52, 19, 13, 71, 86, 73, 96, 99
52, 48, 7, 19, 13, 71, 86, 73, 96, 99
13, 48, 7, 19, 52, 71, 86, 73, 96, 99
48, 13, 7, 19, 52, 71, 86, 73, 96, 99
48, 19, 7, 13, 52, 71, 86, 73, 96, 99
13, 19, 7, 48, 52, 71, 86, 73, 96, 99
19, 13, 7, 48, 52, 71, 86, 73, 96, 99
7, 13, 19, 48, 52, 71, 86, 73, 96, 99
13, 7, 19, 48, 52, 71, 86, 73, 96, 99
7, 13, 19, 48, 52, 71, 86, 73, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## How It Works

### Array to Binary Heap Mapping

For an array with 0-based indexing:
- **Parent of node i**: `(i - 1) / 2`
- **Left child of node i**: `2 * i + 1`
- **Right child of node i**: `2 * i + 2`

**Example Array as Tree:**
```
Array: [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]

Tree representation:
           19 (0)
          /        \
       48 (1)       99 (2)
      /     \       /     \
   71 (3)  13 (4) 52 (5)  96 (6)
   /  \    /
73 (7) 86 (8) 7 (9)
```

### Phase 1: Build Max Heap

**Start from last non-leaf node** (index = size/2 - 1) and heapify downward:
```c
for (i = size / 2 - 1; i >= 0; i--)
    heapify(array, size, size, i);
```

**Process:**
1. Start at index 4 (value 13)
2. Compare with children, swap if needed
3. Move to index 3, 2, 1, 0
4. Result: Max heap where root is maximum

**After building max heap:**
```
           99
          /        \
       86           96
      /     \       /     \
   73      13     52     19
   /  \    /
 48   71  7
```

### Phase 2: Sort by Extraction

**For each iteration:**
1. **Swap** root (max) with last element
2. **Reduce** heap size by 1
3. **Heapify** root to restore heap property
```c
for (i = size - 1; i > 0; i--)
{
    swap(array[0], array[i]);
    print_array(array, size);
    heapify(array, size, i, 0);
}
```

**Iteration 1:**
```
Swap 99 with 7
[7, 86, 96, 73, 13, 52, 19, 48, 71, 99]
Heapify: 7 sinks down
[96, 86, 52, 73, 13, 7, 19, 48, 71, 99]
```

**Continue until sorted...**

## Heapify Algorithm
```c
void heapify(int arr[], size_t size, size_t n, size_t i)
{
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    
    /* Find largest among node, left child, right child */
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    /* If largest is not root, swap and continue */
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        print_array(arr, size);
        heapify(arr, size, n, largest);  /* Recursively heapify */
    }
}
```

## Visual Step-by-Step Example

**Original Array:** `[19, 48, 99, 71, 13]`

**Step 1: Build Max Heap**
```
Initial:     19          Heapify(1):  19          Heapify(0):  99
            /  \                     /  \                     /  \
          48    99                 48    99                 48    19
         / \                      / \                      / \
        71  13                  71  13                   71  13

After build: [99, 71, 19, 48, 13]
```

**Step 2: Extract Maximum**
```
Swap 99 and 13:  [13, 71, 19, 48, 99]
Heapify:         [71, 48, 19, 13, 99]

Swap 71 and 13:  [13, 48, 19, 71, 99]
Heapify:         [48, 13, 19, 71, 99]

Continue...
Final: [13, 19, 48, 71, 99]
```

## Complexity Analysis

| Case | Time Complexity | Explanation |
|------|----------------|-------------|
| **Best** | O(n log n) | Build heap: O(n), Extract n times with heapify: O(n log n) |
| **Average** | O(n log n) | Same as best case |
| **Worst** | O(n log n) | Same as best case - no worst-case degradation |
| **Space** | O(1) | In-place sorting with only a few variables |

### Breakdown:
- **Build Heap**: O(n) - technically, building heap is linear
- **Extract & Heapify**: O(log n) per extraction × n extractions = O(n log n)
- **Total**: O(n) + O(n log n) = **O(n log n)**

## Advantages

✅ **Guaranteed O(n log n)**: No worst-case degradation like QuickSort  
✅ **In-place**: O(1) extra space (unlike Merge Sort)  
✅ **No recursion depth issues**: Iterative outer loop  
✅ **Cache-friendly**: Sequential array access  
✅ **Predictable**: Consistent performance  

## Disadvantages

❌ **Not stable**: Equal elements may change relative order  
❌ **Not adaptive**: Doesn't benefit from partially sorted data  
❌ **Poor cache locality**: Random heap accesses  
❌ **Slower than QuickSort**: In practice, due to constants  

## Comparison with Other Sorts

| Algorithm | Time (Avg) | Time (Worst) | Space | Stable |
|-----------|-----------|--------------|-------|--------|
| **Heap Sort** | O(n log n) | O(n log n) | O(1) | No |
| Quick Sort | O(n log n) | O(n²) | O(log n) | No |
| Merge Sort | O(n log n) | O(n log n) | O(n) | Yes |
| Insertion Sort | O(n²) | O(n²) | O(1) | Yes |

## Use Cases

- **When space is limited**: Better than Merge Sort due to O(1) space
- **When worst-case matters**: Better than QuickSort's O(n²) worst case
- **Embedded systems**: Predictable memory usage
- **Real-time systems**: Guaranteed time bounds
- **Priority queues**: Natural fit for heap data structure

## Implementation Notes

- **Bottom-up heap construction**: More efficient than inserting elements one by one
- **0-based indexing**: Parent at `(i-1)/2`, children at `2i+1` and `2i+2`
- **In-place sorting**: No additional arrays needed
- **Print statements**: Shows each swap for educational purposes

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty array (size = 0) | No operations performed |
| Single element | Already sorted, no swaps |
| Already sorted | Still performs full heap sort |
| Reverse sorted | Still O(n log n), no degradation |
| All equal elements | Works correctly, no errors |

## Optimization Opportunities

1. **Iterative heapify**: Replace recursion with loop (tail recursion)
2. **Remove print statements**: In production for better performance
3. **Bottom-up heap construction**: Already implemented (start from size/2-1)
4. **Early termination**: Not applicable - must complete all extractions

## Author

Project implementation for understanding heap-based sorting algorithms and their applications in computer science.
