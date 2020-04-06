# Programming Assignment 2: Search Trees
In this Programming Assignment, you will be assessing your understanding of Binary Search Trees and K-D Trees.

## Part 1: Tree Balance (20 points)
The time complexity of algorithms on many tree structures depends significantly upon the "balance" of the tree. Trees can be *perfectly balanced*, *perfectly unbalanced*, or somewhere in between.

### Task 1a: Create ``1a.txt`` (5 points)
Imagine we have created a Binary Search Tree by inserting the following sequence of integers into an empty Binary Search Tree (in this exact order):

```
10, 20
```

Create a file called ``1a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when added after the above sequence of integers, will result in a **perfectly *un*balanced** tree.

### Task 1b: Create ``1b.txt`` (5 points)
Imagine we have created a Binary Search Tree by inserting the following sequence of integers into an empty Binary Search Tree (in this exact order):

```
10, 20
```

Create a file called ``1b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a single integer that, when added after the above sequence of integers, will result in a **perfectly balanced** tree.

### Task 1c: Create ``1c.txt`` (5 points)
Create a file called ``1c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a comma-separated list of 7 integers that, when added to an empty Binary Search Tree, will result in a **perfectly *un*balanced** tree.

### Task 1d: Create ``1d.txt`` (5 points)
Create a file called ``1d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as  [``README.md``](README.md)) containing a comma-separated list of 7 integers that, when added to an empty Binary Search Tree, will result in a **perfectly balanced** tree.

