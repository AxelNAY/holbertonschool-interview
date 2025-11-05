# Algorithm Projects - Holberton School

## Description

This repository contains a collection of algorithm and data structure projects completed during my training at **Holberton School**. Each project demonstrates proficiency in problem-solving, algorithmic thinking, and implementation in **C** and **Python**.

The projects cover a wide range of topics from fundamental data structures to advanced algorithms, including sorting algorithms, graph theory, dynamic programming, recursion, and more.

## 🎯 Learning Objectives

Throughout these projects, I have developed skills in:

- **Data Structures**: Arrays, linked lists, trees, heaps, graphs
- **Algorithm Design**: Sorting, searching, optimization
- **Complexity Analysis**: Big O notation, time and space complexity
- **Problem Solving**: Breaking down complex problems into manageable solutions
- **Code Quality**: Writing clean, efficient, and maintainable code
- **Testing**: Validating solutions with comprehensive test cases

## 📚 Project Categories

### Searching Algorithms
- **`advanced_binary_search`** - Advanced binary search with duplicate handling
- **`linear_skip`** - Skip list search implementation
- **`find_the_loop`** - Floyd's cycle detection algorithm

### Sorting Algorithms
- **`heap_sort`** - Heap sort implementation
- **`merge_sort`** - Merge sort with divide-and-conquer
- **`radix_sort`** - Non-comparison based radix sort
- **`insert_in_sorted_linked_list`** - Insertion in sorted linked lists

### Tree Structures
- **`avl_trees`** - AVL tree operations and balancing
- **`sorted_array_to_avl`** - Converting sorted arrays to AVL trees
- **`binary_tree_is_avl`** - AVL tree validation

### Heap Operations
- **`heap_extract`** - Extract maximum from max heap
- **`heap_insert`** - Insert elements into heap

### Linked Lists
- **`double_circular_linked_list`** - Circular doubly linked list operations
- **`linked_list_cycle`** - Detect cycles in linked lists
- **`linked_list_palindrome`** - Check if linked list is palindrome

### String & Pattern Matching
- **`wildcmp`** - Wildcard pattern matching with recursion
- **`palindrome_integer`** - Check if numbers are palindromes

### Mathematical Algorithms
- **`infinite_multiplication`** - Arbitrary precision multiplication
- **`making_change`** - Coin change problem (dynamic programming)
- **`minimum_operations`** - Minimum operations to reach target
- **`pascal_triangle`** - Generate Pascal's triangle

### Grid & Matrix Problems
- **`island_perimeter`** - Calculate island perimeter in grid
- **`rotate_2d_matrix`** - Rotate matrix 90 degrees clockwise
- **`rain`** - Rain water trapping problem

### Graph & Backtracking
- **`nqueens`** - N Queens problem with backtracking

### API & Web
- **`count_it`** - Reddit API word counting
- **`starwars_api`** - Star Wars API character fetcher
- **`log_parsing`** - Parse and analyze log files

### Miscellaneous
- **`Betty`** - C code style checker
- **`count_it`** - Counting algorithm
- **`lockboxes`** - Lockbox key problem
- **`menger`** - Menger sponge fractal
- **`sandpiles`** - Sandpile simulation
- **`slide_line`** - 2048-like sliding algorithm
- **`linux`** - Linux system programming

*...and more projects in progress*

## 🛠️ Technologies & Languages

