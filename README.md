# C_to_MIPS

Compile using the command:

<pre>
gcc -Wall -Wextra -Werror -pedantic  -std=gnu89  headers/main.h  \*.c  -o mipsify -g
</pre>

Run using the command:

<pre>
./mipsify <file>
</pre>

## How to use it

1. first you have to creat your C code and put it in `/test` directory.

    - for example:
    ><pre>touch tests/test.txt</pre>
2. run the mipsify file and add your file in test dirctory as argment

    - for example:
    ><pre>./mipsify tests/test.txt</pre>
