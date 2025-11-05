# UTF-8 Validation

A Python implementation that determines if a given dataset represents a valid UTF-8 encoding by analyzing byte patterns and multi-byte character sequences.

## Description

UTF-8 is a variable-width character encoding that can represent every character in the Unicode character set. This project provides a validation function that checks whether a list of integers (representing bytes) forms a valid UTF-8 encoded string according to the UTF-8 specification.

## Features

- **Complete UTF-8 validation**: Supports 1-4 byte UTF-8 sequences
- **Byte pattern analysis**: Validates proper byte structure and continuation patterns
- **Range checking**: Ensures all values are within valid byte range (0-255)
- **Sequence validation**: Verifies correct number of continuation bytes

## Files Structure

```
.
├── 0-validate_utf8.py    # Core UTF-8 validation implementation
├── 0-main.py             # Test file with example usage
└── README.md             # This file
```

## Usage

### Basic Usage

```python
from validate_utf8 import validUTF8

# Single ASCII character
data = [65]  # 'A'
print(validUTF8(data))  # True

# Multi-byte UTF-8 string
data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

# Invalid UTF-8 sequence
data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```

### Running the Test

```bash
python3 0-main.py
```

Expected output:
```
True
True
False
```

## UTF-8 Encoding Rules

UTF-8 uses the following byte patterns:

| Character Range | Byte 1 | Byte 2 | Byte 3 | Byte 4 |
|----------------|--------|--------|--------|--------|
| U+0000 - U+007F | 0xxxxxxx | | | |
| U+0080 - U+07FF | 110xxxxx | 10xxxxxx | | |
| U+0800 - U+FFFF | 1110xxxx | 10xxxxxx | 10xxxxxx | |
| U+10000 - U+10FFFF | 11110xxx | 10xxxxxx | 10xxxxxx | 10xxxxxx |

### Key Rules:
1. **Single-byte characters**: Start with `0` (0-127)
2. **Multi-byte sequences**: First byte indicates length
3. **Continuation bytes**: Must start with `10` (128-191)
4. **No orphaned continuation bytes**: Continuation bytes must follow a valid start byte

## Algorithm Logic

The validation function works by:

1. **Iterating through each byte** in the input data
2. **Masking to 8 bits** using `& 0xFF` to handle integers > 255
3. **Checking byte patterns**:
   - If expecting continuation bytes, validate they start with `10`
   - If not expecting continuation bytes, determine sequence length
4. **Tracking continuation bytes** needed for multi-byte sequences
5. **Final validation** ensures all sequences are complete

## Function Reference

### `validUTF8(data)`

**Parameters:**
- `data`: List of integers representing bytes (0-255)

**Returns:**
- `True` if the data represents valid UTF-8 encoding
- `False` if the data is invalid UTF-8

**Validation Logic:**
```python
def validUTF8(data):
    continuation_bytes = 0
    
    for num in data:
        byte = num & 0xFF  # Mask to 8 bits
        
        if continuation_bytes == 0:
            # Determine sequence type
            if byte < 128:      # 0xxxxxxx (ASCII)
                continue
            elif byte < 192:    # 10xxxxxx (invalid start)
                return False
            elif byte < 224:    # 110xxxxx (2-byte sequence)
                continuation_bytes = 1
            elif byte < 240:    # 1110xxxx (3-byte sequence)
                continuation_bytes = 2
            elif byte < 248:    # 11110xxx (4-byte sequence)
                continuation_bytes = 3
            else:               # Invalid start byte
                return False
        else:
            # Validate continuation byte
            if byte < 128 or byte >= 192:  # Must be 10xxxxxx
                return False
            continuation_bytes -= 1
    
    return continuation_bytes == 0  # All sequences complete
```

## Example Scenarios

### Valid UTF-8 Sequences

**ASCII characters:**
```python
data = [72, 101, 108, 108, 111]  # "Hello"
validUTF8(data)  # True
```

**Mixed ASCII and multi-byte:**
```python
data = [72, 195, 169, 108, 108, 111]  # "Héllo"
validUTF8(data)  # True
```

**3-byte UTF-8 character:**
```python
data = [226, 156, 147]  # "✓" checkmark
validUTF8(data)  # True
```

### Invalid UTF-8 Sequences

**Orphaned continuation byte:**
```python
data = [128]  # 10000000 without leading byte
validUTF8(data)  # False
```

**Incomplete sequence:**
```python
data = [195]  # 110xxxxx without continuation
validUTF8(data)  # False
```

**Invalid start byte:**
```python
data = [248]  # 11111000 (invalid UTF-8 start)
validUTF8(data)  # False
```

**Value out of byte range:**
```python
data = [256]  # > 255, gets masked to 0
validUTF8(data)  # True (becomes valid after masking)
```

## Byte Pattern Analysis

The function analyzes byte patterns using bit ranges:

- **0-127** (`0xxxxxxx`): Single-byte ASCII characters
- **128-191** (`10xxxxxx`): Continuation bytes (invalid as start bytes)
- **192-223** (`110xxxxx`): Start of 2-byte sequence
- **224-239** (`1110xxxx`): Start of 3-byte sequence
- **240-247** (`11110xxx`): Start of 4-byte sequence
- **248-255** (`11111xxx`): Invalid UTF-8 start bytes

## Error Handling

The function handles various error conditions:

- **Invalid start bytes**: Returns `False` for bytes that cannot begin a UTF-8 sequence
- **Orphaned continuation bytes**: Returns `False` for continuation bytes without proper start
- **Incomplete sequences**: Returns `False` if multi-byte sequences are not completed
- **Out-of-range values**: Automatically masks values > 255 to valid byte range

## Technical Notes

- **Bit masking**: Uses `& 0xFF` to ensure values are treated as single bytes
- **State tracking**: Maintains count of expected continuation bytes
- **Efficient validation**: Single-pass algorithm with O(n) time complexity
- **Memory efficient**: Processes data sequentially without additional storage

## Limitations

- Input must be a list/iterable of integers
- Does not validate Unicode code point ranges (e.g., surrogate pairs)
- Does not check for overlong encodings
- Focuses on byte-level UTF-8 structure validation only

## Testing

Run the included test file to verify functionality:

```bash
python3 0-main.py
```

The test covers:
- Single ASCII character validation
- Multi-character ASCII string validation  
- Invalid UTF-8 sequence detection

## License

This project is part of a programming exercise for UTF-8 encoding validation.
