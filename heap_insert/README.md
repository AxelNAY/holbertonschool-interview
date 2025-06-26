# Heap Insert

A C implementation of binary tree operations with a focus on max heap insertion, maintaining heap properties while inserting new values.

## Description

This project implements a binary tree data structure with heap insertion functionality. The main focus is on creating and maintaining a max binary heap where each parent node has a value greater than or equal to its children. The implementation includes node creation, heap insertion with proper rebalancing, and tree visualization utilities.

## Project Structure

### Core Files

- **`binary_trees.h`** - Header file containing structure definitions and function prototypes
- **`0-binary_tree_node.c`** - Implementation of basic binary tree node creation
- **`1-heap_insert.c`** - Main heap insertion algorithm with helper functions
- **`binary_tree_print.c`** - Utility function for visualizing binary trees
- **`0-main.c`** - Test file for basic binary tree node creation
- **`1-main.c`** - Test file for heap insertion functionality

## Data Structure

The project uses a binary tree structure defined as:

```c
typedef struct binary_tree_s
{
    int n;                          // Integer value stored in the node
    struct binary_tree_s *parent;   // Pointer to parent node
    struct binary_tree_s *left;     // Pointer to left child
    struct binary_tree_s *right;    // Pointer to right child
} binary_tree_t;

typedef struct binary_tree_s heap_t;  // Alias for heap operations
```

## Key Functions

### 1. Node Creation
```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```
- Creates a new binary tree node with specified parent and value
- Returns pointer to new node or NULL on failure
- Initializes left and right children to NULL

### 2. Heap Insertion
```c
heap_t *heap_insert(heap_t **root, int value);
```
- Inserts a value into a max binary heap
- Maintains heap properties (parent ≥ children)
- Ensures tree remains complete
- Returns pointer to newly created node

### 3. Helper Functions

#### Height Calculation
```c
size_t binary_tree_height(const binary_tree_t *tree);
```
- Measures the height of a binary tree
- Returns 0 for NULL or leaf nodes
- Recursively calculates maximum depth

#### Perfect Tree Check
```c
int binary_tree_is_perfect(const binary_tree_t *tree);
```
- Determines if binary tree is perfect (all levels completely filled)
- Returns 1 for perfect trees, 0 otherwise
- Used to determine insertion strategy

#### Node Swapping
```c
void swap(heap_t **parent, heap_t **child);
```
- Swaps parent and child nodes when heap property is violated
- Maintains all pointer relationships
- Ensures heap property is restored

## Algorithm Details

### Heap Insertion Strategy

1. **Empty Tree**: Create root node with given value
2. **Tree Analysis**: Check if tree is perfect or left subtree is incomplete
3. **Insertion Position**:
   - If tree is perfect OR left subtree is not perfect: insert in left subtree
   - Otherwise: insert in right subtree
4. **Heap Property Restoration**: After insertion, swap nodes upward if necessary

### Insertion Logic Flow

```
heap_insert(root, value)
├── If root is NULL: create new root
├── If tree is perfect OR left subtree incomplete:
│   ├── Insert in left subtree (recursively)
│   └── Swap with left child if needed
└── Else:
    ├── Insert in right subtree (recursively)
    └── Swap with right child if needed
```

## Compilation

```bash
# Compile with basic binary tree test
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-binary_tree_node.c binary_tree_print.c -o binary_tree

# Compile with heap insertion test
gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-binary_tree_node.c 1-heap_insert.c binary_tree_print.c -o heap_insert
```

## Usage Examples

### Basic Binary Tree Creation

```c
#include "binary_trees.h"

int main(void)
{
    binary_tree_t *root;
    
    // Create root node
    root = binary_tree_node(NULL, 98);
    
    // Add children
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    
    // Print tree structure
    binary_tree_print(root);
    
    return (0);
}
```

### Heap Insertion Example

```c
#include "binary_trees.h"

int main(void)
{
    heap_t *root = NULL;
    heap_t *node;
    
    // Insert values maintaining heap property
    node = heap_insert(&root, 98);
    node = heap_insert(&root, 402);
    node = heap_insert(&root, 12);
    node = heap_insert(&root, 46);
    
    // Print final heap structure
    binary_tree_print(root);
    
    return (0);
}
```

## Expected Output

When running the heap insertion test (`1-main.c`), you'll see a sequence showing how the heap grows and maintains its max-heap property:

```
Inserted: 98
(098)

Inserted: 402
    .----------(402)
(098)

Inserted: 12
    .----------(402)----------.
(098)                    (012)

... (continues with more insertions)
```

## Heap Properties Maintained

1. **Complete Binary Tree**: All levels filled except possibly the last, which fills left to right
2. **Max Heap Property**: Every parent node value ≥ children node values
3. **Efficient Insertion**: O(log n) time complexity for insertion
4. **Memory Management**: Proper allocation and deallocation of nodes

## Key Features

- **Automatic Rebalancing**: Maintains heap property through intelligent swapping
- **Complete Tree Structure**: Ensures optimal tree shape for heap operations
- **Visual Output**: Includes tree printing functionality for debugging
- **Memory Safety**: Proper malloc/free usage with NULL checks
- **Recursive Design**: Clean recursive implementation for tree operations

## Time Complexity

- **Node Creation**: O(1)
- **Heap Insertion**: O(log n) - where n is number of nodes
- **Height Calculation**: O(n) - visits all nodes
- **Perfect Tree Check**: O(n) - may visit all nodes
- **Tree Printing**: O(n) - visits all nodes

## Space Complexity

- **Node Storage**: O(n) - for n nodes
- **Recursion Stack**: O(log n) - for insertion operations
- **Print Buffer**: O(h × w) - where h is height and w is width for printing

## Error Handling

- NULL pointer checks for all tree operations
- Memory allocation failure handling
- Proper cleanup with tree deletion functions
- Boundary condition handling for empty trees

This implementation provides a solid foundation for understanding binary heaps and tree data structures, with practical insertion algorithms that maintain heap properties efficiently.