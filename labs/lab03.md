---
title: Lab - Types and Math
---

# Lab - Types and Math

## Copying, Moving and Deleting Files in the Terminal

**Disclaimer**: The terminal is a very powerful tool. And with great power, there must also come great responsibility[^1]. Be aware that mistakes at the terminal can delete important files without warning, so be sure your work is always backed up.

[^1] Uncle Ben

### `cp`

The `cp` command "copies" files from one location to another. It's used with two arguments:

1. source: the name of the file that you want to copy
2. destination: the filename that you want to use for the new copy (or directory where you want it placed using the same name)

Examples:

To copy a.txt into a file called b.txt:

```bash
cp a.txt b.txt
```

You can copy files from or to any other directory by specifying a path.  To copy the file c.txt from the parent folder to a file with the same name in the grandparent folder:

```bash
cp ../c.txt ../../c.txt
```

To copy the file d.txt in my Downloads folder to the current directory. If you specify a directory as a destination, it will create a file with the same name there.

```bash
cp ~/Downloads/d.txt .
```

`cp` can also copy directories if you use the `-r` flag. The "r" stands for "recursive", meaning to copy the directory and all files and sub-directories in it, recursively. Example:

To copy the directory "other/" into a directory called "other2/":

```bash
cp -r other other2
```

Here's a summary of how the `cp` command behaves:

| Source      | Destination        | What Happens |
| ----------- | ------------------ | ------------ |
| filename    | unused name        | A file is created at the destination with identical contents to the source |
| filename    | existing filename  | The existing file at the destination is deleted and replaced with a copy of the source file. |
| filename    | existing directory | File is copied inside the existing directory using the original filename. |
| directory   | unused name        | Without -r option, error (nothing happens); with -r, recursively copies directory contents to a new directory created with the destination name. |
| directory   | existing filename  | Command fails; the existing file at the destination remains unchanged.
| directory   | existing directory | Without -r option, error (nothing happens); with -r, recursively copies directory contents to a new directory with the source name, but inside destination directory. |

Finally, note that multiple files can be copied simultaneously as long as the destination is a directory to copy them all into, otherwise keeping the same filenames.  For example:

```bash
cp file1.txt file2.txt file3.txt target_dir/
```

Try copying some files:

1. [Save this zip file to your My Documents folder.](../assets/downloads/lab_terminal.zip)
2. Right click the zipped file in My Documents and select "Extract Here". You should now have a folder called "lab02".
3. `cd` into My Documents (`cd ~/My_Documents`).
4. `cd` to the folder named "lab02", then to the subfolder named "b_folder", then to the folder named "start".
5. If you run `ls`, you should see a folder named "other" and a file named "f.txt".
6. Copy the file named "f.txt" to the file "f2.txt".
7. Copy the folder named "a_folder" to the working directory. The "a_folder" is in the same folder as "b_folder".

⭐ Please show your TA the output from `ls`. There should be four items in the folder named "start":

- f.txt
- f2.txt
- other/
- a_folder/

### `mv`

The `mv` command is short for "move" and is identical to `cp`, except the original source doesn't exist after it has been moved to the destination. `mv` does not need the `-r` flag to move folders, it is happy to move folders just like files. Example:

```bash
mv other other2
```

Run the above command, and confirm the the "other" folder no longer exists, and that there's now an "other2" folder present. Be sure your working directory is the "start" folder.

The `mv` command should be used when you want to rename directories.

### `rm`

The `rm` command is short for "remove". 

**Warning**: files deleted with `rm` are gone forever. They don't go to the Recycle Bin. Please be careful with `rm`.

The `rm` command takes one argument: the file or folder you wish to delete. Like `cp`, if you wish to delete a folder, you need to supply the `-r` flag.

For example, to deletes the file f.txt use:

```bash
rm f.txt
```

To deletes the directory a_folder/, and everything within it type:

```bash
rm -r a_folder
```

## Coding Assignment

### Background

There are many properties of numbers that one can investigate. The ancient Greeks were fascinated by the properties of integers, even ascribing them mystical properties.

One such property is an integer's _additive persistence_, and its resulting _additive root_ ([more information](http://mathworld.wolfram.com/AdditivePersistence.html)). Additive persistence is a property of the sum of the digits of an integer. The sum of the digits is found, and then the summation of digits is performed, creating a new sum. This process repeats until a single integer digit is reached. Consider the following example:

1.  The beginning integer is 1234
2.  The sum of its digits is 1+2+3+4 = 10
3.  The integer is now 10
4.  The sum of its digits is 1+0 = 1
5.  The integer is now 1. When the value reaches a single digit, we are finished. This final integer is the additive root.

The number of cycles is the additive persistence. The integer, 1234, has an additive persistence of 2 (first sum was 10, then the second sum was 1). The final digit reached is called the integer's additive root. The integer, 1234, has an additive root of 1.

