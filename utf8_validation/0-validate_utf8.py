#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding
"""

def validUTF8(data):
    for n in data:
        if n > 255:
            return False
    return True
