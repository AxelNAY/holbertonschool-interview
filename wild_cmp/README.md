# Wildcard String Comparison (wildcmp)

## Description

This project implements a recursive function that compares two strings where the second string can contain the special wildcard character `*`. The asterisk (`*`) can match any sequence of characters, including an empty sequence. This is similar to pattern matching in shell globbing or regular expressions.

## Problem Statement

Write a function that compares two strings and returns `1` if they can be considered identical (considering wildcards), otherwise returns `0`.

### Wildcard Rules

- The character `*` in `s2` can replace any string (including an empty string)
- Multiple `*` characters can appear in `s2`
- `*` is greedy and matches as many characters as possible

## Algorithm Overview

The solution uses **recursive backtracking**:

1. **Base Case**: If both strings are exhausted (`\0`), they match
2. **Wildcard Case**: If current char in `s2` is `*`:
   - Try matching zero characters (skip `*`)
   - Try matching one or more characters (consume from `s1`, keep `*`)
3. **Exact Match Case**: If characters match exactly, continue with both strings
4. **Mismatch**: Return 0 (no match)

**Time Complexity**: O(2^n) in worst case (exponential due to backtracking)  
**Space Complexity**: O(n) for recursion stack

## Files

| File | Description |
|------|-------------|
| `holberton.h` | Header file with function prototype |
| `0-wildcmp.c` | Implementation of wildcard comparison |
| `0-main.c` | Test file with various examples |
| `README.md` | Project documentation |

## Function Prototype
```c
int wildcmp(char *s1, char *s2);
```

### Parameters

- `s1`: The string to be matched (no wildcards)
- `s2`: The pattern string (may contain `*` wildcards)

### Returns

- `1` if the strings can be considered identical
- `0` if the strings cannot match

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-wildcmp.c -o wildcmp
```

## Usage Example
```c
#include "holberton.h"

int main(void)
{
    int result;
    
    result = wildcmp("main.c", "*.c");
    printf("%d\n", result);  // Output: 1
    
    result = wildcmp("main.c", "main.c");
    printf("%d\n", result);  // Output: 1
    
    result = wildcmp("main.c", "m*c");
    printf("%d\n", result);  // Output: 1
    
    result = wildcmp("main.c", "*.py");
    printf("%d\n", result);  // Output: 0
    
    return (0);
}
```

## Expected Output

Running the test file produces:
```
1
1
1
1
1
1
1
0
1
1
0
0
```

## How It Works

### Step-by-Step Example

**Example 1: `wildcmp("main.c", "*.c")`**
```
Step 1: s1="main.c", s2="*.c"
  → s2[0] is '*'
  → Try skip '*': wildcmp("main.c", ".c") → fails
  → Try consume: wildcmp("ain.c", "*.c")

Step 2: s1="ain.c", s2="*.c"
  → s2[0] is '*'
  → Try skip '*': wildcmp("ain.c", ".c") → fails
  → Try consume: wildcmp("in.c", "*.c")

... continues consuming until:

Step 6: s1=".c", s2="*.c"
  → s2[0] is '*'
  → Try skip '*': wildcmp(".c", ".c") → succeeds!

Result: 1 (match)
```

**Example 2: `wildcmp("main.c", "m*c")`**
```
Step 1: s1="main.c", s2="m*c"
  → s1[0]='m', s2[0]='m' → match
  → wildcmp("ain.c", "*c")

Step 2: s1="ain.c", s2="*c"
  → s2[0] is '*'
  → Try skip '*': wildcmp("ain.c", "c") → fails
  → Try consume: wildcmp("in.c", "*c")

... continues until:

Step 6: s1="c", s2="*c"
  → s2[0] is '*'
  → Try skip '*': wildcmp("c", "c") → succeeds!

Result: 1 (match)
```

**Example 3: `wildcmp("abc", "*b")` (Fails)**
```
Step 1: s1="abc", s2="*b"
  → s2[0] is '*'
  → Try skip '*': wildcmp("abc", "b") → 'a' != 'b' → fail
  → Try consume: wildcmp("bc", "*b")

Step 2: s1="bc", s2="*b"
  → s2[0] is '*'
  → Try skip '*': wildcmp("bc", "b") → 'b' == 'b'
  → wildcmp("c", "") → 'c' != '\0' → fail
  → Try consume: wildcmp("c", "*b")

Step 3: s1="c", s2="*b"
  → s2[0] is '*'
  → Try skip '*': wildcmp("c", "b") → 'c' != 'b' → fail
  → Try consume: wildcmp("", "*b")

Step 4: s1="", s2="*b"
  → s2[0] is '*'
  → Try skip '*': wildcmp("", "b") → '\0' != 'b' → fail
  → Try consume: s1[0] == '\0' → fail

Result: 0 (no match)
```

## Implementation Details

### Code Breakdown
```c
int wildcmp(char *s1, char *s2)
{
    /* Base case: both strings exhausted */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    
    /* Wildcard case */
    if (*s2 == '*')
    {
        /* Try matching zero characters (skip '*') */
        if (wildcmp(s1, s2 + 1))
            return (1);
        
        /* Try matching one or more characters */
        if (*s1 != '\0' && wildcmp(s1 + 1, s2))
            return (1);
        
        return (0);
    }
    
    /* Exact character match */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));
    
    /* Mismatch */
    return (0);
}
```

### Wildcard Matching Logic

When encountering `*`:

1. **Skip wildcard** (match empty string):
```c
   wildcmp(s1, s2 + 1)  // Try pattern without '*'
