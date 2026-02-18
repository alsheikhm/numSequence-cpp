# numSequence-cpp

# Overview

Number Sequence & Data Type Analyzer is a console-based C++ program that generates a recursive integer sequence and determines the largest sequence value that can be safely stored in both a signed 32-bit `int` and a signed 64-bit `long long`.

The program begins with the fixed starting values 1, 3, and 5, then repeatedly applies a recurrence relation to generate subsequent terms while proactively detecting overflow before it occurs.

# Sequence Definition

The sequence is defined as:

- f(0) = 1  
- f(1) = 3  
- f(2) = 5  
- f(n) = (5 * f(n-1)) - (3 * f(n-2)) + f(n-3)

# Program Behavior

The program performs two main tasks:

1. Prints to the console:
   - The largest valid sequence value that fits in a signed 32-bit `int`
   - The largest valid sequence value that fits in a signed 64-bit `long long`

2. Writes every generated term from the initial three values up to the largest valid `long long` term into a file named `sequence.txt`, with one value per line.

# Overflow Detection Strategy

The program prevents overflow by checking whether the *next* computed term would exceed the limits of the target data type before performing the calculation.

It uses boundary checks based on:

- `INT_MAX` for `int` overflow detection
- `LLONG_MAX` for `long long` overflow detection

Checks include guarding multiplication and addition portions of the recurrence (e.g., validating `c > MAX/5`, `b > MAX/3`, and verifying the final sum stays within range).

# Core Concepts Applied

- Recursion-based sequence generation (iterative implementation)
- Overflow prevention using maximum-range constants (`<climits>`)
- File I/O using `ofstream` to generate `sequence.txt`
- Loop-driven state progression using a rolling window (`a`, `b`, `c`)
- Defensive programming with pre-check validation before arithmetic

# How to Run

1. Compile the program using a C++ compiler (ex. g++, clang++)
2. Run the executable
3. View the console output for max valid values and open `sequence.txt` for the full sequence output
