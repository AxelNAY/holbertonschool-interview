# Palindrome Integer

## Description
This project implements a function to check if an unsigned long integer is a palindrome in C. A palindromic number reads the same forward and backward, such as 121, 1331, or 7337. The implementation uses an array-based approach to store and compare digits.

## Project Structure

```
palindrome_integer/
├── 0-is_palindrome.c  # Main implementation
├── 0-main.c          # Test program with command-line interface
├── palindrome.h      # Header file
└── README.md         # This file
```

## Algorithm

The palindrome check uses a digit extraction and comparison approach:

1. **Count digits**: Determine the number of digits in the input number
2. **Extract digits**: Store each digit in an array from least significant to most significant
3. **Two-pointer comparison**: Compare digits from both ends moving toward the center
4. **Early termination**: Return false immediately if any pair doesn't match

### Implementation Details

- **Digit extraction**: Uses modulo 10 and integer division to extract digits
- **Array storage**: Fixed-size array (20 elements) to handle large unsigned long values
- **Boundary handling**: Special case for single-digit numbers (always palindromes)
- **Memory efficient**: Uses stack-allocated array, no dynamic memory allocation

## Functions

### `int is_palindrome(unsigned long n)`
- **Purpose**: Checks if an unsigned long integer is a palindrome
- **Parameter**: `n` - the unsigned long integer to check
- **Return**: 
  - `1` if the number is a palindrome
  - `0` if the number is not a palindrome
- **Range**: Supports unsigned long values (typically up to 18,446,744,073,709,551,615)

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-is_palindrome.c -o palindrome
```

## Usage

### Command Line
```bash
./palindrome <number>
```

Where `<number>` is any non-negative integer.

### Examples
```bash
./palindrome 121      # Output: 121 is a palindrome.
./palindrome 123      # Output: 123 is not a palindrome.
./palindrome 1331     # Output: 1331 is a palindrome.
./palindrome 7337     # Output: 7337 is a palindrome.
./palindrome 12321    # Output: 12321 is a palindrome.
```

## Test Cases

### Palindromic Numbers
- **Single digit**: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
- **Two digits**: 11, 22, 33, 44, 55, 66, 77, 88, 99
- **Three digits**: 101, 111, 121, 131, 141, 151, 161, 171, 181, 191
- **Four digits**: 1001, 1111, 1221, 1331, 1441, 1551, 1661, 1771, 1881, 1991
- **Large numbers**: 123454321, 987656789

### Non-Palindromic Numbers
- **Two digits**: 10, 12, 13, 21, 23, 32
- **Three digits**: 100, 102, 120, 123, 200, 321
- **Four digits**: 1000, 1020, 1200, 1230, 2000, 3210
- **Large numbers**: 123456789, 987654321

## Algorithm Analysis

### Time Complexity
- **O(d)** where d is the number of digits in the input number
- **Digit extraction**: O(d) to extract all digits
- **Comparison**: O(d/2) to compare pairs of digits
- **Overall**: O(d) linear time complexity

### Space Complexity
- **O(1)** constant space (fixed-size array of 20 integers)
- Independent of input size
- No dynamic memory allocation

### Numerical Range
- **Maximum digits**: 20 (sufficient for 64-bit unsigned lon