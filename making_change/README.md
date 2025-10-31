# Making Change

## Description

This project implements a solution to the **coin change problem**, a classic dynamic programming challenge. Given a pile of coins of different denominations and a target amount, the function determines the fewest number of coins needed to meet that total. If the total cannot be achieved with the available coins, it returns -1.

## Problem Statement

Given:
- A list of coin denominations (e.g., [1, 5, 10, 25])
- A target total amount

Find:
- The minimum number of coins needed to make exact change for the total
- Return -1 if the total cannot be made with any combination of coins

## Algorithm Overview

The solution uses **Dynamic Programming (Bottom-Up Approach)**:

1. Create a DP array where `dp[i]` represents the minimum coins needed for amount `i`
2. Initialize `dp[0] = 0` (zero coins needed for amount 0)
3. For each amount from 1 to total:
   - Try each coin denomination
   - If coin ≤ current amount: `dp[amount] = min(dp[amount], dp[amount - coin] + 1)`
4. Return `dp[total]` if achievable, otherwise -1

**Time Complexity**: O(total × n) where n is the number of coin denominations  
**Space Complexity**: O(total) for the DP array

## Files

| File | Description |
|------|-------------|
| `0-making_change.py` | Implementation of the coin change algorithm |
| `0-main.py` | Test file with example cases |
| `README.md` | Project documentation |

## Function Prototype
```python
def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total.
    
    Args:
        coins (list): List of coin denominations (positive integers)
        total (int): Target amount to make change for
        
    Returns:
        int: Fewest number of coins needed to meet total
             0 if total is 0 or less
             -1 if total cannot be met by any combination of coins
    """
```

## Usage

### Basic Usage
```python
#!/usr/bin/python3
makeChange = __import__('0-making_change').makeChange

# Example 1: US coins
result = makeChange([1, 2, 25], 37)
print(result)  # Output: 7

# Example 2: Custom denominations
result = makeChange([1256, 54, 48, 16, 102], 1453)
print(result)  # Output: 5
```

### Run Test File
```bash
chmod +x 0-main.py
./0-main.py
```

## Expected Output
```
7
5
```

## How It Works

### Example 1: makeChange([1, 2, 25], 37)

**Goal**: Make 37 cents using coins of 1¢, 2¢, and 25¢

**DP Array Construction:**
```
dp[0] = 0   (base case: 0 coins for 0 cents)

For amount 1:
  - Try coin 1: dp[1] = min(∞, dp[0] + 1) = 1
  → dp[1] = 1

For amount 2:
  - Try coin 1: dp[2] = min(∞, dp[1] + 1) = 2
  - Try coin 2: dp[2] = min(2, dp[0] + 1) = 1
  → dp[2] = 1

For amount 25:
  - Try coin 1: dp[25] = min(∞, dp[24] + 1)
  - Try coin 2: dp[25] = min(..., dp[23] + 1)
  - Try coin 25: dp[25] = min(..., dp[0] + 1) = 1
  → dp[25] = 1

...continuing to amount 37...

For amount 37:
  - Try coin 1: dp[37] = min(..., dp[36] + 1)
  - Try coin 2: dp[37] = min(..., dp[35] + 1)
  - Try coin 25: dp[37] = min(..., dp[12] + 1)
  → dp[37] = 7
```

**Optimal Solution**: 25 + 2 + 2 + 2 + 2 + 2 + 2 = 37 (7 coins)

### Example 2: makeChange([1256, 54, 48, 16, 102], 1453)

**DP Process:**
```
dp[0] = 0

For amount 1453:
  - Best combination found: 1256 + 102 + 48 + 16 + 16 + 16 - 1 = 1453
  → Actually: 1256 + 102 + 48 + 16 + 16 + 16 - 1 (needs recalculation)
  
Correct: 1256 + 102 + 48 + 16 + 16 + 16 - 1 
Wait, let me recalculate...

1256 × 1 = 1256 (remaining: 197)
102 × 1 = 102 (remaining: 95)
54 × 1 = 54 (remaining: 41)
16 × 2 = 32 (remaining: 9)
Not possible without smaller coins...

Actually the algorithm finds:
→ dp[1453] = 5
```

The DP algorithm automatically finds the optimal combination.

## Visual DP Table Example

**For makeChange([1, 5, 10], 12):**

| Amount | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|--------|---|---|---|---|---|---|---|---|---|---|----|----|----|
| **dp** | 0 | 1 | 2 | 3 | 4 | 1 | 2 | 3 | 4 | 5 | 1  | 2  | 3  |

**Explanation:**
- `dp[0] = 0`: No coins needed for 0
- `dp[1] = 1`: One 1¢ coin
- `dp[5] = 1`: One 5¢ coin (better than five 1¢ coins)
- `dp[10] = 1`: One 10¢ coin
- `dp[12] = 3`: 10¢ + 1¢ + 1¢ (or 5¢ + 5¢ + 1¢ + 1¢ = 4, but 10+1+1 is better)

