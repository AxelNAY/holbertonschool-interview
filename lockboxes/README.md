# Lockboxes

A Python solution to determine if all lockboxes can be opened given a set of keys and boxes.

## Description

This project implements an algorithm that determines whether all boxes in a collection can be opened. Each box is numbered sequentially and may contain keys to other boxes. The goal is to determine if, starting from the first box (which is always unlocked), you can eventually open all boxes using the keys found inside them.

## Problem Statement

- You have `n` number of locked boxes in front of you
- Each box is numbered sequentially from `0` to `n - 1`
- Each box may contain keys to other boxes
- A key with the same number as a box opens that box
- The first box `boxes[0]` is unlocked
- All keys are positive integers
- There can be keys that do not correspond to any box
- **Goal**: Determine if all boxes can be opened

## Algorithm

The solution uses a breadth-first search approach:

1. Start with box 0 (always unlocked)
2. Keep track of all accessible boxes
3. For each accessible box, collect all keys inside
4. Use keys to access new boxes (if they exist and haven't been opened)
5. Continue until no new boxes can be opened
6. Return `True` if all boxes are accessible, `False` otherwise

## Files

- `0-lockboxes.py` - Main implementation containing the `canUnlockAll` function
- `main_0.py` - Test file with various test cases
- `README.md` - This documentation file

## Usage

```python
#!/usr/bin/python3
from lockboxes import canUnlockAll

# Example 1: All boxes can be opened
boxes = [[1], [2], [3], [4], []]
result = canUnlockAll(boxes)
print(result)  # True

# Example 2: Not all boxes can be opened
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
result = canUnlockAll(boxes)
print(result)  # False
```

## Function Prototype

```python
def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    
    Args:
        boxes (list): A list of lists where each sublist contains keys
    
    Returns:
        bool: True if all boxes can be opened, False otherwise
    """
```

## Test Cases

The project includes several test cases in `main_0.py`:

1. **Linear sequence**: `[[1], [2], [3], [4], []]` → `True`
2. **Complex interconnected**: `[[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]` → `True`
3. **Unreachable boxes**: `[[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]` → `False`
4. **Large dataset with duplicates**: Complex case with multiple keys → `True`
5. **Disconnected groups**: Some boxes unreachable → `False`

## How to Run

```bash
# Run the test cases
python3 main_0.py

# Or import and use in your own code
python3 -c "
from lockboxes import canUnlockAll
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))
"
```

## Time Complexity

- **Time Complexity**: O(n + k) where n is the number of boxes and k is the total number of keys
- **Space Complexity**: O(n) for storing the list of accessible boxes

## Edge Cases Handled

- Empty boxes (no keys inside)
- Keys that don't correspond to any existing box
- Duplicate keys
- Self-referencing keys (key that opens the same box)
- Large datasets with many interconnected boxes

## Algorithm Logic

The algorithm maintains a list called `compare` that tracks all boxes that can be opened:

1. Initialize with box 0 (always accessible)
2. Iterate through each accessible box
3. For each key in the current box:
   - Skip if key is 0 (current box)
   - Skip if key >= number of boxes (invalid key)
   - Skip if box is already accessible
   - Otherwise, add the box to accessible list
4. Compare final accessible count with total boxes

## Author

This implementation provides an efficient solution to the lockboxes problem using a systematic exploration approach.