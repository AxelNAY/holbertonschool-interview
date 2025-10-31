# Minimum Operations

## Description
This project solves the "Minimum Operations" problem: given a text file with a single character 'H', determine the minimum number of operations needed to result in exactly n 'H' characters. The only allowed operations are:
1. **Copy All**: Copy all characters currently in the file
2. **Paste**: Paste the characters from the clipboard

## Project Structure

```
minimum_operations/
├── 0-main.py          # Test file with examples
├── 0-minoperations.py # Main implementation
└── README.md          # This file
```

## Problem Statement

Starting with one 'H' character in a text file, find the minimum number of operations to get exactly n 'H' characters using only:
- **Copy All**: Copies all current characters to clipboard
- **Paste**: Pastes clipboard content to the file

### Example
To get 9 'H' characters:
```
Initial: H                    (1 H)
Copy All, Paste, Paste        → HHH (3 H's, 3 operations)
Copy All, Paste, Paste        → HHHHHHHHH (9 H's, 3 more operations)
Total: 6 operations
```

## Algorithm

The solution uses **prime factorization** based on a key insight:

### Mathematical Insight
To optimally reach n characters, we need to find the most efficient way to multiply our current count. The optimal strategy is:
1. When we have k characters, copy once and paste (p-1) times to get k×p characters
2. This requires p operations total (1 copy + (p-1) pastes)
3. The minimum operations equals the sum of all prime factors of n

### Why Prime Factorization Works
- Each prime factor p represents an optimal "copy + paste" sequence
- Larger composite factors can always be broken down into smaller prime operations
- The sum of prime factors gives the absolute minimum operations

### Implementation Steps
1. Handle edge cases (n ≤ 1)
2. Find all prime factors of n
3. For each prime factor p that divides n:
   - Add p to the operation count
   - Divide n by p
4. Continue until n becomes 1
5. Return total operations

## Function

### `minOperations(n)`
- **Purpose**: Calculates minimum operations to reach exactly n 'H' characters
- **Parameter**: `n` (int) - target number of characters
- **Return**: (int) minimum number of operations needed
- **Edge Cases**: 
  - Returns 0 if n ≤ 1 (impossible or already achieved)

## Algorithm Complexity

- **Time Complexity**: O(√n) - we only check factors up to √n
- **Space Complexity**: O(1) - constant space usage
- **Optimality**: Guaranteed to find the absolute minimum

## Usage

### Running the Test
```bash
python3 0-main.py
```

### Expected Output
```
Min # of operations to reach 4 char: 4
Min # of operations to reach 12 char: 7
```

### Direct Usage
```python
from minoperations import minOperations

# Calculate minimum operations for different targets
print(minOperations(9))   # Output: 6
print(minOperations(4))   # Output: 4
print(minOperations(12))  # Output: 7
```

## Examples Breakdown

### Example 1: n = 4
- Prime factorization: 4 = 2 × 2
- Operations: 2 + 2 = 4
- Process: H → Copy+Paste → HH → Copy+Paste → HHHH

### Example 2: n = 9  
- Prime factorization: 9 = 3 × 3
- Operations: 3 + 3 = 6
- Process: H → Copy+Paste+Paste → HHH → Copy+Paste+Paste → HHHHHHHHH

### Example 3: n = 12
- Prime factorization: 12 = 2 × 2 × 3
- Operations: 2 + 2 + 3 = 7
- Process: H → HH (2 ops) → HHHH (2 ops) → HHHHHHHHHHHH (3 ops)

## Mathematical Properties

### Prime Numbers
- For prime n: exactly n operations needed
- Cannot be optimized further (only divisible by 1 and itself)

### Composite Numbers  
- Sum of prime factors always < n (except for primes)
- Larger prime factors are more efficient than multiple small factors

### Special Cases
- n = 1: 0 operations (already have 1 'H')
- n ≤ 0: 0 operations (impossible/invalid)
- n = 2: 2 operations (Copy All, Paste)

## Algorithm Proof

The algorithm is optimal because:

1. **Lower Bound**: Any sequence of operations can be represented as prime factorization
2. **Achievability**: Our algorithm achieves this lower bound
3. **Greedy Choice**: At each step, using the largest possible factor minimizes total operations

## Performance Analysis

### Best Case: n is prime
- Time: O(√n) to verify primality
- Operations: exactly n

### Worst Case: n has many small prime factors  
- Time: O(√n) for factorization
- Operations: sum of all prime factors

### Average Case
- Most numbers factor efficiently
- Significant improvement over brute force approaches

## Error Handling

- **Invalid Input**: Returns 0 for n ≤ 1
- **Large Numbers**: Algorithm remains efficient due to O(√n) complexity
- **Edge Cases**: Handles all mathematical edge cases correctly

## Applications

This algorithm pattern applies to:
- **Dynamic Programming**: Optimal substructure problems
- **Number Theory**: Prime factorization applications  
- **Resource Optimization**: Minimizing discrete operations
- **Game Theory**: Optimal move sequences

## Testing

The provided test cases verify:
- Basic functionality (n = 4, 12)
- Edge cases (small numbers)
- Mathematical correctness (prime factorization)

## Author

This implementation demonstrates efficient algorithm design using mathematical insights and prime factorization for optimal problem solving.
