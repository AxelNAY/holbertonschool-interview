# Linked List Cycle Detection

A C implementation of Floyd's Cycle Detection Algorithm (also known as the "Tortoise and Hare" algorithm) to detect cycles in singly linked lists.

## Description

This project implements a function that detects whether a singly linked list contains a cycle. A cycle occurs when a node's `next` pointer points back to a previous node in the list, creating an infinite loop. The implementation uses Floyd's cycle detection algorithm, which is both time and space efficient.

## Project Structure

### Core Files

- **`lists.h`** - Header file containing structure definitions and function prototypes
- **`0-check_cycle.c`** - Main implementation of the cycle detection algorithm
- **`0-linked_lists.c`** - Utility functions for linked list operations
- **`0-main.c`** - Test file demonstrating cycle detection functionality

## Data Structure

The project uses a singly linked list structure:

```c
typedef struct listint_s
{
    int n;                    // Integer value stored in the node
    struct listint_s *next;   // Pointer to the next node
} listint_t;
```

## Key Functions

### 1. Check Cycle (Main Function)
```c
int check_cycle(listint_t *list);
```
- **Purpose**: Detects if a linked list contains a cycle
- **Parameters**: `list` - Pointer to the head of the linked list
- **Returns**: 
  - `1` if a cycle is detected
  - `0` if no cycle exists (including empty or NULL lists)
- **Algorithm**: Floyd's Cycle Detection (Tortoise and Hare)
- **Time Complexity**: O(n) where n is the number of nodes
- **Space Complexity**: O(1) - constant space usage

### 2. Utility Functions

#### Print List
```c
size_t print_listint(const listint_t *h);
```
- Prints all elements of a non-cyclic linked list
- Returns the number of nodes printed

#### Add Node at Beginning
```c
listint_t *add_nodeint(listint_t **head, const int n);
```
- Adds a new node at the beginning of the list
- Used for building test lists

#### Free List
```c
void free_listint(listint_t *head);
```
- Deallocates all nodes in a non-cyclic linked list
- **Warning**: Should not be used on cyclic lists

## Algorithm: Floyd's Cycle Detection

### The Tortoise and Hare Approach

Floyd's algorithm uses two pointers moving at different speeds:

- **Slow Pointer (Tortoise)**: Moves one step at a time
- **Fast Pointer (Hare)**: Moves two steps at a time

If there's a cycle, the fast pointer will eventually meet the slow pointer inside the cycle.

### Visual Representation

```
Non-Cyclic List:
[A] -> [B] -> [C] -> [D] -> NULL
 ↑      ↑
slow   fast

Cyclic List:
[A] -> [B] -> [C] -> [D]
       ↑             ↓
       [F] <- [E] <--┘
```

### Step-by-Step Process

```
check_cycle(list)
├── Initialize two pointers (slow and fast) to list head
├── While fast pointer and fast->next are not NULL:
│   ├── Move slow pointer one step forward
│   ├── Move fast pointer two steps forward
│   └── If slow == fast:
│       └── Return 1 (cycle detected)
└── Return 0 (no cycle found)
```

## Code Implementation

### Core Algorithm

```c
int check_cycle(listint_t *list)
{
    listint_t *current = list;  // Slow pointer (tortoise)
    listint_t *temp = list;     // Fast pointer (hare)

    while (temp != NULL && temp->next != NULL)
    {
        current = current->next;      // Move slow pointer 1 step
        temp = temp->next->next;      // Move fast pointer 2 steps

        if (current == temp)          // Pointers meet = cycle detected
        {
            return (1);
        }
    }

    return (0);                       // No cycle found
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

## Usage Example

```c
#include "lists.h"

int main(void)
{
    listint_t *head;
    listint_t *current;
    int i;

    head = NULL;
    
    // Build a linear list: 1024 -> 402 -> 98 -> 4 -> 3 -> 2 -> 1 -> 0
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    
    // Test 1: Check linear list (no cycle)
    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else
        printf("Linked list has a cycle\n");
    
    // Create a cycle: make 5th node point back to head
    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    current->next = head;  // Create cycle
    
    // Test 2: Check cyclic list
    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else
        printf("Linked list has a cycle\n");
    
    return (0);
}
```

## Expected Output

```
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Algorithm Analysis

### Why Floyd's Algorithm Works

1. **Different Speeds**: Slow and fast pointers move at different rates
2. **Cycle Property**: In a cycle, fast pointer will eventually "lap" the slow pointer
3. **Meeting Point**: When pointers meet, a cycle definitely exists
4. **Termination**: If no cycle exists, fast pointer reaches NULL

### Mathematical Proof

If there's a cycle of length `C`:
- When slow pointer enters the cycle, fast pointer is already inside
- Fast pointer gains 1 position on slow pointer each iteration
- They will meet within `C` iterations after slow pointer enters the cycle

### Time Complexity Analysis

- **Best Case**: O(1) - Empty list or immediate NULL
- **Average Case**: O(n) - Linear traversal
- **Worst Case**: O(n) - Visit each node at most twice

### Space Complexity

- **Space**: O(1) - Only two pointer variables used
- **No additional data structures** required

## Edge Cases Handled

1. **Empty List (`list == NULL`)**:
   - Fast pointer is NULL, loop doesn't execute
   - Returns 0 (no cycle)

2. **Single Node, No Cycle**:
   - `temp->next == NULL`
   - Loop terminates, returns 0

3. **Single Node, Self-Cycle**:
   - Node points to itself
   - Pointers meet immediately, returns 1

4. **Two Nodes, Cycle**:
   - Nodes point to each other
   - Detected in first iteration

5. **Large Lists**:
   - Algorithm scales linearly
   - Memory usage remains constant

## Advantages of Floyd's Algorithm

### Benefits

- **Space Efficient**: O(1) space complexity
- **Time Efficient**: O(n) time complexity
- **Simple Implementation**: Easy to understand and code
- **No Modifications**: Doesn't alter the original list
- **Robust**: Handles all edge cases gracefully

### Comparison with Alternatives

| Method | Time | Space | Pros | Cons |
|--------|------|-------|------|------|
| Floyd's | O(n) | O(1) | Fast, space-efficient | Requires understanding |
| Hash Set | O(n) | O(n) | Intuitive | Uses extra memory |
| Marking | O(n) | O(1) | Space-efficient | Modifies original list |

## Common Pitfalls

### Potential Issues

1. **Null Pointer Dereference**:
   - Always check `temp` and `temp->next` before accessing
   - Current implementation handles this correctly

2. **Infinite Loops**:
   - Using only one pointer would create infinite loop in cyclic lists
   - Two-pointer approach prevents this

3. **Memory Management**:
   - Don't use `free_listint()` on cyclic lists
   - Can cause segmentation faults or infinite loops

## Testing Strategy

The test file demonstrates:
- **Linear List Testing**: Verify no false positives
- **Cycle Creation**: Manually create a cycle for testing
- **Cycle Detection**: Confirm algorithm detects the cycle
- **Cycle Removal**: Restore original structure for cleanup

## Performance Characteristics

- **Detection Speed**: Linear in list size
- **Memory Usage**: Constant regardless of list size
- **Scalability**: Suitable for very large lists
- **Reliability**: Mathematically proven algorithm

## Real-World Applications

- **Memory Leak Detection**: Finding circular references
- **Graph Algorithms**: Detecting cycles in directed graphs
- **Data Structure Validation**: Ensuring list integrity
- **Debugging Tools**: Identifying infinite loops in linked structures

This implementation provides a robust, efficient solution for cycle detection in linked lists using one of the most elegant algorithms in computer science.