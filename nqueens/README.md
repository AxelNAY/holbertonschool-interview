# N Queens Problem

## Description

This project implements a solution to the classic **N Queens problem** using backtracking. The N Queens puzzle challenges you to place N chess queens on an N×N chessboard such that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.

## Problem Statement

Given an integer N (where N ≥ 4):
- Place N queens on an N×N chessboard
- No two queens can attack each other
- Find and print all possible solutions

### Queen Attack Rules

A queen can attack another piece if they share:
- The same **row** (horizontal)
- The same **column** (vertical)  
- The same **diagonal** (both directions)

## Algorithm Overview

The solution uses **Backtracking**:

1. Start with an empty board (row 0)
2. For each column in the current row:
   - Check if placing a queen is safe
   - If safe, place the queen and move to the next row
   - Recursively try to place queens in remaining rows
   - If successful, record the solution
   - Backtrack (remove queen) and try next column
3. Continue until all possibilities are explored

**Time Complexity**: O(N!) in worst case  
**Space Complexity**: O(N) for recursion stack and position tracking

## Files

| File | Description |
|------|-------------|
| `0-nqueens.py` | Complete implementation of N Queens solver |
| `README.md` | Project documentation |

## Function Descriptions

### `is_safe(positions, row, col)`

Checks if placing a queen at the given position is safe.

**Parameters**:
- `positions` (list): Current queen positions as [[row, col], ...]
- `row` (int): Row to check
- `col` (int): Column to check

**Returns**:
- `True` if position is safe
- `False` if position conflicts with existing queens

**Checks**:
- Same row or column
- Same diagonal (slope = ±1)

### `solve_nqueens(n, positions, row)`

Recursive backtracking function to find all solutions.

**Parameters**:
- `n` (int): Board size (N×N)
- `positions` (list): Current queen positions
- `row` (int): Current row being processed

**Behavior**:
- Base case: If row == n, solution found (print it)
- Recursive case: Try placing queen in each column, recurse, backtrack

### `main()`

Entry point that validates input and initiates the solver.

**Validates**:
- Exactly one command-line argument
- Argument is an integer
- N ≥ 4

## Usage
```bash
./0-nqueens.py N
```

Where `N` is the size of the chessboard (N ≥ 4).

### Make Executable
```bash
chmod +x 0-nqueens.py
```

## Examples

### Example 1: 4 Queens
```bash
./0-nqueens.py 4
```

**Output:**
```
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

**Visual representation of solutions:**

**Solution 1:**
```
. Q . .     Row 0: Queen at column 1
. . . Q     Row 1: Queen at column 3
Q . . .     Row 2: Queen at column 0
. . Q .     Row 3: Queen at column 2
```

**Solution 2:**
```
. . Q .     Row 0: Queen at column 2
Q . . .     Row 1: Queen at column 0
. . . Q     Row 2: Queen at column 3
. Q . .     Row 3: Queen at column 1
```

### Example 2: 6 Queens
```bash
./0-nqueens.py 6
```

**Output:** (4 solutions)
```
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
```

### Example 3: 8 Queens (Classic)
```bash
./0-nqueens.py 8
```

**Output:** 92 different solutions

## Error Handling

### Wrong Number of Arguments
```bash
./0-nqueens.py
```
**Output:**
```
Usage: nqueens N
```
**Exit code:** 1

### Non-Integer Input
```bash
./0-nqueens.py abc
```
**Output:**
```
N must be a number
```
**Exit code:** 1

### N Less Than 4
```bash
./0-nqueens.py 3
```
**Output:**
```
N must be at least 4
```
**Exit code:** 1

## How It Works

### Backtracking Algorithm
```python
def solve_nqueens(n, positions, row):
    # Base case: All queens placed
    if row == n:
        print(positions[:])
        return
    
    # Try each column in current row
    for col in range(n):
        if is_safe(positions, row, col):
            positions.append([row, col])      # Place queen
            solve_nqueens(n, positions, row + 1)  # Recurse to next row
            positions.pop()                   # Backtrack (remove queen)
```

### Safety Check Logic
```python
def is_safe(positions, row, col):
    for queen_row, queen_col in positions:
        # Check same row (shouldn't happen with our algorithm)
        if queen_row == row:
            return False
        
        # Check same column
        if queen_col == col:
            return False
        
        # Check diagonals
        # If |row_diff| == |col_diff|, they're on same diagonal
        if abs(queen_row - row) == abs(queen_col - col):
            return False
    
    return True
```

### Diagonal Check Explanation

Two queens at `(r1, c1)` and `(r2, c2)` are on the same diagonal if:
- `|r1 - r2| == |c1 - c2|` (slope = ±1)

**Examples:**
```
(0,0) and (1,1): |0-1| = 1, |0-1| = 1 → Same diagonal ✓
(0,3) and (2,1): |0-2| = 2, |3-1| = 2 → Same diagonal ✓
(0,0) and (1,2): |0-1| = 1, |0-2| = 2 → Different diagonals ✗
```

## Visual Step-by-Step Example (N=4)

### Recursion Tree
```
Start: Row 0, try columns 0-3

