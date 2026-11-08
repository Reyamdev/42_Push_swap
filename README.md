*This project has been created as part of the 42 curriculum by rimayer, zkotab.*

# Push_swap

## Description

**Push_swap** is an algorithmic sorting project written in C. The goal is to sort a sequence of unique integers in ascending order using two stacks (`a` and `b`) and a restricted set of operations, while generating as few operations as possible.

At the start, stack `a` contains the input values in argument order (the first integer is at the top), and stack `b` is empty. The mandatory `push_swap` program writes sorting instructions to **standard output**. The bonus `checker` program reads those instructions from **standard input**, executes them silently, and checks the final stack state.

This implementation includes four runtime strategies: **Simple**, **Medium**, **Complex**, and **Adaptive**. Adaptive is the default.

## Instructions

### Compilation

```sh
make          # Compile push_swap
make bonus    # Compile checker (bonus)
make clean    # Remove object files
make fclean   # Remove objects and executables
make re       # Rebuild the mandatory program
```

The project compiles with `cc -Wall -Wextra -Werror` and uses the included Libft.

### Usage

Pass each integer as a separate argument:

```sh
./push_swap 4 67 3 87 23
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

To check the generated instructions:

```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

A valid sorting sequence produces `OK` from `checker`; a sequence that does not leave `a` sorted and `b` empty produces `KO`. Invalid arguments or instructions produce `Error` on standard error. With no arguments, both programs exit without output.

### Benchmark mode

```sh
./push_swap --adaptive --bench 4 67 3 87 23
```

`--bench` reports the initial disorder percentage, chosen strategy and complexity class, total operation count, and the count of each individual operation. Benchmark information is written to **standard error**, so it does not interfere with the instruction stream on standard output.

## Allowed operations

| Operation | Effect |
| --- | --- |
| `sa`, `sb` | Swap the top two elements of stack `a` or `b` |
| `ss` | Perform `sa` and `sb` together |
| `pa` | Push the top of `b` onto `a` |
| `pb` | Push the top of `a` onto `b` |
| `ra`, `rb` | Rotate a stack: top element moves to the bottom |
| `rr` | Perform `ra` and `rb` together |
| `rra`, `rrb` | Reverse rotate: bottom element moves to the top |
| `rrr` | Perform `rra` and `rrb` together |

Internally, both stacks are doubly linked lists. Moving a node between stacks changes pointers and stack sizes; it does not allocate a new node.

## Algorithms and design choices

**Complexity below refers to the number of Push_swap operations generated**, as required by the project subject. This is distinct from the CPU time spent scanning nodes, finding ranks, or calculating disorder.

### Simple — minimum extraction: O(n²)

The algorithm repeatedly finds the smallest value in `a`, brings it to the top using whichever direction (`ra` or `rra`) requires fewer rotations, and pushes it to `b` with `pb`. Once `a` is empty, all elements are pushed back with `pa`.

### Medium — rank-based chunks: O(n√n)

Each value receives a rank from `0` (smallest) to `n - 1` (largest). The algorithm divides the rank range into chunks of approximately √n elements and transfers one chunk at a time from `a` to `b`. Values outside the current chunk are rotated in `a`. After the transfer, the highest remaining rank is located in `b`, moved to the top by the shorter rotation direction, and pushed back to `a`.

### Complex — binary LSD radix: O(n log n)

The values are first normalized into ranks so that the algorithm works with non-negative consecutive integers. Starting with the least significant bit, each pass examines exactly the original number of elements in `a`:

- Bit `0`: `pb` moves the element to `b`.
- Bit `1`: `ra` keeps the element in `a` while rotating it.
- After the pass: `pa` moves all elements from `b` back to `a`.

The algorithm repeats for every bit needed to represent `n - 1`. The ordering within each bit group is preserved between passes, so the final ranks are ascending.

### Adaptive — selecting by disorder

Before sorting, the program calculates the fraction of **inversions** in the original input. An inversion is a pair of positions `(i, j)` for which `i < j` but `a[i] > a[j]`.

```text
disorder = number_of_inversions / number_of_pairs
```

The adaptive strategy uses the following regimes:

| Initial disorder | Selected algorithm | Operation complexity |
| --- | --- | --- |
| `< 0.20` | Simple | O(n²) |
| `0.20 ≤ disorder < 0.50` | Medium | O(n√n) |
| `≥ 0.50` | Complex | O(n log n) |

These thresholds follow the project's required low-, medium-, and high-disorder regimes. They favor the simple baseline for inputs close to sorted order, the chunk-based method for intermediate disorder, and binary radix for heavily disordered input. An explicit `--simple`, `--medium`, or `--complex` flag overrides adaptive selection.

## Bonus: checker

The `checker` executable reconstructs the initial stack from the command-line integers, then reads newline-terminated instructions from standard input. Its reader uses a persistent stash to handle instructions across `read()` calls. Each valid instruction is dispatched to a **silent** stack operation; unlike the mandatory program, the checker does not print operations or record benchmark statistics.

At end of input:

- `OK` means stack `a` is sorted in ascending order **and** stack `b` is empty.
- `KO` means the final state does not satisfy both conditions.
- `Error` is written to standard error for invalid inputs or malformed instructions.

## Project structure

```text
.
├── Makefile
├── push_swap.h
├── src/
│   ├── main.c
│   ├── algorithms/     # Simple, medium, complex, adaptive, disorder, helpers
│   ├── parsing/        # Strategy flags and integer validation
│   ├── operations/     # Printing and counting stack operations
│   ├── stack/          # Doubly linked-list management
│   └── bench/          # Operation statistics and benchmark output
├── bonus/              # Checker, instruction dispatch, silent operations, stdin reader
└── libft/              # Custom C utility library
```

## Team contributions

This is a two-learner project. The following division reflects the primary file authorship and implementation areas represented in the repository:

- **rimayer:** Parsing, stack management, disorder calculation, adaptive strategy, binary radix strategy, benchmark tracking/output, checker control flow, instruction validation, and buffered instruction reading.
- **zkotab:** Fundamental stack operations, simple minimum-extraction strategy, medium chunk-based strategy, ranking/sorting utilities, and bonus silent stack operations.

## Resources

- **42 Push_swap subject** — required operations, strategy classes, disorder thresholds, benchmark requirements, and checker specification.
- [C language reference — cppreference](https://en.cppreference.com/w/c)
- Radix sort — https://www.youtube.com/watch?v=nu4gDuFabIM
- inversions — https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)

### AI usage

Ai was used as a **learning and review aid**: to discuss algorithmic complexity and algorithm design, help with documentation and variable names for easier reading, preparing tests.
