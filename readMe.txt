Branch Switch Example

Program Name: Concurrency Atomics
Author: CRISPEN LEBLANC
Course: UMGC CMSC335
Date: 11/26/2023
Description:

This program demonstrates the difference between non-atomic and atomic operations
on a shared integer counter and solves the problem of data races and how to avoid them. 
It uses two classes, Counter and AtomicCounter, each with a member function work() 
that increments a counter variable. The first class, Counter, performs non-atomic 
operations, while the second class, AtomicCounter, uses an atomic integer for 
atomic operations. The program creates multiple threads to run the work() or 
work2() functions concurrently. After all threads finish, it prints the final 
values of the counters to compare the results. 

The non-atomic counters will not count in step with eachother because the threads 
are interleaving in the incrementation operation. Within the incrementation, its 
doing a read, modify, and write operation, and both threads are executing each of 
those at different times. The use of the atomic operations in AtomicCounter eliminates 
the data race problem because no other process can read, modify or interupt that 
operation's data, ensuring thread-safe access to the shared counter.