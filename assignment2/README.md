# Assignment 2

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
January 30, 2015
Written in C++

## Programming Assignment

### Fibonacci Sequence
This C++ program generates the first *N* Fibonacci numbers. The Fibonacci
sequence has been used in different fields of computer science such as
searching algorithm, heap data structure, parallel computing and distributed
system. By the definition in the modern usage, a Fibonacci number is the sum
of previous two numbers, while the first and second number are 0 and 1
respectively. The mathematical formula defined by the recursion relation below
shows how to compute a Fibonacci number.
  Let *F1* = 0 and *F2* = 1. Then, the *k*-th Fibonacci number is
  > *Fk* = *F(k−2)* + *F(k−1)*, where *k* = 3, 4, . . . , *N*

  For example, the first 5 Fibonacci numbers are 0, 1, 1, 2, 3.

This program does the following:
  1. The program instructs the user to input the number of Fibonacci
    numbers. In the other words, the user should specify N in the formula
    above
  2. The program computes the first N term of Fibonacci sequence
  3. The program displays the first N term of Fibonacci sequence

### Circular Left Shift
This C++ program performs a circular left shift on a series of 10 random
numbers from 0 to 100. The operation of circular left shift moves the series
of numbers to the left by one position and wrap the first number back to the
last number in the series. Please see the example below:
  Before the circular-left-shift operation: 1, 2, 3, 4, 5
  After the circular-left-shift operation: 2, 3, 4, 5, 1

In order to use random number generator associated with time, the following two C libraries “cstdlib” and “ctime” need to be included.

This program does the following:
  1. The program makes the array size as a constant
  2. The program generates 10 random numbers associated with the current time
  3. The program stores 10 random number in an array
  4. The program performs the circular left shift
  5. The program displays the content of array before the circular left shift
  6. The program displays the content of array after the circular left shift

### Classification
This C++ program classifies 10 random numbers from 0 to 100 into 3 groups. In
order to use random number generator associated with time, the following two C
libraries “cstdlib” and “ctime” need to be included.

This program does the following:
  1. The program generates 10 random numbers associated with the current time
  2. The program classifies a random number into one of three groups
    (0-33, 34-66, and 67-100). Each group is represented as an integer array
  3. The program stores a random number into its corresponding group
  4. The program displays the contents of each group

### Optimization
This C++ program computes the minimal production cost and optimal dimensions
of an cylindrical can. The optimal dimensions of cylindrical can are defined
by the radius (*r*) at the base and height (*h*) of can. The production cost
of such a can is related to the size of surface area and has a unit price of
*0.002/cm^2* in US dollars, while the volume of can is *330 ml*. The formulas
to compute the volume and surface area of a cylindrical can are given below:
  > *volume* = *π×r^2×h*
  > *surface_area* = *2π×r^2* + *2π×r×h*
  > *cost* = *UNIT_PRICE* × *surface_area*

This program does the following:
  1. The program defines *π* as the constant of 3.14159
  2. The program defines the unit price as the constant of 0.002 *USD*
  3. The program defines the volume as the constant of 330.0 *ml*
  4. The program computes the cost related to the surface area of cylindrical
      can
  5. The program computes the minimal cost
  6. The program computes the optimal radius or height corresponding to the
      minimal cost.
  7. The program obtains the computation results with precision in 4 decimal
      places
  8. The program displays the optimal radius, optimal height, and minimal cost