## Part 2: Implementing a Binary Search Tree (40 points)
Much of the beginning of this course is centered around [Binary Search Trees (BSTs)](https://en.wikipedia.org/wiki/Binary_search_tree). As such, it is important for us to be able to implement the basic functionality of a BST.

### Task: Edit [``BST.cpp``](BST.cpp) (``BST`` functions)
In this repository, there is a file called [``BST.cpp``](BST.cpp) that contains the initial steps towards implementing a BST. Function headers (with usage details) are included in [``BST.h``](BST.h), and you need to fill in the constructor, destructor, and all functions of the ``BST`` class. Note that, at this point in the PA, we do not expect you to fill in the ``BST::Node::successor()`` function: that will be in a later part of this PA.

We have provided a tester program, [``BSTTest``](BSTTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -O3 -std=c++11 -o BSTTest BSTTest.cpp BST.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```
$ g++ -Wall -pedantic -O3 -std=c++11 -o BSTTest BSTTest.cpp BST.cpp
$ ./BSTTest
Success
```

If it prints anything *other* than ``Success``, that means it has bugs. We expect you to be able to debug your code however you feel is best (e.g. print statements, ``gdb``, etc.).

### Checking for Memory Leaks
Remember that you will be dynamically creating ``Node`` objects, so beware of memory leaks! You can use ``valgrind`` to check for memory leaks. For example, you can run it as follows:

```bash
valgrind --tool=memcheck --leak-check=yes ./BSTTest
```

If it gives you a report like the following, you do not have memory leaks and are good to go (the important part is ``All heap blocks were freed -- no leaks are possible``):

```
==2129== Memcheck, a memory error detector
==2129== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2129== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2129== Command: ./BSTTest
==2129==
==2129== error calling PR_SET_PTRACER, vgdb might block
==2129==
==2129== HEAP SUMMARY:
==2129==     in use at exit: 0 bytes in 0 blocks
==2129==   total heap usage: 316 allocs, 316 frees, 83,936 bytes allocated
==2129==
==2129== All heap blocks were freed -- no leaks are possible
==2129==
==2129== For counts of detected and suppressed errors, rerun with: -v
==2129== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

If you *do* have memory leaks, the report will look something like the following:

```
==2178== Memcheck, a memory error detector
==2178== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2178== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2178== Command: ./BSTTest
==2178==
==2178== error calling PR_SET_PTRACER, vgdb might block
==2178==
==2178== HEAP SUMMARY:
==2178==     in use at exit: 3,200 bytes in 100 blocks
==2178==   total heap usage: 312 allocs, 212 frees, 83,816 bytes allocated
==2178==
==2178== 3,200 (32 direct, 3,168 indirect) bytes in 1 blocks are definitely lost in loss record 3 of 3
==2178==    at 0x4C3017F: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2178==    by 0x1095A1: BST::insert(int) (in /mnt/c/Users/niema/Desktop/PA2-Solution/BSTTest)
==2178==    by 0x108F54: main (in /mnt/c/Users/niema/Desktop/PA2-Solution/BSTTest)
==2178==
==2178== LEAK SUMMARY:
==2178==    definitely lost: 32 bytes in 1 blocks
==2178==    indirectly lost: 3,168 bytes in 99 blocks
==2178==      possibly lost: 0 bytes in 0 blocks
==2178==    still reachable: 0 bytes in 0 blocks
==2178==         suppressed: 0 bytes in 0 blocks
==2178==
==2178== For counts of detected and suppressed errors, rerun with: -v
==2178== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

## Part 3: BST Successor (25 points)
One can iterate over the elements of a BST in ascending order by starting at the left-most node in the BST (which is the smallest element) and one-by-one finding each node's [successor](https://www.youtube.com/watch?v=XX_2nHNICO4&list=PLM_KIlU0WoXmkV4QB1Dg8PtJaHTdWHwRS).

### Task: Edit [``BST.cpp``](BST.cpp) (``BST::Node::successor()``)
Now that you have implemented the member functions of the ``BST`` class, it's time to implement ``BST::Node::successor()``, which will find the successor of the current node.

We have provided a tester program, [``SuccessorTest``](SuccessorTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -O3 -std=c++11 -o SuccessorTest SuccessorTest.cpp BST.cpp
```

Here's an example of how it should look like when it's compiled and run from the command line:

```
$ g++ -Wall -pedantic -O3 -std=c++11 -o SuccessorTest SuccessorTest.cpp BST.cpp
$ ./SuccessorTest
Success
```

If it prints anything *other* than ``Success``, that means it has bugs. We expect you to be able to debug your code however you feel is best (e.g. print statements, ``gdb``, etc.).

## Part 4: K-D Trees (15 points)
The [K-Dimensional (or K-D) Tree](https://en.wikipedia.org/wiki/K-d_tree) is an extension of a BST for multi-dimensional data. Essentially, all tree algorithms of a K-D Tree are the same as those for a BST, except in a K-D tree, you alternate between dimensions for each level. For example, in a K-D Tree storing 3-dimensional points, we would only compare the root's *x*-coordinate with our query's *x*-coordinate; on the next level, we would only compare *y*-coordinates; on the next level, we would only compare *z*-coordinates; on the next level, we would only compare *x*-coordinates; etc.

### Task 4a: Create ``4a.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 2D points into an empty K-D Tree (in this exact order):

```
(7,2), (5,4), (9,6), (4,7), (2,3), (8,7)
```

Create a file called ``4a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 2D integer point in the format ``(x,y)`` that, when added after the above sequence of points, will result in a **perfectly balanced** tree.

### Task 4b: Create ``4b.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 3D points into an empty K-D Tree (in this exact order):

```
(21,42,63), (10,100,1000), (3,6,9)
```

Create a file called ``4b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 3D integer point in the format ``(x,y,z)`` that, when added after the above sequence of points, will result in a **perfectly *un*balanced** tree.

### Task 4c: Create ``4c.txt`` (5 points)
Imagine we have created a K-D Tree by inserting the following sequence of integer 4D points into an empty K-D Tree (in this exact order):

```
(10,30,50,70), (20,40,60,80), (15,30,45,60), (100,10,1,0)
```

Create a file called ``4c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a 4D integer point in the format ``(x1,x2,x3,x4)`` that, when added after the above sequence of points, will result in a **perfectly *un*balanced** tree.

## General Tips
We have provided a [``Makefile``](Makefile) to make compilation more convenient. Instead of having to type the ``g++ ...`` command each time you want to recompile your code, you can simply type ``make``. Here's an example of how it should look:

```
$ make
g++ -Wall -pedantic -O3 -std=c++11 -o BSTTest BSTTest.cpp BST.cpp
g++ -Wall -pedantic -O3 -std=c++11 -o SuccessorTest SuccessorTest.cpp BST.cpp
```

If you want to clean up your environment by deleting all the compiled executables, you can simply type ``make clean``. Here's an example of how it should look:

```
$ make clean
rm -f BSTTest SuccessorTest *.o
```

Feel free to [read more about what a ``Makefile`` does](https://www.geeksforgeeks.org/makefile-in-c-and-its-applications/) if you're curious!

## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 1: Tree Balance**
    * 5 points for a correct ``1a.txt`` (0 points for incorrect)
    * 5 points for a correct ``1b.txt`` (0 points for incorrect)
    * 5 points for a correct ``1c.txt`` (0 points for incorrect)
    * 5 points for a correct ``1d.txt`` (0 points for incorrect)
* **Part 2: Implementing a Binary Search Tree**
    * 40 points for a correct solution with no memory leaks
    * 30 points for a correct solution with memory leaks
    * 0 points for an incorrect solution
* **Part 3: BST Successor**
    * 25 points for a correct solution
    * 0 points for an incorrect solution
* **Part 4: KD-Tree**
    * 5 points for a correct ``4a.txt`` (0 points for incorrect)
    * 5 points for a correct ``4b.txt`` (0 points for incorrect)
    * 5 points for a correct ``4c.txt`` (0 points for incorrect)
