# C_to_MIPS

It is a program for converting from the C language to the MIPS language. The program is designed in the C language and contains many features. It converts all arithmetic operations, if statements, and loops. You can refer to the usage instructions for a better understanding. Additionally, to facilitate and simplify the code, we have made some assumptions that you should take into consideration and read below in order to use the code correctly.

## About us

We are six students at the Faculty of Engineering in Port Said, studying Software Engineering. We have undertaken this project as an application for the Microprocessor course to facilitate the conversion of codes from C to MIPS.

## Compileing
utilize this command to compile the code.
```bash
gcc -Wall -Wextra -Werror -pedantic  -std=gnu89  headers/main.h  *.c  -o mipsify -g
```
or you can just type
```bash
make
```

## Usage instructions

Follow the steps below to use MIPSify on your C code.

### Step 1: Create your C code

First, create your C code and place it in the `/test` directory. For example:

```bash
touch tests/test.txt
```

### Step 2: Run MIPSify

Run the `mipsify` script and provide your C file in the test directory as an argument. For example:

```bash
./mipsify tests/test.txt
```

This will execute the MIPSify tool on your C code and generate the corresponding MIPS assembly code. Ensure that the `mipsify` script has the necessary permissions to execute (`chmod +x mipsify`).

## Code Conversion Assumptions

We have made some assumptions in the code conversion to facilitate the process. Please consider these assumptions while using the code.

### Assumptions:

1. Multiplication Operation:
   - Assume that the multiplication operation is performed using the "mul" instruction.
     ```assembly
     mul $s0, $s1, $s2
     ```

2. "muli" Operation:
   - Assume that there is an operation called "muli" that multiplies a constant by a value already present in memory.
     ```assembly
     muli $s0, $s1, 5
     ```
