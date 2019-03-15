% Add more space between paragraphs
\parskip 4pt plus 1pt

@*Project Euler Problem 1. This program solves the first problem of project euler - sum all natural numbers divisible by 3 or 5 below 1000.

Please note this describes a C++ program and the code output should have its file extension changed to cpp and compiled with a C++ compiler such as g++.

This is the skeleton of the program.
@c
@<includes@>@;
@<main function@>@;

@ We should only need {\tt iostream}. We include it here.
@<includes@>=
#include <iostream>

@ This should be pretty simple. Let's define the main function.
@<main function@>=
int main()
{
@<main variables@>@;
@<summation loop@>@;
@<output answer@>@;
return 0;
}

@ The only variable we actually need should be |sum|. A counter will also be used but that will be only within the summation loop and can be defined there. We initialise to zero so that we can use it to add numbers together (technically, because 0 is the identity for addition ;p).
@<main variables@>=
int sum = 0;

@ Now we define the summation loop. It runs from 1 to 999, tests each for divisibility with 3 or 5, and adds the number to sum if the test is successful.
@<summation loop@>=
for (int i = 1; i != 1000; ++i)
{
    if (i % 3 == 0 || i % 5 == 0)
        sum += i;
}

@ The only thing left to do is output the answer.
@<output answer@>=
std::cout << "sum: " << sum << std::endl;
