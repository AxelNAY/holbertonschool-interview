# Rotate 2D Matrix

## Description

This project implements an in-place algorithm to rotate an n×n 2D matrix by 90 degrees clockwise. The rotation is performed without using extra space for another matrix, making it a space-efficient solution commonly asked in technical interviews.

## Problem Statement

Given an n×n 2D matrix, rotate it 90 degrees clockwise **in-place**. The function must modify the input matrix directly without creating a new matrix.

### Visual Example
```
Original Matrix:        Rotated 90° Clockwise:
[1, 2, 3]              [7, 4, 1]
[4, 5, 6]       →      [8, 5, 2]
[7, 8, 9]              [9, 6, 3]
```

## Algorithm Overview

The algorithm uses a **two-step approach**:

1. **Transpose the matrix**: Swap elements across the main diagonal
2. **Reverse each row**: Flip elements horizontally

**Time Complexity**: O(n²) - must visit each element  
**Space Complexity**: O(1) - in-place rotation, no extra matrix

## Files

| File | Description |
|------|-------------|
| `0-rotate_2d_matrix.py` | Implementation of matrix rotation function |
| `main_0.py` | Test file demonstrating the rotation |
| `README.md` | Project documentation |

## Function Prototype
```python
def rotate_2d_matrix(matrix):
    """
    Rotate an n x n 2D matrix 90 degrees clockwise in-place.
    
    Args:
        matrix (list of lists): n×n 2D matrix to rotate
        
    Returns:
        None - modifies the matrix in-place
    """
```

## Usage

### Basic Usage
```python
#!/usr/bin/python3
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

rotate_2d_matrix(matrix)
print(matrix)
```

### Run Test File
```bash
chmod +x main_0.py
./main_0.py
```

## Expected Output
```
[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
```

## How It Works

### Step 1: Transpose the Matrix

**Transpose** means swapping elements across the main diagonal (top-left to bottom-right).
```python
for i in range(n):
    for j in range(i + 1, n):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```

**Example:**
```
Original:           After Transpose:
[1, 2, 3]          [1, 4, 7]
[4, 5, 6]    →     [2, 5, 8]
[7, 8, 9]          [3, 6, 9]
```

**What happens:**
- `matrix[0][1]` ↔ `matrix[1][0]`: 2 ↔ 4
- `matrix[0][2]` ↔ `matrix[2][0]`: 3 ↔ 7
- `matrix[1][2]` ↔ `matrix[2][1]`: 6 ↔ 8
- Diagonal elements (1, 5, 9) stay in place

### Step 2: Reverse Each Row

**Reverse** each row to complete the 90° clockwise rotation.
```python
for row in matrix:
    row.reverse()
```

**Example:**
```
After Transpose:    After Reversing Rows:
[1, 4, 7]          [7, 4, 1]
[2, 5, 8]    →     [8, 5, 2]
[3, 6, 9]          [9, 6, 3]
```

**What happens:**
- Row 0: [1, 4, 7] → [7, 4, 1]
- Row 1: [2, 5, 8] → [8, 5, 2]
- Row 2: [3, 6, 9] → [9, 6, 3]

## Visual Step-by-Step Example

### Example: 3×3 Matrix
```
Original Matrix:
     col0 col1 col2
row0 [ 1,  2,  3 ]
row1 [ 4,  5,  6 ]
row2 [ 7,  8,  9 ]

Step 1: Transpose (swap across diagonal)
Swaps performed:
  (0,1) ↔ (1,0): 2 ↔ 4
  (0,2) ↔ (2,0): 3 ↔ 7
  (1,2) ↔ (2,1): 6 ↔ 8

After transpose:
     col0 col1 col2
row0 [ 1,  4,  7 ]
row1 [ 2,  5,  8 ]
row2 [ 3,  6,  9 ]

Step 2: Reverse each row
Row 0: [1, 4, 7] → [7, 4, 1]
Row 1: [2, 5, 8] → [8, 5, 2]
Row 2: [3, 6, 9] → [9, 6, 3]

Final Result (90° clockwise):
     col0 col1 col2
row0 [ 7,  4,  1 ]
row1 [ 8,  5,  2 ]
row2 [ 9,  6,  3 ]
```

