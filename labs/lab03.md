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
