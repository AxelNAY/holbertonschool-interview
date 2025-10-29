# Big Integer Multiplication in C

This program multiplies two large non-negative integers provided as command-line arguments.  
It handles numbers that exceed the limits of standard C integer types by performing digit-by-digit multiplication using arrays.

---

## 🧮 Features

- Supports multiplication of **very large numbers** (beyond `long long int` range).
- Validates that both inputs are valid positive integers.
- Prints the correct product without leading zeros.
- Displays `"Error"` and exits with code `98` on invalid input.

---

## 📂 File Structure


Main source file containing:
- `is_number()` — Checks if a string contains only digits.
- `multiply_big_numbers()` — Performs the actual multiplication.
- `print_result()` — Prints the computed result cleanly.
- `infinite()` — Handles argument validation and runs multiplication.
- `main()` — Entry point of the program.

---

## ⚙️ Compilation

Use **gcc** to compile:

```bash
gcc -Wall -Werror -Wextra -pedantic 0-mul.c -o mul

🚀 Usage

Run the program by passing two large integers as arguments:

./mul 123456789 987654321


Output:

121932631112635269

🧠 Error Handling

The program prints Error and exits with status code 98 in the following cases:

Incorrect number of arguments.

One or both arguments are not valid positive integers.

Memory allocation fails.

Example:

./mul 123 abc


Output:

Error


Exit code:

98

🧩 Example Tests
./mul 123 456
# Output: 56088

./mul 99999999999999999999 99999999999999999999
# Output: 9999999999999999999800000000000000000001

🧠 How It Works

The program simulates manual multiplication (like on paper):

Each digit of the second number multiplies each digit of the first number.

Intermediate results are stored in an integer array.

Carries are handled properly across digits.

The result is printed without leading zeros.

Time Complexity: O(n × m)
Space Complexity: O(n + m)

🧑‍💻 Author

Developed for Holberton School / ALX SE Program.

📜 License

This project is released under the MIT License.


---