### Example: 4×4 Matrix
```
Original:              Transpose:            Reverse Rows:
[ 1,  2,  3,  4]      [ 1,  5,  9, 13]      [13,  9,  5,  1]
[ 5,  6,  7,  8]  →   [ 2,  6, 10, 14]  →   [14, 10,  6,  2]
[ 9, 10, 11, 12]      [ 3,  7, 11, 15]      [15, 11,  7,  3]
[13, 14, 15, 16]      [ 4,  8, 12, 16]      [16, 12,  8,  4]
```

## Why This Works

### Mathematical Explanation

For a 90° clockwise rotation:
- Element at position `(i, j)` moves to position `(j, n-1-i)`

**Direct approach (not in-place):**
```python
rotated[j][n-1-i] = matrix[i][j]
```

**Two-step approach (in-place):**
1. **Transpose**: `(i, j)` → `(j, i)`
2. **Reverse rows**: `(j, i)` → `(j, n-1-i)`

Combined: `(i, j)` → `(j, i)` → `(j, n-1-i)` ✓

### Visualization
```
Original (i,j):     Transpose (j,i):    Reverse (j,n-1-i):
(0,0) (0,1) (0,2)   (0,0) (1,0) (2,0)   (0,2) (1,2) (2,2)
(1,0) (1,1) (1,2) → (0,1) (1,1) (2,1) → (0,1) (1,1) (2,1)
(2,0) (2,1) (2,2)   (0,2) (1,2) (2,2)   (0,0) (1,0) (2,0)

Which is the correct 90° clockwise rotation!
```

## Implementation Details

### Transpose Loop Optimization
```python
for i in range(n):
    for j in range(i + 1, n):  # Note: j starts at i+1
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```

**Why `j = i + 1`?**
- Avoids swapping diagonal elements with themselves
- Avoids swapping the same pair twice
- Only processes upper triangle of matrix

**Pairs swapped for 3×3 matrix:**
```
i=0: j=1,2 → swap (0,1)↔(1,0), (0,2)↔(2,0)
i=1: j=2   → swap (1,2)↔(2,1)
i=2: (no j values)
```

### In-Place Row Reversal
```python
for row in matrix:
    row.reverse()
```

Python's `list.reverse()` method reverses the list in-place with O(n) time and O(1) space.

## Edge Cases

| Case | Matrix | Result | Notes |
|------|--------|--------|-------|
| 1×1 | `[[1]]` | `[[1]]` | No change |
| 2×2 | `[[1,2],[3,4]]` | `[[3,1],[4,2]]` | Simple rotation |
| Empty | `[]` | `[]` | Edge case (not typical) |
| Single row | `[[1,2,3]]` | Invalid | Must be n×n |

## Example Test Cases

### Test Case 1: 2×2 Matrix
```python
matrix = [[1, 2],
          [3, 4]]

rotate_2d_matrix(matrix)
# Result: [[3, 1], [4, 2]]
```
```
[1, 2]      [3, 1]
[3, 4]  →   [4, 2]
```

### Test Case 2: 4×4 Matrix
```python
matrix = [[1, 2, 3, 4],
          [5, 6, 7, 8],
          [9, 10, 11, 12],
          [13, 14, 15, 16]]

rotate_2d_matrix(matrix)
# Result: [[13, 9, 5, 1], [14, 10, 6, 2], [15, 11, 7, 3], [16, 12, 8, 4]]
```

### Test Case 3: Single Element
```python
matrix = [[42]]

rotate_2d_matrix(matrix)
# Result: [[42]]
```

## Complexity Analysis

### Time Complexity

**O(n²)** where n is the dimension of the matrix

- **Transpose**: O(n²/2) ≈ O(n²) - swap half the elements
- **Reverse rows**: O(n²) - reverse n rows of n elements each
- **Total**: O(n²)

### Space Complexity

**O(1)** - constant extra space

- No additional matrix created
- Only uses a few temporary variables for swapping
- All operations are in-place

### Detailed Analysis

For an n×n matrix:
- **Transpose swaps**: n(n-1)/2 swaps
- **Reverse operations**: n reversals of n elements
- **Total operations**: ~n²

