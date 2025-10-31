# Radix Sort

## Description

This project implements the **Radix Sort** algorithm using the **LSD (Least Significant Digit)** approach. Radix Sort is a non-comparison-based sorting algorithm that sorts integers by processing individual digits. It uses Counting Sort as a subroutine to sort numbers digit by digit, from least significant to most significant.

## What is Radix Sort?

**Radix Sort** is a sorting algorithm that:

1. Processes numbers digit by digit (starting from the least significant digit)
2. Uses a stable sorting algorithm (Counting Sort) for each digit position
3. Sorts numbers based on their radix (base), typically base 10 for decimal numbers
4. Achieves linear time complexity for fixed-length integers

### Key Characteristics

- **Time Complexity**: O(d × (n + k)) where d = digits, n = elements, k = range (0-9)
- **Space Complexity**: O(n + k) for temporary arrays
- **Stability**: Stable - maintains relative order of equal elements
- **Non-comparison**: Doesn't use element comparisons
- **Integer-specific**: Works best with integers or fixed-length keys
- **Linear time**: For fixed number of digits, effectively O(n)

## Algorithm Overview

### LSD (Least Significant Digit) Radix Sort
```
Step 1: Find maximum number to determine digit count
Step 2: For each digit position (1s, 10s, 100s, ...):
        - Apply Counting Sort on current digit
        - Print intermediate result
Step 3: Array is sorted after processing all digits
```

**Example:**
```
Original: [170, 45, 75, 90, 802, 24, 2, 66]

Sort by 1s place: [170, 90, 802, 2, 24, 45, 75, 66]
Sort by 10s place: [802, 2, 24, 45, 66, 170, 75, 90]
Sort by 100s place: [2, 24, 45, 66, 75, 90, 170, 802]
```

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-radix_sort.c` | Implementation of radix sort algorithm |
| `0-main.c` | Test file demonstrating the sorting |
| `print_array.c` | Utility function to display arrays |
| `README.md` | Project documentation |

## Function Prototypes
```c
void radix_sort(int *array, size_t size);
void countSort(int *array, size_t size, int exp);
int getMax(int *array, size_t size);
void print_array(const int *array, size_t size);
```

### Main Functions

**`radix_sort`**

Main function that orchestrates the radix sort process.

**Parameters**:
- `array`: Pointer to the first element of the array to be sorted
- `size`: Number of elements in the array

**Returns**: void (sorts in-place)

**Behavior**:
- Finds the maximum number to determine digit count
- Iterates through each digit position (1, 10, 100, ...)
- Calls counting sort for each digit position

**`countSort`**

Performs counting sort on array based on a specific digit position.

**Parameters**:
- `array`: The array to sort
- `size`: Number of elements
- `exp`: Exponent (10^i) representing current digit position

**Returns**: void

**Behavior**:
- Counts occurrences of each digit (0-9)
- Calculates cumulative counts
- Places elements in sorted order based on current digit
- Prints array after each pass

**`getMax`**

Finds the maximum value in the array.

**Parameters**:
- `array`: The array to search
- `size`: Number of elements

**Returns**: int (maximum value)

**Purpose**: Determines how many digit positions need to be processed

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-radix_sort.c print_array.c -o radix_sort
```

## Usage Example
```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
radix_sort(array, n);
print_array(array, n);
```

