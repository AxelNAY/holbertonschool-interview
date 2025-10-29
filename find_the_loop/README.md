# Find the Loop

## Description

This project implements Floyd's Cycle Detection Algorithm (also known as the "Tortoise and Hare" algorithm) to detect and find the starting point of a loop in a singly linked list. The algorithm uses two pointers moving at different speeds to efficiently detect cycles with O(n) time complexity and O(1) space complexity.

## Algorithm Overview

**Floyd's Cycle Detection Algorithm** works in two phases:

1. **Detection Phase**: Use two pointers (slow and fast) to detect if a loop exists
   - Slow pointer moves 1 step at a time
   - Fast pointer moves 2 steps at a time
   - If they meet, a loop exists

2. **Finding Start Phase**: Once a loop is detected, find where it begins
   - Reset slow pointer to head
   - Move both pointers 1 step at a time
   - Where they meet is the loop's starting node

**Time Complexity**: O(n)  
**Space Complexity**: O(1)  

## Mathematical Proof

When the pointers meet in the detection phase:
- Distance traveled by slow pointer: `d`
- Distance traveled by fast pointer: `2d`
- The difference `d` is a multiple of the loop length

Resetting slow to head and moving both at the same speed ensures they meet at the loop start.

## Files

| File | Description |
|------|-------------|
| `lists.h` | Header file with structure definition and function prototypes |
| `0-find_loop.c` | Implementation of Floyd's cycle detection algorithm |
| `0-main.c` | Test file with various loop scenarios |
| `lib.c` | Helper functions for list manipulation and safe printing |
| `README.md` | Project documentation |

## Data Structure
```c
typedef struct listint_s
{
    int n;                      /* Integer value stored in node */
    struct listint_s *next;     /* Pointer to next node */
} listint_t;
```

## Function Prototypes
```c
listint_t *find_listint_loop(listint_t *head);
```

### Main Function

**`find_listint_loop`**

Finds the node where a loop begins in a singly linked list.

**Parameters**:
- `head`: Pointer to the first node of the linked list

**Returns**:
- Pointer to the node where the loop starts
- `NULL` if there is no loop or if the list is empty

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
    0-main.c 0-find_loop.c lib.c -o find_loop
```

## Usage Example
```c
listint_t *head = NULL;
listint_t *node;

/* Create list: 1024 -> 402 -> 98 -> 7 -> ... */
node = add_nodeint(&head, 0);
add_nodeint(&head, 1);
add_nodeint(&head, 2);
node->next = add_nodeint(&head, 7);  /* Create loop here */
add_nodeint(&head, 98);
add_nodeint(&head, 402);
add_nodeint(&head, 1024);

/* Find loop start */
listint_t *loop_start = find_listint_loop(head);
if (loop_start != NULL)
{
    printf("Loop starts at [%p] %d\n", (void *)loop_start, loop_start->n);
}
```

## Expected Output
```
[0x1b43190] 1024
[0x1b43170] 402
[0x1b43150] 98
[0x1b43130] 7
[0x1b43110] 6
[0x1b430f0] 5
[0x1b430d0] 4
[0x1b430b0] 3
[0x1b43090] 2
[0x1b43070] 1
[0x1b43050] 0
-> [0x1b43130] 7
Loop starts at [0x1b43130] 7
```

## How It Works

### Phase 1: Loop Detection
```c
slow = head;
fast = head;

while (fast && fast->next)
{
    slow = slow->next;        /* Move 1 step */
    fast = fast->next->next;  /* Move 2 steps */
    
    if (slow == fast)         /* Loop detected! */
        break;
}
```

**Visual Example:**
```
List: 1 -> 2 -> 3 -> 4 -> 5
                ↑         ↓
                ← ← ← ← ← ←

Step 1: slow=1, fast=1
Step 2: slow=2, fast=3
Step 3: slow=3, fast=5
Step 4: slow=4, fast=4  ← They meet!
```

### Phase 2: Finding Loop Start
```c
if (slow == fast)  /* Loop detected */
{
    slow = head;   /* Reset slow to head */
    
    while (slow != fast)
    {
        slow = slow->next;  /* Both move 1 step */
        fast = fast->next;
    }
    
    return slow;  /* This is the loop start */
}
```

**Visual Example:**
```
After detection, reset slow to head:
slow=1, fast=4

Step 1: slow=2, fast=5
Step 2: slow=3, fast=3  ← They meet at loop start!
```

## Edge Cases

| Case | Behavior |
|------|----------|
| Empty list (`head == NULL`) | Returns `NULL` |
| Single node, no loop | Returns `NULL` |
| Single node pointing to itself | Detects loop, returns the node |
| List with no loop | Returns `NULL` |
| Loop at head | Returns head |
| Loop in middle | Returns loop start node |

## Algorithm Visualization

### No Loop
```
1 -> 2 -> 3 -> 4 -> NULL

Slow and fast will never meet
Return: NULL
```

### Loop at Node 3
```
1 -> 2 -> 3 -> 4 -> 5
          ↑         ↓
          ← ← ← ← ← ←

Detection: Pointers meet inside loop
Find Start: Both converge at node 3
Return: Node 3
```

### Complete Loop
```
1 -> 2 -> 3 -> 4
↑              ↓
← ← ← ← ← ← ← ←

Detection: Pointers meet
Find Start: Both converge at node 1 (head)
Return: Node 1
```

## Why This Works

**Mathematical Principle:**

Let:
- `L` = distance from head to loop start
- `K` = distance from loop start to meeting point
- `C` = loop circumference

When they meet:
- Slow traveled: `L + K`
- Fast traveled: `L + K + nC` (where n is number of complete loops)

Since fast is 2× faster: `2(L + K) = L + K + nC`

Simplifying: `L = nC - K`

This means the distance from head to loop start equals the distance from meeting point to loop start (traveling forward through the loop).

## Helper Functions (lib.c)

- **`add_nodeint`**: Adds node at beginning of list
- **`print_listint_safe`**: Prints list safely, detecting loops
- **`free_listint_safe`**: Frees list memory safely, handling loops
- **`_find_in_list`**: Helper to track visited nodes

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Loop Detection | O(n) | O(1) |
| Find Loop Start | O(n) | O(1) |
| Overall | O(n) | O(1) |

Where `n` is the number of nodes in the list.

## Advantages

✅ **Constant space**: No additional data structures needed  
✅ **Single pass**: Detects and finds loop in one traversal  
✅ **Elegant solution**: Based on mathematical properties  
✅ **No modification**: Doesn't alter the list structure  
✅ **Efficient**: Linear time complexity  

## Common Applications

- **Memory leak detection**: Finding circular references
- **Cycle detection in graphs**: General cycle detection algorithms
- **Debugging**: Identifying infinite loops in data structures
- **Network routing**: Detecting routing loops
- **Compiler optimization**: Loop detection in control flow

## Alternative Approaches

1. **Hash Table Method**: O(n) time, O(n) space - store visited nodes
2. **Flag/Marking Method**: O(n) time, O(1) space - requires modifying nodes
3. **Floyd's Algorithm**: O(n) time, O(1) space - **optimal solution** ✓