## Alternative Rotation Directions

### Rotate 90° Counter-Clockwise
```python
def rotate_ccw(matrix):
    n = len(matrix)
    
    # Reverse each row first
    for row in matrix:
        row.reverse()
    
    # Then transpose
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```

**Order matters**: Reverse first, then transpose (opposite of clockwise)

### Rotate 180°
```python
def rotate_180(matrix):
    # Method 1: Rotate 90° twice
    rotate_2d_matrix(matrix)
    rotate_2d_matrix(matrix)
    
    # Method 2: Reverse entire matrix
    matrix.reverse()
    for row in matrix:
        row.reverse()
```

### Rotate 270° Clockwise (= 90° Counter-Clockwise)
```python
def rotate_270(matrix):
    # Rotate 90° three times
    for _ in range(3):
        rotate_2d_matrix(matrix)
```

## Non-In-Place Solution

If space is not a constraint:
```python
def rotate_2d_matrix_copy(matrix):
    n = len(matrix)
    rotated = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            rotated[j][n-1-i] = matrix[i][j]
    
    return rotated
```

**Pros**: Simpler logic, clearer formula  
**Cons**: Uses O(n²) extra space

## Use Cases

- **Image processing**: Rotating images 90 degrees
- **Game development**: Board game rotations (chess, Rubik's cube)
- **Computer graphics**: Texture and sprite manipulation
- **Data transformation**: Matrix operations in linear algebra
- **Interview questions**: Common coding challenge
- **Puzzle solving**: Tetris-like rotations

## Common Mistakes to Avoid

❌ **Swapping all pairs**: Must start j at `i+1`, not 0  
❌ **Not reversing in-place**: Creating new rows instead of reversing  
❌ **Wrong rotation direction**: Transpose + reverse = clockwise, reverse + transpose = counter-clockwise  
❌ **Modifying while iterating**: Be careful with indices during in-place operations  
❌ **Assuming rectangular**: Algorithm only works for n×n matrices  

## Testing Strategy
```python
def test_rotation():
    # Test 1: 3x3 matrix
    matrix1 = [[1, 2, 3],
               [4, 5, 6],
               [7, 8, 9]]
    rotate_2d_matrix(matrix1)
    assert matrix1 == [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
    
    # Test 2: 2x2 matrix
    matrix2 = [[1, 2],
               [3, 4]]
    rotate_2d_matrix(matrix2)
    assert matrix2 == [[3, 1], [4, 2]]
    
    # Test 3: 1x1 matrix
    matrix3 = [[42]]
    rotate_2d_matrix(matrix3)
    assert matrix3 == [[42]]
    
    # Test 4: 4x4 matrix
    matrix4 = [[1, 2, 3, 4],
               [5, 6, 7, 8],
               [9, 10, 11, 12],
               [13, 14, 15, 16]]
    rotate_2d_matrix(matrix4)
    assert matrix4 == [[13, 9, 5, 1],
                       [14, 10, 6, 2],
                       [15, 11, 7, 3],
                       [16, 12, 8, 4]]
    
    print("All tests passed! ✓")

test_rotation()
```

## Related Problems

- **Rotate Image**: Same problem with image data
- **Spiral Matrix**: Traverse matrix in spiral order
- **Matrix Transpose**: First step of this algorithm
- **Flip Image**: Horizontal/vertical flipping
- **Diagonal Traverse**: Traverse matrix diagonally

## Optimization Notes

- **Cache efficiency**: Good - sequential row access
- **Branch prediction**: Excellent - predictable patterns
- **Parallelization**: Can parallelize row reversals
- **SIMD**: Row reversal can use SIMD instructions

## Mathematical Properties

### Rotation Composition

- 90° + 90° = 180°
- 90° × 3 = 270° (= -90°)
- 90° × 4 = 360° (= 0°, identity)

### Inverse Operation

- Rotate 90° clockwise = Rotate 270° counter-clockwise
- To undo a 90° clockwise rotation, rotate 270° clockwise (or 90° counter-clockwise)

## Author

Project implementation for understanding in-place matrix manipulation, transpose operations, and efficient 2D array rotations commonly used in image processing and computer graphics.