```

2. **Consume one character** (match one or more):
```c
   wildcmp(s1 + 1, s2)  // Keep '*', advance string
```

This creates a **branching search** that explores all possible matches.

## Test Cases Analysis

| Test | s1 | s2 | Result | Explanation |
|------|----|----|--------|-------------|
| 1 | `"main.c"` | `"*.c"` | `1` | `*` matches "main" |
| 2 | `"main.c"` | `"m*a*i*n*.*c*"` | `1` | Multiple `*` match empty strings |
| 3 | `"main.c"` | `"main.c"` | `1` | Exact match |
| 4 | `"main.c"` | `"m*c"` | `1` | `*` matches "ain." |
| 5 | `"main.c"` | `"ma*******c"` | `1` | Multiple `*` match "in." |
| 6 | `"main.c"` | `"*"` | `1` | `*` matches everything |
| 7 | `"main.c"` | `"***"` | `1` | Multiple `*` match everything |
| 8 | `"main.c"` | `"m.*c"` | `0` | Literal `.` doesn't match `a` |
| 9 | `"main.c"` | `"**.*c"` | `1` | `*` matches, literal `.` and `*` work |
| 10 | `"main-main.c"` | `"ma*in.c"` | `1` | `*` matches "in-ma" |
| 11 | `"main"` | `"main*d"` | `0` | No `d` at end of string |
| 12 | `"abc"` | `"*b"` | `0` | `*` matches "a", but "bc" != "b" |

## Edge Cases

| Case | Example | Result | Notes |
|------|---------|--------|-------|
| Empty strings | `("", "")` | `1` | Both empty match |
| Empty s1 | `("", "*")` | `1` | `*` can match empty |
| Empty s2 | `("abc", "")` | `0` | Can't match non-empty with empty |
| Only wildcards | `("anything", "***")` | `1` | Multiple `*` match all |
| No wildcards | `("test", "test")` | `1` | Exact string match |
| Wildcard at start | `("test.c", "*.c")` | `1` | Common pattern |
| Wildcard at end | `("file.txt", "file*")` | `1` | Suffix matching |
| Wildcard in middle | `("test123", "test*3")` | `1` | Infix matching |

## Complexity Analysis

### Time Complexity

**Worst Case: O(2^(m+n))**

Where m = length of s1, n = length of s2

**Example causing exponential behavior:**
```c
wildcmp("aaaaaaaab", "*a*a*a*b")
```

Each `*` creates two branches, leading to exponential recursion.

**Best Case: O(min(m, n))**

When strings match exactly with no wildcards.

### Space Complexity

**O(m + n)** for the recursion stack

Maximum depth = sum of string lengths in worst case.

## Optimization Opportunities

### Memoization (Dynamic Programming)
```c
/* Cache results to avoid recomputation */
int dp[MAX_LEN][MAX_LEN];

int wildcmp_memo(char *s1, char *s2, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    
    /* ... regular logic ... */
    
    dp[i][j] = result;
    return result;
}
```

**Time Complexity with Memoization: O(m × n)**

### Iterative Approach

Using a stack or queue to avoid recursion:
```c
/* Pseudo-code */
while (queue not empty)
{
    state = dequeue();
    if (match) return 1;
    if (wildcard) enqueue(both options);
}
```

## Common Pitfalls

❌ **Not handling multiple wildcards**: `"***"` should work  
❌ **Greedy matching**: `*` should try both short and long matches  
❌ **Off-by-one errors**: Ensure both strings exhaust at same time  
❌ **Not checking null terminator**: Must check `\0` for both strings  
❌ **Stack overflow**: Very long strings can cause deep recursion  

## Use Cases

- **File globbing**: Shell pattern matching (`*.c`, `test*.txt`)
- **Search filters**: Database query patterns
- **Configuration matching**: Route patterns in web frameworks
- **Text processing**: Simple pattern matching in editors
- **Command-line tools**: Filename matching (like `find`, `grep`)

## Related Problems

- **Regular Expression Matching**: More complex with `.`, `+`, `?`
- **Substring Search**: KMP, Boyer-Moore algorithms
- **Glob Pattern Matching**: Extended wildcards (`?`, `[]`, `{}`)
- **Fuzzy String Matching**: Approximate matching with errors
- **Path Pattern Matching**: Hierarchical wildcard matching

## Comparison with Regular Expressions

| Feature | Wildcmp (`*`) | RegEx |
|---------|---------------|-------|
| Any sequence | `*` | `.*` |
| Single char | N/A | `.` |
| One or more | N/A | `+` |
| Zero or one | N/A | `?` |
| Character class | N/A | `[a-z]` |
| Complexity | Simple | Complex |

## Testing Strategy
```c
/* Test categories */

// Exact matches
wildcmp("test", "test") == 1

// Simple wildcards
wildcmp("test", "*") == 1
wildcmp("test", "t*") == 1
wildcmp("test", "*t") == 1

// Multiple wildcards
wildcmp("test", "t*s*") == 1
wildcmp("test", "***") == 1

// Failures
wildcmp("test", "x*") == 0
wildcmp("test", "*x") == 0
wildcmp("test", "t*x") == 0

// Edge cases
wildcmp("", "") == 1
wildcmp("", "*") == 1
wildcmp("a", "") == 0
```

## Author

Project implementation for understanding recursive backtracking, pattern matching, and the classic wildcard string comparison problem.
