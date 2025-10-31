# Island Perimeter

## Description

This project implements a function to calculate the perimeter of an island represented in a 2D grid. The grid uses `1` to represent land cells and `0` to represent water cells. The perimeter is calculated by counting all the exposed edges of land cells (edges that border water or the grid boundary).

## Problem Overview

Given a rectangular grid where:
- `0` represents water
- `1` represents land
- Cells are connected horizontally/vertically (not diagonally)
- The grid is completely surrounded by water
- There is exactly one island (or no island)
- The island doesn't have "lakes" (water inside that isn't connected to the water around the island)

Calculate the **perimeter** of the island.

## Algorithm Overview

The solution iterates through each cell in the grid and for every land cell (`1`), it checks all four sides (up, down, left, right):
- If a side faces water (`0`) or the grid boundary, it contributes 1 to the perimeter
- If a side faces another land cell, it contributes 0 to the perimeter

**Time Complexity**: O(n × m) where n and m are the grid dimensions  
**Space Complexity**: O(1) - only uses a counter variable

## Files

| File | Description |
|------|-------------|
| `0-island_perimeter.py` | Implementation of the island perimeter function |
| `0-main.py` | Test file with example grid |
| `README.md` | Project documentation |

## Function Prototype
```python
def island_perimeter(grid):
    """Returns the perimeter of the island described in grid
    
    Args:
        grid (list of list of int): 2D grid where 0=water, 1=land
        
    Returns:
        int: The perimeter of the island
    """
```

## Usage

### Import and Call
```python
#!/usr/bin/python3
island_perimeter = __import__('0-island_perimeter').island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 0, 0]
]

print(island_perimeter(grid))  # Output: 18
```

### Run Example
```bash
chmod +x 0-main.py
./0-main.py
```

## Expected Output
```
18
```

## How It Works

### Visual Example

**Input Grid:**
```
[0, 0, 0, 0, 0, 0]
[0, 1, 1, 1, 0, 0]
[0, 1, 1, 1, 0, 0]
[0, 1, 1, 1, 0, 0]
```

**Visual Representation:**
```
~ ~ ~ ~ ~ ~
~ L L L ~ ~
~ L L L ~ ~
~ L L L ~ ~

Where: ~ = water (0), L = land (1)
```

**Perimeter Calculation:**

For each land cell, count exposed edges:
```
Position (1,1): Top=1, Left=1, Right=0, Bottom=0 → 2 edges
Position (1,2): Top=1, Left=0, Right=0, Bottom=0 → 1 edge
Position (1,3): Top=1, Left=0, Right=1, Bottom=0 → 2 edges
Position (2,1): Top=0, Left=1, Right=0, Bottom=0 → 1 edge
Position (2,2): Top=0, Left=0, Right=0, Bottom=0 → 0 edges
Position (2,3): Top=0, Left=0, Right=1, Bottom=0 → 1 edge
Position (3,1): Top=0, Left=1, Right=0, Bottom=1 → 2 edges
Position (3,2): Top=0, Left=0, Right=0, Bottom=1 → 1 edge
Position (3,3): Top=0, Left=0, Right=1, Bottom=1 → 2 edges

Total perimeter = 2+1+2+1+0+1+2+1+2 = 18
```

**Edge Visualization:**
```
    1  1  1
  +--+--+--+
1 |  |  |  | 1
  +--+--+--+
1 |  |  |  | 1
  +--+--+--+
1 |  |  |  | 1
  +--+--+--+
    1  1  1

Perimeter = 3 + 3 + 3 + 3 + 3 + 3 = 18
```

### Algorithm Step-by-Step
```python
for each row i in grid:
    for each column j in row:
        if grid[i][j] == 1:  # Land cell found
            
            # Check top edge
            if i == 0 or grid[i-1][j] == 0:
                count += 1
            
            # Check bottom edge
            if i == n-1 or grid[i+1][j] == 0:
                count += 1
            
            # Check left edge
            if j == 0 or grid[i][j-1] == 0:
                count += 1
            
            # Check right edge
            if j == m-1 or grid[i][j+1] == 0:
                count += 1
```

## Edge Cases

| Case | Grid Example | Perimeter | Explanation |
|------|-------------|-----------|-------------|
| Empty grid | `[]` | `0` | No land cells |
| No island | `[[0, 0], [0, 0]]` | `0` | All water |
| Single cell | `[[1]]` | `4` | All four sides exposed |
| Full row | `[[1, 1, 1]]` | `8` | Top + bottom + 2 ends |
| Full grid | `[[1, 1], [1, 1]]` | `8` | Only outer edges |
| L-shape | `[[1, 0], [1, 1]]` | `10` | Complex shape |

