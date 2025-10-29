# AVL Tree Validator

## Description

This project implements a function to validate whether a binary tree is a valid AVL (Adelson-Velsky and Landis) tree. An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one.

## What is an AVL Tree?

An AVL tree must satisfy three properties:

1. **Binary Search Tree (BST) Property**: For each node, all values in the left subtree must be less than the node's value, and all values in the right subtree must be greater
2. **Balance Property**: The height difference (balance factor) between left and right subtrees of any node must be -1, 0, or 1
3. **Recursive Property**: All subtrees must also be valid AVL trees

## Algorithm Overview

The validation algorithm checks:

- **BST Property**: Ensures values are within valid min/max bounds
- **Balance Factor**: Calculates height difference between left and right subtrees
- **Recursive Validation**: Verifies both subtrees are valid AVL trees

**Time Complexity**: O(n²) - visits each node once, but calculates height for each node  
**Space Complexity**: O(h) where h is the height (recursion stack)

## Files

| File | Description |
|------|-------------|
| `binary_trees.h` | Header file with structure definitions and function prototypes |
| `0-binary_tree_is_avl.c` | Implementation of AVL tree validation |
| `0-main.c` | Test file with various tree configurations |
| `binary_tree_node.c` | Function to create a new binary tree node |
| `binary_tree_print.c` | Utility function to visualize binary trees |

## Data Structure
```c
typedef struct binary_tree_s
{
    int n;                          /* Value stored in the node */
    struct binary_tree_s *parent;   /* Pointer to parent node */
    struct binary_tree_s *left;     /* Pointer to left child */
    struct binary_tree_s *right;    /* Pointer to right child */
} binary_tree_t;

typedef struct binary_tree_s avl_t;
```

## Function Prototypes
```c
int binary_tree_is_avl(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
```

### Main Function

**`binary_tree_is_avl`**
- **Parameters**: `tree` - pointer to the root node of the tree to check
- **Returns**: 
  - `1` if the tree is a valid AVL tree
  - `0` if the tree is NULL or not a valid AVL tree

### Helper Functions

**`height`** - Measures the height of a binary tree
- Returns the height of the tree, 0 if tree is NULL

**`is_avl_helper`** - Recursive helper to validate AVL properties
- Checks BST property with min/max bounds
- Calculates and validates balance factor
- Recursively validates subtrees

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-binary_tree_is_avl.c binary_tree_node.c binary_tree_print.c -o avl_validator
```

## Usage Example
```c
binary_tree_t *root;
int avl;

root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
root->right = binary_tree_node(root, 128);

avl = binary_tree_is_avl(root);
printf("Is tree AVL: %d\n", avl);  // Output: 1 (true)
```

## Expected Output
```
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 1
Is 12 avl: 1

       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)  .--(097)     (402)
Is 98 avl: 1

            .-------(098)-------.
       .--(012)--.         .--(128)--.
  .-(010)     (054)     (097)     (402)--.
                                       (430)
Is 98 avl: 0

            .-------(098)-------.
       .--(012)--.         .--(128)--.
  .-(010)     (054)     (097)     (402)--.
                                       (430)
                                    .-(420)
Is 98 avl: 0
```

## How It Works

1. **NULL Check**: Returns 0 if the tree is NULL
2. **BST Validation**: Ensures each node's value is within valid bounds (greater than all left ancestors, less than all right ancestors)
3. **Height Calculation**: Recursively calculates the height of left and right subtrees
4. **Balance Factor Check**: Computes `balance = left_height - right_height` and verifies it's between -1 and 1
5. **Recursive Validation**: Validates both left and right subtrees with updated bounds

## Balance Factor Examples

- **Balance Factor = 0**: Left and right subtrees have equal height (perfectly balanced)
- **Balance Factor = 1**: Left subtree is one level taller (left-heavy, still valid)
- **Balance Factor = -1**: Right subtree is one level taller (right-heavy, still valid)
- **Balance Factor > 1 or < -1**: Tree is unbalanced (NOT a valid AVL tree)
