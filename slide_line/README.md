# Slide Line

A C implementation that reproduces the 2048 game mechanics on a single horizontal line, allowing elements to slide and merge in either direction.

## Description

This project implements the core sliding and merging logic from the popular 2048 puzzle game. Given an array of integers representing a single line, the program can slide all non-zero elements to either the left or right, merging identical adjacent values in the process.

## Features

- **Bidirectional sliding**: Support for both left (`L`) and right (`R`) directions
- **Element merging**: Identical adjacent elements are combined (like in 2048)
- **Zero handling**: Non-zero elements slide past zeros
- **Single merge rule**: Each element can only be merged once per operation

## Files Structure

```
.
├── 0-main.c           # Main program with command-line interface
├── 0-slide_line.c     # Core sliding and merging implementation
├── slide_line.h       # Header file with function declarations and constants
└── README.md          # This file
```

## Compilation

Compile the program using gcc:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-slide_line.c -o slide_line
```

## Usage

```bash
./slide_line <DIRECTION> <n1> [n2] [n3] ...
```

### Parameters

- `DIRECTION`: Either `L` (slide left) or `R` (slide right)
- `n1, n2, n3, ...`: Integer values for the line (up to 32 elements)

### Examples

**Sliding left:**
```bash
./slide_line L 2 2 0 0
```
Output:
```
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
```

**Sliding right:**
```bash
./slide_line R 2 0 0 2
```
Output:
```
Line: 2, 0, 0, 2
Slide to the right
Line: 0, 0, 0, 4
```

**Complex example:**
```bash
./slide_line L 2 2 4 8 8
```
Output:
```
Line: 2, 2, 4, 8, 8
Slide to the left
Line: 4, 4, 16, 0, 0
```

## Algorithm Logic

### Sliding Left (SLIDE_LEFT = 0)
1. Iterate through the array from left to right
2. For each non-zero element:
   - If it matches the previous processed element and hasn't been merged, combine them
   - Otherwise, place it in the next available position on the left
3. Fill remaining positions with zeros

### Sliding Right (SLIDE_RIGHT = 1)
1. Iterate through the array from right to left
2. For each non-zero element:
   - If it matches the previous processed element and hasn't been merged, combine them
   - Otherwise, place it in the next available position on the right
3. Fill remaining positions with zeros

## Function Reference

### `slide_line`
```c
int slide_line(int *line, size_t size, int direction);
```

**Parameters:**
- `line`: Pointer to array of integers to be modified
- `size`: Number of elements in the array
- `direction`: `SLIDE_LEFT` (0) or `SLIDE_RIGHT` (1)

**Returns:**
- `1` on success
- `0` on failure (invalid direction)

**Behavior:**
- Modifies the input array in-place
- Slides all non-zero elements in the specified direction
- Merges identical adjacent elements (following 2048 rules)
- Each element can only participate in one merge per operation

## Constants

- `SLIDE_LEFT`: Defined as `0` - slides elements toward index 0
- `SLIDE_RIGHT`: Defined as `1` - slides elements toward the highest index
- `LINE_SIZE`: Maximum supported line size (32 elements)

## Error Handling

The program handles several error conditions:

- **Invalid direction**: Returns 0 if direction is not `SLIDE_LEFT` or `SLIDE_RIGHT`
- **Insufficient arguments**: Displays usage message if fewer than 3 arguments provided
- **Invalid direction character**: Shows error if direction is not 'L' or 'R'

## Limitations

- Maximum line size is 32 elements
- Only works with integer values
- Elements can only merge once per operation (2048 game rule)

## Example Scenarios

### Merging identical values
```bash
# Input: [2, 2, 2, 2] sliding left
# Output: [4, 4, 0, 0]
./slide_line L 2 2 2 2
```

### No merging possible
```bash
# Input: [2, 4, 8, 16] sliding left
# Output: [2, 4, 8, 16] (no change)
./slide_line L 2 4 8 16
```

### Sliding with zeros
```bash
# Input: [0, 2, 0, 2] sliding right
# Output: [0, 0, 2, 2]
./slide_line R 0 2 0 2
```

## Technical Notes

- The implementation uses in-place array modification for memory efficiency
- Merge detection prevents double-merging in a single operation
- The algorithm maintains the relative order of non-mergeable elements

## License

This project is part of a programming exercise implementing 2048 game mechanics.
