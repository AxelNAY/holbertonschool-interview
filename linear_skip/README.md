# Linear Skip List Search

## Description

This project implements a search algorithm for a **skip list** data structure. A skip list is a sorted linked list enhanced with an "express lane" that allows for faster traversal by skipping over multiple nodes at once. The `linear_skip` function combines the efficiency of skip-forward jumps with linear search to find values in O(√n) average time.

## What is a Skip List?

A **skip list** is a probabilistic data structure that allows fast search within an ordered sequence of elements. It consists of:

1. **Base layer**: A standard sorted singly linked list
2. **Express lane**: Additional pointers that skip over multiple nodes (typically √n spacing)

This creates a "fast lane" for quickly narrowing down the search range before performing a linear search in the identified segment.

## Algorithm Overview

The search algorithm works in two phases:

1. **Express Lane Phase**: Jump through express pointers until finding the range containing the target
2. **Linear Search Phase**: Perform linear search within the identified range

**Time Complexity**: O(√n) average case  
**Space Complexity**: O(1) - only uses a few pointers

## Files

| File | Description |
|------|-------------|
| `search.h` | Header file with skip list structure and function prototypes |
| `0-linear_skip.c` | Implementation of the linear skip search algorithm |
| `0-main.c` | Test file demonstrating the search |
| `create_skiplist.c` | Helper function to create skip list from array |
| `print_skiplist.c` | Utility to visualize the skip list structure |
| `free_skiplist.c` | Function to deallocate skip list memory |
| `README.md` | Project documentation |

## Data Structure
```c
typedef struct skiplist_s
{
    int n;                      /* Value stored in the node */
    size_t index;               /* Position in the original list */
    struct skiplist_s *next;    /* Pointer to next node (base layer) */
    struct skiplist_s *express; /* Pointer to express lane node */
} skiplist_t;
```

### Skip List Structure
```
Express Lane: [0] ---------> [4] ---------> [9] ---------> [15]
                |             |              |              |
Base Layer:    [0]->[1]->[2]->[3]->[4]->[5]->[6]->[7]->[8]->[9]->...->[15]
```

The express lane skips approximately √n nodes, creating a two-level hierarchy.

## Function Prototypes
```c
skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
```

### Main Function

**`linear_skip`**

Searches for a value in a sorted skip list of integers.

**Parameters**:
- `list`: Pointer to the head of the skip list
- `value`: Value to search for

**Returns**:
- Pointer to the first node where value is located
- `NULL` if value is not present or if head is NULL