Row 0, Col 0: [0,0]
  ├─ Row 1, Col 0: X (same column)
  ├─ Row 1, Col 1: X (diagonal)
  ├─ Row 1, Col 2: [0,0][1,2]
  │   ├─ Row 2, Col 0: X (diagonal)
  │   ├─ Row 2, Col 1: X (same column as row 0)
  │   ├─ Row 2, Col 2: X (same column)
  │   └─ Row 2, Col 3: X (diagonal)
  │   BACKTRACK
  └─ Row 1, Col 3: [0,0][1,3]
      └─ Row 2, Col 1: [0,0][1,3][2,1]
          └─ Row 3, Col 0: X (diagonal)
          └─ Row 3, Col 1: X (same column)
          └─ Row 3, Col 2: X (diagonal)
          └─ Row 3, Col 3: X (diagonal)
          BACKTRACK

Row 0, Col 1: [0,1]
  ├─ Row 1, Col 3: [0,1][1,3]
      ├─ Row 2, Col 0: [0,1][1,3][2,0]
          └─ Row 3, Col 2: [0,1][1,3][2,0][3,2] ✓ SOLUTION!
          
Continue exploring...
```

## Number of Solutions by N

| N | Solutions |
|---|-----------|
| 4 | 2 |
| 5 | 10 |
| 6 | 4 |
| 7 | 40 |
| 8 | 92 |
| 9 | 352 |
| 10 | 724 |
| 11 | 2,680 |
| 12 | 14,200 |

Note: The pattern is not simple; solutions don't increase monotonically.

## Complexity Analysis

### Time Complexity

**Worst case**: O(N!)
- At row 1: N choices
- At row 2: ~(N-1) choices
- At row 3: ~(N-2) choices
- Total: N × (N-1) × (N-2) × ... ≈ N!

**Average case**: Much better due to pruning from constraint checking

### Space Complexity

**O(N)** for:
- Recursion stack: N levels deep
- Positions list: Stores N queen positions

## Optimizations (Not Implemented)

### Bitmask Approach
```python
# Use bit operations for faster conflict checking
# Track columns, diagonals using integers
```

### Symmetry Reduction
```python
# Only search half the board, mirror solutions
# Reduces search space by 2x for symmetric boards
```

### Heuristic Ordering
```python
# Try most constrained columns first
# Fails faster, reduces backtracking
```

## Backtracking Pattern

The general backtracking template:
```python
def backtrack(state):
    if is_solution(state):
        record_solution(state)
        return
    
    for choice in get_choices(state):
        if is_valid(choice):
            make_choice(choice)
            backtrack(new_state)
            undo_choice(choice)  # Backtrack
```

Applied to N Queens:
- **State**: Current row and queen positions
- **Choices**: Columns in current row
- **Valid**: No conflicts with existing queens
- **Make choice**: Add queen to positions
- **Undo**: Remove queen from positions

## Why N Must Be ≥ 4?

- **N = 1**: Trivial (one queen, one solution)
- **N = 2**: Impossible (2×2 board, queens always attack)
- **N = 3**: Impossible (3×3 board, no valid placement)
- **N ≥ 4**: Always has at least one solution

## Testing Recommendations
```bash
# Valid inputs
./0-nqueens.py 4    # Smallest valid case
./0-nqueens.py 8    # Classic 8-queens
./0-nqueens.py 10   # Larger board

# Invalid inputs
./0-nqueens.py      # Missing argument
./0-nqueens.py 4 5  # Too many arguments
./0-nqueens.py abc  # Non-integer
./0-nqueens.py 3    # Too small
./0-nqueens.py -5   # Negative number
```

## Related Problems

- **N Queens Completion**: Place remaining queens on partially filled board
- **N Queens Count**: Count solutions without printing them
- **Peaceful Queens**: Allow queens on same diagonal
- **Super Queens**: Queens can also move as knights
- **3D Queens**: Queens on a 3D board

## Real-World Applications

- **Constraint satisfaction problems**: Resource allocation, scheduling
- **VLSI design**: Component placement without interference
- **Parallel processing**: Task assignment to processors
- **Network routing**: Conflict-free path assignment
- **Genetic algorithms**: Benchmarking optimization techniques

## Advantages of Backtracking

✅ **Complete**: Finds all solutions  
✅ **Optimal**: No unnecessary exploration  
✅ **Simple**: Clear recursive structure  
✅ **Flexible**: Easy to modify constraints  
✅ **Guaranteed**: Will find solution if one exists  

## Common Mistakes to Avoid

❌ **Not checking diagonals**: Rows and columns aren't enough  
❌ **Modifying shared state**: Use list copies when needed  
❌ **Forgetting to backtrack**: Must remove queens after exploring  
❌ **Inefficient diagonal check**: Absolute value trick is elegant  
❌ **Printing mutable list**: Use `positions[:]` to copy  

## Performance Notes

For large N (N > 12):
- Runtime increases dramatically
- Consider using optimization techniques
- Parallel processing can help
- Not practical for N > 20 without advanced methods

## Author

Project implementation for understanding backtracking algorithms and constraint satisfaction problems through the classic N Queens puzzle.
