Branch Switch Example

Program Name: Concurrency Atomics
Author: CRISPEN LEBLANC
Course: UMGC CMSC335
Date: 11/26/2023
Description:

This program demonstrates the occurance of a data race problem in a multithreaded 
process and showcases how to mitigate it using atomic operations.
 
The program defines two classes, Counter and AtomicCounter, each with a member 
function work() or work2() that is responsible for incrementing a counter variable.
The key difference lies in how these operations are performed. The first class, Counter, 
performs non-atomic operations, while the second class, AtomicCounter, uses an atomic integer
 for atomic operations. 

To simulate concurrency, the program creates multiple threads to execute the work() or 
work2() functions concurrently. After all threads finish, it prints the final values 
of the counters to compare the results.

The non-atomic counters will not count in step with eachother because the threads 
are interleaving in the incrementation operation. Within the incrementation, its 
performing read, modify, and write operations, and both threads are executing each of 
those at different times. As a result the non-atomic counters do not produce the expected
final value.

In contrast, the use of the atomic operations in the AtomicCounter class eliminates the 
data race problem because no other process can read, modify or interupt that operation's 
data. Atomic operations execute as a single, indivisible units, preventing interference 
from other threads. This ensures thread-safe access to the shared counter variable, and 
guarantees the display of the correct final value, 200,000.