**Prints**: 
- Each express lane node checked
- The range where value is found
- Each node checked during linear search

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-linear_skip.c create_skiplist.c print_skiplist.c free_skiplist.c -lm -o skip
```

Note: `-lm` flag is needed for the `sqrt()` function in `create_skiplist.c`

## Usage Example
```c
int array[] = {0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
size_t size = sizeof(array) / sizeof(array[0]);

skiplist_t *list = create_skiplist(array, size);
skiplist_t *result = linear_skip(list, 53);

if (result)
    printf("Found %d at index: %lu\n", 53, result->index);
else
    printf("Value not found\n");

free_skiplist(list);
```

## Expected Output
```
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```

## How It Works

### Phase 1: Express Lane Traversal
```c
node = list;
while (node->express && node->express->n < value)
{
    printf("Value checked at index [%lu] = [%d]\n",
           node->express->index, node->express->n);
    node = node->express;
}
```

**Purpose**: Jump through express lane until finding a node where:
- Next express node is NULL (end of express lane), OR
- Next express node's value ≥ target value

**Example**: Searching for 53 in array
```
Express: [0:0] -> [4:4] -> [8:18] -> [12:61]
                    ↑                  ↑
              18 < 53            61 >= 53 (stop)
```

### Phase 2: Define Search Range
```c
if (node->express)
{
    printf("Value checked at index [%lu] = [%d]\n",
           node->express->index, node->express->n);
    prev = node;
    node = node->express;
}
else
{
    prev = node;
    while (node->next)
        node = node->next;
}
```

**Purpose**: Determine the boundaries for linear search:
- If express lane continues: search between current and next express node
- If at end of express lane: search from current to end of list

### Phase 3: Linear Search
```c
printf("Value found between indexes [%lu] and [%lu]\n",
       prev->index, node->index);

while (prev && prev->index <= node->index)
{
    printf("Value checked at index [%lu] = [%d]\n",
           prev->index, prev->n);
    if (prev->n == value)
        return (prev);
    prev = prev->next;
}
```

**Purpose**: Traverse nodes linearly in the identified range until finding the value.

## Visual Example

**Skip List for array: [0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99]**
```
Express:  [0] ---------> [4] ---------> [18] ---------> [61]
           |              |               |               |
Base:     [0]-[1]-[2]-[3]-[4]-[7]-[12]-[15]-[18]-[19]-[23]-[53]-[61]-[62]-[76]-[99]
Index:     0   1   2   3   4   5   6    7    8    9   10   11   12   13   14   15
```

**Searching for 53:**

1. **Express Jump**: 0 → 4 (4 < 53, continue)
2. **Express Jump**: 4 → 8 (18 < 53, continue)
3. **Express Jump**: 8 → 12 (61 ≥ 53, stop)
4. **Range Identified**: Between indices 8 and 12
5. **Linear Search**: 18 → 19 → 23 → **53** (found!)

## Complexity Analysis

| Operation | Time | Comparisons |
|-----------|------|-------------|
| Express lane jumps | O(√n) | ~√n checks |
| Linear search in range | O(√n) | ≤√n checks |
| **Total** | **O(√n)** | **~2√n checks** |

### Comparison with Other Algorithms

| Algorithm | Sorted List | Time | Space |
|-----------|-------------|------|-------|
| **Skip List Search** | Required | O(√n) | O(1) |
| Linear Search | Not required | O(n) | O(1) |
| Binary Search | Required | O(log n) | O(1) |
| Jump Search | Required | O(√n) | O(1) |

## Express Lane Initialization

The express lane spacing is calculated as √n:
```c
void init_express(skiplist_t *list, size_t size)
{
    const size_t step = sqrt(size);  /* Express nodes every √n positions */
    size_t i;
    skiplist_t *save;
    
    for (save = list, i = 0; i < size; ++i, list = list->next)
    {
        if (i % step == 0)
        {
            save->express = list;
            save = list;
        }
    }
}
```

**For n = 16**: step = 4, express nodes at indices 0, 4, 8, 12  
**For n = 100**: step = 10, express nodes at indices 0, 10, 20, 30, ...

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty list (`list == NULL`) | Returns `NULL` |
| Value at head | Finds immediately after express check |
| Value at tail | Searches to end of list |
| Value not present | Returns `NULL` after full range search |
| Single element | Works correctly with no express lane |
| Duplicate values | Returns first occurrence |

## Advantages of Skip Lists

✅ **Faster than linear search**: O(√n) vs O(n)  
✅ **Simpler than binary search trees**: No rebalancing needed  
✅ **Dynamic**: Easy insertion/deletion (not shown here)  
✅ **Cache-friendly**: Sequential memory access in ranges  
✅ **Probabilistic balance**: Self-adjusting structure  

## Disadvantages

❌ **Slower than binary search**: O(√n) vs O(log n)  
❌ **Extra memory**: Express lane pointers  
❌ **Requires sorted data**: Must maintain order  
❌ **Not optimal for arrays**: Binary search better for random access  

## Use Cases

- **Database indexing**: Fast range queries on sorted data
- **In-memory caches**: LRU caches with fast lookups
- **Network routing**: Skip graphs for distributed systems
- **File systems**: Quick file location in sorted directories
- **Real-time systems**: Predictable search performance

## Comparison: Skip List vs Jump Search

Both achieve O(√n) complexity:

| Feature | Skip List | Jump Search |
|---------|-----------|-------------|
| Structure | Linked list + express | Array |
| Memory | O(n + √n) | O(n) |
| Insertion | O(√n) | O(n) |
| Deletion | O(√n) | O(n) |
| Cache | Poor | Good |

**Skip List advantage**: Dynamic operations  
**Jump Search advantage**: Better cache locality

## Advanced Skip Lists

In production, skip lists typically use:
- **Multiple levels**: Not just one express lane (e.g., probabilistic skip lists)
- **Randomized heights**: Nodes randomly assigned to levels
- **Better complexity**: O(log n) with multiple levels
- **Concurrent access**: Lock-free implementations possible

## Testing Recommendations
```c
/* Test cases */
- Search for first element
- Search for last element
- Search for middle element
- Search for non-existent value
- Search in empty list
- Search in single-element list
- Search in list with duplicates
```

## Memory Management
```c
/* Always free the skip list after use */
free_skiplist(list);

/* The free function recursively frees all nodes */
void free_skiplist(skiplist_t *list)
{
    if (list)
    {
        free_skiplist(list->next);
        free(list);
    }
}
```

## Author

Project implementation for understanding skip list data structures and hybrid search algorithms combining express lanes with linear search.
