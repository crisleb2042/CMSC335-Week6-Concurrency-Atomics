/* 
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
the data race problem, ensuring thread-safe access to the shared counter.

*/

#include <atomic>
#include <iostream>
#include <thread>

//  Class for non-atomic counter operations
class Counter {
    public:
        int counter = 0;
            //  Member function to increment the counter in non-atomic method
            void work () {
                for (int i = 0; i < 100000; i += 1) {
                    counter += 1;
                }
                
            };
};

//  Class for atomic counter operations
class AtomicCounter {
    public:
        std::atomic<int> counter2 = 0;
        //  Member function to increment the counter in atomic method
        void work2 () {
                for (int j = 0; j < 100000; j += 1) {
                    counter2 += 1;
                }
            }

};

int main() {

    int counter = 0;                //  Non-atomic counter
    std::atomic<int> counter2 = 0;  //  Atomic counter

    Counter work;                  // Create instance of counter class
    AtomicCounter work2;           //  Create instance of AtomicCounter2 class
    
    //  Create threads to run the work() function on the non-atomic counter
    std::thread t1(&Counter::work, &work);
    std::thread t2(&Counter::work, &work);
    //  wait for both threads to finish
    t1.join();
    t2.join();
    //  Prints the non-atomic counter value
    std::cout<< "Non-atomic Counter: " << work.counter << '\n';

    std::thread t3(&AtomicCounter::work2, &work2);
    std::thread t4(&AtomicCounter::work2, &work2);
    //  wait for both threads to finish
    t3.join();
    t4.join();
    //  Prints the atomic counter value
    std::cout<< "Atomic Counter: " << work2.counter2 << '\n';

    return 0;
}