# Rain Water Trapping Problem

## Description

This project implements a solution to the **Rain Water Trapping** problem, also known as the "Container With Most Water" variant. Given an array of non-negative integers representing the heights of walls (with unit width 1), the function calculates how many square units of water can be trapped between the walls after it rains.

## Problem Statement

Imagine a cross-section view of walls of varying heights arranged side by side. When it rains, water collects in the valleys between taller walls. Calculate the total volume of water that can be trapped.

### Visual Example
```
Input: [0, 1, 0, 2, 0, 3, 0, 4]

Elevation map:
        █
      █ █
    █ █ █
  █ █ █ █
0 1 0 2 0 3 0 4

Water trapped (shown as ~):
        █
      █~█
    █~█~█
  █~█~█~█
0 1 0 2 0 3 0 4

Water: 6 units (marked with ~)
```

## Algorithm Overview

The solution uses a **brute force approach** with nested loops:

1. For each position (except first and last):
   - Find the maximum height to the left
   - Find the maximum height to the right
   - Water at this position = `min(left_max, right_max) - current_height`
   - Add to total if positive

**Time Complexity**: O(n²) - for each element, scan left and right  
**Space Complexity**: O(1) - only uses a few variables

## Files

| File | Description |
|------|-------------|
| `0-rain.py` | Implementation of rain water trapping function |
| `0_main.py` | Test file with example cases |
| `README.md` | Project documentation |

## Function Prototype
```python
def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.
    
    Args:
        walls (list): List of non-negative integers representing wall heights
        
    Returns:
        int: Total amount of rainwater retained in square units
             0 if walls is empty or None
    """
```

## Usage

### Basic Usage
```python
#!/usr/bin/python3
rain = __import__('0-rain').rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Output: 6
```

### Run Test File
```bash
chmod +x 0_main.py
./0_main.py
```

## Expected Output
```
6
6
```

## How It Works

### Example 1: [0, 1, 0, 2, 0, 3, 0, 4]
```
Position 0: Skip (first position)
Position 1: left_max=1, right_max=4, water=min(1,4)-1 = 0
Position 2: left_max=1, right_max=4, water=min(1,4)-0 = 1
Position 3: left_max=2, right_max=4, water=min(2,4)-2 = 0
Position 4: left_max=2, right_max=4, water=min(2,4)-0 = 2
Position 5: left_max=3, right_max=4, water=min(3,4)-3 = 0
Position 6: left_max=3, right_max=4, water=min(3,4)-0 = 3
Position 7: Skip (last position)

Total: 0 + 1 + 0 + 2 + 0 + 3 = 6
```

**Visual representation:**
```
Index:  0  1  2  3  4  5  6  7
Height: 0  1  0  2  0  3  0  4
              ↑     ↑        ↑
Water:  0  0  1  0  2  0  3  0
Total water = 6 units
```

### Example 2: [2, 0, 0, 4, 0, 0, 1, 0]
```
Position 0: Skip (first position)
Position 1: left_max=2, right_max=4, water=min(2,4)-0 = 2
Position 2: left_max=2, right_max=4, water=min(2,4)-0 = 2
Position 3: left_max=4, right_max=4, water=min(4,4)-4 = 0
Position 4: left_max=4, right_max=1, water=min(4,1)-0 = 1
Position 5: left_max=4, right_max=1, water=min(4,1)-0 = 1
Position 6: left_max=4, right_max=1, water=min(4,1)-1 = 0
Position 7: Skip (last position)

Total: 2 + 2 + 0 + 1 + 1 + 0 = 6
```

**Visual representation:**
```
      █
█ ~ ~ █
█ ~ ~ █ ~ ~ █
█ ~ ~ █ ~ ~ █
2 0 0 4 0 0 1 0

Water at positions: [0, 2, 2, 0, 1, 1, 0, 0] = 6
```

## Step-by-Step Algorithm
```python
def rain(walls):
    if not walls:
        return 0
    
    result = 0
    
    # Process each position (skip first and last)
    for i in range(1, len(walls) - 1):
        # Find max height to the left (including current)
        left_max = walls[i]
        for j in range(i):
            left_max = max(left_max, walls[j])
        
        # Find max height to the right (including current)
        right_max = walls[i]
        for j in range(i + 1, len(walls)):
            right_max = max(right_max, walls[j])
        
        # Water at position i
        water_at_i = min(left_max, right_max) - walls[i]
        result += water_at_i
    
    return result
```

## Key Insight

**Water level at position i** is determined by:
- The **shorter** of the two tallest walls on either side
- Minus the height of the wall at position i
```
Water at i = min(max_left, max_right) - height[i]
```

If the result is negative (current wall is taller), no water is trapped.

## Visual Examples

### Example 3: [3, 0, 2, 0, 4]
```
      █
█     █
█   █ █
█ ~ █ █
█ ~ █ ~ █
3 0 2 0 4

left_max:  [3, 3, 3, 3, 4]
right_max: [4, 4, 4, 4, 4]

Position 1: min(3,4) - 0 = 3
Position 2: min(3,4) - 2 = 1
Position 3: min(3,4) - 0 = 3

Total: 3 + 1 + 3 = 7
```

