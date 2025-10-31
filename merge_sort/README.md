# Merge Sort

## Description

This project implements the **Merge Sort** algorithm, one of the most efficient and widely-used comparison-based sorting algorithms. Merge Sort uses a divide-and-conquer strategy to recursively divide the array into smaller subarrays, sort them, and then merge them back together in sorted order.

## What is Merge Sort?

**Merge Sort** is a sorting algorithm that:

1. **Divides** the array into two halves recursively until each subarray has one element
2. **Conquers** by sorting the subarrays (base case: single element is already sorted)
3. **Combines** by merging the sorted subarrays back together in order

### Key Characteristics

- **Time Complexity**: O(n log n) in all cases (best, average, worst)
- **Space Complexity**: O(n) - requires additional temporary array
- **Stability**: Stable - maintains relative order of equal elements
- **Comparison-based**: Uses element comparisons for sorting
- **Recursive**: Natural divide-and-conquer implementation
- **Predictable**: Always O(n log n), no worst-case degradation

## Algorithm Overview

### Divide and Conquer Strategy
```
Original: [19, 48, 99, 71, 13, 52, 96, 73, 86, 7]

Divide:
    [19, 48, 99, 71, 13] | [52, 96, 73, 86, 7]
    [19, 48] [99, 71, 13] | [52, 96] [73, 86, 7]
    [19] [48] [99] [71, 13] | [52] [96] [73] [86, 7]
    ...

Merge:
    [19, 48] [71, 99, 13] | [52, 96] [73, 7, 86]
    [19, 48, 71, 99, 13] | [52, 73, 96, 7, 86]
    [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
```

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-merge_sort.c` | Implementation of merge sort algorithm |
| `0-main.c` | Test file demonstrating the sorting |
| `print_array.c` | Utility function to display arrays |
| `README.md` | Project documentation |

## Function Prototypes
```c
void merge_sort(int *array, size_t size);
void merge_sort_helper(int *array, size_t size, int *new_array);
void merge(int *array, size_t size, int *new_array, int middle);
void print_array(const int *array, size_t size);
```

### Main Functions

**`merge_sort`**

Entry point that initializes the merge sort process.

**Parameters**:
- `array`: Pointer to the first element of the array to be sorted
- `size`: Number of elements in the array

**Returns**: void (sorts in-place, but uses temporary array)

**`merge_sort_helper`**

Recursive helper function that divides the array.

**Parameters**:
- `array`: Pointer to the array segment to sort
- `size`: Number of elements in this segment
- `new_array`: Temporary array for merging operations

**Returns**: void

**`merge`**

Merges two sorted halves into a single sorted array.

**Parameters**:
- `array`: Pointer to the array to merge
- `size`: Total size of the segment
- `new_array`: Temporary array for merging
- `middle`: Index dividing the two halves

**Returns**: void

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-merge_sort.c print_array.c -o merge_sort
```

## Usage Example
```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
merge_sort(array, n);
print_array(array, n);
```

## Expected Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 19, 48
[right]: 13, 71
[Done]: 13, 19, 48, 71
Merging...
[left]: 99
[right]: 52
[Done]: 52, 99
Merging...
[left]: 73
[right]: 86
[Done]: 73, 86
Merging...
[left]: 96
[right]: 73, 86
[Done]: 73, 86, 96
Merging...
[left]: 52, 99
[right]: 73, 86, 96
[Done]: 52, 73, 86, 96, 99
Merging...
[left]: 7
[right]: 
[Done]: 7
Merging...
[left]: 13, 19, 48, 71
[right]: 52, 73, 86, 96, 99
[Done]: 13, 19, 48, 52, 71, 73, 86, 96, 99
Merging...
[left]: 13, 19, 48, 52, 71, 73, 86, 96, 99
[right]: 7
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## How It Works

### Step 1: Divide Phase

The array is recursively divided into two halves:
```c
void merge_sort_helper(int *array, size_t size, int *new_array)
{
    int middle = size / 2;
    
    if (size < 2)
        return;  /* Base case: single element is sorted */
    
    merge_sort_helper(array, middle, new_array);              /* Sort left half */
    merge_sort_helper(array + middle, size - middle, new_array); /* Sort right half */
    merge(array, size, new_array, middle);                    /* Merge sorted halves */
}
```