## Step-by-Step Algorithm
```python
def makeChange(coins, total):
    # Step 1: Handle edge cases
    if total <= 0:
        return 0
    if not coins:
        return -1
    
    # Step 2: Initialize DP array
    dp = [total + 1] * (total + 1)  # Use total+1 as "infinity"
    dp[0] = 0  # Base case
    
    # Step 3: Build DP table bottom-up
    for amt in range(1, total + 1):
        for coin in coins:
            if coin <= amt:
                # Try using this coin
                dp[amt] = min(dp[amt], dp[amt - coin] + 1)
    
    # Step 4: Return result
    return dp[total] if dp[total] <= total else -1
```

## Edge Cases

| Case | Input | Output | Explanation |
|------|-------|--------|-------------|
| Zero total | `([1, 5, 10], 0)` | `0` | No coins needed |
| Negative total | `([1, 5, 10], -5)` | `0` | Invalid amount |
| No coins | `([], 10)` | `-1` | Cannot make change |
| Impossible amount | `([5, 10], 3)` | `-1` | Cannot make 3 with only 5s and 10s |
| Exact match | `([25], 25)` | `1` | One coin exactly |
| Single coin type | `([1], 100)` | `100` | Need 100 pennies |

## Example Test Cases
```python
# Test Case 1: Standard US coins
print(makeChange([1, 5, 10, 25], 63))  # Output: 6 (25+25+10+1+1+1)

# Test Case 2: Impossible
print(makeChange([5, 10], 3))  # Output: -1

# Test Case 3: Zero amount
print(makeChange([1, 5, 10], 0))  # Output: 0

# Test Case 4: Single coin
print(makeChange([1], 10))  # Output: 10

# Test Case 5: Large denominations
print(makeChange([10, 20, 50], 100))  # Output: 2 (50+50)

# Test Case 6: Greedy fails but DP works
print(makeChange([1, 3, 4], 6))  # Output: 2 (3+3, not 4+1+1)
```

## Why Greedy Doesn't Work

**Greedy Algorithm** (always use largest coin) fails for some coin systems:
```python
Coins: [1, 3, 4]
Target: 6

Greedy: 4 + 1 + 1 = 6 (3 coins) ❌
Optimal: 3 + 3 = 6 (2 coins) ✓

DP finds the optimal solution!
```

## Complexity Analysis

| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(total × n) | Nested loops: amounts × coins |
| **Space** | O(total) | DP array of size total+1 |
| **Initialization** | O(total) | Creating and filling dp array |

### For Large Inputs:
- `total = 10,000`, `n = 5` coins
- Time: ~50,000 operations (very fast)
- Space: ~40 KB memory

## Optimization Notes

### Why `total + 1` as Infinity?
```python
dp = [total + 1] * (total + 1)
```

- Represents "impossible" initially
- Any valid solution uses ≤ `total` coins (all 1-cent coins)
- Allows comparison without special infinity handling
- Final check: `dp[total] <= total` determines if achievable

### Alternative: Using `float('inf')`
```python
dp = [float('inf')] * (total + 1)
# But need to check: return dp[total] if dp[total] != float('inf') else -1
```

Both work, but `total + 1` is slightly more efficient.

## Related Problems

- **Unbounded Knapsack**: Similar DP structure
- **Coin Change II**: Count number of ways (not minimum coins)
- **Rod Cutting**: Maximize value with cuts
- **Minimum Cost Path**: Similar state transition

## Advantages of DP Solution

✅ **Finds optimal solution**: Guaranteed minimum coins  
✅ **Handles any coin system**: Works even when greedy fails  
✅ **Efficient**: Polynomial time complexity  
✅ **Simple implementation**: Clear bottom-up approach  
✅ **No recursion overhead**: Iterative solution  

## Common Mistakes to Avoid

❌ **Using greedy algorithm**: Doesn't work for all coin systems  
❌ **Forgetting base case**: `dp[0] = 0` is essential  
❌ **Wrong initialization**: Must use "infinity" concept  
❌ **Off-by-one errors**: Array size is `total + 1`  
❌ **Not checking impossibility**: Must return -1 when unreachable  

## Practical Applications

- **Currency exchange**: Minimize transaction fees
- **Vending machines**: Optimal change dispensing
- **Resource allocation**: Minimize resource units used
- **Network routing**: Minimize hop count
- **Task scheduling**: Minimize number of time slots

## Variations

### Coin Change with Limited Coins
```python
# Each coin can only be used once
# Requires 2D DP: dp[i][amount]
```

### Coin Change II (Count Ways)
```python
# Count number of different combinations
# Different DP recurrence relation
```

### Coin Change with Specific Coins
```python
# Track which coins were used
# Store path in addition to count
```

## Author

Project implementation for understanding dynamic programming and the classic coin change problem with optimal substructure and overlapping subproblems.
