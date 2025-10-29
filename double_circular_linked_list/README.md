# Double Circular Linked List

## Description

This project implements a **double circular linked list** in C with operations to add nodes at the beginning and end of the list. Unlike standard doubly linked lists, this circular implementation connects the last node back to the first node, creating a continuous loop structure.

## Data Structure
```c
typedef struct List
{
    char *str;           /* Dynamically allocated string */
    struct List *prev;   /* Pointer to previous node */
    struct List *next;   /* Pointer to next node */
} List;
```

### Circular Structure Properties

- **Last node's `next`** points to the **first node** (head)
- **First node's `prev`** points to the **last node**
- For a single node: `node->next` and `node->prev` point to itself
- No NULL pointers in a non-empty list (except the head pointer when empty)

## Features

- **Dynamic string allocation**: Uses `strdup()` to create independent string copies
- **Circular double linking**: Maintains bidirectional links with circular connection
- **Head pointer management**: Automatically updates head pointer as needed
- **Memory safety**: Includes NULL checks and error handling

## Files

| File | Description |
|------|-------------|
| `list.h` | Header file with structure definition and function prototypes |
| `0-add_node.c` | Implementation of node creation and insertion functions |
| `0-main.c` | Test file demonstrating list operations |
| `README.md` | Project documentation |

## Function Prototypes
```c
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
```

### Functions

#### `add_node_end`
Adds a new node at the end of the circular doubly linked list.

**Parameters**:
- `list`: Double pointer to the head of the list
- `str`: String to store in the new node

**Returns**:
- Pointer to the newly created node
- `NULL` on failure (malloc error or invalid parameters)

**Behavior**:
- If list is empty: Creates first node pointing to itself
- If list exists: Inserts node between last node and head

#### `add_node_begin`
Adds a new node at the beginning of the circular doubly linked list.

**Parameters**:
- `list`: Double pointer to the head of the list
- `str`: String to store in the new node

**Returns**:
- Pointer to the newly created node (new head)
- `NULL` on failure

**Behavior**:
- Calls `add_node_end()` to insert the node
- Updates the head pointer to point to the new node

#### `create_node` (Helper)
Internal function that allocates and initializes a new node.

**Parameters**:
- `str`: String to duplicate and store

**Returns**:
- Pointer to allocated node
- `NULL` on allocation failure

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-add_node.c -o circular_list
```

## Usage Example
```c
List *list = NULL;

/* Add nodes to the end */
add_node_end(&list, "First");
add_node_end(&list, "Second");
add_node_end(&list, "Third");

/* Add nodes to the beginning */
add_node_begin(&list, "New Head");
```

## Expected Output
```
Hello World!
	->prev: Hello World!
	->next: Hello World!
Added to the end:
Holberton
	->prev: Engineer
	->next: School
School
	->prev: Holberton
	->next: Full
Full
	->prev: School
	->next: Stack
Stack
	->prev: Full
	->next: Engineer
Engineer
	->prev: Stack
	->next: Holberton
Hello World!
	->prev: Hello World!
	->next: Hello World!
Added to the beginning:
Engineer
	->prev: Holberton
	->next: Stack
Stack
	->prev: Engineer
	->next: Full
Full
	->prev: Stack
	->next: School
School
	->prev: Full
	->next: Holberton
Holberton
	->prev: School
	->next: Engineer
```

## How It Works

### Adding to Empty List
```
Before: list = NULL

After:  [Node] ⟲
        prev: Node, next: Node
```

### Adding to End of List
```
Before: [Head] ⇄ [Node2] ⇄ [Last]
         ↑________________________↓

After:  [Head] ⇄ [Node2] ⇄ [Last] ⇄ [New]
         ↑_________________________________↓
```

### Adding to Beginning
```
Before: [Old_Head] ⇄ [Node2] ⇄ [Last]
         ↑____________________________↓

After:  [New_Head] ⇄ [Old_Head] ⇄ [Node2] ⇄ [Last]
         ↑____________________________________________↓
```

## Implementation Details

### Node Creation
```c
List *new_node = malloc(sizeof(List));
new_node->str = strdup(str);  // Duplicate string
new_node->prev = new_node->next = NULL;
```

### Circular Linking (End Insertion)
```c
if (!head)  /* Empty list */
{
    new_node->next = new_node->prev = new_node;
    *list = new_node;
}
else  /* Existing list */
{
    last = head->prev;              /* Get last node */
    new_node->next = head;          /* New node points to head */
    last->next = new_node;          /* Old last points to new node */
    new_node->prev = last;          /* New node points back to old last */
    head->prev = new_node;          /* Head points back to new last */
}
```

## Memory Management

- **String duplication**: Uses `strdup()` to create independent copies
- **Dynamic allocation**: Each node is allocated with `malloc()`
- **Memory leak prevention**: Ensure proper cleanup with `free()` (not implemented in this file)

## Advantages of Circular Doubly Linked Lists

✅ **Bidirectional traversal**: Can move forward and backward  
✅ **No NULL checks in traversal**: Every node has valid `prev` and `next`  
✅ **Efficient end operations**: Direct access to last node via `head->prev`  
✅ **Circular iteration**: Natural support for round-robin algorithms  
✅ **Easy to insert/delete**: No special cases for head/tail (except head pointer update)

## Use Cases

- **Round-robin scheduling**: Process scheduling, task rotation
- **Music/video playlists**: Loop playback functionality
- **Buffer management**: Circular buffers for streaming data
- **Game development**: Turn-based systems, entity cycling
- **Navigation systems**: Circular menus, carousel interfaces

## Potential Improvements

- Add `free_list()` function to deallocate all nodes
- Implement `delete_node()` for removing nodes
- Add `get_node_at_index()` for position-based access
- Implement `list_size()` to count nodes
- Add `reverse_list()` to change direction
