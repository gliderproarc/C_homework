A simple C project for learning about file IO and string manipulation

Here is what the program needs to be able to do:

---
Write program that does the following:
+ Open the attached text file (FoxDog.txt)
+ Read each word in the file.
+ Reverse each word in the file.
+ Write each reversed word back out to a new file.
---

Looks pretty simple. I am imagining a single C source file that has 3 functions:
1. A function that takes a .txt file and store all the contents as a nested vector, where the fist grouping is a lines and the second grouping is words delimited by white space
2. The I need a function that takes the items in the nested list and reverses the order of the characters. Something like a for loop that goes through each of the elements in the vector, takes the list of words that makes up each line, and reverses the order of the strings.
3. Lastly, a function that handles writing to a new file. Take a vector like the first one (overwrite? modify in place?) and write it out to a file with the same rules, space delimiting items in a list, and the newlines to separate those lists of words.


First things first, let's get a .org file going to get these functions tested.

---
Okay, all finished. The final program is in this directory called "final", and it's complied from the code in the source file "main.c".