### Step 2: Merge Phase

Two sorted subarrays are merged into one sorted array:
```c
void merge(int *array, size_t size, int *new_array, int middle)
{
    int left = 0, right = middle, i = 0;
    
    /* Merge while both halves have elements */
    while (left < middle && right < size)
    {
        if (array[left] < array[right])
            new_array[i++] = array[left++];
        else
            new_array[i++] = array[right++];
    }
    
    /* Copy remaining elements from left half */
    while (left < middle)
        new_array[i++] = array[left++];
    
    /* Copy remaining elements from right half */
    while (right < size)
        new_array[i++] = array[right++];
    
    /* Copy back to original array */
    for (i = 0; i < size; i++)
        array[i] = new_array[i];
}
```

## Visual Example

**Sorting [38, 27, 43, 3, 9, 82, 10]:**
```
Level 0 (Divide):
                    [38, 27, 43, 3, 9, 82, 10]
                    /                        \
Level 1:    [38, 27, 43, 3]              [9, 82, 10]
            /            \                /          \
Level 2: [38, 27]      [43, 3]        [9, 82]      [10]
         /    \        /    \         /    \         |
Level 3: [38] [27]   [43]  [3]      [9]  [82]     [10]

Level 3 (Merge):
         [27, 38]     [3, 43]        [9, 82]      [10]
            \           /              \           /
Level 2:    [3, 27, 38, 43]          [9, 10, 82]
                    \                    /
Level 1:           [3, 9, 10, 27, 38, 43, 82]
```

### Detailed Merge Example

**Merging [27, 38] and [3, 43]:**
```
Left:  [27, 38]    Right: [3, 43]
        ↑                  ↑
       
Compare: 27 vs 3 → 3 is smaller
Result: [3, _, _, _]

Left:  [27, 38]    Right: [3, 43]
        ↑                     ↑
       
Compare: 27 vs 43 → 27 is smaller
Result: [3, 27, _, _]

Left:  [27, 38]    Right: [3, 43]
            ↑              ↑
       
Compare: 38 vs 43 → 38 is smaller
Result: [3, 27, 38, _]

Left:  [27, 38]    Right: [3, 43]
        (empty)            ↑
       
Copy remaining: 43
Result: [3, 27, 38, 43]
```

## Recursion Tree

**For array of size 8:**
```
Height: log₂(8) = 3 levels

Level 0: [--------8 elements--------]    1 merge of 8 elements
Level 1: [----4----]    [----4----]      2 merges of 4 elements each
Level 2: [--2--] [--2--] [--2--] [--2--] 4 merges of 2 elements each
Level 3: [1][1] [1][1] [1][1] [1][1]    8 base cases (no merge)

Total operations: 8 + 8 + 8 = 24 = 8 × 3 = n × log(n)
```

## Complexity Analysis

### Time Complexity

| Case | Complexity | Explanation |
|------|-----------|-------------|
| **Best** | O(n log n) | Always divides and merges all elements |
| **Average** | O(n log n) | Same as best case |
| **Worst** | O(n log n) | No worst-case degradation |

**Breakdown:**
- **Divide**: O(log n) levels (binary division)
- **Merge**: O(n) work per level
- **Total**: O(n) × O(log n) = **O(n log n)**

### Space Complexity

- **Auxiliary Space**: O(n) for temporary array
- **Recursion Stack**: O(log n) for call stack
- **Total**: **O(n)**

## Memory Usage Pattern
```c
/* Single temporary array allocated once */
int *new_array = malloc(sizeof(int) * size);

/* Reused for all merge operations */
merge_sort_helper(array, size, new_array);

/* Freed after sorting complete */
free(new_array);
```

**Advantage**: Single allocation instead of multiple allocations per recursion level.

## Comparison with Other Sorts

