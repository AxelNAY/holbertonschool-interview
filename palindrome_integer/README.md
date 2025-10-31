# Palindrome Number Checker

## Description

This project implements a function to check whether a given unsigned long integer is a **palindrome**. A palindrome number reads the same forwards and backwards. For example, 121, 12321, and 1 are palindromes, while 123 and 1230 are not.

## What is a Palindrome Number?

A **palindrome number** is a number that remains the same when its digits are reversed.

**Examples:**
- ✅ **1** → Palindrome (single digit)
- ✅ **121** → Palindrome (reads same: 1-2-1)
- ✅ **12321** → Palindrome (reads same: 1-2-3-2-1)
- ✅ **9009** → Palindrome (reads same: 9-0-0-9)
- ❌ **123** → Not palindrome (reversed: 321)
- ❌ **1230** → Not palindrome (reversed: 0321 = 321)

## Algorithm Overview

The function uses an **array-based comparison approach**:

1. Extract all digits of the number into an array
2. Use two pointers (one at start, one at end)
3. Compare digits from both ends moving inward
4. If all pairs match, it's a palindrome

**Time Complexity**: O(d) where d is the number of digits  
**Space Complexity**: O(d) for storing digits in array

## Files

| File | Description |
|------|-------------|
| `palindrome.h` | Header file with function prototype |
| `0-is_palindrome.c` | Implementation of palindrome checker |
| `0-main.c` | Test file for command-line usage |
| `README.md` | Project documentation |

## Function Prototype
```c
int is_palindrome(unsigned long n);
```

### Parameters

- `n` (unsigned long): The number to check for palindrome property

### Returns

- `1` if the number is a palindrome
- `0` if the number is not a palindrome

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-is_palindrome.c -o palindrome
```

## Usage

### Command Line
```bash
./palindrome <number>
```

### Examples
```bash
# Palindrome examples
./palindrome 1
# Output: 1 is a palindrome.

./palindrome 121
# Output: 121 is a palindrome.

./palindrome 12321
# Output: 12321 is a palindrome.

./palindrome 1001
# Output: 1001 is a palindrome.

# Non-palindrome examples
./palindrome 123
# Output: 123 is not a palindrome.

./palindrome 1230
# Output: 1230 is not a palindrome.

./palindrome 9876543210
# Output: 9876543210 is not a palindrome.
```

### Programmatic Usage
```c
#include "palindrome.h"

unsigned long num = 12321;
int result = is_palindrome(num);

if (result)
    printf("%lu is a palindrome\n", num);
else
    printf("%lu is not a palindrome\n", num);
```

## How It Works

### Step-by-Step Process

**Example: Checking 12321**
```c
Step 1: Count digits
temp = 12321
Count: 5 digits
max = 4 (index of last digit)

Step 2: Extract digits into array
n = 12321
tab[4] = 12321 % 10 = 1    n = 1232
tab[3] = 1232 % 10 = 2     n = 123
tab[2] = 123 % 10 = 3      n = 12
tab[1] = 12 % 10 = 2       n = 1
tab[0] = 1 % 10 = 1        n = 0

Array: [1, 2, 3, 2, 1]

Step 3: Compare from both ends
min = 0, max = 4
Compare tab[0] vs tab[4]: 1 == 1 ✓

min = 1, max = 3
Compare tab[1] vs tab[3]: 2 == 2 ✓

min = 2, max = 2 (min >= max, stop)

Result: All pairs match → Palindrome!
```

### Algorithm Visualization
```
Number: 12321

Digit extraction:
12321 → [1, 2, 3, 2, 1]
         ↑        ↑
        min      max

Comparison rounds:
Round 1: tab[0] vs tab[4] → 1 == 1 ✓
Round 2: tab[1] vs tab[3] → 2 == 2 ✓
Round 3: tab[2] vs tab[2] → Stop (min == max)

Result: Palindrome
```

## Implementation Details

### Digit Counting
```c
unsigned long temp = n;
int max = 0;

while (temp != 0)
{
    temp /= 10;  /* Remove last digit */
    max++;       /* Count digits */
}
```

**Example:** For n = 12321
- temp = 12321 → max = 1
- temp = 1232 → max = 2
- temp = 123 → max = 3
- temp = 12 → max = 4
- temp = 1 → max = 5
- temp = 0 → stop

### Digit Extraction
```c
for (int i = max; i >= 0; i--)
{
    tab[i] = n % 10;  /* Get last digit */
    n /= 10;          /* Remove last digit */
}
```

**Example:** For n = 12321, max = 4
- i = 4: tab[4] = 1, n = 1232
- i = 3: tab[3] = 2, n = 123
- i = 2: tab[2] = 3, n = 12
- i = 1: tab[1] = 2, n = 1
- i = 0: tab[0] = 1, n = 0

### Two-Pointer Comparison
```c
int min = 0, max = (digit_count - 1);

