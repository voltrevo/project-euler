% Add more space between paragraphs
\parskip 4pt plus 1pt

@*Project Euler Problem 2. This program finds the summation of the even fibonacci numbers that do not exceed four million.

Please note this describes a C++ program and the code output should have its file extension changed to cpp and compiled with a C++ compiler such as g++.

This is the skeleton of the program.
@c
@<includes@>@;
@<main function@>@;

@ We should only need to include {\tt iostream}.
@<includes@>=
#include <iostream>

@ Here the structure of the main function is defined. We only need a few variables, a loop to calculate and conditionally add primes to a sum, and an output of the answer.
@<main function@>=
int main()
{
@<main variables@>@;
@<summation loop@>@;
@<output answer@>@;
return 0;
}

@ We're going to need to keep track of two fibonacci numbers at a time. This is because the fibonacci numbers are defined by a recurrence relationship that depends on the previous two terms, and we will use this as a straightforward approach to calculating them. The first two fibonacci numbers are $1$ so these two fibonacci numbers will be initialised to 1. Neither of these are even so they will not need to be added to the sum. We also need to keep track of the |sum|.
@<main variables@>=
int fibA = 1;
int fibB = 1;
int sum = 0;

@ Now we define the summation loop. The loop should exit when either |fibA| or |fibB| exceeds four million, but |fibA| and |fibB| will be updated at different times, so we'll just use |true| instead of a terminating condition and rely on break statements for the loop's termination.

Statements marked with (1) calculate the fibonacci numbers. The fibonacci numbers are defined via the recurrence relationship $fib(n) = fib(n - 1) + fib(n - 2)$ and $fib(1) = fib(2) = 1$. So, in |fibA += fibB;| |fibB| was the last fibonacci number and |fibA| the one before it, so after execution |fibA| stores the next fibonacci number. Similarly for the other statement marked with (1).
@<summation loop@>=
while (true)
{
    fibA += fibB; // (1)
    if (fibA > 4000000)
        break;
    
    if (fibA % 2 == 0)
        sum += fibA;
    
    fibB += fibA; // (1)
    if (fibB > 4000000)
        break;
    
    if (fibB % 2 == 0)
        sum += fibB;
}

@ After that is done we just output the result.
@<output answer@>=
std::cout << "sum: " << sum << std::endl;

@*Index.