### Languages
- ![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
- ![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white)

### Tools & Concepts
- **Version Control**: Git, GitHub
- **Testing**: Unit tests, edge case validation
- **Debugging**: GDB, Valgrind (for C)
- **Code Style**: Betty (C), PEP 8 (Python)
- **Documentation**: Markdown, inline comments

## 📂 Repository Structure
```
algorithm-projects/
│
├── advanced_binary_search/
│   ├── 0-advanced_binary.c
│   ├── search_algos.h
│   └── README.md
│
├── avl_trees/
│   ├── 0-binary_tree_is_avl.c
│   ├── binary_trees.h
│   └── README.md
│
├── making_change/
│   ├── 0-making_change.py
│   └── README.md
│
├── nqueens/
│   ├── 0-nqueens.py
│   └── README.md
│
└── [other projects...]
```

Each project directory contains:
- **Source files**: Implementation in C or Python
- **Header files**: Function prototypes (for C projects)
- **README.md**: Detailed project documentation
- **Test files**: Example usage and validation

## 🚀 Getting Started

### Prerequisites

**For C projects:**
```bash
gcc (GNU Compiler Collection)
make (optional, for projects with Makefiles)
```

**For Python projects:**
```bash
Python 3.x (3.8 or higher recommended)
```

### Running Projects

**C Projects:**
```bash
# Navigate to project directory
cd advanced_binary_search/

# Compile
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o program

# Run
./program
```

**Python Projects:**
```bash
# Navigate to project directory
cd making_change/

# Make executable (if needed)
chmod +x 0-making_change.py

# Run
./0-making_change.py
# or
python3 0-making_change.py
```

## 📖 Documentation

Each project includes its own comprehensive README with:

- Problem statement and objectives
- Algorithm explanation and complexity analysis
- Implementation details
- Usage examples with expected output
- Edge cases and testing strategies
- Compilation/execution instructions

## 🎓 Learning Resources

These projects are based on concepts from:

- **Data Structures & Algorithms** courses
- **Computer Science fundamentals**
- **Holberton School curriculum**
- Classic algorithm problems (LeetCode, HackerRank style)

## 📊 Project Status

| Status | Description |
|--------|-------------|
| ✅ Completed | Fully implemented and tested |
| 🚧 In Progress | Currently being developed |
| 📋 Planned | Upcoming projects |

**Current Status**: 🚧 Actively adding new projects

## 🧪 Testing

Projects include various testing approaches:

- **Unit Tests**: Individual function testing
- **Integration Tests**: Full program execution
- **Edge Cases**: Boundary conditions, empty inputs, large datasets
- **Memory Testing**: Valgrind for C projects (leak detection)

Example test execution:
```bash
# For C projects with provided test files
gcc -Wall -Wextra -Werror -pedantic *.c -o test
./test

# For Python projects
python3 -m pytest  # if using pytest
# or
python3 test_file.py
```

## 🏆 Key Achievements

- ✅ Implemented 30+ algorithm projects
- ✅ Mastered both C and Python for algorithmic problem-solving
- ✅ Achieved optimal time and space complexity in solutions
- ✅ Developed strong debugging and optimization skills
- ✅ Completed complex problems including N Queens, AVL trees, and dynamic programming

## 🔄 Continuous Learning

This repository is actively maintained and regularly updated with:

- New algorithm implementations
- Code optimizations and refactoring
- Enhanced documentation
- Additional test cases
- Performance improvements

## 📝 Code Standards

All code follows industry best practices:

**C Projects:**
- Betty style guide compliance
- No memory leaks (validated with Valgrind)
- Proper error handling
- Comprehensive documentation

**Python Projects:**
- PEP 8 style guide
- Type hints where applicable
- Docstrings for all functions
- Clean, readable code

## 🤝 Contributing

While this is a personal learning repository, suggestions and feedback are welcome:

1. Open an issue for discussion
2. Fork the repository
3. Create a feature branch
4. Submit a pull request

## 📧 Contact

**Author**: [Your Name]
- **GitHub**: [@YourUsername](https://github.com/YourUsername)
- **LinkedIn**: [Your LinkedIn](https://linkedin.com/in/yourprofile)
- **Email**: your.email@example.com

## 🏫 Acknowledgments

- **Holberton School** - For the comprehensive curriculum and project-based learning approach
- **Mentors and Peers** - For guidance and collaborative problem-solving
- **Open Source Community** - For inspiration and learning resources

## 📄 License

This project is part of the Holberton School curriculum. All rights reserved for educational purposes.

---

**Built with 💻 and ☕ during my journey at Holberton School**

*Last Updated: November 2025*