| Algorithm | Time (Avg) | Time (Worst) | Space | Stable | Method |
|-----------|-----------|--------------|-------|--------|--------|
| **Merge Sort** | O(n log n) | O(n log n) | O(n) | Yes | Divide & Conquer |
| Quick Sort | O(n log n) | O(n²) | O(log n) | No | Divide & Conquer |
| Heap Sort | O(n log n) | O(n log n) | O(1) | No | Selection |
| Insertion Sort | O(n²) | O(n²) | O(1) | Yes | Insertion |
| Bubble Sort | O(n²) | O(n²) | O(1) | Yes | Exchange |

## Advantages of Merge Sort

✅ **Guaranteed O(n log n)**: No worst-case degradation  
✅ **Stable**: Maintains relative order of equal elements  
✅ **Predictable**: Consistent performance regardless of input  
✅ **Parallelizable**: Independent subarrays can be sorted in parallel  
✅ **External sorting**: Excellent for sorting data on disk  
✅ **Good for linked lists**: No random access needed  

## Disadvantages

❌ **Extra space**: Requires O(n) additional memory  
❌ **Not in-place**: Needs temporary array  
❌ **Overhead**: Slower than QuickSort in practice for arrays  
❌ **Not adaptive**: Doesn't benefit from partially sorted data  

## Use Cases

- **External sorting**: Sorting large files that don't fit in memory
- **Linked list sorting**: Natural fit for linked structures
- **Stable sorting**: When relative order of equal elements matters
- **Guaranteed performance**: When O(n log n) worst-case is required
- **Parallel sorting**: Easy to parallelize merge operations
- **Database systems**: Merge join operations

## Optimization Opportunities

### 1. Hybrid Approach
```c
/* Use insertion sort for small subarrays (size < 10) */
if (size < 10)
{
    insertion_sort(array, size);
    return;
}
```

### 2. In-Place Merge Sort
- More complex implementation
- Reduces space to O(1) but increases time complexity

### 3. Natural Merge Sort
- Exploits existing runs in partially sorted data
- Adaptive variant of merge sort

### 4. Bottom-Up Merge Sort
```c
/* Iterative instead of recursive */
/* Avoids recursion stack overhead */
```

## Stability Example

**Why stability matters:**
```
Input:  [(5, A), (3, B), (5, C), (1, D)]
Sorted: [(1, D), (3, B), (5, A), (5, C)]
                                 ↑     ↑
                              Order preserved for equal keys
```

Merge Sort maintains: `(5, A)` before `(5, C)` in output.

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty array (size = 0) | Returns immediately (safe) |
| Single element | Base case, no operations |
| Already sorted | Still performs full merge sort |
| Reverse sorted | Same complexity, no degradation |
| All equal elements | Works correctly, stable |
| Two elements | One comparison, one merge |

## Testing Recommendations
```c
/* Test cases */
int empty[] = {};                          /* Empty array */
int single[] = {42};                       /* Single element */
int two[] = {2, 1};                       /* Two elements */
int sorted[] = {1, 2, 3, 4, 5};          /* Already sorted */
int reverse[] = {5, 4, 3, 2, 1};         /* Reverse sorted */
int duplicates[] = {3, 1, 4, 1, 5, 9, 2, 6, 5}; /* With duplicates */
```

## Memory Management
```c
/* Proper allocation and cleanup */
int *new_array = malloc(sizeof(int) * size);

if (new_array == NULL)
{
    /* Handle allocation failure */
    return;
}

/* Use new_array for merging... */

free(new_array);  /* Always free allocated memory */
```

## Performance Notes

- **Cache efficiency**: Poor locality during merge phase
- **Branch prediction**: Regular pattern helps CPU prediction
- **Memory bandwidth**: Limited by speed of copying data
- **Practical performance**: ~2-3x slower than QuickSort for random data

## Related Algorithms

- **Timsort**: Hybrid of merge sort and insertion sort (Python's default)
- **3-way merge sort**: Divides into 3 parts instead of 2
- **Parallel merge sort**: Multi-threaded implementation
- **External merge sort**: For disk-based sorting

## Author

Project implementation for understanding divide-and-conquer algorithms and the classic merge sort technique with guaranteed O(n log n) performance.
