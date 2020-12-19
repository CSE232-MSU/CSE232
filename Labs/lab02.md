# Lab 02 - Types and Math

## Copying, Moving and Deleting Files in the Terminal

Disclaimer: the terminal is a very powerful tool. And with great power, comes great responsibility (Uncle Ben). Be aware that mistakes at the terminal can break computers and delete important files, so be sure your work is always backed up.

### cp

The `cp` command "copies" files from one path (location) to another. The `cp` is used with two arguments:

1.  The source file: This is the file you want to copy.
2.  The destination file: This is where you want your copy to be placed

You copy files that are in you working directory or by specifing a path to the file. Examples:

<pre>cp a.txt b.txt           # This copies a.txt into a file called b.txt

cp ../c.txt ../../c.txt
# This copies c.txt (which is in the parent folder) to a file called c.txt (which is in the grandparent folder)

cp ~/Downloads/d.txt .
# This copies the d.txt file in my Downloads folder to the current directory
# If you specify a directory as a destination, it will create a file with the same name there.
</pre>

The `cp` can also copy directories if you use the `-r` flag. The "r" stands for recursive, meaning to copy the directory and all sub-directories of it. Example:

<pre>cp -r other other2 # copies the directory "test" into a directory called "test2"</pre>

1.  Save the file ([lab02_folder.zip](lab02/lab02_folder.zip)) to your My Documents. You may need to right click the link and select "Save Link As ..."
2.  Right click the zipped file on the My Documents and select "Extract Here". You should now have a folder called "lab02_folder" on your Documents now.
3.  Change directories to the My Documents (`cd ~/My_Documents`).
4.  `cd` to the folder named "lab02_folder", then to the subfolder named "b_folder", then to the folder named "start".
5.  If you run `ls`, you should see a folder named "other" and a file named "f.txt".
6.  Copy the file named "f.txt" to the file "f2.txt".
7.  Copy the folder named "a_folder" to the working directory. The "a_folder" is in the same folder as "b_folder".

![](Red_star.svg) Please show your TA the output from `ls`. There should be four items in the folder named "start":

*   f.txt
*   f2.txt
*   other/
*   a_folder/

### mv

The `mv` command is short for move and is identical to cp, except the original source doesn't exist after if is moved to the destination. Also, `mv` doesn't need the `-r` flag to move folders, it is happy to move folders just like files. Example:

<pre>mv other other2</pre>

Run the above command, and confirm the the "other" folder no longer exists, and there's now a "other2" folder present. Be sure your working directory is the "start" folder.

The `mv` command is often used to rename directories and folders.

### rm

The `rm` command is short for remove (delete). **WARNING: files deleted with `rm` are effectively gone forever. They don't go to the TrashCan/RecycleBin. So please be careful with `rm`.**

The `rm` command takes one argument: the file or folder you wish to delete. Note: if you wish to delete a folder, you need to supply the `-r` flag. Example:

<pre>rm f.txt # Deletes the file f.txt
rm -r a_folder # Deletes the folder a_folder and everything within it.</pre>

## Lab Assignment

### Assignment Overview

The aim of this assignment is practice the use of while loops and conditionals statements. You are going to write a program that prompts the user for an integer and then determines the **additive persistence** and corresponding **additive root**. You will continue prompting the user for an integer until they enter a negative number which indicates they are finished.

### Background

There are many properties of numbers that one can investigate. The ancient Greeks were fascinated with the properties of integers, even ascribing them mystical properties.

One such property is an integer's additive persistence and its resulting additive root (see: [http://mathworld.wolfram.com/AdditivePersistence.html](http://mathworld.wolfram.com/AdditivePersistence.html)). Additive persistence is a property of the sum of the digits of an integer. The sum of the digits is found, and then the summation of digits is performed creating a new sum. This process repeats until a single integer digit is reached. Consider the following example:

1.  The beginning integer is 1234
2.  The sum of its digits is 1+2+3+4 = 10
3.  The integer is now 10
4.  The sum of its digits is 1+0 = 1
5.  The integer is 1\. When the value reaches a single digit, we are finished. This final integer is the additive root

The number of cycles is the additive persistence. The integer 1234 has an additive persistence of 2 (first sum was 10, then the second sum was 1). The final digit reached is called the integer's additive root. The additive digital root of 1234 is 1.

### Program Specifications

The program should run as follows.

1.  Program should accept a series of integers from standard input (cin). The program ends under one of the following circumstances:
    1.  the next gathered integer is a negative number
    2.  if all the integers from the file have been processed (EOF encountered, cin returns false)
2.  If the given integer is a single digit, report its additive persistence as 0 and its additive root as itself on a single line as two space-separated numbers
3.  For each multidigit, non-negative, integer output on a single line the two space-separated numbers:
    1.  the integer's additive persistence
    2.  the integer's additive root

![](Red_star.svg) Please show your TA your working program.

### Getting Started

1.  Break the problem down into parts. Some obvious parts:
    1.  gather input from the file, and check for negative numbers (the quit condition)
    2.  check if the input is between 0 and 9 (that's a special case as indicated)
    3.  otherwise, write a loop that calculates the persistence (track the count through this loop)
    4.  inside that loop, write a loop that can sum the digits of an integer until it reaches a single digit
2.  How do you get the digits of an integer? Look at a combination of division (`/`) and remainder(`%`) operators on integers.
3.  I would add some 'diagnostic output' so you can be sure things are working as they should. For each pass through the loop of the additive persistence, print each new integer created. Feel free to always do this as you need to work on your ability to debug problems. You can always fix it to give the exact, required output later.

### Want to do more?

There is also a multiplicative persistence. Put that in your loop and calculate it for each number.

The **multiplicative persistence** (see: [http://mathworld.wolfram.com/MultiplicativePersistence.html](http://mathworld.wolfram.com/MultiplicativePersistence.html)) and resulting **multiplicative root** are determined the same way, only multiplying the digits of an integer instead of adding. For example:

1.  The beginning integer is 1234
2.  The product of its digits is 1*2*3*4 = 24
3.  The integer is now 24
4.  The product of its digits is 2*4 = 8
5.  The integer is 1\. When the value reaches a single digit, we are finished. This final integer is the multiplicative root

As before, the number of cycles is the multiplicative persistence. The final digit reached is called the integer's multiplicative root. The integer 1234 has an multiplicative persistence of 2 and a multiplicative root of 8.

### Things to think about

*   what type should the integers be (int, long) and why
*   what is the largest long you can have (look it up)
*   what happens when you enter a number that is too large? For example, the smallest number with and additive persistence of 4 is 19999999999999999999999\. Can you make your calculation with that number?