### Example 4: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
```
        █
    █ ~ █ ~ █ ~ █
  █ █ ~ █ ~ █ █ █
█ █ █ █ █ █ █ █ █
0 1 0 2 1 0 1 3 2 1 2 1

Total: 6 units
```

## Edge Cases

| Case | Input | Output | Explanation |
|------|-------|--------|-------------|
| Empty list | `[]` | `0` | No walls |
| Single wall | `[5]` | `0` | Need at least 2 walls |
| Two walls | `[3, 0, 3]` | `3` | Water trapped between |
| No valleys | `[1, 2, 3, 4]` | `0` | Always ascending |
| Descending | `[4, 3, 2, 1]` | `0` | Always descending |
| All equal | `[2, 2, 2, 2]` | `0` | No trapping |
| All zeros | `[0, 0, 0]` | `0` | No walls |

## Complexity Analysis

### Time Complexity

**O(n²)** where n is the length of the walls array

- Outer loop: n-2 iterations
- Inner loops: Up to n iterations each
- Total: ~(n-2) × 2n ≈ O(n²)

### Space Complexity

**O(1)** - constant space

- Only uses a few variables: `result`, `i`, `j`, `left_max`, `right_max`
- No additional data structures

## Example Calculations

### Detailed Walkthrough: [0, 1, 0, 2, 0, 3, 0, 4]
```python
i=1 (height=1):
  left_max = max(0) = 0, but current is 1, so left_max = 1
  right_max = max(0,2,0,3,0,4) = 4
  water = min(1, 4) - 1 = 0

i=2 (height=0):
  left_max = max(0,1) = 1
  right_max = max(2,0,3,0,4) = 4
  water = min(1, 4) - 0 = 1 ✓

i=3 (height=2):
  left_max = max(0,1,0) = 1, but current is 2, so left_max = 2
  right_max = max(0,3,0,4) = 4
  water = min(2, 4) - 2 = 0

i=4 (height=0):
  left_max = max(0,1,0,2) = 2
  right_max = max(3,0,4) = 4
  water = min(2, 4) - 0 = 2 ✓

i=5 (height=3):
  left_max = max(0,1,0,2,0) = 2, but current is 3, so left_max = 3
  right_max = max(0,4) = 4
  water = min(3, 4) - 3 = 0

i=6 (height=0):
  left_max = max(0,1,0,2,0,3) = 3
  right_max = max(4) = 4
  water = min(3, 4) - 0 = 3 ✓

Total = 0 + 1 + 0 + 2 + 0 + 3 = 6
```

## Optimized Approaches (Not Implemented)

### Approach 1: Two-Pointer (O(n) time, O(1) space)
```python
def rain_optimized(walls):
    if not walls:
        return 0
    
    left, right = 0, len(walls) - 1
    left_max, right_max = 0, 0
    result = 0
    
    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                result += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                result += right_max - walls[right]
            right -= 1
    
    return result
```

### Approach 2: Dynamic Programming (O(n) time, O(n) space)
```python
def rain_dp(walls):
    if not walls:
        return 0
    
    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    
    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])
    
    # Fill right_max array
    right_max[n-1] = walls[n-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])
    
    # Calculate water
    result = 0
    for i in range(n):
        result += min(left_max[i], right_max[i]) - walls[i]
    
    return result
```

## Performance Comparison

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| **Brute Force (current)** | O(n²) | O(1) | Simple but slow |
| Two-Pointer | O(n) | O(1) | Optimal |
| Dynamic Programming | O(n) | O(n) | Easy to understand |
| Stack-based | O(n) | O(n) | Complex but elegant |

## Use Cases

- **Water collection systems**: Reservoir design
- **Terrain analysis**: Flood prediction
- **Computer graphics**: Height map processing
- **Interview questions**: Common coding problem
- **Algorithm design**: Pattern for two-pointer technique

## Testing Recommendations
```python
# Test cases
test_cases = [
    ([0, 1, 0, 2, 0, 3, 0, 4], 6),
    ([2, 0, 0, 4, 0, 0, 1, 0], 6),
    ([3, 0, 2, 0, 4], 7),
    ([], 0),
    ([5], 0),
    ([1, 2, 3, 4, 5], 0),
    ([5, 4, 3, 2, 1], 0),
    ([2, 2, 2, 2], 0),
    ([4, 2, 0, 3, 2, 5], 9),
]

for walls, expected in test_cases:
    result = rain(walls)
    status = "✓" if result == expected else "✗"
    print(f"{status} walls={walls}, expected={expected}, got={result}")
```

## Common Mistakes to Avoid

❌ **Not handling empty list**: Must check `if not walls`  
❌ **Including first/last positions**: Water can't be trapped at edges  
❌ **Wrong min/max logic**: Must use min of max values  
❌ **Negative water**: Water amount is never negative  
❌ **Off-by-one errors**: Loop range must be `range(1, len(walls) - 1)`  

## Related Problems

- **Container With Most Water**: Two-pointer variant
- **Largest Rectangle in Histogram**: Stack-based approach
- **Trapping Rain Water II**: 2D version (matrix)
- **Pour Water**: Dynamic water flow simulation
- **Product of Array Except Self**: Similar left/right max pattern

## Author

Project implementation for understanding array manipulation, optimization techniques, and the classic rain water trapping problem with various solution approaches.
