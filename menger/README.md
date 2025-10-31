# Menger Sponge

## Description
This project implements a 2D Menger Sponge generator in C. The Menger Sponge is a fractal curve that is a universal curve, meaning it has topological dimension one, but mathematical dimension log(8)/log(3) ≈ 1.893. This implementation creates a 2D cross-section representation of the famous 3D Menger Sponge fractal.

## Project Structure

```
menger/
├── 0-main.c      # Main entry point and argument handling
├── 0-menger.c    # Core Menger Sponge generation algorithm
├── menger.h      # Header file with function declarations
└── README.md     # This file
```

## What is a Menger Sponge?

The Menger Sponge is a fractal curve described by Karl Menger in 1926. In this 2D representation:
- **Level 0**: A single filled square (1×1)
- **Level 1**: A 3×3 grid with the center removed
- **Level 2**: Each filled square from level 1 becomes a level 1 pattern (9×9 grid)
- **Level n**: Each filled square becomes a level 1 pattern recursively

The fractal exhibits self-similarity at every scale, creating an intricate pattern of holes within holes.

## Algorithm

The implementation uses an elegant mathematical approach:

1. **Calculate size**: For level n, the size is 3^n × 3^n
2. **Iterate through each position**: Check every coordinate (i, j) in the grid
3. **Recursive hole detection**: For each position, repeatedly:
   - Check if both coordinates mod 3 equal 1 (center of a 3×3 block)
   - If yes, mark as empty space
   - If no, divide coordinates by 3 and repeat
4. **Character assignment**: Print '#' for filled areas, ' ' for holes

### Mathematical Insight
The key insight is that a position (i, j) should be empty if at any scale when dividing by powers of 3, both coordinates have remainder 1 when divided by 3.

## Functions

### `void menger(int level)`
- **Purpose**: Generates and prints a 2D Menger Sponge of the specified level
- **Parameters**: 
  - `level`: The recursion level (0 or higher)
- **Behavior**: 
  - Returns immediately if level < 0
  - Prints '#' for solid areas and ' ' for holes
  - Each row is terminated with a newline

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 0-main.c 0-menger.c -lm -o menger
```

**Note**: The `-lm` flag is required to link the math library for the `pow()` function.

## Usage

```bash
./menger <level>
```

Where `<level>` is a non-negative integer representing the fractal level.

### Examples

```bash
./menger 0    # 1×1 solid square
./menger 1    # 3×3 grid with center hole
./menger 2    # 9×9 complex pattern
./menger 3    # 27×27 highly detailed fractal
```

## Sample Outputs

### Level 0 (1×1):
```
#
```

### Level 1 (3×3):
```
###
# #
###
```

### Level 2 (9×9):
```
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
```

## Pattern Analysis

- **Size Growth**: Level n produces a 3^n × 3^n grid
- **Self-Similarity**: Each filled 3×3 block contains the pattern from level 1
- **Fractal Dimension**: The theoretical fractal dimension is log(8)/log(3) ≈ 1.893
- **Hole Density**: As the level increases, the ratio of holes to solid area increases

## Mathematical Properties

### Size Progression
- Level 0: 1×1 (1 character)
- Level 1: 3×3 (9 characters)  
- Level 2: 9×9 (81 characters)
- Level 3: 27×27 (729 characters)
- Level n: 3^n × 3^n (3^(2n) characters)

### Memory and Performance
- **Time Complexity**: O(3^(2n)) - quadratic in terms of the grid size
- **Space Complexity**: O(1) - only uses variables, no dynamic allocation
- **Output Size**: 3^(2n) + 3^n characters (including newlines)

## Limitations

- **Large Levels**: Higher levels produce exponentially larger outputs
- **Integer Overflow**: Very high levels may cause integer overflow in size calculation
- **Display**: Large fractals may exceed terminal display capabilities

## Error Handling

- **Invalid Arguments**: Program exits with usage message if no level provided
- **Negative Levels**: Function returns immediately without output
- **Non-numeric Input**: `atoi()` handles conversion, treating invalid input as 0

## Mathematical Background

The Menger Sponge demonstrates several important mathematical concepts:
- **Fractals**: Self-similar patterns at different scales
- **Recursive Structures**: Patterns defined in terms of themselves
- **Dimensional Analysis**: Objects with non-integer dimensions
- **Geometric Series**: Area calculations involve infinite series

## Compilation Notes

- Requires C99 standard or later for variable declarations
- Math library linking (`-lm`) necessary for `pow()` function
- Standard compiler warnings enabled for code quality

## Author

This implementation demonstrates fractal generation using efficient mathematical algorithms and follows C programming best practices.
