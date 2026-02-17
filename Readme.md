*This project has been created as part of the 42 curriculum by alamrani@42.*

# Push_Swap

## Description
`push_swap` is a project that challenges students to sort a stack of integers using a minimal set of operations.  
The goal is to efficiently sort the numbers with the fewest instructions possible, using two stacks (`A` and `B`) and a set of allowed operations:

- `sa`, `sb`, `ss` — swap the first two elements of a stack  
- `pa`, `pb` — push the top element from one stack to the other  
- `ra`, `rb`, `rr` — rotate a stack upwards  
- `rra`, `rrb`, `rrr` — rotate a stack downwards  

The project starts with implementing special-case sorting for small numbers of elements (2, 3, 5), then progresses to a scalable solution using **radix sort** for larger sets of numbers.

### Small Stack Sorting
- **2 elements**: Simple swap if out of order.  
- **3 elements**: Use combinations of swap and rotate operations to sort with minimal moves.  
- **5 elements**: Push the smallest and largest to stack `B`, sort remaining 3 in `A`, then push back from `B`.

### Large Stack Sorting
- **Radix sort**: Implements a bitwise radix sort using stack operations, ensuring O(n log n) efficiency for larger inputs.

## Instructions
### Compilation
The project uses a Makefile to compile the source files. To compile:

```bash
make
```
### Execution
This will produce the executable:

```bash
./push_swap
```
Run the program with a list of integers:
```bash
./push_swap 3 2 5 1 4
```