while (min < max)
{
    if (tab[min] != tab[max])
        return (0);  /* Not a palindrome */
    
    min++;  /* Move inward from left */
    max--;  /* Move inward from right */
}
```

## Edge Cases

| Case | Number | Result | Explanation |
|------|--------|--------|-------------|
| Single digit | 0, 1, 9 | Palindrome | All single digits are palindromes |
| Two same digits | 11, 22, 99 | Palindrome | Symmetric |
| Two different digits | 12, 23, 45 | Not palindrome | Not symmetric |
| Trailing zeros | 120, 1000 | Not palindrome | Zero isn't at the start when reversed |
| All same digits | 111, 5555 | Palindrome | All digits match |
| Maximum unsigned long | Depends | Varies | Function handles up to 20 digits |

## Example Test Cases
```c
/* Palindromes */
is_palindrome(0)        → 1  (single digit)
is_palindrome(7)        → 1  (single digit)
is_palindrome(11)       → 1  (two digits)
is_palindrome(121)      → 1  (three digits)
is_palindrome(1221)     → 1  (even length)
is_palindrome(12321)    → 1  (odd length)
is_palindrome(9009)     → 1  (with zeros)
is_palindrome(123454321) → 1 (nine digits)

/* Not palindromes */
is_palindrome(10)       → 0  (trailing zero)
is_palindrome(123)      → 0  (no symmetry)
is_palindrome(1230)     → 0  (trailing zero)
is_palindrome(12345)    → 0  (ascending)
is_palindrome(54321)    → 0  (descending)
```

## Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Count digits | O(d) | O(1) |
| Extract digits | O(d) | O(d) |
| Compare digits | O(d/2) | O(1) |
| **Total** | **O(d)** | **O(d)** |

Where `d` is the number of digits in the number.

**For unsigned long (up to 20 digits)**:
- Time: ~20 operations
- Space: 20 integers (80 bytes)

## Limitations

### Array Size Constraint
```c
int tab[20];  /* Fixed size array */
```

**Maximum supported:**
- Unsigned long max: 18,446,744,073,709,551,615 (20 digits)
- Array size: 20 elements
- Works for all valid unsigned long values

### No Overflow Check

The function assumes the input fits within unsigned long range. No validation is performed.

## Alternative Approaches

### Approach 1: Reverse and Compare (Not Used)
```c
/* Reverse the number and compare with original */
unsigned long reversed = 0;
unsigned long temp = n;

while (temp != 0)
{
    reversed = reversed * 10 + temp % 10;
    temp /= 10;
}

return (reversed == n);
```

**Pros:** Simpler, no array needed  
**Cons:** Risk of overflow during reversal for large numbers

### Approach 2: String Conversion (Not Used)
```c
/* Convert to string and compare characters */
char str[21];
sprintf(str, "%lu", n);
int len = strlen(str);

for (int i = 0; i < len/2; i++)
    if (str[i] != str[len-1-i])
        return 0;
return 1;
```

**Pros:** Simple string comparison  
**Cons:** String conversion overhead, not pure arithmetic

### Approach 3: Current Implementation ✓

**Pros:** Clear logic, no overflow risk  
**Cons:** Uses extra space for array

## Optimization Opportunities

### Early Exit for Single Digit
```c
if (n < 10)
    return (1);  /* Single digit is always palindrome */
```

Already implemented in the code.

### Reduce Space with Recursion
```c
/* Check palindrome recursively without array */
/* More complex but uses O(log n) space */
```

### Bit Manipulation (Not Applicable)

Palindrome checking requires decimal representation, so bit manipulation doesn't provide advantages.

## Use Cases

- **Project Euler problems**: Many involve palindrome numbers
- **Coding interviews**: Common algorithmic question
- **Number theory**: Prime palindromes, palindrome dates
- **Data validation**: Check for symmetric patterns
- **Educational**: Teaching two-pointer technique

## Common Mistakes to Avoid

❌ **Not handling single digits**: Must return 1 immediately  
❌ **Array overflow**: Fixed size array limits number size  
❌ **Reverse overflow**: Reversing large numbers can overflow  
❌ **Leading zeros**: 0120 != 120 in reverse  
❌ **Off-by-one errors**: Pointer movement must stop at center  

## Testing Strategy
```bash
# Boundary cases
./palindrome 0          # Minimum
./palindrome 1          # Single digit
./palindrome 10         # Trailing zero

# Small palindromes
./palindrome 11         # Two digits
./palindrome 121        # Three digits
./palindrome 1221       # Even length

# Large palindromes
./palindrome 123454321  # Nine digits
./palindrome 12345678987654321  # Very large

# Non-palindromes
./palindrome 123        # Simple
./palindrome 1230       # Trailing zero
./palindrome 987654321  # Descending
```

## Related Problems

- **Palindrome string**: Check if string is palindrome
- **Longest palindromic substring**: Find longest palindrome in string
- **Palindrome partitioning**: Split string into palindrome parts
- **Super palindrome**: Number and its square are both palindromes
- **Palindrome pairs**: Find pairs of words forming palindromes

## Author

Project implementation for understanding two-pointer technique and digit manipulation in C programming.
