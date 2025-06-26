# Sandpiles

## Description
This project implements the Abelian sandpile model in C. The sandpile model is a cellular automaton that demonstrates self-organized criticality. The implementation computes the sum of two 3×3 sandpile grids and applies stabilization rules until the resulting grid reaches a stable configuration.

## Project Structure

```
sandpiles/
├── 0-main.c        # Test file with example grids
├── 1-main.c        # Additional test case
├── 0-sandpiles.c   # Main implementation
├── sandpiles.h     # Header file
└── README.md       # This file
```

## What is a Sandpile?

The Abelian sandpile model, also known as the Bak-Tang-Wiesenfeld model, is a cellular automaton introduced by Per Bak, Chao Tang, and Kurt Wiesenfeld in 1987. It demonstrates the concept of self-organized criticality.

### Key Concepts
- **Grains of sand**: Each cell contains a number representing grains of sand
- **Stability threshold**: Cells with 4 or more grains are unstable
- **Toppling**: Unstable cells distribute their excess grains to neighbors
- **Avalanche effect**: One toppling can trigger cascading topplings

## Sandpile Rules

### Stability Condition
A cell is **stable** if it contains 3 or fewer grains of sand.

### Toppling Rules
When a cell contains 4 or more grains:
1. The cell loses 4 grains
2. Each of its 4 orthogonal neighbors (up, down, left, right) gains 1 grain
3. Grains that would fall off the grid boundary are lost forever
4. The process continues until all cells are stable

### Addition Operation
1. Add corresponding cells from both grids element-wise
2. Apply stabilization rules if any cell becomes unstable
3. Continue until the entire grid is stable

## Algorithm Implementation

### Core Functions

#### `void sandpiles_sum(int grid1[3][3], int grid2[3][3])`
- **Purpose**: Computes the sum of two sandpile grids and stabilizes the result
- **Parameters**: 
  - `grid1`: First 3×3 grid (modified in-place with the result)
  - `grid2`: Second 3×3 grid (unchanged)
- **Process**:
  1. Element-wise addition of both grids
  2. Stability verification
  3. Stabilization if needed

#### `bool verify(int grid[3][3])`
- **Purpose**: Checks if a grid is stable
- **Return**: `true` if stable, `false` if unstable
- **Side Effect**: Prints unstable grids during stabilization process

#### `void stable(int grid[3][3])`
- **Purpose**: Stabilizes an unstable grid through recursive toppling
- **Process**:
  1. Create a copy of the current grid state
  2. Apply toppling rules to all unstable cells simultaneously
  3. Recursively call itself if the grid is still unstable

### Stabilization Process

The stabilization uses a **simultaneous update** approach:
1. **Snapshot**: Take a copy of the current grid state
2. **Distribute**: For each cell with ≥4 grains, distribute to neighbors
3. **Subtract**: Remove 4 grains from each cell that toppled
4. **Check**: Verify stability and repeat if necessary

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-sandpiles.c -o sandpiles
```

## Usage

### Running Test Cases
```bash
./sandpiles
```

### Example Output

#### Test Case 1:
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 1 2
1 2 1
2 1 2
```

#### Test Case 2:
```
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
```

## Mathematical Properties

### Self-Organized Criticality
- **Critical state**: The system naturally evolves to a critical state
- **Scale invariance**: Avalanches occur at all scales
- **Power law distribution**: Avalanche sizes follow a power law

### Abelian Property
- **Commutativity**: A + B = B + A (order doesn't matter)
- **Associativity**: (A + B) + C = A + (B + C)
- **Identity element**: The zero grid acts as identity
- **Unique representation**: Each equivalence class has a unique stable representative

### Group Structure
The set of stable sandpile configurations forms an Abelian group under the sandpile addition operation.

## Algorithm Analysis

### Time Complexity
- **Best case**: O(1) if both grids are stable after addition
- **Worst case**: O(k × 9) where k is the number of stabilization iterations
- **Average case**: Depends on the initial configuration and grain distribution

### Space Complexity
- **O(1)**: Constant space usage (fixed 3×3 grids)
- **Stack space**: O(k) for recursive calls during stabilization

### Convergence
- **Guaranteed termination**: The process always terminates in finite steps
- **Monotonic decrease**: Total number of grains decreases or stays the same
- **Unique stable state**: Each configuration has exactly one stable representative

## Edge Cases

### Boundary Conditions
- **Edge cells**: Have fewer than 4 neighbors
- **Corner cells**: Have only 2 neighbors
- **Grain loss**: Grains falling off the boundary are permanently lost

### Special Configurations
- **All zeros**: Stable configuration (identity element)
- **All threes**: Maximum stable configuration
- **Highly unstable**: Grids requiring many stabilization steps

## Applications

### Scientific Applications
- **Physics**: Models avalanche behavior in granular media
- **Computer science**: Studies self-organized criticality
- **Mathematics**: Group theory and algebraic structures
- **Complex systems**: Understanding emergent behavior

### Computational Uses
- **Algorithm design**: Cellular automaton principles
- **Simulation**: Modeling critical phenomena
- **Visualization**: Fractal-like patterns in large grids

## Visualization Patterns

In larger grids, sandpiles create beautiful fractal patterns:
- **Sierpinski triangles**: Emerge in certain configurations
- **Recursive structures**: Self-similar patterns at different scales
- **Critical avalanches**: Create intricate geometric designs

## Implementation Details

### Memory Management
- **Stack allocation**: Uses fixed-size arrays
- **No dynamic memory**: Avoids malloc/free complexity
- **Efficient copying**: Direct array copying for snapshots

### Error Handling
- **Boundary checks**: Prevents array out-of-bounds access
- **Stability verification**: Ensures proper termination
- **Input validation**: Handles edge cases gracefully

## Performance Considerations

### Optimization Opportunities
- **Batch processing**: Handle multiple cells simultaneously
- **Lazy evaluation**: Skip stable regions during updates
- **Parallel processing**: Independent cell updates can be parallelized

### Scalability
- **Grid size**: Algorithm extends to larger grids
- **Multiple grids**: Can process multiple sandpile operations
- **Real-time**: Suitable for interactive applications

## Testing

The provided test cases demonstrate:
- **Basic functionality**: Simple grid addition and stabilization
- **Complex cascades**: Multi-step stabilization processes
- **Edge cases**: Various initial configurations
- **Output format**: Proper visualization of intermediate steps

## Author

This implementation demonstrates the fascinating mathematical properties of sandpile models and their applications in studying self-organized criticality and complex systems behavior.