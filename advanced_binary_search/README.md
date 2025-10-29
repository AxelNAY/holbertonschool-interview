# Advanced Binary Search

## Description

This project implements an advanced binary search algorithm in C that finds the **first occurrence** of a value in a sorted array of integers. Unlike standard binary search, this implementation specifically locates the leftmost instance when duplicate values exist.

## Algorithm Overview

The advanced binary search uses a recursive approach with the following characteristics:

- **Time Complexity**: O(log n)
- **Space Complexity**: O(log n) due to recursion stack
- **Input**: Sorted array of integers with possible duplicates
- **Output**: Index of the first occurrence of the target value, or -1 if not found

## Key Features

- Prints the search space at each recursive step for visualization
- Handles duplicate values by finding the first occurrence
- Uses recursive binary search implementation
- Includes null and empty array validation

## Files

| File | Description |
|------|-------------|
| `search_algos.h` | Header file containing function prototype |
| `0-advanced_binary.c` | Implementation of the advanced binary search algorithm |
| `0-main.c` | Test file demonstrating the algorithm |

## Function Prototypes
```c
int advanced_binary(int *array, size_t size, int value);
```

### Parameters
- `array`: Pointer to the first element of the sorted array
- `size`: Number of elements in the array
- `value`: Value to search for

### Return Value
- Returns the index of the **first occurrence** of `value`
- Returns `-1` if the value is not found or if the array is NULL/empty

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-advanced_binary.c -o advanced_binary
```

## Usage Example
```c
int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
size_t size = sizeof(array) / sizeof(array[0]);

int index = advanced_binary(array, size, 5);
printf("Found 5 at index: %d\n", index);  // Output: 3
```

## Expected Output
```
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## How It Works

1. **Initial Check**: Validates that the array is not NULL and size > 0
2. **Binary Division**: Calculates the middle index of the current search space
3. **First Occurrence Check**: Verifies if the middle element is the target AND the previous element is different (ensuring it's the first occurrence)
4. **Recursive Search**: 
   - If target ≤ middle value: search left half (including middle)
   - If target > middle value: search right half (excluding middle)
5. **Visualization**: Prints the current search space at each step
