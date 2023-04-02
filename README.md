# push_swap

42cursus - (2021-2022) 💻

- Result : 125/100 ✅

![screen](https://i.imgur.com/OSw8mfX.gif)

## 📝 Description

This project is about sorting data on a stack, with a limited set of instructions, and the smallest number of moves.

I had to write 2 programs in C:

- The first, named `checker` which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
- The second one called `push_swap` which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts integer arguments received.

I was inspired by [Quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm but with a limited set of instructions.

### 🧮 Complexity:

- Worst case : `O(n²)`
- Best case : `O(n log n)`
- Average case : `O(n log n)`
- Memory used :`O(n)`

## 📚 Usage

list of instructions:

| command | description                                                                                                 |
| ------- | ----------------------------------------------------------------------------------------------------------- |
| sa      | `swap a` - Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb      | `swap b` - Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss      | `sa` and `sb` at the same time.                                                                             |
| pa      | `push a` - Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.     |
| pb      | `push b` - Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.     |
| ra      | `rotate a` - Shift up all elements of stack a by 1. The first element becomes the last one.                 |
| rb      | `rotate b` - Shift up all elements of stack b by 1. The first element becomes the last one.                 |
| rr      | `ra` and `rb` at the same time.                                                                             |
| rra     | `reverse rotate a` - Shift down all elements of stack a by 1. The last element becomes the first one.       |
| rrb     | `reverse rotate b` - Shift down all elements of stack b by 1. The last element becomes the first one.       |
| rrr     | `rra` and `rrb` at the same time.                                                                           |

## 🚀 Usage

### 📦 Installation

```bash
git clone git@github.com:tsannie/push_swap_tester.git && cd push_swap_tester
make
```

### 📝 Usage for `checker`

```bash
# Enter instructions on the standard input
ARG="4 12 42 87 51"; ./checker $ARG

# Test the instructions of the push_swap program
ARG="4 12 42 87 51"; ./push_swap $ARG | ./checker $ARG

Options:
    -v : visualizer
    -c : color
```

### 📝 Usage for `push_swap`

```bash
ARG="4 12 42 87 51"; ./push_swap $ARG
```

## 🧪 Test

For test the performance of the program, you can use my [push_swap_tester](https://github.com/tsannie/push_swap_tester) project.

Example with `20` iterations and `500` numbers:

![screen](https://camo.githubusercontent.com/1a2f829e39369e4e6acfe2a2ddc6dc8e1c734fccfb498efdd2c5db3cf4574b60/68747470733a2f2f692e696d6775722e636f6d2f7477355755386f2e706e67)

## 👤 Author

[@tsannie](https://github.com/tsannie)