## Example Calculations

### Example 1: Single Cell
```python
grid = [[1]]
# Perimeter = 4 (all sides exposed)
```
```
+--+
|  |
+--+
Edges: top=1, bottom=1, left=1, right=1 = 4
```

### Example 2: Horizontal Line
```python
grid = [[1, 1, 1, 1]]
# Perimeter = 10
```
```
+--+--+--+--+
|           |
+--+--+--+--+
Edges: top=4, bottom=4, left=1, right=1 = 10
```

### Example 3: Square
```python
grid = [
    [1, 1],
    [1, 1]
]
# Perimeter = 8
```
```
+--+--+
|     |
+--+--+
|     |
+--+--+
Edges: 2+2+2+2 = 8
```

### Example 4: Complex Shape
```python
grid = [
    [0, 1, 0, 0],
    [1, 1, 1, 0],
    [0, 1, 0, 0],
    [1, 1, 0, 0]
]
# Perimeter = 16
```
```
  +--+
  |  |
+--+--+--+
|        |
+--+--+--+
   |  |
+--+--+
|     |
+--+--+

Count each exposed edge
```

## Implementation Details

### Boundary Checking
```python
# Top edge
if i == 0 or grid[i-1][j] == 0:
    count += 1
```
- `i == 0`: At top boundary
- `grid[i-1][j] == 0`: Cell above is water

### Avoiding Index Out of Bounds

The condition `i == 0` prevents accessing `grid[-1][j]` which would incorrectly wrap around in Python. Similarly for other boundaries.

## Complexity Analysis

| Operation | Complexity |
|-----------|-----------|
| Iterate through grid | O(n × m) |
| Check each direction | O(1) per cell |
| **Total Time** | **O(n × m)** |
| **Space** | **O(1)** |

Where:
- `n` = number of rows
- `m` = number of columns

## Advantages

✅ **Simple and intuitive**: Easy to understand logic  
✅ **Single pass**: Only needs to traverse grid once  
✅ **Constant space**: No additional data structures needed  
✅ **No recursion**: Avoids stack overflow for large grids  
✅ **Handles all edge cases**: Works for any valid grid configuration  

## Alternative Approaches

### Approach 1: Count Islands, Then Calculate
```python
perimeter = (number_of_land_cells × 4) - (number_of_shared_edges × 2)
```
- Requires two passes through the grid
- More complex logic

### Approach 2: DFS/BFS Traversal
```python
# Traverse island using DFS and count edges
```
- More complex implementation
- Same time complexity
- Useful if need to identify separate islands

### Approach 3: This Implementation ✓
- **Best balance** of simplicity and efficiency
- Single pass, clear logic
- Optimal for this problem

## Common Mistakes to Avoid

❌ **Forgetting boundary checks**: `if i > 0` instead of `if i == 0 or ...`  
❌ **Diagonal connections**: Problem states only horizontal/vertical  
❌ **Double counting**: Each edge should be counted once  
❌ **Not handling empty grid**: Must check `if not grid`  

## Testing Recommendations
```python
# Test cases
test_cases = [
    ([], 0),                           # Empty grid
    ([[0]], 0),                        # No island
    ([[1]], 4),                        # Single cell
    ([[1, 1, 1, 1]], 10),             # Horizontal line
    ([[1], [1], [1], [1]], 10),       # Vertical line
    ([[1, 1], [1, 1]], 8),            # 2×2 square
    ([[0, 1, 0], [1, 1, 1]], 12),     # T-shape
]

for grid, expected in test_cases:
    result = island_perimeter(grid)
    print(f"Grid: {grid} → Perimeter: {result} (Expected: {expected})")
```

## Use Cases

- **Game development**: Calculate boundaries of terrain regions
- **Image processing**: Find perimeters of connected components
- **Geographic information systems**: Calculate coastline lengths
- **Computer graphics**: Determine shape boundaries
- **Puzzle solving**: Measure area boundaries in grid-based puzzles

## Related Problems

- Count number of islands
- Max area of island
- Number of distinct islands
- Flood fill algorithm
- Connected components in grid

## Author

Project implementation for understanding grid traversal and boundary detection algorithms.
