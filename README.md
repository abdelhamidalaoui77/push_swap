*This project has been created as part of the 42 curriculum by alamrani42.*

# push_swap

## Description

push_swap is an algorithmic project whose goal is to sort a stack of integers using a limited set of predefined operations and the smallest possible number of moves.

The program receives a list of integers as arguments and outputs a sequence of stack operations that sorts the numbers in ascending order. The challenge is not simply to sort, but to do so efficiently under strict operational constraints.

This project focuses on:

- Data structure manipulation (linked lists)
- Algorithmic thinking and optimization
- Complexity analysis
- Bitwise operations
- Memory management in C

The final objective is to implement an efficient sorting strategy (Radix Sort adapted to index-based normalization) while respecting 42 coding standards and project constraints.

---

## Project Goals

- Implement stack operations from scratch
- Handle argument parsing and validation securely
- Detect duplicates and invalid inputs
- Manage memory properly (no leaks)
- Implement small-case sorting (2–3 numbers optimized)
- Implement an efficient large-scale sorting algorithm (Radix Sort)
- Minimize the total number of operations

---

## Allowed Operations

The program works with two stacks: **A** and **B**.

### Swap

- `sa` — swap the first two elements of stack A  
- `sb` — swap the first two elements of stack B  
- `ss` — perform `sa` and `sb` simultaneously  

### Push

- `pa` — push the top element of B to A  
- `pb` — push the top element of A to B  

### Rotate

- `ra` — shift all elements of A up by one  
- `rb` — shift all elements of B up by one  
- `rr` — perform `ra` and `rb` simultaneously  

### Reverse Rotate

- `rra` — shift all elements of A down by one  
- `rrb` — shift all elements of B down by one  
- `rrr` — perform `rra` and `rrb` simultaneously  

No other operations are allowed.

---

## Algorithm Strategy

### Index Normalization

Before sorting, values are normalized by assigning each number an index based on its sorted order.

Example:
```bash
    Original:   42      -5      17
    Indexes:     2       0       1
    Sorted:     -5      17      42
```

This simplifies comparisons and allows efficient bitwise processing.

---

### Small Cases (2–3 Numbers)

Small inputs are handled using dedicated logic:

- 2 numbers → simple swap if needed  
- 3 numbers → minimal combination of swap and rotate operations  

This ensures optimal performance for trivial cases.

---

### Main Sorting Algorithm: Radix Sort (Binary)

For larger datasets, a binary Radix Sort is implemented:

- Determine the maximum number of bits needed.
- Iterate bit by bit (from least significant bit to most).
- For each bit:
  - If bit = 0 → `pb`
  - If bit = 1 → `ra`
- Push all elements back to stack A.
- Repeat for next bit.

This ensures:

- Deterministic complexity  
- Efficient sorting for 100 and 500 numbers  
- Compliance with project performance thresholds  

Time complexity: **O(n log n)** (relative to bit count)

---

## Instructions

### Compilation

Use the provided Makefile:

```bash
make
```
This will generate:
```bash
./push_swap
```
Clean object files:
```bash
make clean
```
Remove all generated files:
```bash
make fclean
```
Recompile everything:
```bash
make re
```

### Execution

Run the program with a list of integers:
```bash
./push_swap 3 2 5 1 4
```
The program outputs a sequence of operations that sorts the stack.

Example output:
```bash
pb
ra
pb
ra
pa
pa
```
To test with the official checker:
```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```
Expected result:
```bash
OK
```

### Error Handling

The program handles:
   - Non-numeric input.
   - Integer overflow
   - Duplicate values
   - Empty input
   - Mixed quoted/unquoted arguments

In case of error, it prints:

```bash
Error
```

### Technical Choices

#### Data Structure
   - Singly linked list implementation for stacks
   - Each node contains :
            - Value
            - Index
            - Pointer to next
Linked lists were chosen to simplify push and rotate operations without reallocations.

#### Memory Management
   - All allocated memory is freed
   - No leaks allowed
   - Parsing functions validate before insertion
   - Defensive programming used throughout

### Resources

#### Documentation and References
   - GNU C Manual: [https://www.gnu.org/software/gnu-c-manual/](https://www.gnu.org/software/gnu-c-manual/)
   - Bitwise Operators in C: [https://en.cppreference.com/w/c/language/operator_arithmetic](https://en.cppreference.com/w/c/language/operator_arithmetic)
   - Radix Sort Explanation: [https://www.geeksforgeeks.org/radix-sort/](https://www.geeksforgeeks.org/radix-sort/)
   - Linked List Implementation in C: [https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
   []

### AI Usage

AI was used strictly as a learning and review assistant to:
   - Clarify algorithmic concepts (Radix Sort, bitwise logic)
   - Validate understanding of stack manipulation
   - Review design decisions
   - Help structure documentation
All code was written, tested, and debugged manually.
Algorithm design and implementation decisions were fully understood before integration.

### Conclusion

push_swap is a deep introduction to algorithm optimization under constraints.
It reinforces data structure mastery, disciplined memory management, and efficient problem-solving.

The final implementation demonstrates a structured approach:
  - Validate input
  - Normalize values
  - Handle trivial cases
  - Apply optimized Radix Sort
  - Minimize operations