### Program Specifications

Accept a series of integers from standard input (`cin`). The program ends under one of the following circumstances (meaning that we repeat this entire process -- use a loop):
1.  If the next gathered integer is a negative number
2.  If all the integers from the file have been processed (EOF encountered, i.e., `cin` returns `false`)

If the given integer is a single digit, report its additive persistence as 0, and its additive root as itself on a single line as two space-separated numbers

For each multi-digit, non-negative integer, output on a single line the two space-separated numbers:
1.  The integer's additive persistence
2.  The integer's additive root

⭐ Please show the TA your working program.

### Assignment Notes

How do you get started on a program like this?

1.  Break the problem down into parts. Here are some obvious ones:
    - Gather input from the file, and check for negative numbers (the quit condition)
    - Check if the input is between 0 and 9 (that's a special case, as indicated above)
    - Otherwise, write a loop that calculates the persistence (track the count through this loop)
    - Inside that loop, write another loop that can sum the digits of an integer until it reaches a single digit
2.  How do you get the digits of an integer? Look at using a combination of the division (`/`) and modulus (`%`) operators.
3.  As you try to get this program working, add some "diagnostic output" so you can be sure that it is running like you expect it to. For each pass through the loop of the additive persistence, print each new integer created. You can always fix it to give the exact, required output later.

### Want to do more?

There is also a multiplicative persistence. Put that in your loop and calculate it for each number.

The _multiplicative persistence_ ([see this page for more information](http://mathworld.wolfram.com/MultiplicativePersistence.html)) and resulting _multiplicative root_ are determined the same way, only multiplying the digits of an integer instead of adding. For example:

1.  The beginning integer is 1234
2.  The product of its digits is 1\*2\*3\*4 = 24
3.  The integer is now 24
4.  The product of its digits is 2\*4 = 8
5.  The integer is now 8. When the value reaches a single digit, we are finished. This final integer is the multiplicative root

As before, the number of cycles is the multiplicative persistence. The final digit reached is called the integer's multiplicative root. The integer, 1234, has an multiplicative persistence of 2, and a multiplicative root of 8.

### Things to Think About

- What type should the numeric values be (`int`? `long`?) and why?
- What is the largest `long` you can have?
- What happens when you enter a number that is too large? For example, the smallest number with an additive persistence of 4 is 19999999999999999999999. Can you make your calculation with that number?


## Honors Material - Accessing individual bits in numbers

In the lab above, you explored working with individual values in C++.  Those values (and all other data in C++) are stored as a series of bits (0s and 1s).  Those bits are accessible individually and can sometimes be informative about the underlying numbers.

### Background

A regular `int` in C++ is typically encoded using 32 bits: one bit to indicate the sign of the value (i.e., should it have a minus sign out front?) and another 31 bits to indicate the magnitued.  The encoding for integers is called [twos-complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). An `unsigned int`, on the other hand, is a simple binary number, since all values are positive.

In the base-ten number system that we are all used to using in everyday life, the right-most digit tells us how many 1's there are in the number, the next says how many tens, the next how many hundreds, and so on -- each time we move left a digit we multiply by 10 and continue up through all powers of 10 that we need.  Thus the number 154 has a four 1s plus five 10s plus a single 100.  All very intuitive to us.

When we encode numbers in binary it's a similar system.  The right-most bit tells us how many ones there are in the value, and then each bit as your move left tells you how many 2s, 4s, 8s, etc, multiplying by two each time instead of ten.  Each position represents whether the associated power of two should be added to the value.

Consider the binary value 10011010.  Working from left to right, there are no 1s, one 2, no 4s, one 8, one 16, no 32s, no 64, and one 128.  To figure out what value this number represents we would add up all of the positions with ones and get 2+8+16+128 = 154.  If we wanted to directly represent a binary value as a literal in C++ we just need to put `0b` at the beginning.  So typing `0b10011010` would create the same value as typing `154`.

Counting in binary also follows the same rule as in decimal.  Increment the left-most position if you can.  If you're already at the maximum digit (9 in decimal or 1 in binary) loop back around to zero and increment the next position to the left.  In all cases you can have leading zeros without changing the value.

| Binary | Decimal |
| ------ | ------- |
|  0000  |   00    |
|  0001  |   01    |
|  0010  |   02    |
|  0011  |   03    |
|  0100  |   04    |
|   ...  |   ...   |
|  1001  |   09    |
|  1010  |   10    |
|  1011  |   11    |
|  1100  |   12    |
|   ...  |   ...   |

The computer always represents unsigned integers in binary.  Only when we ask C++ to print a value does it convert it to decimal in order to make it easier for us to understand.

There are six operators in C++ that allow us to directly interact with the binary representation of a value.  If you use them with `unsigned` values, they will operate on each bit individually, and thus they are called "bitwise" operations.  Let us assume that we have two 8-bit unsigned variables, defined as follows:

```c++
uint8_t a = 0b00001111;
uint8_t b = 0b01010101;
```

| Operator    | Symbol | Example | Result       | Explanation |
| ----------- | ------ | ------- | ------------ | ----------- |
| bitwise not |  `~`   | `~a`    | `0b11110000` | Toggle every bit in the binary representation of the value `a`. |
| shift left  |  `<<`  | `a << 1`| `0b00011110` | Move all of the bits in `a` to the left based on the second number. Use zeros for all new bits. |
| shift right  |  `>>` | `a >> 2`| `0b00000011` | Move all of the bits in `a` to the right based on the second number. Use zeros for all new bits. |
| bitwise and |  `&`   | `a & b` | `0b00000101` | Pair up bits in `a` and `b`.  If both are 1, put a 1 at that position in the result. |
| bitwise or  |  `|`   | `a | b` | `0b01011111` | Pair up bits in `a` and `b`.  If either is 1, put a 1 at that position in the result. |
| bitwise xor |  `^`   | `a ^ b` | `0b01011010` | Pair up bits in `a` and `b`.  If they are different, put a 1 at that position in the result. |

These operators make it possible to read or manipulate individual bits.  For example if I use `x & 1` the result will be the same as the last bit in `x`.

If I wanted to print the count the number of ones in the binary representation of the variable `x`, I could do something like:

```c++
uint32_t x = 2113;
size_t count = 0;                   // Track the count of ones here.
for (size_t i = 0; i < 32; ++i) {   // Go through each bit position in x.
  if (x & (1 << i))) { count++; }   // Shift the a 1 to the target position; use "&" to single it out.
}
std::cout << "The variable x has " << count << " ones in its binary encoding." << std::endl;
```

In the above example, the final count would be 3 (1 + 64 + 2048 = 2113).

### Assignment

You are going to write a program that reads in one or more unsigned integers (with `std::cin`) and outputs how each integer would be converted from binary (from least significant value to most).

For example, if you read in the value 2113 (as in the example above) you would output: `1+64+2048`.  Conveniently the conversion from decimal (the input number) to binary happens automatically.  So you just need to step through the bits of the loaded value, track what number each bit position is associated with, and print them when needed.

There is a Coding Rooms honors assignment for this lab; use that to test and submit your program.

A few notes:
* Numbers can be large.  Make sure to use an `unsigned int` to load them into.
* If only one bit is set, print the associated number by itself.  For example, `0b01000000` should output `64`.
* If NO bits are set, you should just output a single `0`.
* Pluses should only come between the powers of two that are being summed.  You should track if you've already output any values as part of the current response and, if so, output a `+` before the next number.

### Trivia

As always, this section is not part of your coursework, but open to all who want to learn more details.

The number of digits used in a number system is called its [radix](https://en.wikipedia.org/wiki/Radix) or base.  Decimal has a radix of 10 and is referred to as a "base 10 counting system"; there are ten possible digits in each position and we multiply by 10 as we move from left to right. Binary has a radix of 2 (a "base two counting system") so there are two possible bits (0 or 1) and we multiply by two as we go.  In other numbering systems, the same rules apply -- in octal there are eight possible symbols at each position (0 through 7) and we multiply by 8; in hexadecimal there are 16 possible symbols (0-9 and A-F) and we multiply by 16.  These are all number systems that turn out to be important in computer science.  [This page](https://en.cppreference.com/w/cpp/language/integer_literal) discusses how to use any of these bases for integer literals in C++.

There is an entire set of algorithms that take advantage of the binary encodings of values on computers.  They are referred to as "Bit Magic", with a good library of them [here](http://graphics.stanford.edu/~seander/bithacks.html). Beware though - these algorithms can be incredibly tricky and far beyond the scope of this course.  To give one example, a faster version of the bit-counting algorithm above looks like this:

```c++
uint32_t x = 2113;
size_t count = 0;       // Track the count of ones here.
while (x) {             // Keep going while there are any ones left in x.
  x = x & (x - 1);      // Remove the right-most 1 from x.
}
std::cout << "The variable x has " << count << " ones in its binary encoding." << std::endl;
```

This algorithm systematically removes each one from the variable `x`, counting them as it goes.  It stops when there are no ones left in the binary representation of the number.  The tricky part is the line `x = x & (x - 1)`.  If the right side were `x & x` it would always return `x` since any value bitwise-anded to itself is that same value again.  But subtracting one from one of the x's disrupts the right-most 1 in the representation, resulting in something close to the original `x` but with that right-most 1 removed.  This is the sort of trick that most programmers would never think of on their own, but can be useful for more efficient code if you need it.  While the first bit-counter always looped 32 times, this new version loops once for each 1 that is counted.
