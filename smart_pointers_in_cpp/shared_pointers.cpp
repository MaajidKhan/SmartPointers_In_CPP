/*
There are few points about it:
0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
1. Several shared_ptr can point to the same object (managed object).
2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
   and once last shared_ptr goes out of scope then the managed object gets deleted.

Trivia:
1.
control block keeps track of reference count of your managed object. whenever you assign your smart pointer to
another smart pointer, this control block will kick in and increment the reference count.
once the last shared_ptr goes out of scope, then the managed object gets deleted.

2.
<  control block is thread safe  >
The Reference count in control block is thread safe as per the c++ standards. No matter, how many times you declare
and re-assign shared_ptr, the count increment/decrement is automatically taken care of in a thread-safe manner.


3. shared_ptr is threads safe and not thread safe. [what is this??]
   a. control block is thread safe
   b. managed object is not
   It is not thread safe. we can use mutex and other methods to make it thread safe manually.
4. There are three ways shared_ptr will destroy the managed object.
   a. If the last shared_ptr goes out of scope.
   b. If you initialize shared_ptr with some other shared_ptr.
   c. If you reset shared_ptr.
5. Reference count doesn't work when we use reference (Address of the shared_ptr) or pointer of shared_ptr.
*/
#include <iostream>
using namespace std;
#include <memory>
#include <thread>

class Foo
{
    int x;
    public :
    Foo(int x): x{x} {}
    int getX() { return x; }
    ~Foo() { cout << "~Foo" << endl; }
};

void fun(std::shared_ptr<Foo> sp)
{
    cout << "fun: " << sp.use_count() << endl;
}

int main()
{
    /*
    Foo *f = new Foo(1);
    cout << f->getX() << endl;
    // delete f; // There's a risk that you might forget writing this line of code leading to memory leak.
    */
    shared_ptr <Foo> sp(new Foo(1));
    // auto sp = std::make_shared<Foo>(1); //One more way of declaring a shared_ptr
    cout << sp->getX() << endl;
    cout << "The use count  for sp is: " << sp.use_count() << endl;  // prints 1

    cout << " - -  - - - - - - - - -" << endl;
    shared_ptr <Foo> sp1 = sp; //Assigning sp as value to sp1 (will work)
    cout << sp1->getX() << endl;
    cout << "The use count for sp1 is: " << sp1.use_count() << endl; // prints 2
    cout << "The use count for sp is: " << sp.use_count() << endl;   // Now sp also prints 2

    cout << " - -  - - - - - - - - -" << endl;

    shared_ptr <Foo> &sp2 = sp; //Assigning sp to a refrence variable sp2. You will get same use_count
    //No increment, as you are just referencing it to the older object (sp)
    cout << sp2->getX() << endl;
    cout << "The use count for sp2 is: " << sp2.use_count() << endl;

    cout << " - -  - - - - - - - - -" << endl;

    cout << "Assigning sp object as a refernce to pointer sp3" << endl;
    shared_ptr <Foo> *sp3 = &sp; // Assigning sp object as a refernce to pointer sp3. you will get same use_count.
    //No increment, as you are just referencing it to the older object (sp)
    cout << "The use count for sp3 is: " << sp3->use_count() << endl;

    /*
    Demonstrating using Threads

    std::shared_ptr<Foo> sp4(new Foo(100));
    thread t1(fun, sp4), t2(fun, sp4), t3(fun, sp4); //passing our shared pointer into 3 threads
    //Now each thread gets a shared_pointer
    cout << "main: " << sp4.use_count() << endl; //Prints use_count 4 for 1 thread,
    //use_count 3 for one, use_count 2 for one and use_count 1 for the first shared_ptr
    t1.join(); t2.join(); t3.join();

    */

    cout << " - -  - - - - - - - - -" << endl;
    return 0;
}
