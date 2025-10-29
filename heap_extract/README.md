# Heap Extract

## Description

This project implements the extraction operation for a **Max Binary Heap**. The `heap_extract` function removes and returns the root node (maximum value) from the heap while maintaining the heap property. This is a fundamental operation in heap data structures, commonly used in priority queues and heap sort algorithms.

## What is a Max Binary Heap?

A **Max Binary Heap** is a complete binary tree where:

1. **Heap Property**: Every parent node has a value greater than or equal to its children
2. **Complete Binary Tree**: All levels are filled except possibly the last, which is filled from left to right
3. **Root Contains Maximum**: The root node always contains the largest value in the heap

## Algorithm Overview

The extraction process follows these steps:

1. **Save root value** to return later
2. **Find last node** in the heap (rightmost node in the last level)
3. **Replace root** with the last node's value
4. **Remove last node** from the heap
5. **Heapify down** from root to restore heap property

**Time Complexity**: O(log n) for heapify operation  
**Space Complexity**: O(log n) for recursion stack

## Files

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file with structure definitions and function prototypes |
| `0-heap_extract.c` | Implementation of heap extraction and helper functions |
| `0-main.c` | Test file demonstrating heap extraction |
| `binary_tree_print.c` | Utility function to visualize binary trees |
| `README.md` | Project documentation |

## Data Structure
```c
typedef struct binary_tree_s
{
    int n;                          /* Value stored in the node */
    struct binary_tree_s *parent;   /* Pointer to parent node */
    struct binary_tree_s *left;     /* Pointer to left child */
    struct binary_tree_s *right;    /* Pointer to right child */
} binary_tree_t;

typedef struct binary_tree_s heap_t;
```

## Function Prototypes
```c
int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *tree);
```

### Main Function

**`heap_extract`**

Extracts the root node of a Max Binary Heap.

**Parameters**:
- `root`: Double pointer to the root node of the heap

**Returns**:
- The value stored in the root node (maximum value)
- `0` if the heap is empty or NULL

**Behavior**:
- Removes the root node
- Maintains heap property after extraction
- Updates the root pointer

### Helper Functions

**`find_last_and_heapify`** - Multi-purpose recursive helper
- **Mode 1** (count_mode=1): Counts total nodes in the heap
- **Mode 2** (count_mode=0, total>0): Finds the last node using level-order indexing
- **Mode 3** (count_mode=0, total=-1): Performs heapify-down operation

**`max`** - Finds maximum value node in a subtree (legacy compatibility)

**`recurse_extract`** - Alternative extraction approach (legacy compatibility)

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-heap_extract.c binary_tree_print.c -o heap_extract
```

## Usage Example
```c
heap_t *tree;
int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2};
size_t n = sizeof(array) / sizeof(array[0]);

tree = _array_to_heap(array, n);  /* Build heap from array */

int max = heap_extract(&tree);     /* Extract root (maximum) */
printf("Extracted: %d\n", max);    /* Output: 98 */
```

## Expected Output
```
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(087)--.         .--(084)--.         .--(068)--.         .--(079)--.
  .--(034)     (047)     (022)     (020)     (032)     (002)     (021)     (062)
(001)
Extracted: 98

                 .-----------------(095)-----------------.
       .-------(087)-------.                   .-------(091)-------.
  .--(084)--.         .--(022)--.         .--(068)--.         .--(079)--.
(034)     (047)     (001)     (020)     (032)     (002)     (021)     (062)
Extracted: 95

                 .-----------------(091)-------.
       .-------(087)-------.              .--(079)--.
  .--(084)--.         .--(022)--.    .--(068)--.  (062)
(034)     (047)     (001)     (020)(032)     (002)
                                  (021)
Extracted: 91
```

## How It Works

### Step-by-Step Extraction Process

**Initial Max Heap:**
```
       98
      /  \
    95    91
   / \    / \
  87  84 68  79
 / \  / \
34 47 22 20
```

**Step 1: Save Root Value**
```
extracted_value = 98
```

**Step 2: Find Last Node (rightmost in last level)**
```
Last node = 20 (index 10 in level-order)
```

**Step 3: Replace Root with Last Node**
```
       20
      /  \
    95    91
   / \    / \
  87  84 68  79
 / \  /
34 47 22
```

**Step 4: Remove Last Node**
```
Last node (20) is removed from its position
```

**Step 5: Heapify Down**
```
Compare 20 with children (95, 91)
  → Swap with 95 (larger child)

       95
      /  \
    20    91
   / \    / \
  87  84 68  79
 / \  /
34 47 22

Compare 20 with children (87, 84)
  → Swap with 87 (larger child)

       95
      /  \
    87    91
   / \    / \
  20  84 68  79
 / \  /
34 47 22

Compare 20 with children (34, 47)
  → Swap with 47 (larger child)

       95
      /  \
    87    91
   / \    / \
  47  84 68  79
 / \  /
34 20 22

Heap property restored!
```

## Finding Last Node Algorithm

Uses **level-order indexing** (1-based):
```
       1
      / \
    2     3
   / \   / \
  4   5 6   7
 / \ /
8  9 10

For total_nodes = 10:
- Navigate using binary representation of index
- Binary path determines left/right choices
```

**Binary Navigation:**
- Index 10 in binary: 1010
- Path: Root → Left (0) → Right (1) → Left (0)

## Heapify Down Process
```c
while (node has children)
{
    largest = node;
    
    if (left_child > largest)
        largest = left_child;
    
    if (right_child > largest)
        largest = right_child;
    
    if (largest == node)
        break;  /* Heap property satisfied */
    
    swap(node, largest);
    node = largest;  /* Continue down */
}
```

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty heap (`root == NULL`) | Returns `0` |
| Single node heap | Extracts root, sets `*root = NULL`, returns value |
| Two-node heap | Extracts root, remaining node becomes new root |
| Complete binary tree | Standard extraction with full heapify |

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Save root value | O(1) | O(1) |
| Count nodes | O(n) | O(log n) |
| Find last node | O(log n) | O(log n) |
| Heapify down | O(log n) | O(log n) |
| **Total** | **O(n)** * | **O(log n)** |

*Note: Can be optimized to O(log n) by maintaining node count

## Heap Properties Maintained

✅ **Max Heap Property**: Parent ≥ children  
✅ **Complete Binary Tree**: All levels filled left-to-right  
✅ **Structural Integrity**: Parent pointers correctly updated  
✅ **Memory Management**: Last node properly freed  

## Common Applications

- **Priority Queues**: Efficiently get highest priority item
- **Heap Sort**: Extract maximum repeatedly for sorting
- **Job Scheduling**: Process highest priority jobs first
- **Event-Driven Simulation**: Handle events by priority
- **Dijkstra's Algorithm**: Get minimum distance vertex
- **Huffman Coding**: Build optimal prefix codes

## Optimization Opportunities

1. **Store node count**: Avoid O(n) counting on each extraction → O(log n) total
2. **Iterative heapify**: Replace recursion with loops to save stack space
3. **Parent tracking**: Maintain pointer to last node's parent
4. **Array representation**: Use array instead of linked structure

## Comparison with Min Heap

| Operation | Max Heap | Min Heap |
|-----------|----------|----------|
| Extract | Returns maximum | Returns minimum |
| Heapify direction | Down (decrease) | Down (increase) |
| Comparison | Parent > Children | Parent < Children |
| Use case | Get largest first | Get smallest first |

## Related Operations

- **heap_insert**: Add new element while maintaining heap property
- **heap_build**: Construct heap from unsorted array
- **heap_sort**: Sort array using repeated extraction
- **heap_replace**: Extract and insert in single operation (more efficient)
