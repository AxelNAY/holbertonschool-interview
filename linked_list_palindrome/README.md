# Linked List Palindrome

## Description
This project implements a function to check if a singly linked list is a palindrome in C. A palindrome is a sequence that reads the same forward and backward.

## Project Structure

```
linked_list_palindrome/
├── 0-is_palindrome.c    # Main implementation
├── 0-main.c            # Test file
├── linked_lists.c      # Utility functions
├── lists.h            # Header file
└── README.md          # This file
```

## Algorithm

The palindrome check uses an efficient approach with O(n) time complexity and O(1) extra space:

1. **Find the middle**: Use the "tortoise and hare" technique with two pointers (slow and fast) to find the middle of the linked list
2. **Reverse the second half**: Reverse the second half of the linked list starting from the middle
3. **Compare**: Compare the first half with the reversed second half node by node
4. **Restore**: Reverse the second half back to its original state to maintain list integrity
5. **Return result**: Return 1 if palindrome, 0 otherwise

## Functions

### `int is_palindrome(listint_t **head)`
- **Purpose**: Checks if a singly linked list is a palindrome
- **Parameters**: Double pointer to the head of the linked list
- **Return**: 1 if the list is a palindrome, 0 otherwise
- **Edge cases**: Empty list, single node, or two-node lists are considered palindromes

### `listint_t *reverse_list(listint_t *head)`
- **Purpose**: Reverses a singly linked list
- **Parameters**: Pointer to the head of the list to reverse
- **Return**: Pointer to the new head of the reversed list

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

## Usage

```bash
./palindrome
```

## Example

The test case in `0-main.c` creates a palindromic linked list:
```
1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1
```

Expected output:
```
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

## Time and Space Complexity

- **Time Complexity**: O(n) - where n is the number of nodes in the linked list
- **Space Complexity**: O(1) - constant extra space (not counting the input)

## Key Features

- Non-destructive: The original linked list structure is preserved
- Memory efficient: Uses constant extra space
- Handles edge cases: Empty lists, single nodes, and even/odd length lists
- Proper memory management: No memory leaks

## Author

This implementation follows the Holberton School coding standards and best practices for C programming.