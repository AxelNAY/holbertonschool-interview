# Insert in Sorted Linked List

A C implementation for inserting a number into a sorted singly linked list while maintaining the sorted order.

## Description

This project implements a function that inserts a new node with a given integer value into a sorted singly linked list. The insertion maintains the ascending order of the list, placing the new node in the correct position. The implementation includes utility functions for list management, printing, and memory cleanup.

## Project Structure

### Core Files

- **`lists.h`** - Header file containing structure definitions and function prototypes
- **`0-insert_number.c`** - Main implementation of the sorted insertion algorithm
- **`linked_lists.c`** - Utility functions for linked list operations
- **`0-main.c`** - Test file demonstrating the insertion functionality

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

### 1. Insert Node (Main Function)
```c
listint_t *insert_node(listint_t **head, int number);
```
- **Purpose**: Inserts a number into a sorted linked list maintaining order
- **Parameters**: 
  - `head`: Double pointer to the head of the list
  - `number`: Integer value to insert
- **Returns**: Pointer to the new node, or NULL on failure
- **Time Complexity**: O(n) where n is the number of nodes
- **Space Complexity**: O(1)

### 2. Utility Functions

#### Print List
```c
size_t print_listint(const listint_t *h);
```
- Prints all elements of the linked list
- Returns the number of nodes in the list

#### Add Node at End
```c
listint_t *add_nodeint_end(listint_t **head, const int n);
```
- Adds a new node at the end of the list
- Used for building test lists

#### Free List
```c
void free_listint(listint_t *head);
```
- Deallocates all nodes in the linked list
- Prevents memory leaks

## Algorithm Details

### Insertion Strategy

The `insert_node` function uses the following algorithm:

1. **Memory Allocation**: Create a new node and handle allocation failure
2. **Edge Case Handling**: 
   - Empty list: Insert as first node
   - Insert at beginning: New value is smaller than head
3. **Position Finding**: Traverse list to find correct insertion point
4. **Node Insertion**: Link the new node into the correct position

### Step-by-Step Process

```
insert_node(head, number)
├── Allocate memory for new node
├── Handle allocation failure
├── Set node value and initialize next pointer
├── Check edge cases:
│   ├── Empty list → Insert as head
│   └── Insert at beginning → New head
├── Find insertion position:
│   └── Traverse until current->next >= number
└── Insert node:
    ├── new->next = current->next
    └── current->next = new
```

## Code Walkthrough

### Core Implementation

```c
listint_t *insert_node(listint_t **head, int number) {
    listint_t *new;
    listint_t *current;

    current = *head;

    // Allocate memory for new node
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    // Handle empty list or insert at beginning
    if (*head == NULL || (*head)->n >= number) {
        new->next = *head;
        *head = new;
        return (new);
    }
    
    // Find correct position
    while (current->next != NULL && current->next->n < number) {
        current = current->next;
    }
    
    // Insert node
    new->next = current->next;
    current->next = new;
    return (new);
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-insert_number.c linked_lists.c -o insert
```

## Usage Example

```c
#include "lists.h"

int main(void)
{
    listint_t *head = NULL;
    
    // Build a sorted list: 0, 1, 2, 3, 4, 98, 402, 1024
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    
    print_listint(head);
    printf("-----------------\n");
    
    // Insert 27 in correct position
    insert_node(&head, 27);
    
    print_listint(head);
    
    free_listint(head);
    return (0);
}
```

## Expected Output

```
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```

## Algorithm Analysis

### Time Complexity
- **Best Case**: O(1) - Insert at beginning
- **Average Case**: O(n/2) - Insert in middle
- **Worst Case**: O(n) - Insert at end or before last element

### Space Complexity
- **Space**: O(1) - Only one new node allocated
- **No additional data structures** required

## Edge Cases Handled

1. **Empty List**: 
   - `*head == NULL`
   - New node becomes the head

2. **Insert at Beginning**:
   - `number < (*head)->n`
   - New node becomes new head

3. **Insert at End**:
   - `number > all existing values`
   - New node added at tail

4. **Insert in Middle**:
   - Find correct position maintaining order
   - Link appropriately between existing nodes

5. **Duplicate Values**:
   - Inserts after existing equal values
   - Maintains stable insertion order

6. **Memory Allocation Failure**:
   - Returns NULL if malloc fails
   - No list modification on failure

## Key Features

- **Maintains Sorted Order**: Automatic positioning in ascending order
- **Memory Efficient**: O(1) space complexity
- **Robust Error Handling**: Handles allocation failures gracefully
- **Edge Case Coverage**: Works with empty lists, single elements, and all positions
- **Clean Interface**: Simple function signature with clear return values
- **No Side Effects**: Original list structure preserved on failure

## Testing Strategy

The test file (`0-main.c`) demonstrates:
- Building a pre-sorted list
- Inserting a value that should go in the middle
- Printing before and after to verify correct positioning
- Proper memory cleanup

## Memory Management

- **Allocation**: Single `malloc()` call for new node
- **Deallocation**: `free_listint()` function cleans up entire list
- **Leak Prevention**: All allocated memory properly tracked and freed
- **Failure Handling**: Returns NULL on allocation failure without side effects

## Performance Characteristics

- **Insertion**: O(n) worst case, O(1) best case
- **Memory Usage**: Minimal - only one new node per insertion
- **Traversal**: Single pass to find insertion point
- **No Reallocation**: No need to rebuild or reorganize existing structure

This implementation provides an efficient and robust solution for maintaining sorted linked lists with dynamic insertions.
