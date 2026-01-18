*This project has been created as part of the 42 curriculum by faeljedd.*

# push_swap

## Description

The **push_swap** project is an algorithmic challenge whose objective is to sort a list of integers using **two stacks (`a` and `b`)** and a restricted set of operations, while producing the **smallest possible number of moves**. 

---

## Instructions

### Compilation

To compile the project, run:

```make```

This will generate the executable :

```push_swap```

---
#### Execution

Run the program by passing a list of integers as arguments :

```./push_swap <list_of_integers>```

Example:

```./push_swap 2 1 3 6 5 8```

The program outputs a sequence of instructions, one per line, that sorts the stack.

---
#### Error Handling
If the input is invalid (non-integer values, duplicates, overflow, etc.), the program prints:

```Error```


to the standard error output.

If no arguments are provided, the program prints nothing.

---
## Bonus — Checker

As a bonus, a program named **checker** is implemented to verify whether a sequence of instructions correctly sorts the stack.

### Description

The **checker** program takes the same list of integers as `push_swap`, then reads a list of instructions from the standard input.  
It executes these instructions on the stacks and verifies the final state.

#### Outputs:

- ```Error``` if the input is invalid 
- ```OK``` if sorted and stack b is empty
- ```KO``` otherwise


#### Compilation
To compile the checker project, run:

`make bonus`

This will generate the bonus executable

`./checker.`

## Resources
[Youtube/push_swap](https://www.youtube.com/watch?v=wRvipSG4Mmk)

[medium/turk algo](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## AI Usage

AI tools were used to help understand sorting concepts and to explaining the turk algorithme

## Rules Overview

- Two stacks are used:
  - `stack a`: initialized with a list of unique integers
  - `stack b`: initially empty
- Only a predefined set of operations is allowed (`sa`, `pb`, `ra`, etc.)
- The program must output **only** the sorting instructions
- The goal is to sort `stack a` in **ascending order**
- Any invalid input must result in `"Error\n"` printed to `stderr`

---

## Allowed Operations

| Operation | Description |
|---------|------------|
| sa | Swap the first two elements of stack a |
| sb | Swap the first two elements of stack b |
| ss | sa and sb at the same time |
| pa | Push the top of b to a |
| pb | Push the top of a to b |
| ra | Rotate stack a upwards |
| rb | Rotate stack b upwards |
| rr | ra and rb at the same time |
| rra | Reverse rotate stack a |
| rrb | Reverse rotate stack b |
| rrr | rra and rrb at the same time |

---