## Expected Output
```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## How It Works

### Step-by-Step Execution

**Original Array:** `[19, 48, 99, 71, 13, 52, 96, 73, 86, 7]`

**Step 1: Find Maximum**
```c
max = 99  (2 digits)
```

**Step 2: Sort by 1s Place (exp = 1)**

Extract 1s digit from each number:
```
19 → 9
48 → 8
99 → 9
71 → 1
13 → 3
52 → 2
96 → 6
73 → 3
86 → 6
7  → 7
```

Count occurrences:
```
Digit: 0  1  2  3  4  5  6  7  8  9
Count: 0  1  1  2  0  0  2  1  1  2
```

Cumulative counts:
```
Digit: 0  1  2  3  4  5  6  7  8  9
Cum:   0  1  2  4  4  4  6  7  8  10
```

Place in output (from right to left to maintain stability):
```
Result: [71, 52, 13, 73, 96, 86, 7, 48, 19, 99]
```

**Step 3: Sort by 10s Place (exp = 10)**

Extract 10s digit:
```
71 → 7
52 → 5
13 → 1
73 → 7
96 → 9
86 → 8
7  → 0
48 → 4
19 → 1
99 → 9
```

After counting sort on 10s place:
```
Result: [7, 13, 19, 48, 52, 71, 73, 86, 96, 99]
```

**Final Result:** `[7, 13, 19, 48, 52, 71, 73, 86, 96, 99]`

### Counting Sort Algorithm
```c
void countSort(int *array, size_t size, int exp)
{
    /* Step 1: Create output and count arrays */
    int output[size];
    int count[10] = {0};  /* Digits 0-9 */
    
    /* Step 2: Count occurrences of each digit */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;
    
    /* Step 3: Calculate cumulative counts */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    /* Step 4: Build output array (backwards for stability) */
    for (i = size - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }
    
    /* Step 5: Copy back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];
}
```

## Visual Example

**Sorting [170, 45, 75, 90, 802, 24, 2, 66]**
```
Original:
[170, 45, 75, 90, 802, 24, 2, 66]

Pass 1 (1s place):
1s digits: [0, 5, 5, 0, 2, 4, 2, 6]
Result: [170, 90, 802, 2, 24, 45, 75, 66]
         └─┬─┘ └─┬─┘ └─┬─┘  └─┬─┘  └─┬─┘
           0     0     2      4      5,6

Pass 2 (10s place):
10s digits: [7, 9, 0, 0, 2, 4, 7, 6]
Result: [802, 2, 24, 45, 66, 170, 75, 90]
         └─┬─┘  └─┬─┘  └─┬─┘  └──┬──┘
           0      2,4    6       7,9

Pass 3 (100s place):
100s digits: [8, 0, 0, 0, 0, 1, 0, 0]
Result: [2, 24, 45, 66, 75, 90, 170, 802]
         └────────┬────────┘  └─┬─┘ └─┬─┘
                  0             1     8
```

## Digit Extraction Formula
```c
digit = (number / exp) % 10
```

**Examples:**
- For 802, exp=1 (1s place): (802/1) % 10 = 2
- For 802, exp=10 (10s place): (802/10) % 10 = 0
- For 802, exp=100 (100s place): (802/100) % 10 = 8

## Why Stability Matters

**Unstable sort would break radix sort:**
```
Numbers: [170, 90]

If unstable on 1s place:
Both end in 0, but order could swap to [90, 170]

Then on 10s place:
10s: [9, 7] → sorted to [170, 90]

But we need original relative order!
```

**Stable counting sort preserves order**, ensuring radix sort works correctly.

## Complexity Analysis

### Time Complexity

| Case | Complexity | Explanation |
|------|-----------|-------------|
| **Best** | O(d × (n + k)) | d digits, n elements, k=10 (0-9) |
| **Average** | O(d × (n + k)) | Same as best |
| **Worst** | O(d × (n + k)) | Same as best |

For fixed d (like 32-bit integers):
- **Effectively O(n)** - linear time!

**Example calculation:**
- Array of 1000 numbers (n = 1000)
- Maximum 5 digits (d = 5)
- Base 10 (k = 10)
- Time: 5 × (1000 + 10) = 5,050 operations

### Space Complexity

- **Auxiliary Space**: O(n + k)
  - Output array: O(n)
  - Count array: O(k) = O(10) = O(1)
- **Total**: **O(n)**

## Comparison with Other Sorts

| Algorithm | Time (Avg) | Time (Worst) | Space | Stable | Comparison |
|-----------|-----------|--------------|-------|--------|------------|
| **Radix Sort** | O(d×n) | O(d×n) | O(n) | Yes | No |
| Quick Sort | O(n log n) | O(n²) | O(log n) | No | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n) | Yes | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(1) | No | Yes |
| Counting Sort | O(n + k) | O(n + k) | O(k) | Yes | No |

## Advantages of Radix Sort

✅ **Linear time**: O(n) for fixed-digit integers  
✅ **Stable**: Preserves order of equal elements  
✅ **Predictable**: No worst-case degradation  
✅ **Non-comparison**: Doesn't rely on comparisons  
✅ **Parallel-friendly**: Digit positions can be processed in parallel  
✅ **Simple**: Straightforward implementation  

## Disadvantages

❌ **Integer-only**: Doesn't work well for arbitrary data  
❌ **Space overhead**: Requires O(n) extra space  
❌ **Digit dependency**: Performance depends on digit count  
❌ **Base sensitivity**: Efficiency varies with number base  
❌ **Not in-place**: Needs temporary arrays  
❌ **Large range**: Poor for numbers with many digits  

## Use Cases

- **Integer sorting**: Fixed-range integers (IDs, ages, zip codes)
- **String sorting**: Fixed-length strings (dates, codes)
- **Suffix array construction**: Text processing algorithms
- **External sorting**: When data doesn't fit in memory
- **Parallel processing**: Easy to parallelize
- **Counting sort enhancement**: Multi-digit version

## Variations

### MSD (Most Significant Digit) Radix Sort
```c
/* Start from leftmost digit */
/* Can short-circuit if ranges become small */
/* Recursive implementation */
```

**Advantage**: Can stop early for some elements  
**Disadvantage**: More complex, needs recursion

### Different Bases
```c
/* Use base 256 for bytes */
/* Fewer passes but larger count array */

for (exp = 1; m / exp > 0; exp *= 256)
    countSort(array, size, exp);
```

**Trade-off**: Fewer passes vs. larger count array

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty array (size = 0) | Returns immediately |
| Single element | Returns immediately (already sorted) |
| All equal | Works correctly, all passes do nothing |
| Negative numbers | **Not supported** (current implementation) |
| Already sorted | Still performs all passes |
| Reverse sorted | Works correctly |

## Handling Negative Numbers

**Current implementation limitation**: Only works with non-negative integers.

**To support negatives:**
```c
/* Split into negative and positive arrays */
/* Sort each separately */
/* Reverse negatives and concatenate */
```

Or use offset:
```c
/* Find minimum */
/* Add offset to make all numbers positive */
/* Sort */
/* Subtract offset back */
```

## Optimization Opportunities

### 1. Variable Length Arrays (Already Used)
```c
int output[size];  /* VLA - efficient */
```

### 2. Skip Passes for Small Numbers
```c
/* If max < 10, only one pass needed */
if (max < 10)
{
    countSort(array, size, 1);
    return;
}
```

### 3. Use Larger Base
```c
/* Base 256: Process byte by byte */
/* Fewer passes but larger count array */
```

### 4. Hybrid with Insertion Sort
```c
/* Use insertion sort for small subarrays */
/* Within each bucket during radix sort */
```

## Performance Notes

**Best for:**
- Large arrays (n > 1000)
- Small digit count (d ≤ 10)
- Dense range of values
- When stability is required

**Not ideal for:**
- Small arrays (overhead not worth it)
- Very large numbers (many digits)
- Sparse range (most buckets empty)
- Floating-point numbers

## Real-World Applications

- **Database indexing**: Sort records by numeric keys
- **IP address sorting**: Fixed 32-bit values
- **Date/time sorting**: Fixed-format timestamps
- **Memory address sorting**: Pointer sorting
- **Bucket sort**: As a stable subroutine
- **Parallel algorithms**: GPU sorting implementations

## Testing Recommendations
```c
/* Test arrays */
int single[] = {42};
int two[] = {48, 19};
int equal[] = {5, 5, 5, 5};
int sorted[] = {1, 2, 3, 4, 5};
int reverse[] = {5, 4, 3, 2, 1};
int mixed[] = {170, 45, 75, 90, 802, 24, 2, 66};
int large[] = {999999, 1, 50000, 123, 999, 88888};
```

## Common Mistakes to Avoid

❌ **Using unstable counting sort**: Breaks radix sort correctness  
❌ **Forgetting to print**: Must print after each digit pass  
❌ **Wrong digit extraction**: `(num / exp) % 10` is critical  
❌ **Overflow in exp**: Use size_t for exp to avoid overflow  
❌ **Not handling size < 2**: Early return needed  
❌ **VLA initialization**: C89 doesn't allow `int arr[n] = {0}`  

## Author

Project implementation for understanding non-comparison sorting algorithms and the radix sort technique with linear time complexity for fixed-digit integers.
