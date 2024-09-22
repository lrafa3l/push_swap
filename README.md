# Push_swap

## Introduction
The **Push_swap** project is a simple yet challenging algorithm project that requires sorting data using a set of integer values, two stacks, and a series of operations to manipulate those stacks. 

## Objectives
Sorting algorithms are crucial in a developer's journey, as they introduce the concept of complexity and efficiency.

The key objectives of the project include:

- Learning to write efficient and optimized algorithms.
- Understanding complexity and performance in sorting problems.
- Writing clean and effective C code.

## The Rules
- You have two stacks, named `a` and `b`.
- Initially, stack `a` contains a set of unique integers (both positive and negative), while stack `b` is empty.
- The goal is to sort the integers in ascending order in stack `a` using the following operations:
  - `sa` (swap a): Swap the first two elements at the top of stack a.
  - `sb` (swap b): Swap the first two elements at the top of stack b.
  - `ss`: Perform sa and sb simultaneously.
  - `pa` (push a): Move the first element from stack b to stack a.
  - `pb` (push b): Move the first element from stack a to stack b.
  - `ra` (rotate a): Shift all elements in stack a up by one, with the first element becoming the last.
  - `rb` (rotate b): Shift all elements in stack b up by one.
  - `rr`: Perform ra and rb simultaneously.
  - `rra` (reverse rotate a): Shift all elements in stack a down by one, with the last element becoming the first.
  - `rrb` (reverse rotate b): Shift all elements in stack b down by one.
  - `rrr`: Perform rra and rrb simultaneously.

## How does it works?
Here’s an example of how some of these operations are used to sort a list of integers:

Initial state:
``` less
Stack a: [2, 1, 3, 6, 5, 8]
Stack b: []
```
- `sa` swaps the first two elements of stack `a`: `[1, 2, 3, 6, 5, 8]`.
- `pb` three times moves three elements to stack `b`.
``` less
Stack a: [6, 5, 8]
Stack b: [3, 2, 1]
```
- `ra` and `rb` rotate both stacks:
``` less
Stack a: [5, 8, 6]
Stack b: [2, 1, 3]
```
- After several more operations, stack `a` is sorted as `[1, 2, 3, 5, 6, 8]`.

## Running the Program
To run the `push_swap` program, compile the program using the provided `Makefile` and then execute it with a list of integers as arguments. The program will output the instructions needed to sort the integers.
``` bash
make
./push_swap [list_of_integers]
```
### Example
1. Sorting a list of integers:

```bash
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
 ```
2. Handling invalid input:
``` bash
$> ./push_swap 0 one 2 3
Error
```

3. Checking the number of instructions:
``` bash
$> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
```
4. Verifying the correctness of sorting:
``` bash
$> ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

If the `checker` program displays "KO", it means that the list of instructions generated by `push_swap` does not correctly sort the numbers.

